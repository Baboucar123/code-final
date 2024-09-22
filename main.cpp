#include <iostream>
#include "Client.h"
#include "Compte.h"

using namespace std;

void afficherMenu(Compte& compte, Client& client, Compte& autreCompte);

int main() {
    int code_secret;

    // Création de deux clients avec leur code secret respectif
    Client client1("CIN12345", "Jean", "Dupont", "0612345678", 1234); // Code 1234 pour Jean Dupont
    Compte compte1(123456, 5000.0, client1); // Compte pour Jean Dupont

    Client client2("CIN67890", "Marie", "Durand", "0698765432", 5678); // Code 5678 pour Marie Durand
    Compte compte2(654321, 3000.0, client2); // Compte pour Marie Durand

    cout << "Bienvenue dans notre distributeur LCL !" << endl;

    bool fin = false;  // Pour arrêter le programme après avoir terminé avec les deux clients

    while (!fin) {
        cout << "\nVeuillez inserer votre carte bancaire." << endl;
        cout << "Saisissez votre code secret a quatre chiffres : " << endl;
        cin >> code_secret;

        // Vérification du code secret du client1 ou du client2
        if (client1.verifierCodeSecret(code_secret)) {
            cout << "Code accepte. Bienvenue " << client1.getNom() << " " << client1.getPrenom() << " !" << endl;
            afficherMenu(compte1, client1, compte2);  // Afficher le menu des opérations pour client1
        } else if (client2.verifierCodeSecret(code_secret)) {
            cout << "Code accepte. Bienvenue " << client2.getNom() << " " << client2.getPrenom() << " !" << endl;
            afficherMenu(compte2, client2, compte1);  // Afficher le menu des opérations pour client2
        } else {
            cout << "Code incorrect. Veuillez réessayer." << endl;
        }

        // Demander à l'utilisateur s'il souhaite quitter ou continuer
        char quitter;
        cout << "\nSouhaitez-vous quitter ? (o/n) : ";
        cin >> quitter;
        if (quitter == 'o' || quitter == 'O') {
            fin = true;
        }
    }

    cout << "Merci de votre visite. A la prochaine !" << endl;
    return 0;
}

// Fonction pour afficher le menu des opérations
void afficherMenu(Compte& compte, Client& client, Compte& autreCompte) {
    int choix;
    double montant;

    do {
        cout << "\nVeuillez choisir une operation : " << endl;
        cout << "1. Debiter le compte" << endl;
        cout << "2. Crediter le compte" << endl;
        cout << "3. Virement vers un autre compte" << endl;
        cout << "4. Consulter votre solde" << endl;
        cout << "5. Consulter votre RIB" << endl;
        cout << "6. Commander un chequier" << endl;
        cout << "7. Quitter le compte" << endl;
        cin >> choix;

        switch (choix) {
            case 1: // Débiter le compte
                cout << "Montant a debiter : ";
                cin >> montant;
                compte.debiter(montant);
                break;

            case 2: // Créditer le compte
                cout << "Montant a crediter : ";
                cin >> montant;
                compte.crediter(montant);
                break;

            case 3: // Virement vers un autre compte
                cout << "Montant du virement : ";
                cin >> montant;
                compte.virement(autreCompte, montant);  // Virement du compte actuel vers l'autre compte
                break;

            case 4: // Consulter le solde
                compte.consulter();
                break;

            case 5: // Consulter le RIB
                compte.afficherRIB();
                break;

            case 6: // Commander un chéquier
                cout << "Chequier commande." << endl;
                break;

            case 7: // Quitter le compte
                cout << "Deconnexion du compte de " << client.getNom() << " " << client.getPrenom() << "." << endl;
                break;

            default:
                cout << "Choix non valide." << endl;
        }
    } while (choix != 7);  // Continue tant que l'utilisateur n'a pas choisi de quitter le compte
}