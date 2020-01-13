#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "affichervoiture.h"

enum
{
	ID,
	MARQUE,
	MODELE,
	MATRICULE,
	PRIX,
	COLUMNS
};

void afficher_voiture(GtkTreeView *liste)
{ 

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char Id[10];
char Marque[50];
char Modele[50];
char Matricule[1900];
char Prix[50];

store=NULL;

FILE*f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Marque",renderer,"text",MARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Modele",renderer,"text",MODELE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Matricule",renderer,"text",MATRICULE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Prix",renderer,"text",PRIX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("/home/fahed/Projets/sky-travel/src/voiture.txt","r");

if(f==NULL)
	{
return;
	}
else
{
f=fopen("/home/fahed/Projets/sky-travel/src/voiture.txt","a+");
	while(fscanf(f,"%s %s %s %s %s \n",Id,Marque,Modele,Matricule,Prix)!=EOF)
	{
	gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter, ID, Id, MARQUE, Marque, MODELE, Modele, MATRICULE, Matricule, PRIX, Prix, -1);
	}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}


}


}
