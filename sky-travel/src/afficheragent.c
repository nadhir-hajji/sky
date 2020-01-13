#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "afficheragent.h"

enum
{
	ID,
	NOM,
	PRENOM,
	ADRESSE,
	DATE_NAISSANCE,
	CIN,
	TELEPHONE,
	LOGIN,
	MOT_DE_PASSE,
	DATE_CREATION,
	COLUMNS
};

void afficher_agent(GtkTreeView *liste)
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
column=gtk_tree_view_column_new_with_attributes(" Id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Adresse",renderer,"text",ADRESSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Date_de_naissance",renderer,"text",DATE_NAISSANCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" N_Tel",renderer,"text",TELEPHONE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Login",renderer,"text",LOGIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Mot_de_passe",renderer,"text",MOT_DE_PASSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Date_de_creation",renderer,"text",DATE_CREATION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("/home/fahed/Projets/sky-travel/src/agent.txt","r");

if(f==NULL)
	{
return;
	}
else
{
f=fopen("/home/fahed/Projets/sky-travel/src/agent.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",Id,Nom,Prenom,Adresse,Date_de_naissance,Cin,N_Tel,Login,Mot_de_passe,Date_de_creation)!=EOF)
	{
	gtk_list_store_append(store, &iter);
	gtk_list_store_set(store, &iter, ID, Id, NOM, Nom, PRENOM, Prenom, ADRESSE, Adresse, DATE_NAISSANCE, Date_de_naissance, CIN, Cin, TELEPHONE, N_Tel, LOGIN, Login, MOT_DE_PASSE, Mot_de_passe, DATE_CREATION, Date_de_creation, -1);
	}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}


}


}
