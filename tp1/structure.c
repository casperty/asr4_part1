#include<stdio.h>
#include "rat.h"
struct rat produit(struct rat n1, struct rat n2){
    struct rat produit;
    produit.den=n1.den*n2.den;
    produit.num=n1.num*n2.num;
    return produit;
 
}
struct rat sommeRat(struct rat n1, struct rat n2){
	struct rat somme;
	somme.num=n1.num*n2.den+n2.num*n1.den;
	somme.den=n1.den*n2.den;
	return somme;
}
struct rat plus_petit(struct rat list[]){
	int indice, min=0;
	double pPetit;
	double teste;
	for(indice=1;list[indice].den!=0;indice++){
		pPetit = (double)list[min].num/(double)list[min].den;
		teste = (double)list[indice].num/(double)list[indice].den;
		if(pPetit>teste){
			min=indice;
		}
	} 
	return list[min];
}

