#ifndef RESERVATION_H_INCLUDED
#define RESERVATION_H_INCLUDED

#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
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

struct wati
{
	char jour[20];
	int num_jour;
	char mois[20];
	int annee;
	int seconde;
	int minute;
	int heure;

};
typedef struct wati wa;

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
char date_naissance[100];
char cin[100];
char tel[100];
char log[50];
char pass[50];
char datecreation[100];

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


void ajouter_agent(agent p);

void ajouter_voiture(voiture v);

void ajouter_evaluation(evaluation e);

void ajouter_client(client c);

void ajouter_vol(vol v);

void supprimerclient(client a);

void modifierclient(client a);

#endif 
