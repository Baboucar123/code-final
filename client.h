#ifndef CLIENT_H
#define CLIENT_H

#include <string>
using namespace std;

class Client {
private:
    string CIN;
    string nom;
    string prenom;
    string telephone;
    int codeSecret;  // Nouveau : Code secret à 4 chiffres

public:
    Client(string c, string n, string p, string t, int code);
    string getNom() const;
    string getPrenom() const;
    string getCIN() const;
    string getTelephone() const;
    bool verifierCodeSecret(int code) const;  // Méthode pour vérifier le code secret
    void afficherIdentite() const;
};

#endif
