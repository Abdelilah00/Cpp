#include <iostream>
using namespace std;
#define MAX 5
/*---------------------------------------------*/

void swap(int &x,int &y){
    int z = y;
    y = x;
    x = z;
}
class table{
protected:
    int nb_case;
    int *tab;
public:
    table(int taille = MAX):nb_case(taille){
        tab = new int[nb_case];
    }

    void saisie_tab(){
        int i=0;
        while (i < nb_case){
            cout<<"tab["<<i<<"] :"<<endl;
            cin>> tab[i];
            i++;
        }
    }
    void affich_tab(){
        int i=0;
        while (i < nb_case){
            cout<<"tab["<<tab[i]<<"]"<<endl;
            i++;
        }
    }
    void tri(){
        bool drap;
        do{
            drap = false;
            for (int i = 0; i < nb_case-1; i++) {
                if(tab[i] > tab[i+1]){
                    swap(tab[i],tab[i+1]);
                    drap = true;
                }
            }
        }while (drap);
    }
};
class matrix : public table{
    int nb_colonne;
    int nb_ligne;
    int **ptr;
public:

    matrix(int nb_l = 3,int nb_cl = 3):nb_colonne(nb_cl),nb_ligne(nb_l),table(nb_l){
        ptr =(int**)tab;

        for (int i = 0; i < nb_ligne; i++) {
            *(ptr+i) = new int[nb_colonne];
        }
    };

    void saisie_matrix(){
        int i=0,j=0;
        while (i < nb_ligne){
            while (j < nb_colonne){
                cout<<"Case ["<<i<<"] ["<<j<<"] : "<<endl;
                cin >> *(*(ptr+j)+i);
                j++;
            }
            j=0;
            i++;
        }
    }
    void affich_matrix(){
        int i=0,j=0;
        while (i <nb_ligne){
            while (j <nb_colonne){
                cout<<"["<<*(*(ptr+i)+j)<<"] ";
                j++;
            }
            j=0;
            i++;
            cout<<endl;
        }
    }
};

/*---------------------------------------------*/
int main(){

    matrix mat(3,3);
    mat.saisie_matrix();
    mat.affich_matrix();

    return 0;
}

