#include "arbre.h"
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

void insert(Node **tree, Point point)
{
    if (*tree == NULL)
    {
        Node *newNode = malloc(sizeof(Node));
        newNode->point = point;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;

        *tree = newNode;
    }
    else
    {
        if (distOrigine(point) < distOrigine((*tree)->point))
        {
            insert(&((*tree)->leftChild), point);
        }
        else
        {
            insert(&((*tree)->rightChild), point);
        }
    }
}

Node *find(Node *tree, Point point)
{
    if (tree != NULL)
    {
        if (dist(tree->point, point) == 0)
        {
            return tree;
        }
        else if (distOrigine(tree->point) > distOrigine(point))
        {
            return find(tree->leftChild, point);
        }
        else
        {
            return find(tree->rightChild, point);
        }
    }
    return NULL;
}

void delete (Node **tree, Point point)
{

    if (*tree != NULL)
    {
        if (dist((*tree)->point, point) == 0) // si point trouvé
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
            { // cas 4, on trouve le point qui doit remplacer celui du noeud.
                Node *temp = (*tree)->leftChild;
                while (temp && temp->rightChild != NULL)
                {
                    temp = temp->rightChild;
                }

                (*tree)->point = temp->point;
                //on rappelle la fonction pour supprimer le point devenu doublon.
                delete (&(*tree)->leftChild, temp->point);
            }
        }
        else if (distOrigine((*tree)->point) > distOrigine(point))
        {
            delete (&(*tree)->leftChild, point);
        }
        else
        {
            delete (&(*tree)->rightChild, point);
        }
    }
}

void printTree(Node *tree)
{
    if (tree != NULL)
    {
        printTree(tree->leftChild);
        printf("Distance à l'origine : %f\n", distOrigine(tree->point));
        printf("(x : %i, y : %i, z : %i)\n", (tree->point).x, (tree->point).y, (tree->point).z);
        printTree(tree->rightChild);
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
        return 1 + MAX(nbLine(tree->rightChild), nbLine(tree->leftChild));
    }
}

void pprintTree(Node *tree)
{
    if (tree == NULL)
    {
        printf("Il n'y a rien dans l'arbre !\n");
        return;
    }

    int nb_line = nbLine(tree);
    printf("Nombre de lignes de l'arbre : %i\n", nb_line);
    if (nb_line > 6)
    {
        nb_line = 6;
        printf("Nombre de lignes affichées : 6\n");
    }

    Node *temp;
    Fifo *fifo = initFifo(pow(2, nb_line));
    enfiler(fifo, tree);

    int widthCount = 1; // Nombre de noeud dans le FIFO
    int tempPoint;      // Variable utilisée pour factoriser une opération.

    int nbSpace = 2; // Calcul de l'espacement entre valeur
    for (int i = 1; i < nb_line; i++)
    {
        nbSpace = 2 + (2 * nbSpace);
    }

    printSpace(((nbSpace - 2) / 2)); // Premier espacement
    for (int i = 1; i <= nb_line; i++)
    {

        for (int j = 0; j < widthCount; j++)
        {
            temp = defiler(fifo);

            if (temp)
            {
                tempPoint = (10 * distOrigine(temp->point));
                if (tempPoint == 0)
                {
                    printf("00");
                }
                else
                {
                    printf("%i", tempPoint);
                }
                enfiler(fifo, temp->leftChild);
                enfiler(fifo, temp->rightChild);
            }
            else
            {
                // On empile quand même pour gérer l'espacement de la prochaine ligne.
                printf("  ");
                enfiler(fifo, NULL);
                enfiler(fifo, NULL);
            }
            printSpace(nbSpace); // Espacement entre valeur.
        }

        printf("\n");

        nbSpace = (nbSpace - 2) / 2;
        printSpace(((nbSpace - 2) / 2)); //espacement de la ligne suivante

        widthCount = fifo->nbNodes; // Mise à jour du nombre de noeud à afficher sur la ligne.
    }
}

void reset(Node **tree)
{
    if (*tree != NULL)
    {
        reset(&(*tree)->leftChild);
        reset(&(*tree)->rightChild);
        free(*tree);
        *tree = NULL;
    }
}