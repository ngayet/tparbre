#include "point.h"
#include "arbre.h"
#include "fifo.h"
#include <time.h>

void saisie(Node **tree);
Point saisieCoordonnees();
void insererRandomPoint(Node **tree);
void testFifo();

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
    do
    {
        printf("Entrez les coordonnées :\n");
        printf("x : ");
        scanf(" %i", &x);
        printf("y : ");
        scanf(" %i", &y);
        printf("z : ");
        scanf(" %i", &z);
        printf("\n");
        if (distOrigine((Point){x, y, z}) > 10)
        {
            printf("Coordonnées trop grandes.\n");
        }
    } while (distOrigine((Point){x, y, z}) > 10);
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
        printf("7 : Reset de l'arbre\n");
        printf("8 : Test d'une file\n\n");

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
            if (find(*tree, saisieCoordonnees()))
                printf("Le point est présent dans l'arbre.\n");
            else
                printf("Le point n'est pas présent dans l'arbre.\n");
            break;
        case 6:
            pprintTree(*tree);
            printf("\n");
            break;
        case 7:
            reset(tree);
            printf("Fini\n");
            break;
        case 8:
            testFifo();
            break;
        default:
            break;
        }
    }
}

/**
 * @brief Menu pour tester le fifo.
 * 
 */
void testFifo()
{
    int reponse = 1;
    int taille;

    printf("Taper la taille de la file : ");
    scanf(" %d", &taille);
    Fifo *fifoTest = initFifo(taille);
    printf("File créée\n");

    printf("\n");
    while (reponse != 0)
    {
        printf("========== Menu ==========\n");
        printf("0 : Sortir du test file\n");
        printf("1 : Enfiler\n");
        printf("2 : Défiler\n");
        printf("3 : Afficher la file\n");
        printf("4 : La file est-elle vide ?\n");
        printf("5 : La file est-elle pleine ?\n");
        printf("6 : Valeur de head et queue\n\n");

        printf("Votre choix ? ");
        scanf(" %i", &reponse);
        printf("\n");

        if (reponse == 1)
        {
            Node *nodeTemp = malloc(sizeof(Node));
            nodeTemp->leftChild = NULL;
            nodeTemp->rightChild = NULL;
            nodeTemp->point = saisieCoordonnees();
            enfiler(fifoTest, nodeTemp);
        }
        if (reponse == 2)
        {
            printf("Point défilé : \n");
            Node *nodeTemp = defiler(fifoTest);
            printTree(nodeTemp);
            free(nodeTemp);
        }

        switch (reponse)
        {
        case 0:
            break;
        case 1:
            printf("Fini\n");
            break;
        case 2:
            printf("Fini\n");
            break;
        case 3:
            printFifo(fifoTest);
            printf("\n");
            break;
        case 4:
            if (isEmpty(fifoTest))
            {
                printf("File vide");
            }
            else
            {
                printf("File non vide");
            }
            printf("\n");
            break;
        case 5:
            if (isFull(fifoTest))
            {
                printf("File pleine");
            }
            else
            {
                printf("File non pleine");
            }
            printf("\n");
            break;
        case 6:
            printf("head = %i\n", fifoTest->head);
            printf("queue = %i\n", fifoTest->queue);
            break;
        default:
            break;
        }
    }
}