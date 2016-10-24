#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "cellule.cpp"
using namespace std;

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
            for(int i=0; i<taille; i++) {
              for(int j=0; j<taille; j++) {
                tab[i][j].setLigne(i);
                tab[i][j].setColonne(j);
              }
            }
        }

        ~Grille() {
        }
  
        int getGridSize() { return taille; }
  
        Cellule** getTab() { return tab; }

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
                    changementEtatCellule(tab[i][j].update(tab, taille), i, j);
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
