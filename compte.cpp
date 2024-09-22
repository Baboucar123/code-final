#include <iostream>
#include "Compte.h"

using namespace std;

Compte::Compte(int numero, double solde, Client proprietaire)
    : numeroCompte(numero), solde(solde), proprietaire(proprietaire) {}

void Compte::consulter() const {
    cout << "Solde du compte : " << solde << " euros" << endl;
}

void Compte::debiter(double montant) {
    if (montant > solde) {
        cout << "Fonds insuffisants." << endl;
    } else {
        solde -= montant;
        cout << "Compte debite de " << montant << " euros." << endl;
    }
}

void Compte::crediter(double montant) {
    solde += montant;
    cout << "Compte credite de " << montant << " euros." << endl;
}

void Compte::virement(Compte &autreCompte, double montant) {
    if (montant > solde) {
        cout << "Fonds insuffisants pour effectuer le virement." << endl;
    } else {
        solde -= montant;
        autreCompte.crediter(montant);
        cout << "Virement de " << montant << " euros effectue vers le compte " << autreCompte.numeroCompte << endl;
    }
}

void Compte::afficherRIB() const {
    cout << "RIB : " << numeroCompte << endl;
    cout << "Propriétaire : " << proprietaire.getNom() << " " << proprietaire.getPrenom() << endl;
}
