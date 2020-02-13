#include "arbre.h"
#include <time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    Noeud *arbre = NULL;

    for (int i = 0; i < 10; i++)
    {
        inserer(&arbre, (Point){rand() % 11, rand() % 11, rand() % 11});
        // insererPoint(&arbre, (Point){i, 0, 0});
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
Noeud **rechercher(Noeud **arbre, Point point)
{
    if (*arbre != NULL)
    {
        int testEgal = egal((*arbre)->point, point);

        if (testEgal == POINT_1_PLUS_GRAND)
        {
            return rechercher(&((*arbre)->enfant_gauche), point);
        }
        else if (testEgal == POINT_1_PLUS_PETIT)
        {
            return rechercher(&((*arbre)->enfant_droit), point);
        }
        else if (testEgal == DISTANCE_EGAL_COORDONNEES_NON_EGAL)
        {
            return rechercher(&((*arbre)->enfant_droit), point);
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
    
    if(*arbre != NULL)
    {
        if (egal((*arbre)->point, point)== POINT_1_PLUS_PETIT)
        {
            supprimer(&(*arbre)->enfant_droit, point);
        }
        else if (egal((*arbre)->point, point)== POINT_1_PLUS_GRAND)
        {
            supprimer(&(*arbre)->enfant_gauche, point);
        }
        else
        {
            free(*arbre);
            if ((*arbre)->enfant_gauche == NULL && (*arbre)->enfant_droit == NULL)
            {

            }
            else if((*arbre)->enfant_droit == NULL)
            {
                *arbre = (*arbre)->enfant_gauche;
            }
            else if ((*arbre)->enfant_gauche == NULL)
            {
                *arbre = (*arbre)->enfant_droit;
            }
            else
            {
                Noeud * temp = (*arbre)->enfant_gauche;
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
        Noeud *temp;
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
            temp = *(rechercher(arbre, saisieCoordonnees()));
            if (temp != NULL)
            {
                printf("Le point est présent dans l'arbre.\n\n");
                printf("%f (x : %i, y : %i, z : %i)\n", distOrigine(temp->point),(temp->point).x, (temp->point).y, (temp->point).z);
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
