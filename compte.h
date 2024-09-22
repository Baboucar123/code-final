#ifndef COMPTE_H
#define COMPTE_H

#include "Client.h"

class Compte {
private:
    int numeroCompte;
    double solde;
    Client proprietaire;

public:
    Compte(int numero, double solde, Client proprietaire);
    void consulter() const;
    void debiter(double montant);
    void crediter(double montant);
    void virement(Compte &autreCompte, double montant);
    void afficherRIB() const;
};

#endif
