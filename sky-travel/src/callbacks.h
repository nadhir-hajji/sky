#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


void on_button_visiteur_simple_clicked (GtkWidget *buttonvisiteur, gpointer user_data);

void on_button_connecter_clicked (GtkWidget *buttonconnecter, gpointer user_data);

void on_button_inscription_clicked (GtkWidget *buttoninscription, gpointer user_data);

void on_button_connecter_aac_clicked (GtkWidget *buttonconnecteraac, gpointer user_data);

void on_button_retouraccueil_clicked (GtkWidget *buttonretouraccueil, gpointer user_data);

void on_button_validerinsciptionclient_clicked (GtkWidget *buttonvalidinscriclient, gpointer user_data);

void on_button_retourauthentificationinscri_clicked (GtkWidget *buttonretourautheninscri, gpointer user_data);

void on_button_gestionagents_clicked (GtkWidget *buttongestionagent, gpointer user_data);

void on_button_retourauthentification_clicked (GtkWidget *buttonretourauthetif, gpointer user_data);

void on_button_ajoutagent_clicked (GtkWidget *buttonajoutagent, gpointer user_data);

void on_button_modifieragent_clicked (GtkWidget *buttonmodifieragent, gpointer user_data);

void on_button_supprimeragent_clicked (GtkWidget *buttonsupprimeragent, gpointer user_data);

void on_button_retouradmin_clicked (GtkWidget *buttonretouradmin, gpointer user_data);

void on_button_retourgestionagent_clicked (GtkWidget *buttonretourgestionagent, gpointer user_data);

void on_button_validerajoutagent_clicked (GtkWidget *buttonvaliderajoutagent, gpointer user_data);

void on_button_validermodifieragent_clicked (GtkWidget *buttonvalidermodifieragent, gpointer user_data);

void on_button_validersupprimeragent_clicked (GtkWidget *buttonvalidersupprimeragent, gpointer user_data);

void on_button_retourgestionagentsup_clicked (GtkWidget *buttonretourgestionagentsup, gpointer user_data);

void on_button_retouraut_clicked (GtkWidget *buttonretouraut, gpointer user_data);

void on_button_retourau_clicked (GtkWidget *buttonretourau, gpointer user_data);

void on_button_retourgestionagentmod_clicked (GtkWidget *buttonretourgestionagentmod, gpointer user_data);

void on_button_rechercheidagent_clicked (GtkWidget *button_rechercheidagent, gpointer user_data);

void on_button_gestionprestations_clicked   (GtkWidget *buttongestionprestations, gpointer user_data);

void on_button_retouragentprestations_clicked (GtkWidget *buttonretouragentprestations, gpointer user_data);

void on_button_retourgestionprestationvoiture_clicked (GtkWidget *buttonretourgestionprestationvoiture, gpointer user_data);

void on_button_ajoutvoiture_clicked (GtkWidget *buttonajoutvoiture, gpointer user_data);

void on_button_supprimervoiture_clicked (GtkWidget *buttonsupprimervoiture, gpointer user_data);

void on_button_modifiervoiture_clicked (GtkWidget *buttonmodifiervoiture, gpointer user_data);

void on_button_rechercheidvoiture_clicked (GtkWidget *buttonrechercheidvoiture, gpointer user_data);

void on_button_gestionvoitures_clicked (GtkWidget *buttongestionvoitures, gpointer user_data);

void on_button_lienfacebook_clicked (GtkWidget *buttonlienfacebook, gpointer user_data);

void on_button_validerajoutvoiture_clicked (GtkWidget *buttonvaliderajoutvoiture, gpointer user_data);

void on_button_retourajoutgestionvoiture_clicked (GtkWidget *buttonretourajoutgestionvoiture, gpointer user_data);

void on_button_retourgestionvoituresup_clicked (GtkWidget *buttonretourgestionvoituresup, gpointer user_data);

void on_button_validersupprimervoiture_clicked (GtkWidget *buttonvalidersupprimervoiture, gpointer user_data);

void on_button_retourmodifiergestionvoiture_clicked (GtkWidget *buttonretourmodifiergestionvoiture, gpointer user_data);

void on_button_validermodifiervoiture_clicked (GtkWidget *buttonvalidermodifiervoiture, gpointer user_data);

void on_button_retourevaluatioclient_clicked (GtkWidget *buttonretourevaluatioclient, gpointer user_data);

void on_button_ajoutevaluation_clicked (GtkWidget *buttonajoutevaluation, gpointer user_data);

void on_button_modifieravaluation_clicked (GtkWidget *buttonmodifieravaluation, gpointer user_data);

void on_button_supprimerevaluation_clicked  (GtkWidget *buttonsupprimerevaluation, gpointer user_data);

void on_button_idevaluation_clicked (GtkWidget *buttonidevaluation, gpointer user_data);

void on_button_gestionevaluation_clicked (GtkWidget *buttongestionevqluqtion, gpointer user_data);

void on_button_retourgestionevaluationajout_clicked (GtkWidget *buttonretourgestionevaluationajout, gpointer         user_data);

void on_button_validerajoutevaluation_clicked (GtkWidget *buttonvaliderajoutevaluation, gpointer user_data);

void on_button_retourgestionevaluationsup_clicked (GtkWidget *buttonretourgestionevaluationsup, gpointer user_data);

void on_button_validersupprimerevaluation_clicked (GtkWidget *buttonvalidersupprimerevaluation, gpointer user_data);

void on_button_retourgestionevaluationmodif_enter (GtkWidget *buttonretourgestionevaluationmodif, gpointer user_data);

void on_button_vaildermodifierevaluation_clicked (GtkWidget *buttonvaildermodifierevaluation, gpointer user_data);

void on_button_retourgestionevaluationmodif_clicked (GtkWidget *buttonretourgestionevaluationmodif, gpointer user_data);

void on_button_retourgestionclientclient_clicked (GtkWidget *buttonretourgestionclientclient, gpointer user_data);

void on_button_gestionclient_clicked (GtkWidget *buttongestionclient, gpointer user_data);

void on_button_ajouterclient_clicked (GtkWidget *buttonajouterclient, gpointer user_data);

void on_button_retourgestionclientajout_clicked (GtkWidget *buttonretourgestionclientajout, gpointer user_data);

void on_button_validerajoutclient_clicked (GtkWidget *buttonvaliderajoutclient,gpointer user_data);

void on_button_rechercheidclient_clicked (GtkWidget *buttonrechercheidclient,  gpointer user_data);

void on_button_supprimerclient_clicked (GtkWidget *buttonsupprimerclient, gpointer user_data);

void on_button_retourgestionclientsup_clicked (GtkWidget *buttonretourgestionclientsup, gpointer user_data);


void on_button_validersupprimerclient_clicked (GtkWidget *buttonvalidersupprimerclient, gpointer user_data);

void on_button_validermodifierclient_clicked (GtkWidget *buttonvalidermodifierclient, gpointer user_data);

void on_button_retourgestionclientmod_clicked (GtkWidget *buttonretourgestionclientmod, gpointer user_data);

void on_button_modifierclient_clicked (GtkWidget *buttonmodifierclient, gpointer user_data);

void on_button_gestionvols_clicked (GtkWidget *buttongestionvols, gpointer user_data);

void on_button_retourgestionprestationvol_clicked (GtkWidget *buttonretourgestionprestationvol, gpointer user_data);

void on_button_modifiervol_clicked (GtkWidget *buttonmodifiervol, gpointer user_data);

void on_button_retourgestiovolajout_clicked (GtkWidget *buttonretourgestiovolajout, gpointer user_data);

void on_button_ajoutvol_clicked (GtkWidget *buttonajoutvol, gpointer user_data);

void on_button_validerajoutvol_clicked (GtkWidget *buttonvaliderajoutvol, gpointer user_data);

void on_button_rechercheidvol_clicked (GtkWidget *buttonrechercheidvol, gpointer user_data);

void on_button_retourgestionvolsupp_clicked (GtkWidget *buttonretourgestionvolsupp, gpointer user_data);

void on_button_supprimervol_clicked (GtkWidget *buttonsupprimervol, gpointer user_data);

void on_button_validersupprimervol_clicked  (GtkWidget *buttonvalidersupprimervol, gpointer user_data);

void on_button_retourmodifiergestionvol_clicked (GtkWidget *buttonretourmodifiergestionvol, gpointer user_data);

void on_button_validermodifiervol_clicked   (GtkWidget *buttonvalidermodifiervol, gpointer user_data);

void on_button_gestionreservation_clicked (GtkWidget *buttongestionreservation, gpointer user_data);

void on_button_retourclientreservation_clicked (GtkWidget *button, gpointer user_data);

void on_buttongestionvols_clicked (GtkWidget *objet, gpointer user_data);

void
on_RETOURvols_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_refreshgestionvoiture_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_validervols_enter                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retourresvol_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_validercode_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttongestionvoiture_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_retourlstv_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_recherchelstv_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_validerlstv_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void on_button_retouraccueilvisiteur_clicked (GtkWidget *buttonretouraccueilvisiteur, gpointer user_data);
