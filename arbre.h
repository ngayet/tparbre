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
 * Dans le pire des cas l'arbre se présente comme une liste chainée.
 * La fonction se rappelle n fois si l'élèment doit être inséré après la feuille.
 *
 * @param tree
 * @param point
 */
void insert(Node **tree, Point point);

/**
 * @brief Retourne le pointeur du noeud contenant le point cherché.
 * Complexité en temps : O(n).
 * Complexité en mémoire : O(1).
 * Dans le pire des cas l'arbre se présente comme une liste chainée.
 * La fonction se rappelle n fois si l'élèment est la feuille.
 *
 * @param tree
 * @param point
 * @return Noeud*
 */
Node *find(Node *tree, Point point);

/**
 * @brief Supprime un point de l'arbre.
 * Complexité en temps : O(n).
 * Complexité en mémoire : O(1).
 * Dans le pire des cas l'arbre se présente comme une liste chainée.
 * La fonction se rappelle n fois si l'élèment est la feuille.
 *
 * @param tree
 * @param point
 */
void delete(Node **tree, Point point);

/**
 * @brief Affiche l'arbre.
 * Complexité en temps : O(n).
 * Complexité en mémoire : O(1).
 * La fonction se rappelle n fois.
 * 
 * @param tree
 */
void printTree(Node *tree);

/**
 * @brief Affiche count nombre d'espace.
 * Complexité en temps : O(n).
 * Complexité en mémoire : O(1).
 * 
 * @param count 
 */
void printSpace(int count);

/**
 * @brief Retourne le nombre de ligne d'un arbre.
 * Complexité en temps : O(n).
 * Complexité en mémoire : O(n).
 * Dans le pire des cas l'arbre se présente comme une liste chainée.
 * La fonction se rappelle n fois.
 * La fonction est réentrante, elle sauvegarde une valeur à chaque appel.
 * 
 * @param tree 
 * @return int 
 */
int nbLine(Node *tree);

/**
 * @brief Affiche les 6 premières lignes d'un arbre.
 * Les valeurs affichées sont la distance du point depuis l'origine,
 * multipliée par 10, tronquée sur un entier.
 * 
 * Complexité en temps : O(2^n).
 * Complexité en mémoire : O(2^n).
 * Nous enfilons la valeur null dans la file lorsque qu'il y a normalement
 * un noeud (comme dans un arbre parfaitement équilibré) pour gérer les
 * espaces. La fonction peut être amélioré, nous ne l'avons pas fait par manque
 * de temps.
 * 
 * @param tree 
 */
void pprintTree(Node *tree);

/**
 * @brief Free tous les noeuds.
 * Complexité en temps : O(n).
 * Complexité en mémoire : O(1).
 * La fonction se rappelle n fois.
 * 
 * @param tree 
 */
void reset(Node **tree);
#endif
