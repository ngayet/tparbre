#ifndef fifo_h
#define fifo_h

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "arbre.h"

typedef struct fifo
{
    int size;               // nombre maxi dans la file
    int queue;              // indice du dernier élément enfilé
    int head;               // indice du prochain élément à défiler
    int nbNodes;           // nombre de noeuds dans la file
    struct node **tabNodes; // adresse du 1er élément du tableau tabnoeuds
} Fifo;

/**
 * @brief Renvoit une nouvelle file (vide) intitialisée.
 * Complexité en temps : O(1).
 * Complexité en mémoire : O(1).
 * 
 * @param size 
 * @return Fifo* 
 */
Fifo *initFifo(int size);

/**
 * @brief désalloue la file et ce qu'elle contient.
 * Complexité en temps : O(1).
 * Complexité en mémoire : O(1).
 * 
 * @param fifo 
 */
void freeFifo(Fifo *fifo);

/**
 * @brief Retourne vrai si la file est vide.
 * Complexité en temps : O(1).
 * Complexité en mémoire : O(1).
 * 
 * @param fifo 
 * @return true 
 * @return false 
 */
bool isEmpty(Fifo *fifo);

/**
 * @brief Retourne vrai si la file est pleine.
 * Complexité en temps : O(1).
 * Complexité en mémoire : O(1).
 * 
 * @param fifo 
 * @return true 
 * @return false 
 */
bool isFull(Fifo *fifo);

/**
 * @brief renvoit l'adresse de l'élément stocké en queue de la file.
 * Complexité en temps : O(1).
 * Complexité en mémoire : O(1).
 * 
 * @param fifo 
 * @return struct node* 
 */
struct node *queue(Fifo *fifo);

/**
 * @brief Renvoit la valeur de l'élément stocké en tête de la file.
 * Complexité en temps : O(1).
 * Complexité en mémoire : O(1).
 * 
 * @param fifo 
 * @return struct node* 
 */
struct node *head(Fifo *fifo);

/**
 * @brief Enfile un noeud dans la file.
 * Retourne vrai si l'enfilage a réussi.
 * Complexité en temps : O(1).
 * Complexité en mémoire : O(1).
 * 
 * @param fifo 
 * @param node 
 * @return true 
 * @return false 
 */
bool enfiler(Fifo *fifo, struct node *node);

/**
 * @brief Defile un noeud de la file.
 * Retourne vrai si le defilage a réussi.
 * Complexité en temps : O(1).
 * Complexité en mémoire : O(1).
 * 
 * @param fifo 
 * @return struct node* 
 */
struct node *defiler(Fifo *fifo);

/**
 * @brief Affiche la file.
 * Complexité en temps : O(n).
 * Complexité en mémoire : O(1).
 * 
 * @param fifo 
 */
void printFifo(Fifo *fifo);

#endif