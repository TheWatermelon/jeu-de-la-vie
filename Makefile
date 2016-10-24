jeu:    main.o menus.o grille.o simulation.o
    g++ -o jeu main.o menus.o grille.o simulation.o

main.o: main.cpp fonctions.h
    g++ -c main.cpp

menus.o: menus.cpp fonctions.h
    g++ -c menus.cpp

grille.o: grille.cpp
    g++ -c grille.cpp

simulation.o: simulation.cpp
    g++ -c simulation.cpp

clean:
    rm -f jeu *.o
