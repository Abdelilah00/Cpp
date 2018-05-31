#include <iostream>
using namespace std;

class ListSimpleChen{
private:
    static int listSimpleChen;

public:
    int data = 0;
    ListSimpleChen *next = nullptr;
    ListSimpleChen *tete = nullptr;

public:
    ListSimpleChen(){
        cout<<++listSimpleChen<<" Construit Simple"<<endl;
    }
    ~ListSimpleChen(){
        cout<<--listSimpleChen<<" Detruit Simple"<<endl;
    }

    virtual void Insert(int data){
        auto *tmp = new ListSimpleChen;
        tmp->data = data;
        tmp->next = tete;
        tete = tmp;
    }
    virtual void Affich(){
        ListSimpleChen *curr = tete;
        while (curr){
            cout<<curr->data<<endl;
            curr = curr->next;
        }
    }
    virtual void Delet(int data){
        ListSimpleChen *curr = tete;
        ListSimpleChen *curr2 = curr->next;

        if(curr->data == data){
            tete = curr->next;
            delete curr;
            return;
        } else {
            while (curr2){
                if(curr2->data == data){
                    curr->next = curr2->next;
                    delete curr2;
                    return;
                }else {
                    curr = curr->next;
                    curr2 = curr->next;
                }
            }
            cout<<data<<" n'existe pas"<<endl;
        }
    }
    friend class ArbreBin;
    friend class File;
};

class ListDoubleChen : ListSimpleChen{
    static int listDoubleChen;
protected:
    ListDoubleChen *preview = nullptr;
    ListDoubleChen *fin = nullptr;
public:
    ListDoubleChen(){
        cout<<++listDoubleChen<<" Construit Double"<<endl;

    }
    ~ListDoubleChen(){
        cout<<--listDoubleChen<<" Detruit Double"<<endl;
    }
    void Insert(int data) {
        auto *tmp = new ListDoubleChen;
        auto *tmp2 = new ListDoubleChen;

        tmp->data = data;
        tmp->next = nullptr;
        tmp->preview = nullptr;

        if(fin == nullptr){
            fin = tmp;
            tete = tmp;
        }else{
            tmp->next = tete;
            tete = tmp;
            tmp2 = (ListDoubleChen*)tete->next;
            tmp2->preview = (ListDoubleChen*)tete;
        }
    }
    void Affich(const string x){
        if(x == "tete"){
            ListSimpleChen::Affich();
        } else{
            ListDoubleChen *curr = fin;
            while (curr){
                cout<<curr->data<<endl;
                curr = curr->preview;
            }
        }
    };
    virtual void Delet(int data) {
        auto *curr =(ListDoubleChen*) tete;
        auto *curr2 = (ListDoubleChen*) tete->next;
        auto *tmp = new ListDoubleChen;

        if(tete->data == data && fin->data != data){
            tete = tete->next;
            tmp =(ListDoubleChen*) tete;
            delete tmp->preview;
            tmp->preview = nullptr;
            return;
        } else if(fin->data == data){
            fin = fin->preview;
            delete fin->next;
            fin->next = nullptr;
            return;
        } else{
            while (curr2){
                if(curr2->data == data){
                    curr->next = curr2->next;
                    tmp = (ListDoubleChen*) curr->next;
                    tmp->preview = curr;
                    delete curr2;
                    return;
                }else {
                    curr =(ListDoubleChen*) curr->next;
                    curr2 =(ListDoubleChen*) curr->next;
                }
            }
        }
        cout<<data<<" n'existe pas"<<endl;
    }
    friend class File;
    friend class ArbreBin;
};

class Pile : ListSimpleChen{
    static int pile;

public:
    Pile(){
        cout<<++pile<<" Construit Pile"<<endl;
    }
    ~Pile(){
        cout<<--pile<<" Detruit Pile"<<endl;
    }
    void Push(int data){
        Insert(data);
    }
    void Pop(){
        auto *tmp =  (Pile*) tete;
        tete = tete->next;
        delete tmp;
    }
    void Affich(){
        ListSimpleChen::Affich();
    }
    void Delet(int data){
        ListSimpleChen::Delet(data);
    }
};
class File : ListSimpleChen{
    static int file;
protected:
    File *fin;
public:
    File(){
        cout<<++file<<" Construit File"<<endl;
    }
    ~File(){
        cout<<--file<<" Construit File"<<endl;
    }

    void Enfiler(int data){

        auto *tmp = new File;
        tmp->data = data;
        tmp->next = nullptr;
        if(tete == nullptr){
            tete = fin = tmp;
        }else{
            fin->next = tmp;
            fin = tmp;
        }

        if(tete == nullptr)tete = fin;
    }
    void Defiler(){
        auto *tmp = tete;
        tete = tete->next;
        delete tmp;
    }
    using ListSimpleChen::Affich;
    using ListSimpleChen::Delet;

};

class ArbreBin : ListDoubleChen{
    ArbreBin *racine = nullptr;
    static int arbreBin;

    void Insert(ArbreBin *NewCell, ArbreBin *racine){
        if(NewCell->data > racine->data){
            if(racine->next == nullptr){
                racine->next = NewCell;
            } else{
                Insert(NewCell,(ArbreBin*) racine->next);
            }
        } else{
            if(racine->preview == nullptr){
                racine->preview = NewCell;
            } else{
                Insert(NewCell,(ArbreBin*)racine->preview);
            }
        }
    }
    void affichage(ArbreBin *racine){
        if(racine == nullptr)return;
        else{
            affichage((ArbreBin*)racine->preview);
            affichage((ArbreBin*)racine->next);
            cout<<racine->data<<"\t";
        }
    }

public:
    ArbreBin(){
        cout<<++arbreBin<<" Construit ArbreBin"<<endl;
    }
    ~ArbreBin(){
        cout<<--arbreBin<<" Detruit ArbreBin"<<endl;
    }
    void Insert(int data) {
        auto *NewCell = new ArbreBin;
        NewCell->ListSimpleChen::data = data;
        NewCell->preview = nullptr;
        NewCell->next = nullptr;

        if(racine == nullptr){
            this->racine = NewCell;
        } else{
            Insert(NewCell, this->racine);
        }
    }
    void affichage(){
        affichage(this->racine);
    }
};

/*#########################################*/

int ListSimpleChen::listSimpleChen= 0;
int ListDoubleChen::listDoubleChen= 0;
int Pile::pile = 0;
int File::file = 0;
int ArbreBin::arbreBin = 0;

//ListDoubleChen* ListDoubleChen::fin = nullptr;
//ListSimpleChen* ListSimpleChen::tete = nullptr;
/*########################################*/

int main(){
    ArbreBin bn;
    bn.Insert(12);
    bn.Insert(35);
    bn.Insert(6);
    bn.affichage();

    return 0;
}