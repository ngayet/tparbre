#include "fifo.h"

Fifo *initFifo(int size)
{
    Fifo *fifo = malloc(sizeof(Fifo));
    fifo->size = size;
    fifo->tabNodes = malloc(size * sizeof(Node *));
    fifo->queue = 0;
    fifo->head = 0;
    fifo->nbNoeuds = 0;
    return fifo;
}

void freeFifo(Fifo *fifo)
{
    free(fifo->tabNodes);
    free(fifo);
}

bool enfiler(Fifo *fifo, Node *noeud)
{
    if (isFull(fifo))
    {
        printf("Débordement de la file.\n");
        return false;
    }
    else
    {
        fifo->nbNoeuds++;
        *((fifo->tabNodes) + (fifo->queue++)) = noeud;
        if (fifo->queue >= (fifo->size - 1))
            fifo->queue = 0;
        return true;
    }
}
// retourne vrai si lâ€™enfilage a rÃ©ussi
// element est de type char dans un premier temps pour pouvoir tester facilement,
// il faudra modifier le prototype pour travailler sur les arbres
Node *defiler(Fifo *fifo)
{
    if (isEmpty(fifo))
    {
        printf("Pile vide, pas d'élément à défiler\n");
        return NULL;
    }
    else
    {
        fifo->nbNoeuds--;
        if (fifo->head == fifo->size - 1)
        {
            int buff = fifo->head;
            fifo->head = 0;
            return (fifo->tabNodes)[buff];
        }
        return (fifo->tabNodes)[fifo->head++];
    }
}
bool isEmpty(Fifo *fifo)
{
    return fifo->nbNoeuds == 0;
}

bool isFull(Fifo *fifo)
{
    return fifo->nbNoeuds == fifo->size;
}

Node *head(Fifo *fifo)
{
    return *(fifo->tabNodes) + (fifo->head);
}
// renvoit la valeur de lâ€™Ã©lÃ©ment stockÃ© en tÃªte de la file

Node *queue(Fifo *fifo)
{
    return *(fifo->tabNodes) + (fifo->queue);
}
// renvoit l'adresse de l'Ã©lÃ©ment stockÃ© en queue de la file
void printFifo(Fifo *fifo)
{
    if (isEmpty(fifo))
        printf("File vide.\n");

    Point point;
    int i = (fifo->head);

    while (i != (fifo->queue))
    {
        if (i == fifo->size)
            i = 0;
        point = ((fifo->tabNodes)[i])->point;
        printf("Point[%i] = (%i, %i, %i)\n", i, point.x, point.y, point.z);
        i++;
    }
}
