#include <gtk/gtk.h>
#include "vols.h"
#include <string.h>

enum 
{
DATE_DEPART,
DESTINATION,
COLUMNS
};
void showtreevols( GtkWidget *liste){

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;

GtkListStore *store;
char date_depart[30];
char destination[30];

store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date_depart", renderer, "text",DATE_DEPART, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("destination", renderer, "text",DESTINATION, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING);
f = fopen("vols.txt","r");

if(f==NULL) return;
else 
	{
f = fopen("vols.txt", "a+");
	while(fscanf(f,"%s %s \n",destination,date_depart)!=EOF)
				{
gtk_list_store_append(store, &iter);
gtk_list_store_set (store,&iter, DESTINATION, destination,DATE_DEPART ,date_depart , -1);  }
		fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}	
}
}

void ajoutercodevo(char p[100])
{

char a1[20];
char b1[200];
FILE *f;
FILE *t;
f=fopen("vols.txt","r");
t=fopen("vols_reserver.txt","a+");
if(f !=NULL) {

while (fscanf(f,"%s %s  \n",a1,b1)!=EOF)
{if ((strcmp(p,a1)==0))

{fprintf(t,"%s %s  \n",a1,b1);}

}
}
fclose(f);
fclose(t);

}
void supprimecodevo(char p[100])
{



char a1[20];
char b1[200];
FILE *f;
FILE *t;
f=fopen("vols.txt","r");
t=fopen("temp.txt","a+");
if(f !=NULL) {

while (fscanf(f,"%s %s  \n",a1,b1)!=EOF)
{if ((strcmp(p,a1)!=0))

{fprintf(t,"%s %s  \n",a1,b1);}

}
}
fclose(f);
fclose(t);
remove("vols.txt");
rename("temp.txt","vols.txt");


}


