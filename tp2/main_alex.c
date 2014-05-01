#include <stdio.h>
#include "chaine.h"
int main(int argc, char *argv[]) {
  char apres[]="apres";
    char voila[]="voila";
    char bonjour[]="bonjour";
    char monTableau[]="test";
    char monTableau2[]="teste";
    char *pointeur = &monTableau[0];
    char *pointeur2=monTableau2;
    char *pointeur3;
    char s1[] = "Le chocolat, c'est délicieux", s2[] = "c'est";
    int longueur;
    int comparateur;
    printf("Exerice 1\n");
    longueur=mon_strlen(bonjour);
    printf("Longueur de \'bonjour\' : %i\n",longueur);
    longueur=mon_strlen(apres);
    printf("Longueur de \'apres\' : %i\n",longueur);
    longueur=mon_strlen(voila);
    printf("Longueur de \'voila\' : %i\n",longueur);
    printf("Exerice 2\n");
    longueur=mon_strlen(pointeur);
    printf("Longueur de \'test\' (pointeur) : %i\n",longueur);
    printf("Exerice 3\n");
    comparateur=mon_strcmp(pointeur,pointeur2);
    printf("Comparaison entre \'test\' et \'teste\': %i\n",comparateur);
    comparateur=mon_strncmp(pointeur,pointeur2,5);
    printf("Comparaison : %i\n",comparateur);
    pointeur3=mon_strcat(pointeur, pointeur2);
    printf("Concatenation : %s\n",pointeur3);
    printf("Exercice 6 : %s \n",mon_strchr(pointeur2, 'e')); /*retourne este*/
    printf("Exercice 6 : %s \n",mon_strchr(pointeur2, 'f')); /* retourne null*/
    /*retourne "teste", retourne null si mon_strstr(monTableau, monTableau2)*/
    printf("Exercice 7 : %s \n",mon_strstr(monTableau, monTableau2)); 
    printf("Exercice 7 : %s \n",mon_strstr(monTableau2, monTableau));
    printf("Exercice 7 : %s \n",mon_strstr(s1, s2)); 
     
    return 0;
}
