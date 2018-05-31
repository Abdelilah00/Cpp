#include <iostream>

class Table{
private:
    int taille_tab;
    int *tab;
    void swap(int &x, int &y){
        int z = x;
        x = y;
        y = z;
    }
    int Max_Tab(){
        int Max=tab[0];
        int i;
        for ( i = 1; i < taille_tab; ++i) {
            if(Max<tab[i]){
                Max=tab[i];
            }
            return Max;
        }
    }

public:
    Table(int taille){
        taille_tab = taille;
        tab = new int(taille_tab);
    }

    void TriShell(){
        int incr = taille_tab/2;

        while (incr != 0){
            int i = incr;
            while(i<taille_tab){
                int key = tab[i];
                int j = i-incr;
                while (j >= 0 && tab[j] > key){
                    tab[j+incr]=tab[j];
                    j = j - incr;
                }
                tab[j+incr] = key;
                i++;
            }
            incr = incr/2;
        }
    }
    void TriInsertion() {
        for (int key = 1; key < taille_tab; key++) {
            int i = key-1;
            int tmpkey = tab[key];

            while (i>=0 && tmpkey > tab[i]){
                tab[i+1] = tab[i];
                tab[i--] = tmpkey;
            }
        }
    }
    void TriBubble(){
        bool flag;
        do{
            flag = false;
            for (int j = 0; j < taille_tab - 1; ++j) {
                if(tab[j]<tab[j+1]){
                    swap(tab[j],tab[j+1]);
                    flag = true;
                }
            }
        }while(flag);
    }
    void TriCounting(){
        int curr = 0;
        int max = Max_Tab();
        auto * counting_array = new int[max]; // Zeros out the array

        for(curr = 0; curr < taille_tab; curr ++){
            counting_array[tab[curr]]++;
        }

        int num = 0;
        curr = 0;

        while(curr <= taille_tab){
            while(counting_array[num] > 0) {
                tab[curr] = num;
                counting_array[num]--;
                curr++;
                if(curr > taille_tab){ break; }
            }
            num++;
        }
    }

    void Scan(){
        int i=0;
        while (i<taille_tab){
            std::cin>>tab[i++];
        }
    }
    void Afficher(){
        int i=0;
        while (i<taille_tab)
            std::cout<<tab[i++]<<"\t";
        std::cout<<std::endl;
    }
};

int main() {

    Table tab(5);
    tab.Scan();
    tab.TriRapide();
    tab.Afficher();

    return 0;
}
