#include "fifo.h"

Fifo * initFifo(int taille) {
    Fifo *fifo= malloc(sizeof(Fifo));
    fifo->taille=taille;
    fifo->tabnoeuds=malloc(taille*sizeof(Noeud*);
    fifo->queue=0;
    fifo->tete=0;
    return fifo;
}

void freeFifo(Fifo *fifo){
    free(fifo->tabnoeuds);
    free (fifo);
}

bool enfiler(Fifo *fifo, Noeud *noeud) {
    if (isFull(fifo)){
        printf("Débordement de la file");
        return false;
    }
    else {
        (fifo->tabnoeuds)+(++(fifo->queue)) = noeud;
        return true;
    }
}
// retourne vrai si lâ€™enfilage a rÃ©ussi
// element est de type char dans un premier temps pour pouvoir tester facilement,
// il faudra modifier le prototype pour travailler sur les arbres
Noeud* defiler(Fifo *fifo){
    if (isEmpty(fifo)){
        printf("Pile vide, pas d'élément à  défiler\n");
        return NULL;
    }
    else {
        return (fifo->tabnoeuds)+((fifo->tete)++);
        }
}


void printFifo(Fifo *fifo){
    int i = (fifo->tete);
    while (i != (fifo->queue)) {
        printf("valeur : %f (x : %i, y : %i, z : %i)\n", distOrigine(i->point),
               (i->point).x, (i->point).y, (i->point).z);
        i++;
    }
}
