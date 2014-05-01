#include <stdio.h>
#include "chaine.h"
#ifdef STRLEN_PTR
int mon_strlen(char *s){
int nb=0;
int i=0;
    while(s[i]!='\0'){/* ou while(*s++ != '\0')*/
        nb++;   
        i++;
    }
return nb;
}   
#else
int mon_strlen(char s[]){
int nb=0;
int i=0;
    while(s[i]!='\0'){
        nb++;   
        i++;
    }
return nb;
}
#endif

int mon_strcmp(char *s1, char *s2){
int i=0;
while(s1[i]!='\0' || s2[i]!='\0'){
    if(s1[i]<s2[i]){
        return -1;
    }else if(s1[i]>s2[i]){
        return 1;
    }
	i++;
}
	return 0;
}
int mon_strncmp(const char * s1, const char * s2, int n){
int i=0;
while(i<n){
    if(s1[i]<s2[i]){
        return -1;
    }else if(s1[i]>s2[i]){
        return 1;
    }
	i++;
}
	return 0;
}
char *mon_strcat(char *s1, const char *s2){
	int length_s1 = mon_strlen(s1);
    int length_s2 = mon_strlen((char*) s2);
    int i;
    for(i=0;i<=length_s2;i++)
        *(s1+i+length_s1)=*(s2+i);
    return s1 ;

}
char *mon_strchr(const char *s, int c) {
        int i = 0;

        /* Parcours de la chaine dans la limite de sa longueur */
        while (s[i] != '\0' ) {
                /* Si le caractère rencontré est égal à celui en paramètre */
                if (s[i] == (char) c) { /* /!\ Attention au cast /!\ */
                        return (char *)&s[i]; 
                        /* On renvoie le cast en pointeur de caractère : (char *)
                           l'adresse de la case où on a rencontré le caractère recherché : &s[i]
                           &s[i] équivaut à (s + i) -> Pointeur de la première case du tableau s + i-> (char *)(s + i)
                        */
                }
                i++;
        }
        return NULL;
}

char *mon_strstr(const char *haystack, const char *needle) {
        int i;

        /* On parcours toute la chaine haystack */
        for (i = 0; i < mon_strlen((char *)haystack); i++) {
                /* À chaque i, on compare la chaine haystack[i] à la chaine needle
                sur toute la longueur de la chaine needle */
                if ( mon_strncmp(((char *) haystack + i), needle, mon_strlen((char *) needle)) == 0 ) {
                        return ((char *)haystack + i);
                        /* On retourne la chaine à partir de l'indice i */
                }
        }
        return NULL;
}


