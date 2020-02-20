#ifndef arbre_h
#define arbre_h

#include <stdlib.h>
#include <stdio.h>
#include "point.h"
#include "fifo.h"

typedef struct node
{
    Point point;
    struct node *leftChild;
    struct node *rightChild;
} Node;

/**
 * @brief Insere un nouveau point dans l'arbre.
 * Complexité en temps : O(n).
 * Complexité en mémoire : O(1).
 *
 * @param tree
 * @param point
 */
void inserer(Node **tree, Point point);

/**
 * @brief Retourne le pointeur du noeud contenant le point cherché.
 * Complexité en temps : O(n).
 * Complexité en mémoire : O(1).
 *
 * @param tree
 * @param point
 * @return Noeud*
 */
Node *rechercher(Node *tree, Point point);

/**
 * @brief Supprime un point de l'arbre.
 * Complexité en temps : O(n).
 * Complexité en mémoire : O(1).
 *
 * @param tree
 * @param point
 */
void supprimer(Node **tree, Point point);

/**
 * @brief Affiche l'arbre.
 * Complexité en temps : O(n).
 * Complexité en mémoire : O(1).
 *
 * @param tree
 */
void afficher(Node *tree);

/**
 * @brief 
 * Complexité en temps : O(2^n).
 * Complexité en mémoire : O(2^n).
 * 
 * @param tree 
 */
void pprintTree(Node *tree);

#endif
