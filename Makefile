jeu: main.o menus.o grille.o simulation.o cellule.o
	g++ -o jeu main.o menus.o grille.o cellule.o simulation.o

main.o: main.cpp fonctions.h
	g++ -c main.cpp

menus.o: menus.cpp fonctions.h
	g++ -c menus.cpp

grille.o: grille.cpp
	g++ -c grille.cpp
    
cellule.o: cellule.cpp
	g++ -c cellule.cpp

simulation.o: simulation.cpp
	g++ -c simulation.cpp

clean:
	rm -f jeu *.o
