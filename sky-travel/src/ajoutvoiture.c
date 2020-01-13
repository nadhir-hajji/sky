#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "ajoutvoiture.h"

void ajouter_voiture(voiture v)
{

char id[30];
char marque[50];
char modele[50];
char matricule[1900];
char prix[50];

int rang;

FILE*f;

FILE *f1;
f1=fopen("/home/fahed/Projets/sky-travel/src/voiture.txt","r");

if(f1 !=NULL){
while(fscanf(f1,"%s %s %s %s %s \n",id,marque,modele,matricule,prix)!=EOF)
{
	rang=atoi(id)+1;

}fclose(f1);

}


sprintf(v.id,"%u", rang);
////////////

f=fopen("/home/fahed/Projets/sky-travel/src/voiture.txt","a+");

	if(f!=NULL)
		{
fprintf(f,"%s %s %s %s %s \n",v.id,v.marque,v.modele,v.matricule,v.prix);
		
		fclose(f);
		}




}
