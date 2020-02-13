#include <stdlib.h>
#include <stdio.h>
#include "point.h"

#ifndef arbre_h
#define arbre_h

typedef struct noeud{
    Point point;
    struct noeud* gauche;
    struct noeud* droite;
}Noeud;

void inserer(Noeud** arbre, Point point);

void supprimer(Noeud** arbre, Point point);

void afficher(Noeud* arbre);
void saisie(Noeud** arbre);
#endif
