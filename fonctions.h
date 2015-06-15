#ifndef FONCTIONS_H
#define FONCTIONS_H

/* grille.cpp */
class Cellule {};
class Grille {};

/* menus.cpp */
void mainMenu();
void menuSimulationRapide();
void menuSimulationAvancee();
void menuInfo();

/* simulation.cpp */
void afficherSimulation(int, Grille, char*);
void lancerSimulation(char, int, int, int, double);

#endif /* FONCTIONS_H */
