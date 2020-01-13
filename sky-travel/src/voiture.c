#include <gtk/gtk.h>
#include "voiture.h"
#include <string.h>
void verifiercodev(char p[])
{

char a1[20];
char b1[200];
char c1[20];
char d1[20];
FILE *f;
FILE *t;
f=fopen("voitures.txt","r");
t=fopen("tem.txt","a+");
if(f !=NULL) {

while (fscanf(f,"%s %s %s %s \n",a1,b1,c1,d1)!=EOF)
{if ((strcmp(p,a1)==0))

{fprintf(t,"%s %s %s %s \n",a1,b1,c1,d1);}

}
}
fclose(f);
fclose(t);

}
enum 
{
DATE,
MARQUE,
KILOMETRAGE,
PRIX,
COLUMNS
};
void showtreev( GtkWidget *liste){

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;

GtkListStore *store;
char date[30];
char marque[30];
char kilometrage[30];
char prix[30];

store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date", renderer, "text",DATE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("marque", renderer, "text",MARQUE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("kilometrage", renderer, "text",KILOMETRAGE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prix", renderer, "text",PRIX, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f = fopen("tem.txt","r");

if(f==NULL) return;
else 
	{
f = fopen("tem.txt", "a+");
	while(fscanf(f,"%s %s %s %s \n",date,marque,kilometrage,prix)!=EOF)
				{
gtk_list_store_append(store, &iter);
gtk_list_store_set (store,&iter, DATE, date,MARQUE ,marque ,KILOMETRAGE,kilometrage,PRIX,prix,  -1);  }
		fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}	
}
}



