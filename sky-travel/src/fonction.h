#ifndef RESERVATION_H_INCLUDED
#define RESERVATION_H_INCLUDED

#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
struct agent
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

};
typedef struct agent agent;

struct voiture
{

char id[30];
char marque[50];
char modele[50];
char matricule[1900];
char prix[50];

};
typedef struct voiture voiture;

struct evaluation
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

};
typedef struct evaluation evaluation;

struct client
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

};
typedef struct client client;

struct vol
{

char id[30];
char depart[50];
char destination[50];
char date_depart[400];
char prix[50];

};
typedef struct vol vol;

int verifier (char log1[20],char pass1[20]);

int liste_agent (char ref[50][50]);
int liste_voiture (char ref[50][50]);
int liste_evaluation (char ref[50][50]);
int liste_client (char ref[50][50]);
int liste_vol (char ref[50][50]);
void supprimeragent(agent a);
void supprimervoiture(voiture a);
void supprimerevaluation(evaluation a);
void supprimervol(vol a);

void modifieragent(agent a);
void modifiervoiture(voiture a);
void modifiervol(vol a);
void modifierevaluation(evaluation e);
void afficher_client(GtkTreeView *liste);
#endif 
