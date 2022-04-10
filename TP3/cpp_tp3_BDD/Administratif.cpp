#include "header/Administratif.h"

void Administratif::affiche(){
    Personne::affiche();
    cout << "et je suis un personnel administratif" << endl;
}

void Administratif::profession(){
    Personne::qualite();
    cout << " en tant que " << _fonction <<  " et mon bureau est le " << _bureau << endl;
}

void Administratif::qualite() {
    Personne::qualite();
    cout << endl;
}

void Administratif::afficherPersonne(ostream& os) {
    Liste<string>::ListeIterateur it(_experiences);

    Personne::afficherPersonne(os);
    os << "Fonction : " << _fonction << endl;

    os << "Expériences : " << endl;
    while(it.hasNext())
        os << "- " << it.get() << endl;
}