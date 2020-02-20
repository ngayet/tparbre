#include "point.h"
#include "arbre.h"
#include "fifo.h"
#include <time.h>

void saisie(Node **arbre);
Point saisieCoordonnees();

int main()
{
    srand(time(NULL));
    Node *arbre = NULL;

    saisie(&arbre);

    // Fifo * fifo = initFifo(2);

    // Noeud *nouveauNoeud1 = malloc(sizeof(Noeud));
    // nouveauNoeud1->point = (Point){rand() % 11, rand() % 11, rand() % 11};
    // nouveauNoeud1->leftChild = NULL;
    // nouveauNoeud1->rightChild = NULL;
    // Noeud *nouveauNoeud2 = malloc(sizeof(Noeud));
    // nouveauNoeud2->point = (Point){rand() % 11, rand() % 11, rand() % 11};
    // nouveauNoeud2->leftChild = NULL;
    // nouveauNoeud2->rightChild = NULL;
    // Noeud *nouveauNoeud3 = malloc(sizeof(Noeud));
    // nouveauNoeud3->point = (Point){rand() % 11, rand() % 11, rand() % 11};
    // nouveauNoeud3->leftChild = NULL;
    // nouveauNoeud3->rightChild = NULL;

    // enfiler(fifo, nouveauNoeud1);
    // enfiler(fifo, nouveauNoeud2);
    // enfiler(fifo, nouveauNoeud3);

    // printFifo(fifo);

    // defiler(fifo);
    // enfiler(fifo, nouveauNoeud1);
    // enfiler(fifo, nouveauNoeud1);
    // defiler(fifo);
    // enfiler(fifo, nouveauNoeud1);
    // enfiler(fifo, nouveauNoeud1);
    // printFifo(fifo);

    // printf("head : %i, queu : %i\n",head(fifo)->point.x,queue(fifo)->point.x);

    return 0;
}

void insererRandomPoint(Node **arbre)
{
    int nb;
    printf("Nombre de point : ");
    scanf(" %i", &nb);
    for (int i = 1; i <= nb; i++)
    {
        inserer(arbre, (Point){rand() % 6, rand() % 6, rand() % 6});
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
void saisie(Node **arbre)
{
    int reponse = 1;

    printf("\n");
    while (reponse != 0)
    {
        Node *temp;
        printf("========== Menu ==========\n");
        printf("0 : sortir du programme\n");
        printf("1 : inserer un point\n");
        printf("2 : inserer des points aléatoires\n");
        printf("3 : supprimer un point\n");
        printf("4 : afficher l'arbre\n");
        printf("5 : connaître la présence d'un point\n");
        printf("6 : joli affichage de l'arbre\n\n");

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
            printf("Inséré.\n\n");
            break;
        case 2:

            insererRandomPoint(arbre);
            printf("Inséré.\n\n");
            break;
        case 3:
            supprimer(arbre, saisieCoordonnees());
            printf("Fini\n\n");
            break;
        case 4:
            afficher(*arbre);
            printf("\n");
            break;
        case 5:
            temp = (rechercher(*arbre, saisieCoordonnees()));
            if (temp != NULL)
            {
                printf("Le point est présent dans l'arbre :\n");
                printf("%f (x : %i, y : %i, z : %i)\n\n", distOrigine(temp->point), (temp->point).x, (temp->point).y, (temp->point).z);
            }
            else
            {
                printf("Le point n'est pas présent dans l'arbre.\n\n");
            }
            break;
        case 6:
            pprintTree(*arbre);
            printf("\n");
            break;
        default:
            break;
        }
    }
}