#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "voiture.h"

#define MAX_VOITURES 100

int main() {
    Voiture voitures[MAX_VOITURES];
    int n = 0;
    int choix;

    charger_donnees(voitures, &n);

    do {
        afficher_menu_principal();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                if (n < MAX_VOITURES) {
                    ajouter_voiture(voitures, &n);
                } else {
                    printf("Capacité maximale atteinte.\n");
                }
                break;
            case 2:
                supprimer_voiture(voitures, &n);
                break;
            case 3: {
                char marque_recherchee[50];
                scanf("%s", marque_recherchee);
                rechercher_par_marque(marque_recherchee, voitures, n);
                break;
            }
            case 4: {
                int disponibilite;
                scanf("%d", &disponibilite);
                rechercher_par_disponibilite(disponibilite, voitures, n);
                break;
            }
            case 5:
                trier_par_marque(voitures, n);
                break;
            case 6:
                trier_par_prix_location(voitures, n);
                break;
            case 7:
                sauvegarder_donnees(voitures, n);
                break;
            case 8:
                charger_donnees(voitures, &n);
                break;
            case 9:
                printf("À bientôt !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 9);

    sauvegarder_donnees(voitures, n);

    return 0;
}
