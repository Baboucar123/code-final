#include <iostream>
#include "Client.h"

using namespace std;

Client::Client(string c, string n, string p, string t, int code)
    : CIN(c), nom(n), prenom(p), telephone(t), codeSecret(code) {}

string Client::getNom() const {
    return nom;
}

string Client::getPrenom() const {
    return prenom;
}

string Client::getCIN() const {
    return CIN;
}

string Client::getTelephone() const {
    return telephone;
}

// Nouveau : Vérifie si le code secret correspond
bool Client::verifierCodeSecret(int code) const {
    return code == codeSecret;
}

void Client::afficherIdentite() const {
    cout << "CIN: " << CIN << endl;
    cout << "Nom: " << nom << endl;
    cout << "Prenom: " << prenom << endl;
    cout << "Telephone: " << telephone << endl;
}
