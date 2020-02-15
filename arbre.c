#include "arbre.h"

/**
 * @brief Insere un nouveau point dans l'arbre.
 *
 * @param arbre
 * @param point
 */
void inserer(Noeud **arbre, Point point)
{
    if (*arbre == NULL)
    {
        Noeud *nouveauNoeud = malloc(sizeof(Noeud));
        nouveauNoeud->point = point;
        nouveauNoeud->enfant_gauche = NULL;
        nouveauNoeud->enfant_droit = NULL;

        *arbre = nouveauNoeud;
    }
    else
    {
        if (distOrigine(point) < distOrigine((*arbre)->point))
        {
            inserer(&((*arbre)->enfant_gauche), point);
        }
        else
        {
            inserer(&((*arbre)->enfant_droit), point);
        }
    }
}

/**
 * @brief Retourne le pointeur du noeud contenant le point cherché
 *
 * @param arbre
 * @param point
 * @return Noeud*
 */
Noeud *rechercher(Noeud *arbre, Point point)
{
    if (arbre != NULL)
    {
        int testEgal = egal(arbre->point, point);

        if (testEgal == POINT_1_PLUS_GRAND)
        {
            return rechercher(arbre->enfant_gauche, point);
        }
        else if (testEgal == POINT_1_PLUS_PETIT)
        {
            return rechercher(arbre->enfant_droit, point);
        }
        else if (testEgal == DISTANCE_EGAL_COORDONNEES_NON_EGAL)
        {
            return rechercher(arbre->enfant_droit, point);
        }
        else
        {
            return arbre;
        }
    }
    return NULL;
}

/**
 * @brief Supprime un point de l'arbre.
 *
 * @param arbre
 * @param point
 */
void supprimer(Noeud **arbre, Point point)
{

    if (*arbre != NULL)
    {
        if (egal((*arbre)->point, point) == POINT_1_PLUS_PETIT)
        {
            supprimer(&(*arbre)->enfant_droit, point);
        }
        else if (egal((*arbre)->point, point) == POINT_1_PLUS_GRAND)
        {
            supprimer(&(*arbre)->enfant_gauche, point);
        }
        else
        {
            free(*arbre);
            if ((*arbre)->enfant_gauche == NULL && (*arbre)->enfant_droit == NULL)
            {
                *arbre = NULL;
            }
            else if ((*arbre)->enfant_droit == NULL)
            {
                *arbre = (*arbre)->enfant_gauche;
            }
            else if ((*arbre)->enfant_gauche == NULL)
            {
                *arbre = (*arbre)->enfant_droit;
            }
            else
            {
                Noeud *temp = (*arbre)->enfant_gauche;
                while (temp && temp->enfant_droit != NULL)
                {
                    temp = temp->enfant_droit;
                }
                (*arbre)->point = temp->point;
                supprimer(&(*arbre)->enfant_gauche, temp->point);
            }
        }
    }
}

/**
 * @brief Affiche l'arbre.
 *
 * @param arbre
 */
void afficher(Noeud *arbre)
{
    if (arbre != NULL)
    {
        afficher(arbre->enfant_gauche);
        printf("%f (x : %i, y : %i, z : %i)\n", distOrigine(arbre->point),
               (arbre->point).x, (arbre->point).y, (arbre->point).z);
        afficher(arbre->enfant_droit);
    }
}

void pprintTree(Noeud *arbre)
{
    Noeud *temp;
    Fifo *fifo = initFifo(20);
    enfiler(fifo, arbre);

    int widthCount = 1;
    while (widthCount != 0)
    {
        for (size_t i = 0; i < widthCount; i++)
        {
            temp = defiler(fifo);
            if (temp)
            {
                printf("(%.1f)", distOrigine(temp->point));
                enfiler(fifo, temp->enfant_gauche);
                enfiler(fifo, temp->enfant_droit);
            }
            else
            {
                printf("NULL ");
            }
        }
        printf("\n");
        if (fifo->tete <= fifo->queue)
            widthCount = fifo->queue - fifo->tete;
        else
            widthCount = fifo->queue + (fifo->taille - fifo->tete);
    }
}
