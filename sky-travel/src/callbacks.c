#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>


#include "ajoutagent.h"
#include "afficheragent.h"
#include "vol.h"
#include "fonction.h"

#include "code.h"
#include "vols.h"
#include "voiture.h"

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void on_button_visiteur_simple_clicked (GtkWidget *buttonvisiteur, gpointer user_data)
{

GtkWidget *accueil;
GtkWidget *visiteur;
GtkWidget *treeview_voiturevisiteur;
GtkWidget *treeview_volvisiteur;

accueil=lookup_widget(buttonvisiteur,"accueil");
gtk_widget_destroy(accueil);
visiteur=create_visiteur();
gtk_widget_show(visiteur);

treeview_voiturevisiteur=lookup_widget(visiteur,"treeview_voiturevisiteur");
afficher_voiture(treeview_voiturevisiteur);

treeview_volvisiteur=lookup_widget(visiteur,"treeview_volvisiteur");
afficher_vol(treeview_volvisiteur);



}

void on_button_connecter_clicked (GtkWidget *buttonconnecter, gpointer user_data)
{

GtkWidget *accueil;
GtkWidget *authentification;

accueil=lookup_widget(buttonconnecter,"accueil");
gtk_widget_destroy(accueil);
authentification=create_authentification();
gtk_widget_show(authentification);


}


void on_button_inscription_clicked (GtkWidget *buttoninscription, gpointer user_data)
{

GtkWidget *accueil;
GtkWidget *inscription;

accueil=lookup_widget(buttoninscription,"accueil");
gtk_widget_destroy(accueil);
inscription=create_inscription();
gtk_widget_show(inscription);

}



void on_button_connecter_aac_clicked (GtkWidget *buttonconnecteraac, gpointer user_data)
{

GtkWidget *authentification;
GtkWidget *admin;
GtkWidget *agent;
GtkWidget *client;
GtkWidget *label_client;

GtkWidget *inputlogin;
GtkWidget *inputmotdepasse;
GtkWidget *outputerror;

char log1[50];
char pass1[50];

evaluation e;

authentification=lookup_widget(buttonconnecteraac,"authentification");

inputlogin=lookup_widget(buttonconnecteraac,"entry_login");
inputmotdepasse=lookup_widget(buttonconnecteraac,"entry_mot_de_passe");

strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(inputlogin)));

strcpy(log1,gtk_entry_get_text(GTK_ENTRY(inputlogin)));
strcpy(pass1,gtk_entry_get_text(GTK_ENTRY(inputmotdepasse)));

int v=verifier(log1,pass1);

if (v==0)
{
gtk_widget_destroy(authentification);
admin=create_admin();
gtk_widget_show(admin);
}

if (v==1)
{
gtk_widget_destroy(authentification);
agent=create_agent();
gtk_widget_show(agent);
}

if (v==2)
{
gtk_widget_destroy(authentification);
client=create_client();
gtk_widget_show(client);
label_client= lookup_widget(client, "label_client");
gtk_label_set_text(GTK_LABEL(label_client),e.nom);
}

if(v==3) 
{
outputerror=lookup_widget(buttonconnecteraac,"labelerror");
gtk_label_set_text(GTK_LABEL(outputerror),"Vous n'êtes pas inscrits");
}


}
void on_button_retouraccueil_clicked (GtkWidget *buttonretouraccueil, gpointer user_data)
{

GtkWidget *accueil;
GtkWidget *authentification;

authentification=lookup_widget(buttonretouraccueil,"authentification");
gtk_widget_destroy(authentification);
accueil=create_accueil();
gtk_widget_show(accueil);

}


void on_button_validerinsciptionclient_clicked (GtkWidget *buttonvalidinscriclient, gpointer user_data)
{
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*****************////////

//GtkWidget *intputid;
GtkWidget *intputnom;
GtkWidget *intputprenom;
GtkWidget *intputadresse;
//GtkWidget *intputdate_naissance;
GtkWidget *intputcin;
GtkWidget *intputtel;
GtkWidget *intputlog;
GtkWidget *intputpass;
//GtkWidget *intputdatecreation;

GtkWidget *label_client;

GtkWidget *calendar_inscrit;

char jour[50];
char mois[50];
char annee[50];
int *jour1; int mois1;int *annee1;


client c;

intputnom=lookup_widget(buttonvalidinscriclient,"entry_inscritnomclient");
intputprenom=lookup_widget(buttonvalidinscriclient,"entry_inscritprenomclient");
intputadresse=lookup_widget(buttonvalidinscriclient,"entry_inscritadresseclient");
intputcin=lookup_widget(buttonvalidinscriclient,"entry_inscritcinclient");
intputtel=lookup_widget(buttonvalidinscriclient,"entry_inscrittelclient");
intputlog=lookup_widget(buttonvalidinscriclient,"entry_inscritloginclient");
intputpass=lookup_widget(buttonvalidinscriclient,"entry__inscritmotdepasseclient");

calendar_inscrit=lookup_widget(buttonvalidinscriclient,"calendar_inscrit");

gtk_calendar_get_date(calendar_inscrit,&annee1,&mois1,&jour1);

mois1++;

sprintf(jour,"%u", jour1);
sprintf(mois,"%u", mois1);
sprintf(annee,"%u", annee1);

	strcat(c.date_naissance,jour);
	strcat(c.date_naissance,"/");
	strcat(c.date_naissance,mois);
	strcat(c.date_naissance,"/");
	strcat(c.date_naissance,annee);

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(intputnom)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(intputprenom)));
strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(intputadresse)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(intputcin)));
strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(intputtel)));
strcpy(c.log,gtk_entry_get_text(GTK_ENTRY(intputlog)));
strcpy(c.pass,gtk_entry_get_text(GTK_ENTRY(intputpass)));

ajouter_client(c);

GtkWidget *inscription;
GtkWidget *client;

inscription=lookup_widget(buttonvalidinscriclient,"inscription");
gtk_widget_destroy(inscription);

client=create_client();
gtk_widget_show(client);

label_client= lookup_widget(client, "label_client");
gtk_label_set_text(GTK_LABEL(label_client),c.nom);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}


void on_button_retourauthentificationinscri_clicked (GtkWidget *buttonretourautheninscri, gpointer user_data)
{

GtkWidget *accueil;
GtkWidget *inscription;

inscription=lookup_widget(buttonretourautheninscri,"inscription");
gtk_widget_destroy(inscription);
accueil=create_accueil();
gtk_widget_show(accueil);

}


void on_button_gestionagents_clicked (GtkWidget *buttongestionagent, gpointer user_data)
{

GtkWidget *admin;
GtkTreeView *treeview_agent;
GtkWidget *gestion_agent;


admin=lookup_widget(buttongestionagent,"admin");
gtk_widget_destroy(admin);

gestion_agent = create_gestion_agent(); 
gtk_widget_show (gestion_agent);

treeview_agent=lookup_widget(gestion_agent,"treeview_agent");
afficher_agent(treeview_agent);
}


void on_button_retourauthentification_clicked (GtkWidget *buttonretourauthetif, gpointer user_data)
{
GtkWidget *admin;
GtkWidget *authentification;

admin=lookup_widget(buttonretourauthetif,"admin");
gtk_widget_destroy(admin);
authentification=create_authentification();
gtk_widget_show(authentification);


}



void on_button_ajoutagent_clicked (GtkWidget *buttonajoutagent, gpointer user_data)
{

GtkWidget *ajout_agent;
GtkWidget *gestion_agent;

gestion_agent=lookup_widget(buttonajoutagent,"gestion_agent");
gtk_widget_destroy(gestion_agent);
ajout_agent=create_ajout_agent();
gtk_widget_show(ajout_agent);

}




void on_button_modifieragent_clicked (GtkWidget *buttonmodifieragent, gpointer user_data)
{
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

GtkWidget *modifier_agent;
GtkWidget *gestion_agent;
GtkWidget *combobox_modifiersupprimeragent;
GtkWidget *label_idagent;
GtkWidget *entry_modifiernomagent;
GtkWidget *entry_modifierprenomagent;
GtkWidget *entry_modifieradresseagent;
GtkWidget *entry_modifierdatenaissanceagent;
GtkWidget *entry_modifiercinagent;
GtkWidget *entry_modifiertelagent;
GtkWidget *entry_modifierloginagent;
GtkWidget *entry_modifiermotdepasseagent;
GtkWidget *label_datecreationagent;

GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;
GtkWidget *treeview_agent;


gestion_agent=lookup_widget(buttonmodifieragent,"gestion_agent");


treeview_agent=lookup_widget(gestion_agent,"treeview_agent");

selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview_agent));
if(gtk_tree_selection_get_selected(selection, &model, &iter))
{

gchar *id;
gchar *nom;
gchar *prenom;
gchar *adresse;
gchar *date_naissance;
gchar *cin;
gchar *telephone;
gchar *login;
gchar *mot_de_passe;
gchar *date_creation;

gtk_tree_model_get(model, &iter, ID, &id, -1);
gtk_tree_model_get(model, &iter, NOM, &nom, -1);
gtk_tree_model_get(model, &iter, PRENOM, &prenom, -1);
gtk_tree_model_get(model, &iter, ADRESSE, &adresse, -1);
gtk_tree_model_get(model, &iter, DATE_NAISSANCE, &date_naissance, -1);
gtk_tree_model_get(model, &iter, CIN, &cin, -1);
gtk_tree_model_get(model, &iter, TELEPHONE, &telephone, -1);
gtk_tree_model_get(model, &iter, LOGIN, &login, -1);
gtk_tree_model_get(model, &iter, MOT_DE_PASSE, &mot_de_passe, -1);
gtk_tree_model_get(model, &iter, DATE_CREATION, &date_creation, -1);



		gtk_widget_destroy(gestion_agent);
		modifier_agent=create_modifier_agent();
		gtk_widget_show(modifier_agent);

label_idagent=lookup_widget(modifier_agent,"label_idagent");
entry_modifiernomagent= lookup_widget(modifier_agent, "entry_modifiernomagent");
entry_modifierprenomagent= lookup_widget(modifier_agent, "entry_modifierprenomagent");
entry_modifieradresseagent= lookup_widget(modifier_agent, "entry_modifieradresseagent");
entry_modifierdatenaissanceagent= lookup_widget(modifier_agent, "entry_modifierdatenaissanceagent");
entry_modifiercinagent= lookup_widget(modifier_agent, "entry_modifiercinagent");
entry_modifiertelagent= lookup_widget(modifier_agent, "entry_modifiertelagent");
entry_modifierloginagent= lookup_widget(modifier_agent, "entry_modifierloginagent");
entry_modifiermotdepasseagent= lookup_widget(modifier_agent, "entry_modifiermotdepasseagent");
label_datecreationagent= lookup_widget(modifier_agent, "label_datecreationagent");


gtk_label_set_text(GTK_LABEL(label_idagent),id);
gtk_entry_set_text(GTK_ENTRY(entry_modifiernomagent),nom);
gtk_entry_set_text(GTK_ENTRY(entry_modifierprenomagent),prenom);
gtk_entry_set_text(GTK_ENTRY(entry_modifieradresseagent),adresse);
gtk_entry_set_text(GTK_ENTRY(entry_modifierdatenaissanceagent),date_naissance);
gtk_entry_set_text(GTK_ENTRY(entry_modifiercinagent),cin);
gtk_entry_set_text(GTK_ENTRY(entry_modifiertelagent),telephone);
gtk_entry_set_text(GTK_ENTRY(entry_modifierloginagent),login);
gtk_entry_set_text(GTK_ENTRY(entry_modifiermotdepasseagent),mot_de_passe);
gtk_label_set_text(GTK_LABEL(label_datecreationagent),date_creation);
		
	        }


}


void on_button_supprimeragent_clicked (GtkWidget *buttonsupprimeragent, gpointer user_data)
{

GtkWidget *supprimer_agent;
GtkWidget *gestion_agent;
GtkWidget *combobox_modifiersupprimeragent;
GtkWidget *label_agentsupprimer;

char REFAGENT[50];

agent k;
gestion_agent=lookup_widget(buttonsupprimeragent,"gestion_agent");

combobox_modifiersupprimeragent=lookup_widget(buttonsupprimeragent,"combobox_modifiersupprimeragent");
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifiersupprimeragent))!=0)
{
strcpy(REFAGENT,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifiersupprimeragent)));
}

FILE *f;
f=fopen("/home/fahed/Projets/sky-travel/src/agent.txt","r");

if(f !=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",k.id,k.nom,k.prenom,k.adresse,k.date_naissance,k.cin,k.tel,k.log,k.pass,k.datecreation)!=EOF)
{
	if(strcmp(REFAGENT,k.id)==0)
		{
		gtk_widget_destroy(gestion_agent);
		supprimer_agent=create_supprimer_agent();
		gtk_widget_show(supprimer_agent);

		label_agentsupprimer=lookup_widget(supprimer_agent,"label_agentsupprimer");
		gtk_label_set_text(GTK_LABEL(label_agentsupprimer),k.log);
	        }

}fclose(f);

}


}


void on_button_retouradmin_clicked (GtkWidget *buttonretouradmin, gpointer user_data)
{

GtkWidget *admin;
GtkWidget *gestion_agent;

gestion_agent=lookup_widget(buttonretouradmin,"gestion_agent");
gtk_widget_destroy(gestion_agent);
admin=create_admin();
gtk_widget_show(admin);

}


void on_button_retourgestionagent_clicked (GtkWidget *buttonretourgestionagent, gpointer user_data)
{

GtkWidget *ajout_agent;
GtkWidget *gestion_agent;
GtkTreeView *treeview_agent;

ajout_agent=lookup_widget(buttonretourgestionagent,"ajout_agent");
gtk_widget_destroy(ajout_agent);

gestion_agent=create_gestion_agent();
gtk_widget_show(gestion_agent);

treeview_agent=lookup_widget(gestion_agent,"treeview_agent");
afficher_agent(treeview_agent);

}



void on_button_validerajoutagent_clicked (GtkWidget *buttonvaliderajoutagent, gpointer user_data)
{

//GtkWidget *intputid;
GtkWidget *intputnom;
GtkWidget *intputprenom;
GtkWidget *intputadresse;
//GtkWidget *intputdate_naissance;
GtkWidget *intputcin;
GtkWidget *intputtel;
GtkWidget *intputlog;
GtkWidget *intputpass;
//GtkWidget *intputdatecreation;
GtkWidget *intputjour;
GtkWidget *intputmois;
GtkWidget *intputannee;
GtkWidget *label_errorcinagent;

char jour[50];
char mois[50];
char annee[50];
int jour1,mois1,annee1;


agent p;
agent x;
int y=0;

intputnom=lookup_widget(buttonvaliderajoutagent,"entry_ajoutnomagent");
intputprenom=lookup_widget(buttonvaliderajoutagent,"entry_ajoutprenomagent");
intputadresse=lookup_widget(buttonvaliderajoutagent,"entry_ajouadresseagent");
intputcin=lookup_widget(buttonvaliderajoutagent,"entry_ajoutcinagent");
intputtel=lookup_widget(buttonvaliderajoutagent,"entry_ajouttelagent");
intputlog=lookup_widget(buttonvaliderajoutagent,"entry_ajoutloginagent");
intputpass=lookup_widget(buttonvaliderajoutagent,"entry_ajoumotdepasseagent");

intputjour=lookup_widget(buttonvaliderajoutagent,"spinbutton_ajoutjournaissanceagent");
intputmois=lookup_widget(buttonvaliderajoutagent,"spinbutton_ajoutmoisnaissanceagent");
intputannee=lookup_widget(buttonvaliderajoutagent,"spinbutton_ajoutanneenaissanceagent");

jour1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(intputjour));
mois1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(intputmois));
annee1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(intputannee));

sprintf(jour,"%u", jour1);
sprintf(mois,"%u", mois1);
sprintf(annee,"%u", annee1);

	strcat(p.date_naissance,jour);
	strcat(p.date_naissance,"/");
	strcat(p.date_naissance,mois);
	strcat(p.date_naissance,"/");
	strcat(p.date_naissance,annee);

label_errorcinagent=lookup_widget(buttonvaliderajoutagent,"label_errorcinagent");

strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(intputnom)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(intputprenom)));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(intputadresse)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(intputcin)));
strcpy(p.tel,gtk_entry_get_text(GTK_ENTRY(intputtel)));
strcpy(p.log,gtk_entry_get_text(GTK_ENTRY(intputlog)));
strcpy(p.pass,gtk_entry_get_text(GTK_ENTRY(intputpass)));

FILE *f1;
f1=fopen("/home/fahed/Projets/sky-travel/src/agent.txt","r");

if(f1 !=NULL){
while(fscanf(f1,"%s %s %s %s %s %s %s %s %s %s \n",x.id,x.nom,x.prenom,x.adresse,x.date_naissance,x.cin,x.tel,x.log,x.pass,x.datecreation)!=EOF)
{
	if(strcmp(p.cin,x.cin)==0)
		{
		y=1;
	        }

}fclose(f1);

}

if(y==0)
{
ajouter_agent(p);

GtkWidget *ajout_agent;
GtkTreeView *treeview_agent;
GtkWidget *gestion_agent;

ajout_agent=lookup_widget(buttonvaliderajoutagent,"ajout_agent");
gtk_widget_destroy(ajout_agent);

gestion_agent=create_gestion_agent();
gtk_widget_show(gestion_agent);

treeview_agent=lookup_widget(gestion_agent,"treeview_agent");
afficher_agent(treeview_agent);
}

if(y==1)
{
gtk_label_set_text(GTK_LABEL(label_errorcinagent),"Le numero cin existe");

}
}


void on_button_validermodifieragent_clicked (GtkWidget *buttonvalidermodifieragent, gpointer user_data)
{
//////////////////////////////////////////////////////////
GtkWidget *modifier_agent;
GtkTreeView *treeview_agent;
GtkWidget *gestion_agent;

GtkWidget *label_idagent;
GtkWidget *entry_modifiernomagent;
GtkWidget *entry_modifierprenomagent;
GtkWidget *entry_modifieradresseagent;
GtkWidget *entry_modifierdatenaissanceagent;
GtkWidget *entry_modifiercinagent;
GtkWidget *entry_modifiertelagent;
GtkWidget *entry_modifierloginagent;
GtkWidget *entry_modifiermotdepasseagent;
GtkWidget *label_datecreationagent;

agent a;

modifier_agent=lookup_widget(buttonvalidermodifieragent,"modifier_agent");

label_idagent=lookup_widget(buttonvalidermodifieragent,"label_idagent");
entry_modifiernomagent= lookup_widget(buttonvalidermodifieragent, "entry_modifiernomagent");
entry_modifierprenomagent= lookup_widget(buttonvalidermodifieragent, "entry_modifierprenomagent");
entry_modifieradresseagent= lookup_widget(buttonvalidermodifieragent, "entry_modifieradresseagent");
entry_modifierdatenaissanceagent= lookup_widget(buttonvalidermodifieragent, "entry_modifierdatenaissanceagent");
entry_modifiercinagent= lookup_widget(buttonvalidermodifieragent, "entry_modifiercinagent");
entry_modifiertelagent= lookup_widget(buttonvalidermodifieragent, "entry_modifiertelagent");
entry_modifierloginagent= lookup_widget(buttonvalidermodifieragent, "entry_modifierloginagent");
entry_modifiermotdepasseagent= lookup_widget(buttonvalidermodifieragent, "entry_modifiermotdepasseagent");
label_datecreationagent= lookup_widget(buttonvalidermodifieragent, "label_datecreationagent");

strcpy(a.id,gtk_label_get_text(GTK_LABEL(label_idagent)));
strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(entry_modifiernomagent)));
strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(entry_modifierprenomagent)));
strcpy(a.adresse,gtk_entry_get_text(GTK_ENTRY(entry_modifieradresseagent)));
strcpy(a.date_naissance,gtk_entry_get_text(GTK_ENTRY(entry_modifierdatenaissanceagent)));
strcpy(a.cin,gtk_entry_get_text(GTK_ENTRY(entry_modifiercinagent)));
strcpy(a.tel,gtk_entry_get_text(GTK_ENTRY(entry_modifiertelagent)));
strcpy(a.log,gtk_entry_get_text(GTK_ENTRY(entry_modifierloginagent)));
strcpy(a.pass,gtk_entry_get_text(GTK_ENTRY(entry_modifiermotdepasseagent)));
strcpy(a.datecreation,gtk_label_get_text(GTK_LABEL(label_datecreationagent)));

gtk_widget_destroy(modifier_agent);

gestion_agent=create_gestion_agent();
gtk_widget_show(gestion_agent);

modifieragent(a);

treeview_agent=lookup_widget(gestion_agent,"treeview_agent");
afficher_agent(treeview_agent);
}



void on_button_validersupprimeragent_clicked (GtkWidget *buttonvalidersupprimeragent, gpointer user_data)
{

GtkWidget *supprimer_agent;
GtkTreeView *treeview_agent;
GtkWidget *gestion_agent;
GtkWidget *label_agentsupprimer;

agent a;

label_agentsupprimer=lookup_widget(buttonvalidersupprimeragent,"label_agentsupprimer");
strcpy(a.log,gtk_label_get_text(GTK_LABEL(label_agentsupprimer)));


supprimer_agent=lookup_widget(buttonvalidersupprimeragent,"supprimer_agent");
gtk_widget_destroy(supprimer_agent);

gestion_agent=create_gestion_agent();
gtk_widget_show(gestion_agent);

supprimeragent(a);

treeview_agent=lookup_widget(gestion_agent,"treeview_agent");
afficher_agent(treeview_agent);

}



void on_button_retourgestionagentsup_clicked (GtkWidget *buttonretourgestionagentsup, gpointer user_data)
{

GtkWidget *supprimer_agent;
GtkTreeView *treeview_agent;
GtkWidget *gestion_agent;

supprimer_agent=lookup_widget(buttonretourgestionagentsup,"supprimer_agent");
gtk_widget_destroy(supprimer_agent);

gestion_agent=create_gestion_agent();
gtk_widget_show(gestion_agent);

treeview_agent=lookup_widget(gestion_agent,"treeview_agent");
afficher_agent(treeview_agent);

}

void on_button_retouraut_clicked (GtkWidget *buttonretouraut, gpointer user_data)
{

GtkWidget *client;
GtkWidget *authentification;

client=lookup_widget(buttonretouraut,"client");
gtk_widget_destroy(client);
authentification=create_authentification();
gtk_widget_show(authentification);

}


void on_button_retourau_clicked (GtkWidget *buttonretourau, gpointer user_data)
{

GtkWidget *agent;
GtkWidget *authentification;

agent=lookup_widget(buttonretourau,"agent");
gtk_widget_destroy(agent);
authentification=create_authentification();
gtk_widget_show(authentification);

}


void on_button_retourgestionagentmod_clicked (GtkWidget *buttonretourgestionagentmod, gpointer user_data)
{

GtkWidget *modifier_agent;
GtkWidget *gestion_agent;
GtkTreeView *treeview_agent;

modifier_agent=lookup_widget(buttonretourgestionagentmod,"modifier_agent");
gtk_widget_destroy(modifier_agent);

gestion_agent=create_gestion_agent();
gtk_widget_show(gestion_agent);

treeview_agent=lookup_widget(gestion_agent,"treeview_agent");
afficher_agent(treeview_agent);

}


void on_button_rechercheidagent_clicked (GtkWidget *button_rechercheidagent, gpointer user_data)
{
GtkWidget *combobox_modifiersupprimeragent;

char ref[50][50];
int i,nbr;

combobox_modifiersupprimeragent=lookup_widget(button_rechercheidagent,"combobox_modifiersupprimeragent");
nbr=liste_agent(ref);
for(i=0;i<nbr;i++)
{

gtk_combo_box_append_text(GTK_COMBO_BOX(combobox_modifiersupprimeragent),_(ref[i]));

}

}


void on_button_gestionprestations_clicked   (GtkWidget *buttongestionprestations, gpointer user_data)
{

GtkWidget *agent;
GtkWidget *gestion_des_prestations;

agent=lookup_widget(buttongestionprestations,"agent");
gtk_widget_destroy(agent);
gestion_des_prestations=create_gestion_des_prestations();
gtk_widget_show(gestion_des_prestations);

}


void on_button_retouragentprestations_clicked (GtkWidget *buttonretouragentprestations, gpointer user_data)
{

GtkWidget *agent;
GtkWidget *gestion_des_prestations;

gestion_des_prestations=lookup_widget(buttonretouragentprestations,"gestion_des_prestations");
gtk_widget_destroy(gestion_des_prestations);
agent=create_agent();
gtk_widget_show(agent);

}


void on_button_retourgestionprestationvoiture_clicked (GtkWidget *buttonretourgestionprestationvoiture, gpointer user_data)
{
GtkWidget *gestion_prestations_voitures;
GtkWidget *gestion_des_prestations;

gestion_prestations_voitures=lookup_widget(buttonretourgestionprestationvoiture,"gestion_prestations_voitures");
gtk_widget_destroy(gestion_prestations_voitures);
gestion_des_prestations=create_gestion_des_prestations();
gtk_widget_show(gestion_des_prestations);


}


void on_button_ajoutvoiture_clicked (GtkWidget *buttonajoutvoiture, gpointer user_data)
{

GtkWidget *gestion_prestations_voitures;
GtkWidget *ajout_voiture;

gestion_prestations_voitures=lookup_widget(buttonajoutvoiture,"gestion_prestations_voitures");
gtk_widget_destroy(gestion_prestations_voitures);
ajout_voiture=create_ajout_voiture();
gtk_widget_show(ajout_voiture);

}


void on_button_supprimervoiture_clicked (GtkWidget *buttonsupprimervoiture, gpointer user_data)
{

GtkWidget *gestion_prestations_voitures;
GtkWidget *supprimer_voiture;

GtkWidget *combobox_modifiersupprimervoiture;
GtkWidget *label_voituresupprimer;

char REFVOITURE[50];

voiture k;

gestion_prestations_voitures=lookup_widget(buttonsupprimervoiture,"gestion_prestations_voitures");

combobox_modifiersupprimervoiture=lookup_widget(buttonsupprimervoiture,"combobox_modifiersupprimervoiture");
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifiersupprimervoiture))!=0)
{
strcpy(REFVOITURE,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifiersupprimervoiture)));
}

FILE *f;
f=fopen("/home/fahed/Projets/sky-travel/src/voiture.txt","r");

if(f !=NULL){
while(fscanf(f,"%s %s %s %s %s \n",k.id,k.marque,k.modele,k.matricule,k.prix)!=EOF)
{
	if(strcmp(REFVOITURE,k.id)==0)
		{
		gtk_widget_destroy(gestion_prestations_voitures);
		supprimer_voiture=create_supprimer_voiture();
		gtk_widget_show(supprimer_voiture);

		label_voituresupprimer=lookup_widget(supprimer_voiture,"label_voituresupprimer");
		gtk_label_set_text(GTK_LABEL(label_voituresupprimer),k.matricule);
	        }

}fclose(f);

}


}


void on_button_modifiervoiture_clicked (GtkWidget *buttonmodifiervoiture, gpointer user_data)
{
GtkWidget *gestion_prestations_voitures;
GtkWidget *modifier_voiture;

GtkWidget *combobox_modifiersupprimervoiture;
GtkWidget *label_idvoiture;

GtkWidget *entry_modifiermarquevoiture;
GtkWidget *entry_modifiermodelevoiture;
GtkWidget *entry_modifiermatriculevoiture;
GtkWidget *entry_modifierprixvoiture;

char REFVOITURE[50];

voiture k;


gestion_prestations_voitures=lookup_widget(buttonmodifiervoiture,"gestion_prestations_voitures");

combobox_modifiersupprimervoiture=lookup_widget(buttonmodifiervoiture,"combobox_modifiersupprimervoiture");
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifiersupprimervoiture))!=0)
{
strcpy(REFVOITURE,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifiersupprimervoiture)));
}

FILE *f;
f=fopen("/home/fahed/Projets/sky-travel/src/voiture.txt","r");

if(f !=NULL){
while(fscanf(f,"%s %s %s %s %s \n",k.id,k.marque,k.modele,k.matricule,k.prix)!=EOF)
{
	if(strcmp(REFVOITURE,k.id)==0)
		{
		gtk_widget_destroy(gestion_prestations_voitures);
		modifier_voiture=create_modifier_voiture();
		gtk_widget_show(modifier_voiture);

		label_idvoiture=lookup_widget(modifier_voiture,"label_idvoiture");
		entry_modifiermarquevoiture= lookup_widget(modifier_voiture, "entry_modifiermarquevoiture");
		entry_modifiermodelevoiture= lookup_widget(modifier_voiture, "entry_modifiermodelevoiture");
		entry_modifiermatriculevoiture= lookup_widget(modifier_voiture, "entry_modifiermatriculevoiture");
		entry_modifierprixvoiture= lookup_widget(modifier_voiture, "entry_modifierprixvoiture");

		gtk_label_set_text(GTK_LABEL(label_idvoiture),k.id);
		gtk_entry_set_text(GTK_ENTRY(entry_modifiermarquevoiture),k.marque);
		gtk_entry_set_text(GTK_ENTRY(entry_modifiermodelevoiture),k.modele);
		gtk_entry_set_text(GTK_ENTRY(entry_modifiermatriculevoiture),k.matricule);
		gtk_entry_set_text(GTK_ENTRY(entry_modifierprixvoiture),k.prix);
	        }

}fclose(f);

}


}


void on_button_rechercheidvoiture_clicked (GtkWidget *buttonrechercheidvoiture, gpointer user_data)
{

GtkWidget *combobox_modifiersupprimervoiture;

char ref[50][50];
int i,nbr;

combobox_modifiersupprimervoiture=lookup_widget(buttonrechercheidvoiture,"combobox_modifiersupprimervoiture");
nbr=liste_voiture(ref);
for(i=0;i<nbr;i++)
{

gtk_combo_box_append_text(GTK_COMBO_BOX(combobox_modifiersupprimervoiture),_(ref[i]));

}
}


void on_button_gestionvoitures_clicked (GtkWidget *buttongestionvoitures, gpointer user_data)
{

GtkWidget *gestion_prestations_voitures;
GtkWidget *gestion_des_prestations;
GtkWidget *treeview_voiture;

gestion_des_prestations=lookup_widget(buttongestionvoitures,"gestion_des_prestations");
gtk_widget_destroy(gestion_des_prestations);
gestion_prestations_voitures=create_gestion_prestations_voitures();
gtk_widget_show(gestion_prestations_voitures);

treeview_voiture=lookup_widget(gestion_prestations_voitures,"treeview_voiture");
afficher_voiture(treeview_voiture);

}


void on_button_lienfacebook_clicked (GtkWidget *buttonlienfacebook, gpointer user_data)
{

//system("start firefox& www.facebook.com/fahed.xavi");
//ShellExecute(NULL, NULL, "https://www.facebook.com/fahed.xavi", NULL, NULL, SW_SHOWNORMAL);
}


void on_button_validerajoutvoiture_clicked (GtkWidget *buttonvaliderajoutvoiture, gpointer user_data)
{
GtkWidget *gestion_prestations_voitures;
GtkWidget *ajout_voiture;
GtkWidget *treeview_voiture;

GtkWidget *entry_ajoutmarquevoiture;
GtkWidget *entry_ajoutmodelevoiture;
GtkWidget *entry_ajoutprixvoiture;

GtkWidget *intputserie;
GtkWidget *intputnumero;

char serie[50];
char numero[50];

int serie1,numero1;

voiture v;

ajout_voiture=lookup_widget(buttonvaliderajoutvoiture,"ajout_voiture");

entry_ajoutmarquevoiture=lookup_widget(buttonvaliderajoutvoiture,"entry_ajoutmarquevoiture");
entry_ajoutmodelevoiture=lookup_widget(buttonvaliderajoutvoiture,"entry_ajoutmodelevoiture");
entry_ajoutprixvoiture=lookup_widget(buttonvaliderajoutvoiture,"entry_ajoutprixvoiture");

intputserie=lookup_widget(buttonvaliderajoutvoiture,"spinbutton_serievoiture");
intputnumero=lookup_widget(buttonvaliderajoutvoiture,"spinbutton_numerovoiture");

serie1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(intputserie));
numero1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(intputnumero));


sprintf(serie,"%u", serie1);
sprintf(numero,"%u", numero1);

	strcat(v.matricule,serie);
	strcat(v.matricule,"_tunisie_");
	strcat(v.matricule,numero);

strcpy(v.marque,gtk_entry_get_text(GTK_ENTRY(entry_ajoutmarquevoiture)));
strcpy(v.modele,gtk_entry_get_text(GTK_ENTRY(entry_ajoutmodelevoiture)));
strcpy(v.prix,gtk_entry_get_text(GTK_ENTRY(entry_ajoutprixvoiture)));

ajouter_voiture(v);
gtk_widget_destroy(ajout_voiture);
gestion_prestations_voitures=create_gestion_prestations_voitures();
gtk_widget_show(gestion_prestations_voitures);

treeview_voiture=lookup_widget(gestion_prestations_voitures,"treeview_voiture");
afficher_voiture(treeview_voiture);
}


void on_button_retourajoutgestionvoiture_clicked (GtkWidget *buttonretourajoutgestionvoiture, gpointer user_data)
{

GtkWidget *gestion_prestations_voitures;
GtkWidget *ajout_voiture;
GtkWidget *treeview_voiture;

ajout_voiture=lookup_widget(buttonretourajoutgestionvoiture,"ajout_voiture");
gtk_widget_destroy(ajout_voiture);

gestion_prestations_voitures=create_gestion_prestations_voitures();
gtk_widget_show(gestion_prestations_voitures);

treeview_voiture=lookup_widget(gestion_prestations_voitures,"treeview_voiture");
afficher_voiture(treeview_voiture);
}


void on_button_retourgestionvoituresup_clicked (GtkWidget *buttonretourgestionvoituresup, gpointer user_data)
{
GtkWidget *gestion_prestations_voitures;
GtkWidget *supprimer_voiture;
GtkWidget *treeview_voiture;

supprimer_voiture=lookup_widget(buttonretourgestionvoituresup,"supprimer_voiture");
gtk_widget_destroy(supprimer_voiture);

gestion_prestations_voitures=create_gestion_prestations_voitures();
gtk_widget_show(gestion_prestations_voitures);

treeview_voiture=lookup_widget(gestion_prestations_voitures,"treeview_voiture");
afficher_voiture(treeview_voiture);


}


void on_button_validersupprimervoiture_clicked (GtkWidget *buttonvalidersupprimervoiture, gpointer user_data)
{
GtkWidget *supprimer_voiture;
GtkTreeView *treeview_voiture;
GtkWidget *gestion_prestations_voitures;
GtkWidget *label_voituresupprimer;

voiture a;

label_voituresupprimer=lookup_widget(buttonvalidersupprimervoiture,"label_voituresupprimer");
strcpy(a.matricule,gtk_label_get_text(GTK_LABEL(label_voituresupprimer)));


supprimer_voiture=lookup_widget(buttonvalidersupprimervoiture,"supprimer_voiture");
gtk_widget_destroy(supprimer_voiture);

gestion_prestations_voitures=create_gestion_prestations_voitures();
gtk_widget_show(gestion_prestations_voitures);

supprimervoiture(a);

treeview_voiture=lookup_widget(gestion_prestations_voitures,"treeview_voiture");
afficher_voiture(treeview_voiture);



}


void on_button_retourmodifiergestionvoiture_clicked (GtkWidget *buttonretourmodifiergestionvoiture, gpointer user_data)
{

GtkWidget *gestion_prestations_voitures;
GtkWidget *modifier_voiture;
GtkWidget *treeview_voiture;

modifier_voiture=lookup_widget(buttonretourmodifiergestionvoiture,"modifier_voiture");
gtk_widget_destroy(modifier_voiture);

gestion_prestations_voitures=create_gestion_prestations_voitures();
gtk_widget_show(gestion_prestations_voitures);

treeview_voiture=lookup_widget(gestion_prestations_voitures,"treeview_voiture");
afficher_voiture(treeview_voiture);


}


void on_button_validermodifiervoiture_clicked (GtkWidget *buttonvalidermodifiervoiture, gpointer user_data)
{
GtkWidget *modifier_voiture;
GtkTreeView *treeview_voiture;
GtkWidget *gestion_prestations_voitures;

GtkWidget *label_idvoiture;
GtkWidget *entry_modifiermarquevoiture;
GtkWidget *entry_modifiermodelevoiture;
GtkWidget *entry_modifiermatriculevoiture;
GtkWidget *entry_modifierprixvoiture;

voiture a;

modifier_voiture=lookup_widget(buttonvalidermodifiervoiture,"modifier_voiture");

label_idvoiture=lookup_widget(buttonvalidermodifiervoiture,"label_idvoiture");
entry_modifiermarquevoiture= lookup_widget(buttonvalidermodifiervoiture, "entry_modifiermarquevoiture");
entry_modifiermodelevoiture= lookup_widget(buttonvalidermodifiervoiture, "entry_modifiermodelevoiture");
entry_modifiermatriculevoiture= lookup_widget(buttonvalidermodifiervoiture, "entry_modifiermatriculevoiture");
entry_modifierprixvoiture= lookup_widget(buttonvalidermodifiervoiture, "entry_modifierprixvoiture");

strcpy(a.id,gtk_label_get_text(GTK_LABEL(label_idvoiture)));
strcpy(a.marque,gtk_entry_get_text(GTK_ENTRY(entry_modifiermarquevoiture)));
strcpy(a.modele,gtk_entry_get_text(GTK_ENTRY(entry_modifiermodelevoiture)));
strcpy(a.matricule,gtk_entry_get_text(GTK_ENTRY(entry_modifiermatriculevoiture)));
strcpy(a.prix,gtk_entry_get_text(GTK_ENTRY(entry_modifierprixvoiture)));

gtk_widget_destroy(modifier_voiture);

gestion_prestations_voitures=create_gestion_prestations_voitures();
gtk_widget_show(gestion_prestations_voitures);

modifiervoiture(a);

treeview_voiture=lookup_widget(gestion_prestations_voitures,"treeview_voiture");
afficher_voiture(treeview_voiture);


}


void on_button_retourevaluatioclient_clicked (GtkWidget *buttonretourevaluatioclient, gpointer user_data)
{
GtkWidget *client;
GtkWidget *gestion_evaluation;
GtkWidget *treeview_evaluation;

gestion_evaluation=lookup_widget(buttonretourevaluatioclient,"gestion_evaluation");
gtk_widget_destroy(gestion_evaluation);

client=create_client();
gtk_widget_show(client);


}


void on_button_ajoutevaluation_clicked (GtkWidget *buttonajoutevaluation, gpointer user_data)
{
GtkWidget *gestion_evaluation;
GtkWidget *ajout_evaluation;
GtkWidget *label_clientevaluation;
GtkWidget *label_nomclientevaluation;

evaluation e;
gestion_evaluation=lookup_widget(buttonajoutevaluation,"gestion_evaluation");

label_clientevaluation= lookup_widget(buttonajoutevaluation, "label_clientevaluation");
strcpy(e.nom,gtk_label_get_text(GTK_LABEL(label_clientevaluation)));

gtk_widget_destroy(gestion_evaluation);

ajout_evaluation=create_ajout_evaluation();
gtk_widget_show(ajout_evaluation);

label_nomclientevaluation= lookup_widget(ajout_evaluation, "label_nomclientevaluation");
gtk_label_set_text(GTK_LABEL(label_nomclientevaluation),e.nom);

}


void on_button_modifieravaluation_clicked (GtkWidget *buttonmodifieravaluation, gpointer user_data)
{
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
GtkWidget *gestion_evaluation;
GtkWidget *modifier_evaluation;
GtkWidget *label_clientevaluation;
GtkWidget *combobox_modifiersupprimerevaluation;
GtkWidget *label_validationidmodifevaluation;
GtkWidget *label_validationommodifevaluation;
GtkWidget *label_datecreationvalidermodifier;

evaluation e;
evaluation l;

gestion_evaluation=lookup_widget(buttonmodifieravaluation,"gestion_evaluation");

label_clientevaluation= lookup_widget(buttonmodifieravaluation, "label_clientevaluation");
strcpy(e.nom,gtk_label_get_text(GTK_LABEL(label_clientevaluation)));

combobox_modifiersupprimerevaluation=lookup_widget(buttonmodifieravaluation,"combobox_modifiersupprimerevaluation");
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifiersupprimerevaluation))!=0)
{
strcpy(e.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifiersupprimerevaluation)));
}

FILE *f;
f=fopen("/home/fahed/Projets/sky-travel/src/evaluation.txt","r");

if(f !=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s %s %s \n",l.id,l.nom,l.prestation,l.evaluation,l.serviabilite,l.ponctualite,l.prix,l.proprete,l.datecreation)!=EOF)
{
	if(strcmp(e.id,l.id)==0)
		{
		gtk_widget_destroy(gestion_evaluation);
		modifier_evaluation=create_modifier_evaluation();
		gtk_widget_show(modifier_evaluation);

	label_validationommodifevaluation= lookup_widget(modifier_evaluation, "label_validationommodifevaluation");
	gtk_label_set_text(GTK_LABEL(label_validationommodifevaluation),e.nom);
		
	label_validationidmodifevaluation= lookup_widget(modifier_evaluation, "label_validationidmodifevaluation");
	gtk_label_set_text(GTK_LABEL(label_validationidmodifevaluation),e.id);

	label_datecreationvalidermodifier= lookup_widget(modifier_evaluation, "label_datecreationvalidermodifier");
	gtk_label_set_text(GTK_LABEL(label_datecreationvalidermodifier),l.datecreation);
	        }


}fclose(f);
}


}


void on_button_supprimerevaluation_clicked  (GtkWidget *buttonsupprimerevaluation, gpointer user_data)
{

GtkWidget *gestion_evaluation;
GtkWidget *supprimer_evaluation;
GtkWidget *label_clientevaluation;
GtkWidget *label_nomevaluationsup;
GtkWidget *combobox_modifiersupprimerevaluation;
GtkWidget *label_idsupevaluation;

evaluation e;
evaluation l;

gestion_evaluation=lookup_widget(buttonsupprimerevaluation,"gestion_evaluation");

label_clientevaluation= lookup_widget(buttonsupprimerevaluation, "label_clientevaluation");
strcpy(e.nom,gtk_label_get_text(GTK_LABEL(label_clientevaluation)));

combobox_modifiersupprimerevaluation=lookup_widget(buttonsupprimerevaluation,"combobox_modifiersupprimerevaluation");
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifiersupprimerevaluation))!=0)
{
strcpy(e.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifiersupprimerevaluation)));
}

FILE *f;
f=fopen("/home/fahed/Projets/sky-travel/src/evaluation.txt","r");

if(f !=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s %s %s \n",l.id,l.nom,l.prestation,l.evaluation,l.serviabilite,l.ponctualite,l.prix,l.proprete,l.datecreation)!=EOF)
{
	if(strcmp(e.id,l.id)==0)
		{
		gtk_widget_destroy(gestion_evaluation);
		supprimer_evaluation=create_supprimer_evaluation();
		gtk_widget_show(supprimer_evaluation);

		label_nomevaluationsup= lookup_widget(supprimer_evaluation, "label_nomevaluationsup");
		gtk_label_set_text(GTK_LABEL(label_nomevaluationsup),e.nom);
		
		label_idsupevaluation= lookup_widget(supprimer_evaluation, "label_idsupevaluation");
		gtk_label_set_text(GTK_LABEL(label_idsupevaluation),e.id);
	        }


}fclose(f);
}

}


void on_button_idevaluation_clicked (GtkWidget *buttonidevaluation, gpointer user_data)
{

GtkWidget *combobox_modifiersupprimerevaluation;
GtkWidget *gestion_evaluation;
char ref[50][50];
int i;
char nbr;

gestion_evaluation=lookup_widget(buttonidevaluation,"gestion_evaluation");


combobox_modifiersupprimerevaluation=lookup_widget(buttonidevaluation,"combobox_modifiersupprimerevaluation");
nbr=liste_evaluation(ref);
for(i=0;i<nbr;i++)
{

gtk_combo_box_append_text(GTK_COMBO_BOX(combobox_modifiersupprimerevaluation),_(ref[i]));

}
}



void on_button_gestionevaluation_clicked (GtkWidget *buttongestionevaluation, gpointer user_data)
{
GtkWidget *client;
GtkTreeView *treeview_evaluation;
GtkWidget *gestion_evaluation;
GtkWidget *label_client;
GtkWidget *label_clientevaluation;
evaluation e;


client=lookup_widget(buttongestionevaluation,"client");
label_client= lookup_widget(client, "label_client");
strcpy(e.nom,gtk_label_get_text(GTK_LABEL(label_client)));

gtk_widget_destroy(client);

gestion_evaluation= create_gestion_evaluation(); 
gtk_widget_show (gestion_evaluation);

label_clientevaluation= lookup_widget(gestion_evaluation, "label_clientevaluation");
gtk_label_set_text(GTK_LABEL(label_clientevaluation),e.nom);

treeview_evaluation=lookup_widget(gestion_evaluation,"treeview_evaluation");
afficher_evaluation(treeview_evaluation);
}


void on_button_retourgestionevaluationajout_clicked (GtkWidget *buttonretourgestionevaluationajout, gpointer         user_data)
{

GtkWidget *gestion_evaluation;
GtkWidget *ajout_evaluation;
GtkWidget *label_clientevaluation;
GtkWidget *label_nomclientevaluation;
GtkTreeView *treeview_evaluation;

evaluation e;
ajout_evaluation=lookup_widget(buttonretourgestionevaluationajout,"ajout_evaluation");

label_nomclientevaluation= lookup_widget(buttonretourgestionevaluationajout, "label_nomclientevaluation");
strcpy(e.nom,gtk_label_get_text(GTK_LABEL(label_nomclientevaluation)));

gtk_widget_destroy(ajout_evaluation);

gestion_evaluation=create_gestion_evaluation();
gtk_widget_show(gestion_evaluation);

label_clientevaluation= lookup_widget(gestion_evaluation, "label_clientevaluation");
gtk_label_set_text(GTK_LABEL(label_clientevaluation),e.nom);

treeview_evaluation=lookup_widget(gestion_evaluation,"treeview_evaluation");
afficher_evaluation(treeview_evaluation);

}


void on_button_validerajoutevaluation_clicked (GtkWidget *buttonvaliderajoutevaluation, gpointer user_data)
{

GtkWidget *gestion_evaluation;
GtkWidget *ajout_evaluation;
GtkWidget *label_clientevaluation;
GtkWidget *label_nomclientevaluation;
GtkTreeView *treeview_evaluation;
GtkWidget *combobox_ajoutnomprestation;
GtkWidget *combobox_ajoutevaluationprestation;
GtkWidget *combobox_ajoutserviabiliteevaluation;
GtkWidget *combobox_ajoutponctualiteevaluation;
GtkWidget *combobox_ajoutprixevalution;
GtkWidget *combobox_ajoutpropreteevaluation;

evaluation e;

ajout_evaluation=lookup_widget(buttonvaliderajoutevaluation,"ajout_evaluation");

combobox_ajoutnomprestation=lookup_widget(buttonvaliderajoutevaluation,"combobox_ajoutnomprestation");
combobox_ajoutevaluationprestation=lookup_widget(buttonvaliderajoutevaluation,"combobox_ajoutevaluationprestation");
combobox_ajoutserviabiliteevaluation=lookup_widget(buttonvaliderajoutevaluation,"combobox_ajoutserviabiliteevaluation");
combobox_ajoutponctualiteevaluation=lookup_widget(buttonvaliderajoutevaluation,"combobox_ajoutponctualiteevaluation");
combobox_ajoutprixevalution=lookup_widget(buttonvaliderajoutevaluation,"combobox_ajoutprixevalution");
combobox_ajoutpropreteevaluation=lookup_widget(buttonvaliderajoutevaluation,"combobox_ajoutpropreteevaluation");

strcpy(e.prestation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_ajoutnomprestation)));
strcpy(e.evaluation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_ajoutevaluationprestation)));
strcpy(e.serviabilite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_ajoutserviabiliteevaluation)));
strcpy(e.ponctualite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_ajoutponctualiteevaluation)));
strcpy(e.prix,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_ajoutprixevalution)));
strcpy(e.proprete,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_ajoutpropreteevaluation)));

label_nomclientevaluation= lookup_widget(buttonvaliderajoutevaluation, "label_nomclientevaluation");
strcpy(e.nom,gtk_label_get_text(GTK_LABEL(label_nomclientevaluation)));

ajouter_evaluation(e);
gtk_widget_destroy(ajout_evaluation);

gestion_evaluation=create_gestion_evaluation();
gtk_widget_show(gestion_evaluation);

label_clientevaluation= lookup_widget(gestion_evaluation, "label_clientevaluation");
gtk_label_set_text(GTK_LABEL(label_clientevaluation),e.nom);

treeview_evaluation=lookup_widget(gestion_evaluation,"treeview_evaluation");
afficher_evaluation(treeview_evaluation);



}


void on_button_retourgestionevaluationsup_clicked (GtkWidget *buttonretourgestionevaluationsup, gpointer user_data)
{

GtkWidget *gestion_evaluation;
GtkWidget *supprimer_evaluation;
GtkWidget *label_clientevaluation;
GtkWidget *label_nomevaluationsup;
GtkTreeView *treeview_evaluation;

evaluation e;
supprimer_evaluation=lookup_widget(buttonretourgestionevaluationsup,"supprimer_evaluation");

label_nomevaluationsup= lookup_widget(buttonretourgestionevaluationsup, "label_nomevaluationsup");
strcpy(e.nom,gtk_label_get_text(GTK_LABEL(label_nomevaluationsup)));

gtk_widget_destroy(supprimer_evaluation);

gestion_evaluation=create_gestion_evaluation();
gtk_widget_show(gestion_evaluation);

label_clientevaluation= lookup_widget(gestion_evaluation, "label_clientevaluation");
gtk_label_set_text(GTK_LABEL(label_clientevaluation),e.nom);

treeview_evaluation=lookup_widget(gestion_evaluation,"treeview_evaluation");
afficher_evaluation(treeview_evaluation);


}


void on_button_validersupprimerevaluation_clicked (GtkWidget *buttonvalidersupprimerevaluation, gpointer user_data)
{

GtkWidget *supprimer_evaluation;
GtkTreeView *treeview_evaluation;
GtkWidget *gestion_evaluation;
GtkWidget *label_clientevaluation;
GtkWidget *label_nomevaluationsup;
GtkWidget *label_idsupevaluation;


evaluation a;

supprimer_evaluation=lookup_widget(buttonvalidersupprimerevaluation,"supprimer_evaluation");

label_nomevaluationsup=lookup_widget(buttonvalidersupprimerevaluation,"label_nomevaluationsup");
strcpy(a.nom,gtk_label_get_text(GTK_LABEL(label_nomevaluationsup)));

label_idsupevaluation= lookup_widget(buttonvalidersupprimerevaluation, "label_idsupevaluation");
strcpy(a.id,gtk_label_get_text(GTK_LABEL(label_idsupevaluation)));

gtk_widget_destroy(supprimer_evaluation);

supprimerevaluation(a);

gestion_evaluation=create_gestion_evaluation();
gtk_widget_show(gestion_evaluation);

label_clientevaluation= lookup_widget(gestion_evaluation, "label_clientevaluation");
gtk_label_set_text(GTK_LABEL(label_clientevaluation),a.nom);

treeview_evaluation=lookup_widget(gestion_evaluation,"treeview_evaluation");
afficher_evaluation(treeview_evaluation);
}



void on_button_vaildermodifierevaluation_clicked (GtkWidget *buttonvaildermodifierevaluation, gpointer user_data)
{
/////////////////////////////////////////////////////////////////////////////////////////////////////
GtkWidget *gestion_evaluation;
GtkWidget *modifier_evaluation;
GtkWidget *label_clientevaluation;
GtkWidget *label_validationommodifevaluation;
GtkWidget *label_validationidmodifevaluation;
GtkTreeView *treeview_evaluation;
GtkWidget *combobox_modifiernomprestation;
GtkWidget *combobox_modifierevaluationprestation;
GtkWidget *combobox_modifierserviabiliteevaluation;
GtkWidget *combobox_modifierponctualiteevaluation;
GtkWidget *combobox_modifierprixevalution;
GtkWidget *combobox_modifierpropreteevaluation;
GtkWidget *label_datecreationvalidermodifier;

evaluation e;

modifier_evaluation=lookup_widget(buttonvaildermodifierevaluation,"modifier_evaluation");

label_validationommodifevaluation=lookup_widget(buttonvaildermodifierevaluation, "label_validationommodifevaluation");
strcpy(e.nom,gtk_label_get_text(GTK_LABEL(label_validationommodifevaluation)));

label_validationidmodifevaluation=lookup_widget(buttonvaildermodifierevaluation, "label_validationidmodifevaluation");
strcpy(e.id,gtk_label_get_text(GTK_LABEL(label_validationidmodifevaluation)));

label_datecreationvalidermodifier=lookup_widget(buttonvaildermodifierevaluation, "label_datecreationvalidermodifier");
strcpy(e.datecreation,gtk_label_get_text(GTK_LABEL(label_datecreationvalidermodifier)));

combobox_modifiernomprestation=lookup_widget(buttonvaildermodifierevaluation,"combobox_modifiernomprestation");

combobox_modifierevaluationprestation=lookup_widget(buttonvaildermodifierevaluation,"combobox_modifierevaluationprestation");

combobox_modifierserviabiliteevaluation=lookup_widget(buttonvaildermodifierevaluation,"combobox_modifierserviabiliteevaluation");

combobox_modifierponctualiteevaluation=lookup_widget(buttonvaildermodifierevaluation,"combobox_modifierponctualiteevaluation");

combobox_modifierprixevalution=lookup_widget(buttonvaildermodifierevaluation,"combobox_modifierprixevalution");
combobox_modifierpropreteevaluation=lookup_widget(buttonvaildermodifierevaluation,"combobox_modifierpropreteevaluation");

strcpy(e.prestation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifiernomprestation)));
strcpy(e.evaluation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifierevaluationprestation)));
strcpy(e.serviabilite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifierserviabiliteevaluation)));
strcpy(e.ponctualite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifierponctualiteevaluation)));
strcpy(e.prix,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifierprixevalution)));
strcpy(e.proprete,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifierpropreteevaluation)));

gtk_widget_destroy(modifier_evaluation);

gestion_evaluation=create_gestion_evaluation();
gtk_widget_show(gestion_evaluation);

modifierevaluation(e);

label_clientevaluation= lookup_widget(gestion_evaluation, "label_clientevaluation");
gtk_label_set_text(GTK_LABEL(label_clientevaluation),e.nom);

treeview_evaluation=lookup_widget(gestion_evaluation,"treeview_evaluation");
afficher_evaluation(treeview_evaluation);


}


void on_button_retourgestionevaluationmodif_clicked (GtkWidget *buttonretourgestionevaluationmodif, gpointer user_data)
{


GtkWidget *gestion_evaluation;
GtkWidget *modifier_evaluation;
GtkWidget *label_clientevaluation;
GtkWidget *label_validationommodifevaluation;
GtkTreeView *treeview_evaluation;

evaluation e;
modifier_evaluation=lookup_widget(buttonretourgestionevaluationmodif,"modifier_evaluation");

label_validationommodifevaluation=lookup_widget(buttonretourgestionevaluationmodif, "label_validationommodifevaluation");
strcpy(e.nom,gtk_label_get_text(GTK_LABEL(label_validationommodifevaluation)));

gtk_widget_destroy(modifier_evaluation);

gestion_evaluation=create_gestion_evaluation();
gtk_widget_show(gestion_evaluation);

label_clientevaluation= lookup_widget(gestion_evaluation, "label_clientevaluation");
gtk_label_set_text(GTK_LABEL(label_clientevaluation),e.nom);

treeview_evaluation=lookup_widget(gestion_evaluation,"treeview_evaluation");
afficher_evaluation(treeview_evaluation);


}


void on_button_retourgestionclientclient_clicked (GtkWidget *buttonretourgestionclientclient, gpointer user_data)
{

GtkWidget *agent;
GtkWidget *gestion_client;


gestion_client=lookup_widget(buttonretourgestionclientclient,"gestion_client");
gtk_widget_destroy(gestion_client);

agent = create_agent(); 
gtk_widget_show (agent);


}


void on_button_gestionclient_clicked (GtkWidget *buttongestionclient, gpointer user_data)
{

GtkWidget *agent;
GtkTreeView *treeview_client;
GtkWidget *gestion_client;


agent=lookup_widget(buttongestionclient,"agent");
gtk_widget_destroy(agent);

gestion_client = create_gestion_client(); 
gtk_widget_show (gestion_client);

treeview_client=lookup_widget(gestion_client,"treeview_client");
afficher_client(treeview_client);


}


void on_button_ajouterclient_clicked (GtkWidget *buttonajouterclient, gpointer user_data)
{
GtkWidget *ajout_client;
GtkWidget *gestion_client;

gestion_client=lookup_widget(buttonajouterclient,"gestion_client");
gtk_widget_destroy(gestion_client);

ajout_client = create_ajout_client(); 
gtk_widget_show (ajout_client);

}


void on_button_retourgestionclientajout_clicked (GtkWidget *buttonretourgestionclientajout, gpointer user_data)
{

GtkWidget *ajout_client;
GtkTreeView *treeview_client;
GtkWidget *gestion_client;


ajout_client=lookup_widget(buttonretourgestionclientajout,"ajout_client");
gtk_widget_destroy(ajout_client);

gestion_client = create_gestion_client(); 
gtk_widget_show (gestion_client);

treeview_client=lookup_widget(gestion_client,"treeview_client");
afficher_client(treeview_client);



}




void on_button_validerajoutclient_clicked (GtkWidget *buttonvaliderajoutclient,gpointer user_data)
{

//GtkWidget *intputid;
GtkWidget *intputnom;
GtkWidget *intputprenom;
GtkWidget *intputadresse;
//GtkWidget *intputdate_naissance;
GtkWidget *intputcin;
GtkWidget *intputtel;
GtkWidget *intputlog;
GtkWidget *intputpass;
//GtkWidget *intputdatecreation;
GtkWidget *intputjour;
GtkWidget *intputmois;
GtkWidget *intputannee;
GtkWidget *label_client;

char jour[50];
char mois[50];
char annee[50];
int jour1,mois1,annee1;


client c;

intputnom=lookup_widget(buttonvaliderajoutclient,"entry_ajoutnomclient");
intputprenom=lookup_widget(buttonvaliderajoutclient,"entry_ajoutprenomclient");
intputadresse=lookup_widget(buttonvaliderajoutclient,"entry_ajouadresseclient");
intputcin=lookup_widget(buttonvaliderajoutclient,"entry_ajoutcinclient");
intputtel=lookup_widget(buttonvaliderajoutclient,"entry_ajouttelclient");
intputlog=lookup_widget(buttonvaliderajoutclient,"entry_ajoutloginclient");
intputpass=lookup_widget(buttonvaliderajoutclient,"entry_ajoumotdepasseagent");

intputjour=lookup_widget(buttonvaliderajoutclient,"spinbutton_ajoutjournaissanceclient");
intputmois=lookup_widget(buttonvaliderajoutclient,"spinbutton_ajoutmoisnaissanceclient");
intputannee=lookup_widget(buttonvaliderajoutclient,"spinbutton_ajoutanneenaissanceclient");

jour1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(intputjour));
mois1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(intputmois));
annee1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(intputannee));

sprintf(jour,"%u", jour1);
sprintf(mois,"%u", mois1);
sprintf(annee,"%u", annee1);

	strcat(c.date_naissance,jour);
	strcat(c.date_naissance,"/");
	strcat(c.date_naissance,mois);
	strcat(c.date_naissance,"/");
	strcat(c.date_naissance,annee);

strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(intputnom)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(intputprenom)));
strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(intputadresse)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(intputcin)));
strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(intputtel)));
strcpy(c.log,gtk_entry_get_text(GTK_ENTRY(intputlog)));
strcpy(c.pass,gtk_entry_get_text(GTK_ENTRY(intputpass)));

ajouter_client(c);


GtkWidget *ajout_client;
GtkTreeView *treeview_client;
GtkWidget *gestion_client;

ajout_client=lookup_widget(buttonvaliderajoutclient,"ajout_client");



gtk_widget_destroy(ajout_client);

gestion_client = create_gestion_client(); 
gtk_widget_show (gestion_client);

treeview_client=lookup_widget(gestion_client,"treeview_client");
afficher_client(treeview_client);


}


void on_button_rechercheidclient_clicked (GtkWidget *buttonrechercheidclient,  gpointer user_data)
{

GtkWidget *combobox_idmodifiersupprimerclient;

char ref[50][50];
int i,nbr;

combobox_idmodifiersupprimerclient=lookup_widget(buttonrechercheidclient,"combobox_idmodifiersupprimerclient");
nbr=liste_client(ref);
for(i=0;i<nbr;i++)
{

gtk_combo_box_append_text(GTK_COMBO_BOX(combobox_idmodifiersupprimerclient),_(ref[i]));

}


}


void on_button_supprimerclient_clicked (GtkWidget *buttonsupprimerclient, gpointer user_data)
{

GtkWidget *supprimer_client;
GtkWidget *gestion_client;
GtkWidget *combobox_idmodifiersupprimerclient;
GtkWidget *label_clientsupprimer;

char REFAGENT[50];

client k;
gestion_client=lookup_widget(buttonsupprimerclient,"gestion_client");

combobox_idmodifiersupprimerclient=lookup_widget(buttonsupprimerclient,"combobox_idmodifiersupprimerclient");
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_idmodifiersupprimerclient))!=0)
{
strcpy(REFAGENT,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_idmodifiersupprimerclient)));
}

FILE *f;
f=fopen("/home/fahed/Projets/sky-travel/src/client.txt","r");

if(f !=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",k.id,k.nom,k.prenom,k.adresse,k.date_naissance,k.cin,k.tel,k.log,k.pass,k.datecreation)!=EOF)
{
	if(strcmp(REFAGENT,k.id)==0)
		{
		gtk_widget_destroy(gestion_client);
		supprimer_client=create_supprimer_client();
		gtk_widget_show(supprimer_client);

		label_clientsupprimer=lookup_widget(supprimer_client,"label_clientsupprimer");
		gtk_label_set_text(GTK_LABEL(label_clientsupprimer),k.log);
	        }

}fclose(f);

}


}




void on_button_retourgestionclientsup_clicked (GtkWidget *buttonretourgestionclientsup, gpointer user_data)
{

GtkWidget *supprimer_client;
GtkTreeView *treeview_client;
GtkWidget *gestion_client;


supprimer_client=lookup_widget(buttonretourgestionclientsup,"supprimer_client");
gtk_widget_destroy(supprimer_client);

gestion_client = create_gestion_client(); 
gtk_widget_show (gestion_client);

treeview_client=lookup_widget(gestion_client,"treeview_client");
afficher_client(treeview_client);



}


void on_button_validersupprimerclient_clicked (GtkWidget *buttonvalidersupprimerclient, gpointer user_data)
{

GtkWidget *supprimer_client;
GtkTreeView *treeview_client;
GtkWidget *gestion_client;
GtkWidget *label_clientsupprimer;

client a;

label_clientsupprimer=lookup_widget(buttonvalidersupprimerclient,"label_clientsupprimer");
strcpy(a.log,gtk_label_get_text(GTK_LABEL(label_clientsupprimer)));


supprimer_client=lookup_widget(buttonvalidersupprimerclient,"supprimer_client");
supprimerclient(a);
gtk_widget_destroy(supprimer_client);


gestion_client=create_gestion_client();
gtk_widget_show(gestion_client);


treeview_client=lookup_widget(gestion_client,"treeview_client");
afficher_client(treeview_client);


}


void on_button_validermodifierclient_clicked (GtkWidget *buttonvalidermodifierclient, gpointer user_data)
{


GtkWidget *modifier_client;
GtkTreeView *treeview_client;
GtkWidget *gestion_client;

GtkWidget *label_idclient;
GtkWidget *entry_modifiernomclient;
GtkWidget *entry_modifierprenomclient;
GtkWidget *entry_modifieradresseclient;
GtkWidget *entry_modifierdatenaissanceclient;
GtkWidget *entry_modifiercinclient;
GtkWidget *entry_modifiertelclient;
GtkWidget *entry_modifierloginclient;
GtkWidget *entry_modifiermotdepasseclient;
GtkWidget *label_datecreationclient;

client a;

modifier_client=lookup_widget(buttonvalidermodifierclient,"modifier_client");

label_idclient=lookup_widget(buttonvalidermodifierclient,"label_idclient");
entry_modifiernomclient= lookup_widget(buttonvalidermodifierclient, "entry_modifiernomclient");
entry_modifierprenomclient= lookup_widget(buttonvalidermodifierclient, "entry_modifierprenomclient");
entry_modifieradresseclient= lookup_widget(buttonvalidermodifierclient, "entry_modifieradresseclient");
entry_modifierdatenaissanceclient= lookup_widget(buttonvalidermodifierclient, "entry_modifierdatenaissanceclient");
entry_modifiercinclient= lookup_widget(buttonvalidermodifierclient, "entry_modifiercinclient");
entry_modifiertelclient= lookup_widget(buttonvalidermodifierclient, "entry_modifiertelclient");
entry_modifierloginclient= lookup_widget(buttonvalidermodifierclient, "entry_modifierloginclient");
entry_modifiermotdepasseclient= lookup_widget(buttonvalidermodifierclient, "entry_modifiermotdepasseclient");
label_datecreationclient= lookup_widget(buttonvalidermodifierclient, "label_datecreationclient");

strcpy(a.id,gtk_label_get_text(GTK_LABEL(label_idclient)));
strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(entry_modifiernomclient)));
strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(entry_modifierprenomclient)));
strcpy(a.adresse,gtk_entry_get_text(GTK_ENTRY(entry_modifieradresseclient)));
strcpy(a.date_naissance,gtk_entry_get_text(GTK_ENTRY(entry_modifierdatenaissanceclient)));
strcpy(a.cin,gtk_entry_get_text(GTK_ENTRY(entry_modifiercinclient)));
strcpy(a.tel,gtk_entry_get_text(GTK_ENTRY(entry_modifiertelclient)));
strcpy(a.log,gtk_entry_get_text(GTK_ENTRY(entry_modifierloginclient)));
strcpy(a.pass,gtk_entry_get_text(GTK_ENTRY(entry_modifiermotdepasseclient)));
strcpy(a.datecreation,gtk_label_get_text(GTK_LABEL(label_datecreationclient)));

gtk_widget_destroy(modifier_client);

gestion_client=create_gestion_client();
gtk_widget_show(gestion_client);

modifierclient(a);

treeview_client=lookup_widget(gestion_client,"treeview_client");
afficher_client(treeview_client);



}


void on_button_retourgestionclientmod_clicked (GtkWidget *buttonretourgestionclientmod, gpointer user_data)
{

GtkWidget *modifier_client;
GtkTreeView *treeview_client;
GtkWidget *gestion_client;


modifier_client=lookup_widget(buttonretourgestionclientmod,"modifier_client");
gtk_widget_destroy(modifier_client);

gestion_client = create_gestion_client(); 
gtk_widget_show (gestion_client);

treeview_client=lookup_widget(gestion_client,"treeview_client");
afficher_client(treeview_client);




}


void on_button_modifierclient_clicked (GtkWidget *buttonmodifierclient, gpointer user_data)
{

GtkWidget *modifier_client;
GtkWidget *gestion_client;
GtkWidget *combobox_idmodifiersupprimerclient;
GtkWidget *label_idclient;
GtkWidget *entry_modifiernomclient;
GtkWidget *entry_modifierprenomclient;
GtkWidget *entry_modifieradresseclient;
GtkWidget *entry_modifierdatenaissanceclient;
GtkWidget *entry_modifiercinclient;
GtkWidget *entry_modifiertelclient;
GtkWidget *entry_modifierloginclient;
GtkWidget *entry_modifiermotdepasseclient;
GtkWidget *label_datecreationclient;


char REFAGENT[50];
agent k;

gestion_client=lookup_widget(buttonmodifierclient,"gestion_client");


combobox_idmodifiersupprimerclient=lookup_widget(buttonmodifierclient,"combobox_idmodifiersupprimerclient");
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_idmodifiersupprimerclient))!=0)
{
strcpy(REFAGENT,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_idmodifiersupprimerclient)));
}

FILE *f;
f=fopen("/home/fahed/Projets/sky-travel/src/client.txt","r");

if(f !=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",k.id,k.nom,k.prenom,k.adresse,k.date_naissance,k.cin,k.tel,k.log,k.pass,k.datecreation)!=EOF)
{
	if(strcmp(REFAGENT,k.id)==0)
		{
		gtk_widget_destroy(gestion_client);
		modifier_client=create_modifier_client();
		gtk_widget_show(modifier_client);


label_idclient=lookup_widget(modifier_client,"label_idclient");
entry_modifiernomclient= lookup_widget(modifier_client, "entry_modifiernomclient");
entry_modifierprenomclient= lookup_widget(modifier_client, "entry_modifierprenomclient");
entry_modifieradresseclient= lookup_widget(modifier_client, "entry_modifieradresseclient");
entry_modifierdatenaissanceclient= lookup_widget(modifier_client, "entry_modifierdatenaissanceclient");
entry_modifiercinclient= lookup_widget(modifier_client, "entry_modifiercinclient");
entry_modifiertelclient= lookup_widget(modifier_client, "entry_modifiertelclient");
entry_modifierloginclient= lookup_widget(modifier_client, "entry_modifierloginclient");
entry_modifiermotdepasseclient= lookup_widget(modifier_client, "entry_modifiermotdepasseclient");
label_datecreationclient= lookup_widget(modifier_client, "label_datecreationclient");

gtk_label_set_text(GTK_LABEL(label_idclient),k.id);
gtk_entry_set_text(GTK_ENTRY(entry_modifiernomclient),k.nom);
gtk_entry_set_text(GTK_ENTRY(entry_modifierprenomclient),k.prenom);
gtk_entry_set_text(GTK_ENTRY(entry_modifieradresseclient),k.adresse);
gtk_entry_set_text(GTK_ENTRY(entry_modifierdatenaissanceclient),k.date_naissance);
gtk_entry_set_text(GTK_ENTRY(entry_modifiercinclient),k.cin);
gtk_entry_set_text(GTK_ENTRY(entry_modifiertelclient),k.tel);
gtk_entry_set_text(GTK_ENTRY(entry_modifierloginclient),k.log);
gtk_entry_set_text(GTK_ENTRY(entry_modifiermotdepasseclient),k.pass);
gtk_label_set_text(GTK_LABEL(label_datecreationclient),k.datecreation);
		
	        }

}fclose(f);

}




}


void on_button_gestionvols_clicked (GtkWidget *buttongestionvols, gpointer user_data)
{
GtkWidget *gestion_prestations_vols;
GtkWidget *gestion_des_prestations;
GtkWidget *treeview_vol;

gestion_des_prestations=lookup_widget(buttongestionvols,"gestion_des_prestations");
gtk_widget_destroy(gestion_des_prestations);
gestion_prestations_vols=create_gestion_prestations_vols();
gtk_widget_show(gestion_prestations_vols);

treeview_vol=lookup_widget(gestion_prestations_vols,"treeview_vol");
afficher_vol(treeview_vol);




}


void on_button_retourgestionprestationvol_clicked (GtkWidget *buttonretourgestionprestationvol, gpointer user_data)
{
GtkWidget *gestion_prestations_vols;
GtkWidget *gestion_des_prestations;


gestion_prestations_vols=lookup_widget(buttonretourgestionprestationvol,"gestion_prestations_vols");
gtk_widget_destroy(gestion_prestations_vols);

gestion_des_prestations=create_gestion_des_prestations();
gtk_widget_show(gestion_des_prestations);




}

enum
{
	ID,
	DEPART,
	DESTINATION,
	DATEDEPART,
	PRIX,
	COLUMNS
};

void on_button_modifiervol_clicked (GtkWidget *buttonmodifiervol, gpointer user_data)
{

GtkWidget *gestion_prestations_vols;
GtkWidget *modifier_vol;

GtkWidget *label_idmodifievol;

GtkWidget *entry_modifierdepartvol;
GtkWidget *entry_modifierdestinationvol;
GtkWidget *entry_modifierdatedepartvol;
GtkWidget *entry_modifierprixvol;

GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;
GtkWidget *treeview_vol;


gestion_prestations_vols=lookup_widget(buttonmodifiervol,"gestion_prestations_vols");

treeview_vol=lookup_widget(gestion_prestations_vols,"treeview_vol");

selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview_vol));
if(gtk_tree_selection_get_selected(selection, &model, &iter))
{

gchar *id;
gchar *depart;
gchar *destination;
gchar *date_depart;
gchar *prix;

gtk_tree_model_get(model, &iter, ID, &id, -1);
gtk_tree_model_get(model, &iter, DEPART, &depart, -1);
gtk_tree_model_get(model, &iter, DESTINATION, &destination, -1);
gtk_tree_model_get(model, &iter, DATEDEPART, &date_depart, -1);
gtk_tree_model_get(model, &iter, PRIX, &prix, -1);

gtk_widget_destroy(gestion_prestations_vols);

modifier_vol=create_modifier_vol();
gtk_widget_show(modifier_vol);

		label_idmodifievol=lookup_widget(modifier_vol,"label_idmodifievol");
		entry_modifierdepartvol= lookup_widget(modifier_vol, "entry_modifierdepartvol");
		entry_modifierdestinationvol= lookup_widget(modifier_vol, "entry_modifierdestinationvol");
		entry_modifierdatedepartvol= lookup_widget(modifier_vol, "entry_modifierdatedepartvol");
		entry_modifierprixvol= lookup_widget(modifier_vol, "entry_modifierprixvol");

		gtk_label_set_text(GTK_LABEL(label_idmodifievol),id);
		gtk_entry_set_text(GTK_ENTRY(entry_modifierdepartvol),depart);
		gtk_entry_set_text(GTK_ENTRY(entry_modifierdestinationvol),destination);
		gtk_entry_set_text(GTK_ENTRY(entry_modifierdatedepartvol),date_depart);
		gtk_entry_set_text(GTK_ENTRY(entry_modifierprixvol),prix);


}


}


void on_button_retourgestiovolajout_clicked (GtkWidget *buttonretourgestiovolajout, gpointer user_data)
{
GtkWidget *gestion_prestations_vols;
GtkWidget *ajout_vol;
GtkWidget *treeview_vol;

ajout_vol=lookup_widget(buttonretourgestiovolajout,"ajout_vol");
gtk_widget_destroy(ajout_vol);

gestion_prestations_vols=create_gestion_prestations_vols();
gtk_widget_show(gestion_prestations_vols);

treeview_vol=lookup_widget(gestion_prestations_vols,"treeview_vol");
afficher_vol(treeview_vol);

}


void on_button_ajoutvol_clicked (GtkWidget *buttonajoutvol, gpointer user_data)
{

GtkWidget *gestion_prestations_vols;
GtkWidget *ajout_vol;


gestion_prestations_vols=lookup_widget(buttonajoutvol,"gestion_prestations_vols");
gtk_widget_destroy(gestion_prestations_vols);

ajout_vol=create_ajout_vol();
gtk_widget_show(ajout_vol);




}


void on_button_validerajoutvol_clicked (GtkWidget *buttonvaliderajoutvol, gpointer user_data)
{
////////////////////////////////////////////////////////////****************************************************//////////////////////////////
GtkWidget *gestion_prestations_vols;
GtkWidget *ajout_vol;
GtkWidget *treeview_vol;

GtkWidget *entry_ajoutdeaprtvol;
GtkWidget *entry_ajoutdestinationvol;
GtkWidget *entry_ajoutprixvol;

GtkWidget *calendar_vol;

char jour[50];
char mois[50];
char annee[50];

int *jour1;
int mois1;
int *annee1;

vol v;

ajout_vol=lookup_widget(buttonvaliderajoutvol,"ajout_vol");

entry_ajoutdeaprtvol=lookup_widget(buttonvaliderajoutvol,"entry_ajoutdeaprtvol");
entry_ajoutdestinationvol=lookup_widget(buttonvaliderajoutvol,"entry_ajoutdestinationvol");
entry_ajoutprixvol=lookup_widget(buttonvaliderajoutvol,"entry_ajoutprixvol");

calendar_vol=lookup_widget(buttonvaliderajoutvol,"calendar_vol");

gtk_calendar_get_date(calendar_vol,&annee1,&mois1,&jour1);

mois1++;
sprintf(jour,"%u", jour1);
sprintf(mois,"%u", mois1);
sprintf(annee,"%u", annee1);

	strcat(v.date_depart,jour);
	strcat(v.date_depart,"/");
	strcat(v.date_depart,mois);
        strcat(v.date_depart,"/");
	strcat(v.date_depart,annee);

strcpy(v.depart,gtk_entry_get_text(GTK_ENTRY(entry_ajoutdeaprtvol)));
strcpy(v.destination,gtk_entry_get_text(GTK_ENTRY(entry_ajoutdestinationvol)));
strcpy(v.prix,gtk_entry_get_text(GTK_ENTRY(entry_ajoutprixvol)));

ajouter_vol(v);
gtk_widget_destroy(ajout_vol);
gestion_prestations_vols=create_gestion_prestations_vols();
gtk_widget_show(gestion_prestations_vols);

treeview_vol=lookup_widget(gestion_prestations_vols,"treeview_vol");
afficher_vol(treeview_vol);

}


void on_button_rechercheidvol_clicked (GtkWidget *buttonrechercheidvol, gpointer user_data)
{

GtkWidget *combobox_modifiersupprimervol;

char ref[50][50];
int i,nbr;

combobox_modifiersupprimervol=lookup_widget(buttonrechercheidvol,"combobox_modifiersupprimervol");
nbr=liste_vol(ref);
for(i=0;i<nbr;i++)
{

gtk_combo_box_append_text(GTK_COMBO_BOX(combobox_modifiersupprimervol),_(ref[i]));

}

}


void on_button_retourgestionvolsupp_clicked (GtkWidget *buttonretourgestionvolsupp, gpointer user_data)
{

GtkWidget *gestion_prestations_vols;
GtkWidget *supprimer_vol;
GtkWidget *treeview_vol;

supprimer_vol=lookup_widget(buttonretourgestionvolsupp,"supprimer_vol");
gtk_widget_destroy(supprimer_vol);

gestion_prestations_vols=create_gestion_prestations_vols();
gtk_widget_show(gestion_prestations_vols);

treeview_vol=lookup_widget(gestion_prestations_vols,"treeview_vol");
afficher_vol(treeview_vol);




}


void on_button_supprimervol_clicked (GtkWidget *buttonsupprimervol, gpointer user_data)
{
GtkWidget *gestion_prestations_vols;
GtkWidget *supprimer_vol;

GtkWidget *combobox_modifiersupprimervol;
GtkWidget *label_volsupprimer;

char REFVOl[50];

vol k;

gestion_prestations_vols=lookup_widget(buttonsupprimervol,"gestion_prestations_vols");

combobox_modifiersupprimervol=lookup_widget(buttonsupprimervol,"combobox_modifiersupprimervol");
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifiersupprimervol))!=0)
{
strcpy(REFVOl,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_modifiersupprimervol)));
}

FILE *f;
f=fopen("/home/fahed/Projets/sky-travel/src/vol.txt","r");

if(f !=NULL){
while(fscanf(f,"%s %s %s %s %s \n",k.id,k.depart,k.destination,k.date_depart,k.prix)!=EOF)
{
	if(strcmp(REFVOl,k.id)==0)
		{
		gtk_widget_destroy(gestion_prestations_vols);
		supprimer_vol=create_supprimer_vol();
		gtk_widget_show(supprimer_vol);

		label_volsupprimer=lookup_widget(supprimer_vol,"label_volsupprimer");
		gtk_label_set_text(GTK_LABEL(label_volsupprimer),k.id);
	        }

}fclose(f);

}



}


void on_button_validersupprimervol_clicked  (GtkWidget *buttonvalidersupprimervol, gpointer user_data)
{
GtkWidget *gestion_prestations_vols;
GtkWidget *supprimer_vol;

GtkTreeView *treeview_vol;
GtkWidget *label_volsupprimer;

vol a;

label_volsupprimer=lookup_widget(buttonvalidersupprimervol,"label_volsupprimer");
strcpy(a.id,gtk_label_get_text(GTK_LABEL(label_volsupprimer)));


supprimer_vol=lookup_widget(buttonvalidersupprimervol,"supprimer_vol");
gtk_widget_destroy(supprimer_vol);

gestion_prestations_vols=create_gestion_prestations_vols();
gtk_widget_show(gestion_prestations_vols);

supprimervol(a);

treeview_vol=lookup_widget(gestion_prestations_vols,"treeview_vol");
afficher_vol(treeview_vol);




}


void on_button_retourmodifiergestionvol_clicked (GtkWidget *buttonretourmodifiergestionvol, gpointer user_data)
{

GtkWidget *gestion_prestations_vols;
GtkWidget *modifier_vol;
GtkWidget *treeview_vol;

modifier_vol=lookup_widget(buttonretourmodifiergestionvol,"modifier_vol");
gtk_widget_destroy(modifier_vol);

gestion_prestations_vols=create_gestion_prestations_vols();
gtk_widget_show(gestion_prestations_vols);

treeview_vol=lookup_widget(gestion_prestations_vols,"treeview_vol");
afficher_vol(treeview_vol);


}


void on_button_validermodifiervol_clicked   (GtkWidget *buttonvalidermodifiervol, gpointer user_data)
{

GtkWidget *modifier_vol;
GtkTreeView *treeview_vol;
GtkWidget *gestion_prestations_vols;

GtkWidget *label_idmodifievol;

GtkWidget *entry_modifierdepartvol;
GtkWidget *entry_modifierdestinationvol;
GtkWidget *entry_modifierdatedepartvol;
GtkWidget *entry_modifierprixvol;

vol a;

modifier_vol=lookup_widget(buttonvalidermodifiervol,"modifier_vol");

label_idmodifievol=lookup_widget(buttonvalidermodifiervol,"label_idmodifievol");
entry_modifierdepartvol= lookup_widget(buttonvalidermodifiervol, "entry_modifierdepartvol");
entry_modifierdestinationvol= lookup_widget(buttonvalidermodifiervol, "entry_modifierdestinationvol");
entry_modifierdatedepartvol= lookup_widget(buttonvalidermodifiervol, "entry_modifierdatedepartvol");
entry_modifierprixvol= lookup_widget(buttonvalidermodifiervol, "entry_modifierprixvol");

strcpy(a.id,gtk_label_get_text(GTK_LABEL(label_idmodifievol)));
strcpy(a.depart,gtk_entry_get_text(GTK_ENTRY(entry_modifierdepartvol)));
strcpy(a.destination,gtk_entry_get_text(GTK_ENTRY(entry_modifierdestinationvol)));
strcpy(a.date_depart,gtk_entry_get_text(GTK_ENTRY(entry_modifierdatedepartvol)));
strcpy(a.prix,gtk_entry_get_text(GTK_ENTRY(entry_modifierprixvol)));

gtk_widget_destroy(modifier_vol);

gestion_prestations_vols=create_gestion_prestations_vols();
gtk_widget_show(gestion_prestations_vols);

modifiervol(a);

treeview_vol=lookup_widget(gestion_prestations_vols,"treeview_vol");
afficher_vol(treeview_vol);




}


void on_button_gestionreservation_clicked (GtkWidget *buttongestionreservation, gpointer user_data)
{
GtkWidget *client;
GtkWidget *reservation;


client=lookup_widget(buttongestionreservation,"client");
gtk_widget_destroy(client);

reservation=create_reservation();
gtk_widget_show(reservation);


}


void on_button_retourclientreservation_clicked (GtkWidget *buttonretourclientreservation, gpointer user_data)
{


GtkWidget *client;
GtkWidget *reservation;


reservation=lookup_widget(buttonretourclientreservation,"reservation");
gtk_widget_destroy(reservation);

client=create_client();
gtk_widget_show(client);


}


void on_buttongestionvols_clicked (GtkWidget *objet, gpointer user_data)
{
GtkWidget *interfacewindow1=lookup_widget(objet,"reservation");
GtkWidget *interfacewindow2=lookup_widget(objet,"reservationvol");
gtk_widget_destroy(interfacewindow1);
interfacewindow2=create_reservationvol();
gtk_widget_show(interfacewindow2);

GtkWidget *tree=lookup_widget(interfacewindow2,"treeview11");
showtreevols(tree);

}


void
on_RETOURvols_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *interfacewindow1=lookup_widget(button,"reservation");
GtkWidget *interfacewindow2=lookup_widget(button,"reservationvol");
gtk_widget_destroy(interfacewindow2);
interfacewindow1=create_reservation();
gtk_widget_show(interfacewindow1);


}


void
on_refreshgestionvoiture_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *combo=lookup_widget(button,"comboboxvols");
FILE *f=fopen("vols.txt","a+");
char cle[30];char n[30];
if (f!= NULL) while (fscanf(f,"%s %s \n",cle,n)!= EOF) { 
gtk_combo_box_append_text(GTK_COMBO_BOX(combo),cle);}
fclose(f);

}


void
on_validervols_enter                   (GtkButton       *button,
                                        gpointer         user_data)
{
char Bloc[50];
GtkWidget *combo=lookup_widget(button,"comboboxvols");
strcpy(Bloc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
ajoutercodevo(Bloc);
supprimecodevo(Bloc);
GtkWidget *interfacewindow3;
GtkWidget *interfacewindow2=lookup_widget(button,"reservationvol");
gtk_widget_destroy(interfacewindow2);
interfacewindow3=create_code_promotionnel();
gtk_widget_show(interfacewindow3);



}


void
on_button_retourresvol_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_validercode_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *labelx=lookup_widget(button,"error");
GtkWidget *name=lookup_widget(button,"entrycode");

GtkWidget *interfacewindow3=lookup_widget(button,"code_promotionnel");

GtkWidget *reservation;

char *nomdentre=gtk_entry_get_text(GTK_ENTRY(name));

if (verifiercode(nomdentre)==0)

	{gtk_label_set_text(GTK_LABEL(labelx),"wrong code");}
else if (verifiercode(nomdentre)==1) 
{
gtk_widget_destroy(interfacewindow3);

reservation=create_reservation();
gtk_widget_show(reservation);
}


}


void
on_buttongestionvoiture_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *interfacewindow1=lookup_widget(button,"reservation");
GtkWidget *interfacewindow4;


gtk_widget_destroy(interfacewindow1);
interfacewindow4=create_reservationvoiture();
gtk_widget_show(interfacewindow4);

}


void
on_retourlstv_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *interfacewindow1;
GtkWidget *interfacewindow4=lookup_widget(button,"reservationvoiture");
gtk_widget_destroy(interfacewindow4);
interfacewindow1=create_reservation();
gtk_widget_show(interfacewindow1);

}


void
on_recherchelstv_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tree=lookup_widget(button,"treeviewlstv");
GtkWidget *combo=lookup_widget(button,"comboboxlst");
GtkWidget *namev=lookup_widget(button,"entrylstv");
char *nomdentrev=gtk_entry_get_text(GTK_ENTRY(namev));

verifiercodev(nomdentrev);
showtreev(tree);
FILE *f=fopen("tem.txt","a+");
char cle[30];char n[30];char m[30];char k[30];
if (f!= NULL) while (fscanf(f,"%s %s %s %s \n",cle,n,m,k)!= EOF) { 
gtk_combo_box_append_text(GTK_COMBO_BOX(combo),n);}
remove("tem.txt");




}


void
on_validerlstv_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
char a2[100];
char b2[100];
char c2[100];
char d2[100];
char Bloc[50];
GtkWidget *interfacewindow3;
GtkWidget *interfacewindow4=lookup_widget(button,"reservationvoiture");

GtkWidget *combo=lookup_widget(button,"comboboxlst");
GtkWidget *name=lookup_widget(button,"entryfini");
char *nomdentre=gtk_entry_get_text(GTK_ENTRY(name));
strcpy(Bloc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo)));
FILE *a;
FILE *b;

a=fopen("voitures.txt","r");
b=fopen("olll.txt","a+");
if(a !=NULL) {

while (fscanf(a,"%s %s %s %s \n",a2,b2,c2,d2)!=EOF)
{if ((strcmp(Bloc,b2)==0))

fprintf(b,"%s %s %s %s \n",nomdentre,b2,c2,d2);

else if ((strcmp(Bloc,b2)!=0)) fprintf(b,"%s %s %s %s \n",a2,b2,c2,d2);
}

}
fclose(a);
fclose(b);
remove("voitures.txt");
rename("olll.txt","voitures.txt");
gtk_widget_destroy(interfacewindow4);
interfacewindow3=create_code_promotionnel();
gtk_widget_show(interfacewindow3);



}


void on_button_retouraccueilvisiteur_clicked (GtkWidget *buttonretouraccueilvisiteur, gpointer user_data)
{

GtkWidget *accueil;
GtkWidget *visiteur;


visiteur=lookup_widget(buttonretouraccueilvisiteur,"visiteur");
gtk_widget_destroy(visiteur);
accueil=create_accueil();
gtk_widget_show(accueil);

}

