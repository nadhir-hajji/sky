#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "afficheragent.h"

enum
{
	ID,
	NOM,
	PRESTATION,
	EVALUATION,
	SERVIABILITE,
	PONCTUALITE,
	PRIX,
	PROPRETE,
	DATE_CREATION,
	COLUMNS
};

void afficher_evaluation(GtkTreeView *liste)
{ 

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char Id[10];
char Nom[20];
char Prestation[20];
char Evaluation[20];
char Serviabilite[20];
char Ponctualite[20];
char Prix[20];
char Proprete[20];
char Date_de_creation[100];

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
column=gtk_tree_view_column_new_with_attributes(" Prestation",renderer,"text",PRESTATION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Evaluation",renderer,"text",EVALUATION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Serviabilite",renderer,"text",SERVIABILITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Ponctualite",renderer,"text",PONCTUALITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Prix",renderer,"text",PRIX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Proprete",renderer,"text",PROPRETE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Date_de_creation",renderer,"text",DATE_CREATION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("/home/fahed/Projets/sky-travel/src/evaluation.txt","r");

if(f==NULL)
	{
return;
	}
else
{
f=fopen("/home/fahed/Projets/sky-travel/src/evaluation.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s \n",Id,Nom,Prestation,Evaluation,Serviabilite,Ponctualite,Prix,Proprete,Date_de_creation)!=EOF)
	{

	gtk_list_store_append(store, &iter);
	gtk_list_store_set(store, &iter, ID, Id, NOM, Nom, PRESTATION, Prestation, EVALUATION, Evaluation, SERVIABILITE, Serviabilite, PONCTUALITE, Ponctualite, PRIX, Prix, PROPRETE, Proprete, DATE_CREATION, Date_de_creation, -1);
	}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}


}


}
