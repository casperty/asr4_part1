#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "chaines.h"

char * miroir (const char *s){
	char *ch=NULL;
	char *test=(char*)malloc(strlen(s)*sizeof(char));
	int i=0, j= strlen(s)-1;
	if(test!=NULL){
		ch=test;
		for(i=0; i<strlen(s);i++){
			ch[i]=s[j];
			j--;
		}
	}
	return ch;
}
char * saisie(){
	char *foo, *tmp, *test;
	char c;
	int i=0, size=5;
	foo=NULL;
	test=(char*)malloc(5*sizeof(char));
	if(test!=NULL){
		foo=test;
		do{
			c = getchar();
			*(foo+i)= c;
			i++;
			if(i>=size){
				size = size+5;
				tmp = (char*)realloc(foo, size*sizeof(char));
				if(tmp!=NULL){
					foo=tmp;
				} else {
					return NULL;
				}
			}
		}while(c!='\n'&&c!=' ');
		foo = (char*)realloc(foo, size*sizeof(char));
		*(foo+i-1) = '\0'; 
		}
	return foo;

}
int main(int argc, char *argv[]){
	char dash = '-';
	char *error, *chaine, *arg;
	int i=0,s=0, m=0;
	error = "Mauvaise utilisation";
	arg = &dash;
	/*verifie s'il y a les arguments*/
	if(argc < 2){
		printf("%s\n", error);
		return -1;
	}
	/*verification des options*/
	for(i=1; i<argc; i++){	
		if(strncmp(argv[i], arg, 1)==0){
			/*N.B : strchr permets de reperer un caractere dans une chaine*/
			if(strchr(argv[i], 'm')){
				m=1;
			}
			if(strchr(argv[i], 's')){
				s=1;
			}
			/*si pas d'options choisies*/
			if(!strchr(argv[i], 'm') && !strchr(argv[i], 's')){
				printf("%s\n", error);
				return -1;
			}
		} else {
			chaine = argv[i];
		}
	}
	if( (m==1&&chaine==NULL&&s==0) || (s==1&&chaine!=NULL) ){
		printf("%s\n", error);
		return -1;
	}
	/*saisie*/
	if(s==1){
		chaine = saisie();
	}
	/*miroir*/
	if(m==1){
		chaine = miroir(chaine);
	}
	
	printf("%s\n", chaine);
	
	return 0;
}
