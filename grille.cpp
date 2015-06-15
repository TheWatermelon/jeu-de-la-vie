#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

class Cellule {
    private:
        bool alive;

    public:
        Cellule() {
            alive=false;
        }

        void toggleAlive() {
            if(alive)   alive = false;
            else        alive = true;
        }

        bool isAlive() {
            if(alive)   return true;
            else        return false;
        }
};

class Grille {
    private:
        int taille;
        int vie;
        int neutre;
        char methode;
        Cellule** tab;

    public:
        Grille(int t, char m, int v, int n) {
            int i;
            taille = t;
            methode = m;
            vie = v;
            neutre = n;
            /* Initialisation du tableau de cellules */
            tab = new Cellule*[taille];
            for(i=0; i<taille; i++) {
                tab[i] = new Cellule[taille];
            }
        }

        ~Grille() {
        }

        void initGrille() {
            int i, j;
            srand(time(NULL));

            for(i=0; i<taille; i++) {
                for(j=0; j<taille; j++) {
                    if((rand()%2)) {
                        tab[i][j].toggleAlive();
                    }
                }
            }
        }

        void initGrille(double freq) {
            int i, j, f;
            srand(time(NULL));

            /* Convertir la frequence en entier : round(freq*100) */
            f = round(freq*100);

            for(i=0; i<taille; i++) {
                for(j=0; j<taille; j++) {
                    /* Donner vie aux cellules qui sont dans la bonne fréquence */
                    if((rand()%100+1)<=f) {
                        tab[i][j].toggleAlive();
                    }
                }
            }
        }
        
        void afficherGrille() {
            int i, j;

            for(i=0; i<taille; i++) {
                for(j=0; j<taille; j++) {
                    cout << " ";
                    if(tab[i][j].isAlive())
                        cout << '0';
                    else
                        cout << '.';
                }
                cout << '\n';
            }
        }
        
        void nouvelleEtape() {
            int i, j, count;

            /* Boucle qui compte le nombre de voisins */
            for(j=0; j<taille; j++) {
                for(i=0; i<taille; i++) {
                    count=0;
                    /* La cellule est au milieu */
                    if(i>0 && i<(taille-1) && j>0 && j<(taille-1)) {
                        /* NORD */
                        if(tab[i][j-1].isAlive())   count++;
                        /* NORD-EST */
                        if(tab[i+1][j-1].isAlive()) count++;
                        /* EST */
                        if(tab[i+1][j].isAlive())   count++;
                        /* SUD-EST */
                        if(tab[i+1][j+1].isAlive()) count++;
                        /* SUD */
                        if(tab[i][j+1].isAlive())   count++;
                        /* SUD-OUEST */
                        if(tab[i-1][j+1].isAlive()) count++;
                        /* OUEST */
                        if(tab[i-1][j].isAlive())   count++;
                        /* NORD-OUEST */
                        if(tab[i-1][j-1].isAlive()) count++;
                    }
                    /* La cellule est au coin NORD-OUEST */
                    else if(i==0 && j==0) {
                        /* EST */
                        if(tab[i+1][j].isAlive())   count++;
                        /* SUD-EST */
                        if(tab[i+1][j+1].isAlive()) count++;
                        /* SUD */
                        if(tab[i][j+1].isAlive())   count++;
                    }
                    /* La cellule est au coin NORD-EST */
                    else if(i==(taille-1) && j==0) {
                        /* OUEST */
                        if(tab[i-1][j].isAlive())   count++;
                        /* SUD-OUEST */
                        if(tab[i-1][j+1].isAlive()) count++;
                        /* SUD */
                        if(tab[i][j+1].isAlive())   count++;
                    }
                    /* La cellule est au coin SUD-EST */
                    else if(i==(taille-1) && j==(taille-1)) {
                        /* NORD */
                        if(tab[i][j-1].isAlive())   count++;
                        /* NORD-OUEST */
                        if(tab[i-1][j-1].isAlive()) count++;
                        /* OUEST */
                        if(tab[i-1][j].isAlive())   count++;
                    }
                    /* La cellule est au coin SUD-OUEST */
                    else if(i==0 && j==(taille-1)) {
                        /* NORD */
                        if(tab[i][j-1].isAlive())   count++;
                        /* NORD-EST */
                        if(tab[i+1][j-1].isAlive()) count++;
                        /* EST */
                        if(tab[i+1][j].isAlive())   count++;
                    }
                    /* La cellule est au NORD */
                    else if(j==0) {
                        /* EST */
                        if(tab[i+1][j].isAlive())   count++;
                        /* SUD-EST */
                        if(tab[i+1][j+1].isAlive()) count++;
                        /* SUD */
                        if(tab[i][j+1].isAlive())   count++;
                        /* SUD-OUEST */
                        if(tab[i-1][j+1].isAlive()) count++;
                        /* OUEST */
                        if(tab[i-1][j].isAlive())   count++;
                    }
                    /* La cellule est à l'EST */
                    else if(i==(taille-1)) {
                        /* NORD */
                        if(tab[i][j-1].isAlive())   count++;
                        /* NORD-OUEST */
                        if(tab[i-1][j-1].isAlive()) count++;
                        /* OUEST */
                        if(tab[i-1][j].isAlive())   count++;
                        /* SUD-OUEST */
                        if(tab[i-1][j+1].isAlive()) count++;
                        /* SUD */
                        if(tab[i][j+1].isAlive())   count++;
                    }
                    /* La cellule est au SUD */
                    else if(j==(taille-1)) {
                        /* OUEST */
                        if(tab[i-1][j].isAlive())   count++;
                        /* NORD-OUEST */
                        if(tab[i-1][j-1].isAlive()) count++;
                        /* NORD */
                        if(tab[i][j-1].isAlive())   count++;
                        /* NORD-EST */
                        if(tab[i+1][j-1].isAlive()) count++;
                        /* EST */
                        if(tab[i+1][j].isAlive())   count++;
                    }
                    /* La cellule est à l'OUEST */
                    else if(i==0) {
                        /* NORD */
                        if(tab[i][j-1].isAlive())   count++;
                        /* NORD-EST */
                        if(tab[i+1][j-1].isAlive()) count++;
                        /* EST */
                        if(tab[i+1][j].isAlive())   count++;
                        /* SUD-EST */
                        if(tab[i+1][j+1].isAlive()) count++;
                        /* SUD */
                        if(tab[i][j+1].isAlive())   count++;
                    }
                    changementEtatCellule(count, i, j);
                }
            }
        }
        
        bool changementEtatCellule(int c, int i, int j) {
            if(c == neutre) {
                /* Pas de changement d'état */
                return false;
            }
            else if(c == vie) {
                    if(!tab[i][j].isAlive()) {
                        tab[i][j].toggleAlive();
                    }
            }
            else {
                if(tab[i][j].isAlive()) {
                    tab[i][j].toggleAlive();
                }
            }
            return true;
        }
};
