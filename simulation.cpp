#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include "grille.cpp"
using namespace std;

void afficherSimulation(int tour, Grille g, char* c) {
        int i;

    system("clear");
        cout << "******************************************\n";
    cout << "              Etape : "<<tour<<"          \n";
    cout << "******************************************\n\n";

    g.afficherGrille();

    cout << "\n******************************************\n";
    cout << "   - c : Nouvelle étape                   \n";
    cout << "   - C : Passer 5 étapes                  \n";
    cout << "   - e : Sans fin (/!\\ utiliser Ctrl-C)\n";
    cout << "   - q : Quitter                          \n";
    cout << "******************************************\n";
    if(*c!='e')
        cin >> *c;

    switch(*c) {
        case 'c':
            g.nouvelleEtape();
            break;
        case 'C':
            for(i=0; i<5; i++)
                g.nouvelleEtape();
            break;
        case 'q':
            cout << "Fin de la simulation\n";
        default:
            break;
    }
}

void lancerSimulation(char m, int v, int n, int t, double freq) {
    int tour=0;
    char choix=0;
    Grille maGrille(t, m, v, n);
    maGrille.initGrille(freq);

    while(choix != 'q') {
        afficherSimulation(tour, maGrille, &choix);
        if(choix == 'c')
            tour++;
        else if(choix == 'C')
            tour+=5;
        else if(choix == 'e') {
            while(true) {
                maGrille.nouvelleEtape();
                tour++;
                afficherSimulation(tour, maGrille, &choix);
                usleep(500000);
            }
        }
    }
}
