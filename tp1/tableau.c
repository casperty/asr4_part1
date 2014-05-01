#include<stdio.h>
/*affichage du tableau*/
void afficher(int liste[], int taille){
	int i;
	for (i=0; i<taille;i++){
		printf("%d  ",liste[i]);
	}
	printf("\n");
	
}
/*somme des cases du tableau*/
int somme (int liste[], int taille){
	int i=0, somme=0;
	for(i;i<=taille;i++){
		somme=somme+liste[i];
	}
	return somme;
}

int *copie_dans(int dest[], int src[], int taille){
	int i=0;
	for(i;i<=taille;i++){
		dest[i]=src[i];
	}
	return dest;
	
}
int *ajoute_apres(int dest[], int taille_dest, int src[], int taille_src){
	int i=0;
	for(i;i<=taille_dest;i++){
		dest[i+taille_src]=src[i];
	}
	return dest;
}
