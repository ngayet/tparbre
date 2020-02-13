#include "arbre.h"
#include <time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    Noeud *arbre = NULL;

    for (int i = 0; i < 10; i++)
    {
        inserer(&arbre, (Point){rand() % 11, rand() % 11, rand() % 11});
    }
    saisie(&arbre);

    return 0;
}

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
        *arbre = nouveauNoeud;
        nouveauNoeud->point = point;
        nouveauNoeud->enfant_gauche = NULL;
        nouveauNoeud->enfant_droit = NULL;
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
 * @param noeudCourant 
 * @param point 
 * @return Noeud* 
 */
Noeud *rechercher(Noeud **noeudCourant, Point point)
{
    if (*noeudCourant != NULL)
    {
        int testEgal = egal((*noeudCourant)->point, point);

        if (testEgal == POINT_1_PLUS_GRAND)
        {
            return rechercher(&((*noeudCourant)->enfant_gauche), point);
        }
        else if (testEgal == POINT_1_PLUS_PETIT)
        {
            return rechercher(&((*noeudCourant)->enfant_droit), point);
        }
        else if (testEgal == DISTANCE_EGAL_COORDONNEES_NON_EGAL)
        {
            return rechercher(&((*noeudCourant)->enfant_droit), point);
        }
        else
        {
            return *noeudCourant;
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
    Noeud *noeudASupprimer = rechercher(arbre, point);

    if (noeudASupprimer == NULL)
        printf("Le point n'est pas présent.");

    // si le point à supprimer est plus petit que le noeud courant
    // rappeler supprimer avec le noeud gauche.
    if (egal((*arbre)->point, point) == POINT_1_PLUS_GRAND)
    {
        supprimer(&((*arbre)->enfant_gauche), point);
    }
    // si le point à supprimer est plus grand que le noeud courant
    // rappeler supprimer avec le noeud droit.
    else if (egal((*arbre)->point, point) == POINT_1_PLUS_PETIT)
    {
        supprimer(&((*arbre)->enfant_droit), point);
    }
    else
    {
        if ((*arbre)->enfant_gauche && (*arbre)->enfant_droit)
        {
            /* code */
        }
        else if ((*arbre)->enfant_gauche)
        {
        }
        else if ((*arbre)->enfant_droit)
        {
            /* code */
        }
        else
        {
            /* code */
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

/**
 * @brief Retourne un point après une saisie de ses coordonnées.
 * 
 * @return Point 
 */
Point saisieCoordonnees()
{
    int x, y, z;
    printf("Entrez les coordonnées :\n");
    printf("x : ");
    scanf(" %i", &x);
    printf("y : ");
    scanf(" %i", &y);
    printf("z : ");
    scanf(" %i", &z);
    printf("\n");
    return (Point){x, y, z};
}

/**
 * @brief Gère l'affichage dans la console.
 * 
 * @param arbre 
 */
void saisie(Noeud **arbre)
{
    int reponse = 1;

    printf("\n");
    while (reponse != 0)
    {
        printf("========== Menu ==========\n");
        printf("0 : sortir du programme\n");
        printf("1 : inserer un point\n");
        printf("2 : supprimer un point\n");
        printf("3 : afficher l'arbre\n");
        printf("4 : connaître la présence d'un point\n\n");

        printf("Votre choix ? ");
        scanf(" %i", &reponse);
        printf("\n");

        switch (reponse)
        {
        case 0:
            printf("Au revoir !\n");
            break;
        case 1:
            inserer(arbre, saisieCoordonnees());
            printf("Fini\n\n");
            break;
        case 2:
            supprimer(arbre, saisieCoordonnees());
            printf("Fini\n\n");
            break;
        case 3:
            afficher(*arbre);
            printf("\n");
            break;
        case 4:
            if (rechercher(arbre, saisieCoordonnees()) != NULL)
            {
                printf("Le point est présent dans l'arbre.\n\n");
            }
            else
            {
                printf("Le point n'est pas présent dans l'arbre.\n\n");
            }
            break;
        default:
            break;
        }
    }
}
