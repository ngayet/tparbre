#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
/* Ã€ COMPLÃ‰TER */
} Fifo ;

Fifo * initFifo(int size) ;
    // renvoit une nouvelle file (vide) intitialisÃ©e

void freeFifo(Fifo *fifo) ;
    // dÃ©salloue la file et ce quâ€™elle contient

bool isEmpty(Fifo *fifo) ;

bool isFull(Fifo *fifo);

char head(Fifo *fifo) ;
    // renvoit la valeur de lâ€™Ã©lÃ©ment stockÃ© en tÃªte de la file

char * queue(Fifo *fifo) ;
    // renvoit l'adresse de l'Ã©lÃ©ment stockÃ© en queue de la file

bool enfiler(Fifo *fifo, char element) ;
    // retourne vrai si lâ€™enfilage a rÃ©ussi
    // element est de type char dans un premier temps pour pouvoir tester facilement,
    // il faudra modifier le prototype pour travailler sur les arbres

/* Ã€ COMPLÃ‰TER */ defiler(/* Ã€ COMPLÃ‰TER */) ;
    // retourne vrai si le defilage a rÃ©ussi

void printFifo(Fifo *fifo) ;
