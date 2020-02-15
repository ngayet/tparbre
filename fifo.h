#ifndef fifo_h
#define fifo_h

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "arbre.h"

typedef struct fifo{
int taille;  // nombre maxi dans la file
int queue; // indice du dernier élément enfilé
int tete; // indice du prochain élément à défiler
struct noeud **tabnoeuds;  // adresse du 1er élément du tableau tabnoeuds
} Fifo ;

Fifo * initFifo(int size) ;
    // renvoit une nouvelle file (vide) intitialisÃ©e


void freeFifo(Fifo *fifo) ;
    // dÃ©salloue la file et ce quâ€™elle contient

bool isEmpty(Fifo *fifo) ;

bool isFull(Fifo *fifo);

struct noeud* head(Fifo *fifo) ;
    // renvoit la valeur de lâ€™Ã©lÃ©ment stockÃ© en tÃªte de la file

struct noeud* queue(Fifo *fifo) ;
    // renvoit l'adresse de l'Ã©lÃ©ment stockÃ© en queue de la file

bool enfiler(Fifo *fifo, struct noeud *noeud);
    // retourne vrai si lâ€™enfilage a rÃ©ussi
    // element est de type char dans un premier temps pour pouvoir tester facilement,
    // il faudra modifier le prototype pour travailler sur les arbres

struct noeud* defiler(Fifo *fifo);
    // retourne vrai si le defilage a rÃ©ussi

void printFifo(Fifo *fifo) ;

#endif