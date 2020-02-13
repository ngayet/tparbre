#include "arbre.h"
#include <time.h>

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    Noeud* arbre = NULL;

    for (int i = 0; i < 10; i++) {
        inserer(&arbre, creerPoint(rand()%11,rand()%11,rand()%11));
    }
    saisie(&arbre);
    printf("coucou");
    return 0;
}

void inserer(Noeud** arbre, Point point){
    if (*arbre == NULL) {
        Noeud* nouveauNoeud = malloc(sizeof(Noeud));
        *arbre = nouveauNoeud;
        nouveauNoeud->point = point;
        nouveauNoeud->gauche = NULL;
        nouveauNoeud->droite = NULL;
    }else{
        if (distOrigine(point) < distOrigine((*arbre)->point)) {
            inserer(&((*arbre)->gauche), point);
        }else{
            inserer(&((*arbre)->droite), point);
        }
    }
}

void supprimer(Noeud** arbre, Point point){

}

void afficher(Noeud* arbre){
    if(arbre!=NULL){
        afficher(arbre->gauche);
        printf("%f (x : %i, y : %i, z : %i)\n",distOrigine(arbre->point),
        (arbre->point).x,(arbre->point).y,(arbre->point).z);
        afficher(arbre->droite);
    }
}

void saisie(Noeud** arbre){
    int reponse = 1;
    while(reponse != 0){
        printf("========= Menu =========\n");
        printf("0 : sortir du programme\n");
        printf("1 : inserer un point\n");
        printf("2 : supprimer un point\n");
        printf("3 : afficher l'arbre\n\n");

        printf("Votre choix ? ");
        scanf(" %i", &reponse);
        printf("\n");
        int x, y, z;

        switch (reponse) {
            case 1:
                printf("Entrez les coordonnées :\n");
                printf("x : ");
                scanf(" %i", &x);
                printf("y : ");
                scanf(" %i", &y);
                printf("z : ");
                scanf(" %i", &z);

                inserer(arbre, creerPoint(x,y,z));
                printf("Fini\n\n");
                break;
            case 2:
                printf("Entrez les coordonnées :\n");
                printf("x : ");
                scanf(" %i", &x);
                printf("y : ");
                scanf(" %i", &y);
                printf("z : ");
                scanf(" %i", &z);

                supprimer(arbre, creerPoint(x,y,z));
                printf("Fini\n\n");
                break;
            case 3:
                afficher(*arbre);
                printf("\n");
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                break;
        }
    }
}
