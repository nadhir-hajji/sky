#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "ajoutagent.h"


void clo(wa *ajout)
 {

    const char * months[] = {
        "Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet",
        "Août", "Septembre", "Octobre", "Novembre", "Décembre"
    };
    const char * days[] = {
        "Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"
    };

    time_t timestamp = time( NULL );
    struct tm * now = localtime( & timestamp );

    strcpy(ajout->jour ,days[now->tm_wday]);
    ajout->num_jour=now->tm_mday;
    strcpy(ajout->mois ,months[now->tm_mon]);
    ajout->annee=now->tm_year+1900;

   
}
void ajouter_agent(agent p)
{ 
char id[10];
char nom[20];
char prenom[20];
char adresse[50];
char date_naissance[2000];
char cin[100];
char tel[100];
char log[50];
char pass[50];
char datecreation[1000];

int rang=1;

FILE*f;
			wa ajout;
			clo(&ajout);
	char dateajout[50];
        char nombre_jour [30];
        sprintf(nombre_jour,"%u", ajout.num_jour);
	char nombre_annee [30];
        sprintf(nombre_annee,"%u", ajout.annee);
	strcat(p.datecreation,ajout.jour);
	strcat(p.datecreation,"_");
	strcat(p.datecreation,nombre_jour);
	strcat(p.datecreation,"_");
	strcat(p.datecreation,ajout.mois);
	strcat(p.datecreation,"_");
	strcat(p.datecreation,nombre_annee);

///////////////
FILE *f1;
f1=fopen("/home/fahed/Projets/sky-travel/src/agent.txt","r");

if(f1 !=NULL){
while(fscanf(f1,"%s %s %s %s %s %s %s %s %s %s \n",id,nom,prenom,adresse,date_naissance,cin,tel,log,pass,datecreation)!=EOF)
{
	rang=atoi(id)+1;

}fclose(f1);

}


sprintf(p.id,"%u", rang);
////////////

f=fopen("/home/fahed/Projets/sky-travel/src/agent.txt","a+");

	if(f!=NULL)
		{
fprintf(f,"%s %s %s %s %s %s %s %s %s %s \n",p.id,p.nom,p.prenom,p.adresse,p.date_naissance,p.cin,p.tel,p.log,p.pass,p.datecreation);
		
		fclose(f);
		}
}

void ajouter_voiture(voiture v)
{

char id[30];
char marque[50];
char modele[50];
char matricule[50];
char prix[50];

int rang=1;

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


void ajouter_evaluation(evaluation e)
{ 
char id[30];
char nom[50];
char prestation[50];
char evaluation[50];
char serviabilite[50];
char ponctualite[50];
char prix[50];
char proprete[50];
char datecreation[1000];

int rang=1;

FILE*f;
			wa ajout;
			clo(&ajout);
	char dateajout[50];
        char nombre_jour [30];
        sprintf(nombre_jour,"%u", ajout.num_jour);
	char nombre_annee [30];
        sprintf(nombre_annee,"%u", ajout.annee);
	strcat(e.datecreation,ajout.jour);
	strcat(e.datecreation,"_");
	strcat(e.datecreation,nombre_jour);
	strcat(e.datecreation,"_");
	strcat(e.datecreation,ajout.mois);
	strcat(e.datecreation,"_");
	strcat(e.datecreation,nombre_annee);

///////////////
FILE *f1;
f1=fopen("/home/fahed/Projets/sky-travel/src/evaluation.txt","r");

if(f1 !=NULL){
while(fscanf(f1,"%s %s %s %s %s %s %s %s %s \n",id,nom,prestation,evaluation,serviabilite,ponctualite,prix,proprete,datecreation)!=EOF)
{
	rang=atoi(id)+1;

}fclose(f1);

}


sprintf(e.id,"%u", rang);
////////////

f=fopen("/home/fahed/Projets/sky-travel/src/evaluation.txt","a+");

	if(f!=NULL)
		{
fprintf(f,"%s %s %s %s %s %s %s %s %s \n",e.id,e.nom,e.prestation,e.evaluation,e.serviabilite,e.ponctualite,e.prix,e.proprete,e.datecreation);
		
		fclose(f);
		}
}


void ajouter_client(client c)
{ 
char id[10];
char nom[20];
char prenom[20];
char adresse[50];
char date_naissance[100];
char cin[100];
char tel[100];
char log[50];
char pass[50];
char datecreation[100];

int rang;

FILE*f;
			wa ajout;
			clo(&ajout);
	char dateajout[50];
        char nombre_jour [30];
        sprintf(nombre_jour,"%u", ajout.num_jour);
	char nombre_annee [30];
        sprintf(nombre_annee,"%u", ajout.annee);
	strcat(c.datecreation,ajout.jour);
	strcat(c.datecreation,"_");
	strcat(c.datecreation,nombre_jour);
	strcat(c.datecreation,"_");
	strcat(c.datecreation,ajout.mois);
	strcat(c.datecreation,"_");
	strcat(c.datecreation,nombre_annee);

///////////////
FILE *f1;
f1=fopen("/home/fahed/Projets/sky-travel/src/client.txt","r");

if(f1 !=NULL){
while(fscanf(f1,"%s %s %s %s %s %s %s %s %s %s \n",id,nom,prenom,adresse,date_naissance,cin,tel,log,pass,datecreation)!=EOF)
{
	rang=atoi(id)+1;

}fclose(f1);

}


sprintf(c.id,"%u", rang);
////////////

f=fopen("/home/fahed/Projets/sky-travel/src/client.txt","a+");

	if(f!=NULL)
		{
fprintf(f,"%s %s %s %s %s %s %s %s %s %s \n",c.id,c.nom,c.prenom,c.adresse,c.date_naissance,c.cin,c.tel,c.log,c.pass,c.datecreation);
		
		fclose(f);
		}
}


void supprimerclient(client a)
{
client l;
int rang=0;
FILE*f;
FILE*f1;
f=fopen("/home/fahed/Projets/sky-travel/src/client.txt","r");
f1=fopen("/home/fahed/Projets/sky-travel/src/tempo1.txt","a+");
if(f !=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",l.id,l.nom,l.prenom,l.adresse,l.date_naissance,l.cin,l.tel,l.log,l.pass,l.datecreation)!=EOF)
{
	if(strcmp(a.log,l.log)!=0)
		{
rang=rang+1;
sprintf(l.id,"%u", rang);
		fprintf(f1,"%s %s %s %s %s %s %s %s %s %s \n",l.id,l.nom,l.prenom,l.adresse,l.date_naissance,l.cin,l.tel,l.log,l.pass,l.datecreation);
	        }

}fclose(f);
fclose(f1);
}
remove("/home/fahed/Projets/sky-travel/src/client.txt");
rename("/home/fahed/Projets/sky-travel/src/tempo1.txt","/home/fahed/Projets/sky-travel/src/client.txt");
}

void modifierclient(client a)
{
client l;

FILE*f;
FILE*f1;
f=fopen("/home/fahed/Projets/sky-travel/src/client.txt","r");
f1=fopen("/home/fahed/Projets/sky-travel/src/tempo1.txt","a+");
if(f !=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",l.id,l.nom,l.prenom,l.adresse,l.date_naissance,l.cin,l.tel,l.log,l.pass,l.datecreation)!=EOF)
{
	if(strcmp(a.id,l.id)==0)
		{
		fprintf(f1,"%s %s %s %s %s %s %s %s %s %s \n",a.id,a.nom,a.prenom,a.adresse,a.date_naissance,a.cin,a.tel,a.log,a.pass,a.datecreation);
	        }

	if(strcmp(a.id,l.id)!=0)
		{
		fprintf(f1,"%s %s %s %s %s %s %s %s %s %s \n",l.id,l.nom,l.prenom,l.adresse,l.date_naissance,l.cin,l.tel,l.log,l.pass,l.datecreation);
	        }

}fclose(f);
fclose(f1);
}
remove("/home/fahed/Projets/sky-travel/src/client.txt");
rename("/home/fahed/Projets/sky-travel/src/tempo1.txt","/home/fahed/Projets/sky-travel/src/client.txt");
}


void ajouter_vol(vol v)
{

char id[30];
char depart[50];
char destination[50];
char date_depart[50];
char prix[50];

int rang=1;

FILE*f;

FILE *f1;
f1=fopen("/home/fahed/Projets/sky-travel/src/vol.txt","r");

if(f1 !=NULL){
while(fscanf(f1,"%s %s %s %s %s \n",id,depart,destination,date_depart,prix)!=EOF)
{
	rang=atoi(id)+1;

}fclose(f1);

}


sprintf(v.id,"%u", rang);
////////////

f=fopen("/home/fahed/Projets/sky-travel/src/vol.txt","a+");

	if(f!=NULL)
		{
fprintf(f,"%s %s %s %s %s \n",v.id,v.depart,v.destination,v.date_depart,v.prix);
		
		fclose(f);
		}


}

