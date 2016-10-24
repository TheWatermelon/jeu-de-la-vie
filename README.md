# Le jeu de la vie

## Introduction

Le jeu de la vie est un programme codé en C++, à but heuristique.

## Principe

Le jeu de la vie (voir [l'article wikipédia sur le jeu de la vie](http://fr.wikipedia.org/wiki/Jeu_de_la_vie "Wikipédia: Le jeu de la vie")) est affiché en console. Il a été testé sous environnement linux.

## Installation

Récupérez le dépôt avec

`git clone http://github.com/TheWatermelon/jeu-de-la-vie.git`

puis

`cd jeu-de-la-vie/`

et enfin

`make jeu && ./jeu`

## Compatibilité

Si vous voulez utiliser le jeu sous windows, il faut remplacer toutes les instructions system("clear") par system("cls") dans menus.cpp et simulation.cpp
