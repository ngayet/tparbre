#include <stdlib.h>
#include <stdio.h>
#include "point.h"

#ifndef arbre_h
#define arbre_h

typedef struct noeud{
    Point point;
    struct noeud* enfant_gauche;
    struct noeud* enfant_droit;
}Noeud;


void inserer(Noeud** arbre, Point point);
void supprimer(Noeud** arbre, Point point);
void afficher(Noeud* arbre);
Noeud* rechercher(Noeud** arbre, Point point);


void saisie(Noeud** arbre);
Point saisieCoordonnees();

#endif
