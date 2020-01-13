#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "vol.h"

enum
{
	ID,
	DEPART,
	DESTINATION,
	DATEDEPART,
	PRIX,
	COLUMNS
};

void afficher_vol(GtkTreeView *liste)
{ 

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char Id[10];
char Depart[50];
char Destination[50];
char Date_depart[100];
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
column=gtk_tree_view_column_new_with_attributes(" Depart",renderer,"text",DEPART,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Destination",renderer,"text",DESTINATION,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Date_depart",renderer,"text",DATEDEPART,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Prix",renderer,"text",PRIX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("/home/fahed/Projets/sky-travel/src/vol.txt","r");

if(f==NULL)
	{
return;
	}
else
{
f=fopen("/home/fahed/Projets/sky-travel/src/vol.txt","a+");
	while(fscanf(f,"%s %s %s %s %s \n",Id,Depart,Destination,Date_depart,Prix)!=EOF)
	{
	gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter, ID, Id, DEPART, Depart, DESTINATION, Destination, DATEDEPART, Date_depart, PRIX, Prix, -1);
	}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}


}


}
