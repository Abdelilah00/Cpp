#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>

#define MAX 100

using namespace std;
class Point{
protected:
    int x,y;
public:
    Point(int xx=rand()%11, int yy=rand()%11):x(xx),y(yy){};
    double distance(Point const& point){
        return hypot(this->x - point.x , this->y - point.y);
    }
    void equals(Point const& point){
        this->x = point.x;
        this->y = point.y;
    }

};
class Nuage : public Point{
protected:
    int taille = MAX;
    Point centre[2],tmpCentre[2],point[MAX];
    vector<Point> ctr1,ctr2;
    bool flag = true;
    Point Moyenne(vector<Point> ctr){
        int i=0;
        Point moyenne(0,0);
        if(ctr.empty())
            return moyenne;

        for (auto it = ctr.begin(); it != ctr.end(); it++,i++){
            moyenne.x += ctr.at(i).x;
            moyenne.y += ctr.at(i).y;
        }

        moyenne.x = (moyenne.x / i);
        moyenne.y = (moyenne.y / i);

        return moyenne;
    }
public:
    void SetNuage(){
        do {
            SetCentr();
        }while ( tmpCentre[1].x - centre[1].x > 1
                  && tmpCentre[2].x - centre[2].x > 1
                  && tmpCentre[1].y - centre[1].y > 1
                  && tmpCentre[2].y - centre[2].y > 1  );

    }
    void SetCentr(){
        int i=0,j=0,k=0;
        tmpCentre[1].equals(centre[1]);
        tmpCentre[2].equals(centre[2]);
        while(i<taille){
            Point point1(point[i].x, point[i].y);

            if(centre[1].distance(point1) > centre[2].distance(point1)) {
                ctr1.push_back(point1);
                cout<< "ctr1"<<" ";
            }
            else{
                ctr2.push_back(point1);
                cout<<"ctr2"<<" ";
            }
            i++;
        }
        centre[1].equals(Moyenne(ctr1));
        centre[2].equals(Moyenne(ctr2));
    }
    void Afficher(){
        for (int i = 0; i < MAX; ++i) {
            cout <<"("<<point[i].x<<","<<point[i].y<<")"<<endl;
        }
    }
};

int main(){
    srand(time(NULL));

    Nuage nuage;

    nuage.Afficher();
    nuage.SetNuage();

    return 0;
}