#ifndef BDD_H
#define BDD_H

#include <iostream>
#include <string>
#include "ListeRecursif.h"
#include "Personne.h"

using namespace std;


class BDD : protected Liste<Personne*> {
public:
    void ajouter(Personne* p);

    void afficheContenuBDD();
};

#endif // BDD_H
