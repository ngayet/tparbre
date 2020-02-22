#include "point.h"
#include "arbre.h"
#include "fifo.h"
#include <time.h>

void saisie(Node **tree);
Point saisieCoordonnees();
void insererRandomPoint(Node **tree);

int main()
{
    srand(time(NULL));
    Node *tree = NULL;
    saisie(&tree);
    return 0;
}

/**
 * @brief Insere un nombre demandé de point aléatoire dans l'arbre.
 * Les coordonnées ne dépasseront pas la valeur 5.
 * 
 * @param tree 
 */
void insererRandomPoint(Node **tree)
{
    int nb;
    printf("Nombre de point : ");
    scanf(" %i", &nb);
    for (int i = 1; i <= nb; i++)
    {
        insert(tree, (Point){rand() % 6, rand() % 6, rand() % 6});
    }
}

/**
 * @brief Retourne un point après une saisie de ses coordonnées.
 * Un point dépassant une distance à l'origine de 10 n'est pas
 * autorisé pour que l'affichage joli puisse fonctionner.
 *
 * @return Point
 */
Point saisieCoordonnees()
{
    int x, y, z;
    do{        
        printf("Entrez les coordonnées :\n");
        printf("x : ");
        scanf(" %i", &x);
        printf("y : ");
        scanf(" %i", &y);
        printf("z : ");
        scanf(" %i", &z);
        printf("\n");
        if (distOrigine((Point){x, y, z})>10)
        {
            printf("Coordonnées trop grandes.\n");
        }
    }while(distOrigine((Point){x, y, z})>10 );
    return (Point){x, y, z};
}

/**
 * @brief Gère l'affichage dans la console.
 *
 * @param tree
 */
void saisie(Node **tree)
{
    int reponse = 1;

    printf("\n");
    while (reponse != 0)
    {
        printf("========== Menu ==========\n");
        printf("0 : Sortir du programme\n");
        printf("1 : Inserer un point\n");
        printf("2 : Insérer des points aléatoires\n");
        printf("3 : Supprimer un point\n");
        printf("4 : Afficher l'arbre\n");
        printf("5 : Connaître la présence d'un point\n");
        printf("6 : Joli affichage de l'arbre\n");
        printf("7 : Reset de l'arbre\n\n");

        printf("Votre choix ? ");
        scanf(" %i", &reponse);
        printf("\n");

        switch (reponse)
        {
        case 0:
            printf("A bientôt !\n");
            break;
        case 1:
            printf("Merci de ne pas dépasser la valeur 5 lors de la saisie pour un affichage joli correct.\n");
            insert(tree, saisieCoordonnees());
            printf("Inséré.\n\n");
            break;
        case 2:
            insererRandomPoint(tree);
            printf("Inséré.\n\n");
            break;
        case 3:
            delete (tree, saisieCoordonnees());
            printf("Fini\n\n");
            break;
        case 4:
            printTree(*tree);
            printf("\n");
            break;
        case 5:
            if (find(*tree, saisieCoordonnees())) printf("Le point est présent dans l'arbre.\n");
            else printf("Le point n'est pas présent dans l'arbre.\n");
            break;
        case 6:
            pprintTree(*tree);
            printf("\n");
            break;
        case 7:
            reset(tree);
            printf("Fini\n");
            break;
        default:
            break;
        }
    }
}