#include "arbre.h"
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

void inserer(Node **tree, Point point)
{
    if (*tree == NULL)
    {
        Node *nouveauNoeud = malloc(sizeof(Node));
        nouveauNoeud->point = point;
        nouveauNoeud->leftChild = NULL;
        nouveauNoeud->rightChild = NULL;

        *tree = nouveauNoeud;
    }
    else
    {
        if (distOrigine(point) < distOrigine((*tree)->point))
        {
            inserer(&((*tree)->leftChild), point);
        }
        else
        {
            inserer(&((*tree)->rightChild), point);
        }
    }
}

Node *rechercher(Node *tree, Point point)
{
    if (tree != NULL)
    {
        if (dist(tree->point, point) == 0)
        {
            return tree;
        }
        else if (distOrigine(tree->point) > distOrigine(point))
        {
            return rechercher(tree->leftChild, point);
        }
        else
        {
            return rechercher(tree->rightChild, point);
        }
    }
    return NULL;
}

void supprimer(Node **tree, Point point)
{

    if (*tree != NULL)
    {
        if (dist((*tree)->point, point) == 0)
        {
            free(*tree);
            if ((*tree)->leftChild == NULL && (*tree)->rightChild == NULL)
            {
                *tree = NULL;
            }
            else if ((*tree)->rightChild == NULL)
            {
                *tree = (*tree)->leftChild;
            }
            else if ((*tree)->leftChild == NULL)
            {
                *tree = (*tree)->rightChild;
            }
            else
            {
                Node *temp = (*tree)->leftChild;
                while (temp && temp->rightChild != NULL)
                {
                    temp = temp->rightChild;
                }
                (*tree)->point = temp->point;
                supprimer(&(*tree)->leftChild, temp->point);
            }
        }
        else if (distOrigine((*tree)->point) > distOrigine(point))
        {
            supprimer(&(*tree)->leftChild, point);
        }
        else
        {
            supprimer(&(*tree)->rightChild, point);
        }
    }
}

void afficher(Node *tree)
{
    if (tree != NULL)
    {
        afficher(tree->leftChild);
        printf("%f (x : %i, y : %i, z : %i)\n", distOrigine(tree->point),
               (tree->point).x, (tree->point).y, (tree->point).z);
        afficher(tree->rightChild);
    }
}

void printSpace(int count)
{
    for (int i = 0; i < count; i++)
    {
        printf(" ");
    }
}

int nbLine(Node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        int somme = 1;

        somme += MAX(nbLine(tree->rightChild), nbLine(tree->leftChild));

        return somme;
    }
}

void pprintTree(Node *tree)
{
    Node *temp;
    int nb_line = nbLine(tree);
    Fifo *fifo = initFifo(pow(2, nb_line));
    enfiler(fifo, tree);
    int widthCount = 1;
    int startSpace = 0;
    int nbSpace = 0;

    for (int i = 1; i < nb_line; i++)
    {
        startSpace = 1 + (startSpace * 2);
        nbSpace = 2 + (2 * nbSpace);
    }

    printSpace(startSpace);
    for (int i = 1; i <= nb_line; i++)
    {

        for (int j = 0; j < widthCount; j++)
        {
            temp = defiler(fifo);

            if (temp)
            {
                printf("%i", (int)(10 * distOrigine(temp->point)));
                enfiler(fifo, temp->leftChild);
                enfiler(fifo, temp->rightChild);
            }
            else
            {
                // on empile quand même pour gérer l'espacement de la prochaine ligne.
                printf("  ");
                enfiler(fifo, NULL);
                enfiler(fifo, NULL);
            }
            printSpace(nbSpace);
        }

        printf("\n");
        startSpace = (startSpace - 1) / 2;
        nbSpace = (nbSpace - 2) / 2;
        printSpace(startSpace);

        widthCount = fifo->nbNoeuds;
    }
    printf("nombre de colonnes : %i", nb_line);
}
