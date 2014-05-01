#include<stdio.h>
#include "rat.h"
/*prototypes (signatures des fonctions)*/
extern void afficher (int liste[], int taille);
extern int somme (int liste[], int taille);
extern int *copie_dans(int dest[], int src[], int taille);


int main(){
    /*init (exercice 1)*/
    int taille=5, tailleConcat=10;
    int liste[taille];
    liste[0]=0;
    liste[1]=1;
    liste[2]=2;
    liste[3]=3;
    liste[4]=4;
    liste[5]=5;
    int concat[10]={1,2,4,5,6,0,0,0,0,0};
    int copieListe[taille];
    /*init (exercice 2)*/
    struct rat n1,n2,n3,ndefault,resultat;
    n1.den=2;
    n1.num=3;
    n2.den=2;
    n2.num=5;
    n3.den=2;
    n3.num=1;
	ndefault.den=0;
	ndefault.num=0;
    struct rat listetest[]={{1,2},{2,4},{0,0}};
    struct rat liste1[]={n1,n2,ndefault};
 	struct rat liste2[]={n1,n3,ndefault};
 	struct rat liste3[]={n1,n2,n3,ndefault};

     
    /** EXERCICE 1 **/
    printf("Exercice 1 : \n");
    /*appel fonctions*/
    printf("Tableau : ");
    afficher(liste, taille);
    /*somme*/
    printf("Somme: ");
    printf("%i \n",somme (liste, taille));
    /*copie*/
    copie_dans(copieListe, liste, taille);
    printf("Copie : ");
    afficher(copieListe, taille);
    /*concatenation*/
    printf("Avant concatenation : ");
    afficher(concat, tailleConcat);
    ajoute_apres(concat, tailleConcat, liste, taille);
    printf("Apres concatenation : ");
    afficher(concat, tailleConcat);
    printf("\n");
    /** EXERCICE 2 **/
    printf("Exercice 2 : \n");
    printf("Les fractions utilisées :\n");
    printf("n1 : %d / %d\n",n1.num, n1.den);
    printf("n2 : %d / %d\n",n2.num, n2.den);
 	printf("n3 : %d / %d\n",n3.num, n3.den);
    printf("\n");
    resultat=produit(n1,n2);
    printf("Produit de n1 et n2 : %d / %d\n",resultat.num, resultat.den);
    printf("\n");
    resultat=sommeRat(n1,n2);
    printf("Somme de n1 et n2 : %d / %d\n",resultat.num, resultat.den);
    printf("\n");
	printf("On compare n1 et n2 :\n");
    resultat=plus_petit(liste1);
	printf("Le plus petit est %d / %d\n",resultat.num, resultat.den);
    printf("\n");
	printf("On compare n1 et n3 :\n");
    resultat=plus_petit(liste2);
	printf("Le plus petit est %d / %d\n",resultat.num, resultat.den);
    printf("\n");
	printf("On compare toutes les fractions :\n");
    resultat=plus_petit(liste3);
	printf("Le plus petit est %d / %d\n",resultat.num, resultat.den);
    printf("\n");
	printf("On compare les fractions de la liste {{1,2},{2,4},{0,0}} :\n");
    resultat=plus_petit(listetest);
	printf("Le plus petit est %d / %d\n",resultat.num, resultat.den);
     
    return 0;
	
}

