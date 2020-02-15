#include "point.h"
#include "arbre.h"
#include "fifo.h"
#include <time.h>

void saisie(Noeud **arbre);
Point saisieCoordonnees();

int main()
{
    srand(time(NULL));
    Noeud *arbre = NULL;

    for (int i = 0; i < 10; i++)
    {
        inserer(&arbre, (Point){rand() % 11, rand() % 11, rand() % 11});
        // insererPoint(&arbre, (Point){i, 0, 0});
    }
    saisie(&arbre);

    // Fifo * fifo = initFifo(2);

    // Noeud *nouveauNoeud1 = malloc(sizeof(Noeud));
    // nouveauNoeud1->point = (Point){rand() % 11, rand() % 11, rand() % 11};
    // nouveauNoeud1->enfant_gauche = NULL;
    // nouveauNoeud1->enfant_droit = NULL;
    // Noeud *nouveauNoeud2 = malloc(sizeof(Noeud));
    // nouveauNoeud2->point = (Point){rand() % 11, rand() % 11, rand() % 11};
    // nouveauNoeud2->enfant_gauche = NULL;
    // nouveauNoeud2->enfant_droit = NULL;
    // Noeud *nouveauNoeud3 = malloc(sizeof(Noeud));
    // nouveauNoeud3->point = (Point){rand() % 11, rand() % 11, rand() % 11};
    // nouveauNoeud3->enfant_gauche = NULL;
    // nouveauNoeud3->enfant_droit = NULL;

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
        printf("4 : connaître la présence d'un point\n");
        printf("5 : joli affichage de l'arbre\n\n");

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
            temp = (rechercher(*arbre, saisieCoordonnees()));
            if (temp != NULL)
            {
                printf("Le point est présent dans l'arbre.\n\n");
                printf("%f (x : %i, y : %i, z : %i)\n", distOrigine(temp->point), (temp->point).x, (temp->point).y, (temp->point).z);
            }
            else
            {
                printf("Le point n'est pas présent dans l'arbre.\n\n");
            }
            break;
        case 5:
            pprintTree(*arbre);
            printf("\n");
            break;
        default:
            break;
        }
    }
}