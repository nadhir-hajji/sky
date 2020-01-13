#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

#include "fonction.h"


enum
{
	INDICE,
	NOMCLIENT,
	PRENOMCLIENT,
	ADRESSECLIENT,
	DATE_NAISSANCECLIENT,
	CINCLIENT,
	TELEPHONECLIENT,
	LOGINCLIENT,
	MOT_DE_PASSECLIENT,
	DATE_CREATIONCLIENT,
	COLUMNS
};

int verifier (char log1[20],char pass1[20])
{


char id[10];
char nom[20];
char prenom[20];
char adresse[50];
char date_naissance[1000];
char cin[100];
char tel[100];
char log[50];
char pass[50];
char datecreation[1000];


int x=0;
int ver=3;



FILE *f;
f=fopen("/home/fahed/Projets/sky-travel/src/admin.txt","r");

if(f !=NULL){
while(x==0 && fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",id,nom,prenom,adresse,date_naissance,cin,tel,log,pass,datecreation)!=EOF)
{
	if(strcmp(log1,log)==0 && strcmp(pass1,pass)==0)
		{
		ver=0;
		x==1;
	        }

}fclose(f);

}

FILE *f1;
f1=fopen("/home/fahed/Projets/sky-travel/src/agent.txt","r");

if(f1 !=NULL){
while(x==0 && fscanf(f1,"%s %s %s %s %s %s %s %s %s %s \n",id,nom,prenom,adresse,date_naissance,cin,tel,log,pass,datecreation)!=EOF)
{
	if(strcmp(log1,log)==0 && strcmp(pass1,pass)==0)
		{
		ver=1;
		x==1;
	        }

}fclose(f1);

}

FILE *f2;
f2=fopen("/home/fahed/Projets/sky-travel/src/client.txt","r");

if(f2 !=NULL){
while(x==0 && fscanf(f2,"%s %s %s %s %s %s %s %s %s %s \n",id,nom,prenom,adresse,date_naissance,cin,tel,log,pass,datecreation)!=EOF)
{
	if(strcmp(log1,log)==0 && strcmp(pass1,pass)==0)
		{
		ver=2;
		x==1;
	        }

}fclose(f2);

}

return ver;

}


int liste_agent (char ref[][50])
{
char a[10];
char b[20];
char c[20];
char d[50];
char e[2000];
char f[100];
char j[100];
char h[50];
char g[50];
char k[1000];

int nb=0;

FILE*f4;

f4=fopen("/home/fahed/Projets/sky-travel/src/agent.txt","r");

if(f4 !=NULL){
while(fscanf(f4,"%s %s %s %s %s %s %s %s %s %s \n",a,b,c,d,e,f,j,h,g,k)!=EOF)
{
	strcpy(ref[nb],a);
	nb++;

}fclose(f4);

}
return nb;
}



void supprimeragent(agent a)
{
agent l;
int rang=0;
FILE*f5;
FILE*f6;
f5=fopen("/home/fahed/Projets/sky-travel/src/agent.txt","r");
f6=fopen("/home/fahed/Projets/sky-travel/src/tempo.txt","a+");
if(f5 !=NULL){
while(fscanf(f5,"%s %s %s %s %s %s %s %s %s %s \n",l.id,l.nom,l.prenom,l.adresse,l.date_naissance,l.cin,l.tel,l.log,l.pass,l.datecreation)!=EOF)
{
	if(strcmp(a.log,l.log)!=0)
		{
rang=rang+1;
sprintf(l.id,"%u", rang);
		fprintf(f6,"%s %s %s %s %s %s %s %s %s %s \n",l.id,l.nom,l.prenom,l.adresse,l.date_naissance,l.cin,l.tel,l.log,l.pass,l.datecreation);
	        }

}fclose(f5);
fclose(f6);
}
remove("/home/fahed/Projets/sky-travel/src/agent.txt");
rename("/home/fahed/Projets/sky-travel/src/tempo.txt","/home/fahed/Projets/sky-travel/src/agent.txt");
}

void modifieragent(agent a)
{
agent l;

FILE*f7;
FILE*f8;
f7=fopen("/home/fahed/Projets/sky-travel/src/agent.txt","r");
f8=fopen("/home/fahed/Projets/sky-travel/src/tempo.txt","a+");
if(f7 !=NULL){
while(fscanf(f7,"%s %s %s %s %s %s %s %s %s %s \n",l.id,l.nom,l.prenom,l.adresse,l.date_naissance,l.cin,l.tel,l.log,l.pass,l.datecreation)!=EOF)
{
	if(strcmp(a.id,l.id)==0)
		{
		fprintf(f8,"%s %s %s %s %s %s %s %s %s %s \n",a.id,a.nom,a.prenom,a.adresse,a.date_naissance,a.cin,a.tel,a.log,a.pass,a.datecreation);
	        }

	if(strcmp(a.id,l.id)!=0)
		{
		fprintf(f8,"%s %s %s %s %s %s %s %s %s %s \n",l.id,l.nom,l.prenom,l.adresse,l.date_naissance,l.cin,l.tel,l.log,l.pass,l.datecreation);
	        }

}fclose(f7);
fclose(f8);
}
remove("/home/fahed/Projets/sky-travel/src/agent.txt");
rename("/home/fahed/Projets/sky-travel/src/tempo.txt","/home/fahed/Projets/sky-travel/src/agent.txt");
}

int liste_voiture (char ref[][50])
{
char a[10];
char b[20];
char c[20];
char d[50];
char e[100];


int nb=0;

FILE*f;

f=fopen("/home/fahed/Projets/sky-travel/src/voiture.txt","r");

if(f !=NULL){
while(fscanf(f,"%s %s %s %s %s \n",a,b,c,d,e)!=EOF)
{
	strcpy(ref[nb],a);
	nb++;

}fclose(f);

}
return nb;
}


void supprimervoiture(voiture a)
{
voiture l;
int rang=0;
FILE*f;
FILE*f1;
f=fopen("/home/fahed/Projets/sky-travel/src/voiture.txt","r");
f1=fopen("/home/fahed/Projets/sky-travel/src/tempo.txt","a+");
if(f !=NULL){
while(fscanf(f,"%s %s %s %s %s \n",l.id,l.marque,l.modele,l.matricule,l.prix)!=EOF)
{

	if(strcmp(a.matricule,l.matricule)!=0)
		{
rang=rang+1;
sprintf(l.id,"%u", rang);
		fprintf(f1,"%s %s %s %s %s \n",l.id,l.marque,l.modele,l.matricule,l.prix);
	        }

}fclose(f);
fclose(f1);
}
remove("/home/fahed/Projets/sky-travel/src/voiture.txt");
rename("/home/fahed/Projets/sky-travel/src/tempo.txt","/home/fahed/Projets/sky-travel/src/voiture.txt");
}


void modifiervoiture(voiture a)
{
voiture l;

FILE*f;
FILE*f1;
f=fopen("/home/fahed/Projets/sky-travel/src/voiture.txt","r");
f1=fopen("/home/fahed/Projets/sky-travel/src/tempo.txt","a+");
if(f !=NULL){
while(fscanf(f,"%s %s %s %s %s \n",l.id,l.marque,l.modele,l.matricule,l.prix)!=EOF)
{
	if(strcmp(a.id,l.id)==0)
		{
		fprintf(f1,"%s %s %s %s %s \n",a.id,a.marque,a.modele,a.matricule,a.prix);
	        }

	if(strcmp(a.id,l.id)!=0)
		{
		fprintf(f1,"%s %s %s %s %s \n",l.id,l.marque,l.modele,l.matricule,l.prix);
	        }

}fclose(f);
fclose(f1);
}
remove("/home/fahed/Projets/sky-travel/src/voiture.txt");
rename("/home/fahed/Projets/sky-travel/src/tempo.txt","/home/fahed/Projets/sky-travel/src/voiture.txt");
}

int liste_evaluation (char ref[][50])
{
char a[50];
char b[50];
char c[50];
char d[50];
char e[100];
char f[50];
char g[50];
char h[50];
char i[50];

int nb=0;

FILE*f1;

f1=fopen("/home/fahed/Projets/sky-travel/src/evaluation.txt","r");

if(f !=NULL){
while(fscanf(f1,"%s %s %s %s %s %s %s %s %s \n",a,b,c,d,e,f,g,h,i)!=EOF)
{
 
	strcpy(ref[nb],a);
	nb++;
 
}fclose(f1);

}
return nb;
}


void supprimerevaluation(evaluation a)
{

evaluation l;
int rang=0;
FILE*f5;
FILE*f6;
f5=fopen("/home/fahed/Projets/sky-travel/src/evaluation.txt","r");
f6=fopen("/home/fahed/Projets/sky-travel/src/tempo.txt","a+");
if(f5 !=NULL){
while(fscanf(f5,"%s %s %s %s %s %s %s %s %s \n",l.id,l.nom,l.prestation,l.evaluation,l.serviabilite,l.ponctualite,l.prix,l.proprete,l.datecreation)!=EOF)
{
	if(strcmp(a.id,l.id)!=0)
		{
rang=rang+1;
sprintf(l.id,"%u", rang);
		fprintf(f6,"%s %s %s %s %s %s %s %s %s \n",l.id,l.nom,l.prestation,l.evaluation,l.serviabilite,l.ponctualite,l.prix,l.proprete,l.datecreation);
	        }

}fclose(f5);
fclose(f6);
}
remove("/home/fahed/Projets/sky-travel/src/evaluation.txt");
rename("/home/fahed/Projets/sky-travel/src/tempo.txt","/home/fahed/Projets/sky-travel/src/evaluation.txt");


}





void modifierevaluation(evaluation e)

{
evaluation l;

FILE*f7;
FILE*f8;
f7=fopen("/home/fahed/Projets/sky-travel/src/evaluation.txt","r");
f8=fopen("/home/fahed/Projets/sky-travel/src/tempo.txt","a+");
if(f7 !=NULL){
while(fscanf(f7,"%s %s %s %s %s %s %s %s %s \n",l.id,l.nom,l.prestation,l.evaluation,l.serviabilite,l.ponctualite,l.prix,l.proprete,l.datecreation)!=EOF)
{
	if(strcmp(e.id,l.id)==0)
		{
		fprintf(f8,"%s %s %s %s %s %s %s %s %s \n",e.id,e.nom,e.prestation,e.evaluation,e.serviabilite,e.ponctualite,e.prix,e.proprete,e.datecreation);
	        }

	if(strcmp(e.id,l.id)!=0)
		{
		fprintf(f8,"%s %s %s %s %s %s %s %s %s \n",l.id,l.nom,l.prestation,l.evaluation,l.serviabilite,l.ponctualite,l.prix,l.proprete,l.datecreation);
	        }

}fclose(f7);
fclose(f8);
}
remove("/home/fahed/Projets/sky-travel/src/evaluation.txt");
rename("/home/fahed/Projets/sky-travel/src/tempo.txt","/home/fahed/Projets/sky-travel/src/evaluation.txt");


}


void afficher_client(GtkTreeView *liste)
{ 

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char Id[10];
char Nom[20];
char Prenom[20];
char Adresse[50];
char Date_de_naissance[2000];
char Cin[100];
char N_Tel[100];
char Login[50];
char Mot_de_passe[50];
char Date_de_creation[1000];

store=NULL;

FILE*f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Idi",renderer,"text",INDICE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",NOMCLIENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",PRENOMCLIENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Adresse",renderer,"text",ADRESSECLIENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Date_de_naissance",renderer,"text",DATE_NAISSANCECLIENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Cin",renderer,"text",CINCLIENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" N_Tel",renderer,"text",TELEPHONECLIENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Login",renderer,"text",LOGINCLIENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Mot_de_passe",renderer,"text",MOT_DE_PASSECLIENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Date_de_creation",renderer,"text",DATE_CREATIONCLIENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("/home/fahed/Projets/sky-travel/src/client.txt","r");

if(f==NULL)
	{
return;
	}
else
{
f=fopen("/home/fahed/Projets/sky-travel/src/client.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",Id,Nom,Prenom,Adresse,Date_de_naissance,Cin,N_Tel,Login,Mot_de_passe,Date_de_creation)!=EOF)
	{
	gtk_list_store_append(store, &iter);
	gtk_list_store_set(store, &iter, INDICE, Id, NOMCLIENT, Nom, PRENOMCLIENT, Prenom, ADRESSECLIENT, Adresse, DATE_NAISSANCECLIENT, Date_de_naissance, CINCLIENT, Cin, TELEPHONECLIENT, N_Tel, LOGINCLIENT, Login, MOT_DE_PASSECLIENT, Mot_de_passe, DATE_CREATIONCLIENT, Date_de_creation, -1);
	}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}


}


}







int liste_client (char ref[][50])
{
char a[10];
char b[20];
char c[20];
char d[50];
char e[2000];
char f[100];
char j[100];
char h[50];
char g[50];
char k[1000];

int nb=0;

FILE*f4;

f4=fopen("/home/fahed/Projets/sky-travel/src/client.txt","r");

if(f4 !=NULL){
while(fscanf(f4,"%s %s %s %s %s %s %s %s %s %s \n",a,b,c,d,e,f,j,h,g,k)!=EOF)
{
	strcpy(ref[nb],a);
	nb++;

}fclose(f4);

}
return nb;
}

int liste_vol (char ref[][50])
{
char a[10];
char b[20];
char c[20];
char d[100];
char e[100];


int nb=0;

FILE*f;

f=fopen("/home/fahed/Projets/sky-travel/src/vol.txt","r");

if(f !=NULL){
while(fscanf(f,"%s %s %s %s %s \n",a,b,c,d,e)!=EOF)
{
	strcpy(ref[nb],a);
	nb++;

}fclose(f);

}
return nb;
}


void supprimervol(vol a)
{
vol l;
int rang=0;
FILE*f;
FILE*f1;
f=fopen("/home/fahed/Projets/sky-travel/src/vol.txt","r");
f1=fopen("/home/fahed/Projets/sky-travel/src/tempo.txt","a+");
if(f !=NULL){
while(fscanf(f,"%s %s %s %s %s \n",l.id,l.depart,l.destination,l.date_depart,l.prix)!=EOF)
{

	if(strcmp(a.id,l.id)!=0)
		{
rang=rang+1;
sprintf(l.id,"%u", rang);
		fprintf(f1,"%s %s %s %s %s \n",l.id,l.depart,l.destination,l.date_depart,l.prix);
	        }

}fclose(f);
fclose(f1);
}
remove("/home/fahed/Projets/sky-travel/src/vol.txt");
rename("/home/fahed/Projets/sky-travel/src/tempo.txt","/home/fahed/Projets/sky-travel/src/vol.txt");
}

void modifiervol(vol a)
{
vol l;

FILE*f;
FILE*f1;
f=fopen("/home/fahed/Projets/sky-travel/src/vol.txt","r");
f1=fopen("/home/fahed/Projets/sky-travel/src/tempo.txt","a+");
if(f !=NULL){
while(fscanf(f,"%s %s %s %s %s \n",l.id,l.depart,l.destination,l.date_depart,l.prix)!=EOF)
{
	if(strcmp(a.id,l.id)==0)
		{
		fprintf(f1,"%s %s %s %s %s \n",a.id,a.depart,a.destination,a.date_depart,a.prix);
	        }

	if(strcmp(a.id,l.id)!=0)
		{
		fprintf(f1,"%s %s %s %s %s \n",l.id,l.depart,l.destination,l.date_depart,l.prix);
	        }

}fclose(f);
fclose(f1);
}
remove("/home/fahed/Projets/sky-travel/src/vol.txt");
rename("/home/fahed/Projets/sky-travel/src/tempo.txt","/home/fahed/Projets/sky-travel/src/vol.txt");
}


