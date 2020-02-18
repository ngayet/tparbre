#include "fifo.h"

Fifo *initFifo(int taille)
{
    Fifo *fifo = malloc(sizeof(Fifo));
    fifo->taille = taille;
    fifo->tabnoeuds = malloc(taille * sizeof(Noeud *));
    fifo->queue = 0;
    fifo->tete = 0;
    fifo->nbNoeuds = 0;
    return fifo;
}

void freeFifo(Fifo *fifo)
{
    free(fifo->tabnoeuds);
    free(fifo);
}

bool enfiler(Fifo *fifo, Noeud *noeud)
{
    if (isFull(fifo))
    {
        printf("Débordement de la file.\n");
        return false;
    }
    else
    {
        fifo->nbNoeuds++;
        *((fifo->tabnoeuds) + (fifo->queue++)) = noeud;
        if (fifo->queue >= (fifo->taille - 1))
            fifo->queue = 0;
        return true;
    }
}
// retourne vrai si lâ€™enfilage a rÃ©ussi
// element est de type char dans un premier temps pour pouvoir tester facilement,
// il faudra modifier le prototype pour travailler sur les arbres
Noeud *defiler(Fifo *fifo)
{
    if (isEmpty(fifo))
    {
        printf("Pile vide, pas d'élément à défiler\n");
        return NULL;
    }
    else
    {
        fifo->nbNoeuds --;
        if (fifo->tete == fifo->taille - 1)
        {
            int buff = fifo->tete;
            fifo->tete = 0;
            return (fifo->tabnoeuds)[buff];
        }
        return (fifo->tabnoeuds)[fifo->tete++];
    }
}
bool isEmpty(Fifo *fifo)
{
    return fifo->nbNoeuds == 0;
}

bool isFull(Fifo *fifo)
{
    return fifo->nbNoeuds == fifo->taille;
}

Noeud *head(Fifo *fifo)
{
    return *(fifo->tabnoeuds) + (fifo->tete);
}
// renvoit la valeur de lâ€™Ã©lÃ©ment stockÃ© en tÃªte de la file

Noeud *queue(Fifo *fifo)
{
    return *(fifo->tabnoeuds) + (fifo->queue);
}
// renvoit l'adresse de l'Ã©lÃ©ment stockÃ© en queue de la file
void printFifo(Fifo *fifo)
{
    if (isEmpty(fifo))
        printf("File vide.\n");

    Point point;
    int i = (fifo->tete);

    while (i != (fifo->queue))
    {
        if (i == fifo->taille)
            i = 0;
        point = ((fifo->tabnoeuds)[i])->point;
        printf("Point[%i] = (%i, %i, %i)\n", i, point.x, point.y, point.z);
        i++;
    }
}
