#include <iostream>
#include <stdlib.h>
#include "fonctions.h"
using namespace std;

void mainMenu() {
    char choix=0;
    system("clear");
    cout << "******************************************\n";
    cout << "[             Jeu de la vie !            ]\n";
    cout << "******************************************\n";
    cout << " Devenez Dieu ! Créez votre environnement\n";
    cout << " initial et observez votre population\n";
    cout << " vivre... ou mourrir!\n\n";

    cout << " Le principe est simple: une cellule a\n";
    cout << " des cellules voisines, et leur nombre\n";
    cout << " détermine l'état de la cellule à l'étape\n";
    cout << " suivante.\n\n";

    cout << " ~ Si la règle de vie est atteinte, la\n";
    cout << " cellule prend vie à l'étape suivante (ou\n";
    cout << " reste en vie).\n";
    cout << " ~ Si la règle de neutralité est atteinte,\n";
    cout << " la cellule ne change pas d'état à l'étape\n";
    cout << " suivante.\n";
    cout << " ~ Si aucune des deux règles précédentes\n";
    cout << " n'est atteinte, la cellule meurt à\n";
    cout << " l'étape suivante.\n\n";

    cout << "******************************************\n";
    cout << "[             Menu principal             ]\n";
    cout << "******************************************\n";
    cout << "  1 - Simulation rapide                   \n";
    cout << "  2 - Simulation avancée                  \n";
    cout << "  3 - A propos du jeu de la vie           \n";
    cout << "  4 - Quitter                             \n";

    while(choix != '1' && choix != '2' && choix != '3' && choix != '4') {
        cout << " Votre choix : ";
        cin  >> choix;
        cout << '\n';
    }
    
    switch(choix) {
        case '1':
            cout << '\n';
            menuSimulationRapide();
            break;
        case '2':
            menuSimulationAvancee();
            break;
        case '3':
            menuInfo();
            break;
        case '4':
            cout << "Fin de l'application...\n";
            exit(0);
        default:
            cout << "Erreur de saisie, fin de l'application\n";
            exit(0);
    }
}

void menuSimulationRapide() {
    char choix = 0;
    cout << "******************************************\n";
    cout << "[           Simulation rapide            ]\n";
    cout << "******************************************\n";
    cout << "  - Modèle : défaut                       \n";
    cout << "  - Règle de vie : 3 cellules             \n";
    cout << "  - Règle de neutralité : 2 cellules      \n";
    cout << "  - Taille de la grille : 20x20           \n";
    cout << "  - Présence de cellules : 0.5            \n\n";

    while(choix != 'o' && choix != 'n') {
        cout << " Voulez-vous continuer? (o/n) : ";
        cin  >> choix;
    }

    switch(choix) {
        case 'o':
            lancerSimulation('d', 3, 2, 20, 0.5);
        case 'n':
            cout << '\n';
            mainMenu();
        default:
            cout << "Erreur de saisie, retour au menu principal\n";
            mainMenu();
    }
}

void menuSimulationAvancee() {
    char choix=0;
    int vie;
    int neutre;
    int taille;
    double freq;

    while(choix != 'o') {
        cout << "******************************************\n";
        cout << "[           Simulation rapide            ]\n";
        cout << "******************************************\n";
        cout << "  - Modèle : défaut                       \n";
        cout << "  - Règle de vie : "; cin >> vie;
        cout << "  - Règle de neutralité : "; cin >> neutre;
        cout << "  - Taille de la grille : "; cin >> taille;
        cout << "  - Présence de cellules : "; cin >> freq;
        cout << "\n\n Voulez-vous continuer? (o/n) : ";
        cin  >> choix;
    }
    lancerSimulation('d', vie, neutre, taille, freq);

}

void menuInfo() {
    char choix=0;
    cout << "******************************************\n";
    cout << "[              Informations              ]\n";
    cout << "******************************************\n";
    cout << " Ce programme n'est pas un jeu à propre-  \n";
    cout << " ment parler. Il s'agit d'un automate qui \n";
    cout << " permet de trouver des schémas stables    \n";
    cout << " parmis des exemples de simulation. Pour  \n";
    cout << " en savoir plus sur cet automate,         \n";
    cout << " Wikipédia sait tout à son sujet! :)      \n\n";
    cout << "******************************************\n\n";
    cout << " Revenir au menu? (o/n) : ";
    cin  >> choix;

    switch(choix) {
        case 'o':
            mainMenu();
        case 'n':
            cout << "Fin de l'application...\n";
            exit(0);
        default:
            cout << "Saisie incorrecte, fin de l'application...\n";
            exit(0);
    }
}
