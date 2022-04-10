#include "header/Etudiant.h"
#include <ostream>

void Etudiant::affiche(void) {
    Personne::affiche();
    cout << "et je suis étudiant" << endl;
}

void Etudiant::profession(){
    Personne::qualite();
    cout << " et je suis en " << _branche;
    if(!_filiere.empty())
        cout << " en filière " << _filiere;
    cout << endl;
}

void Etudiant::qualite() {
    Personne::qualite();
    cout << endl;
}

void Etudiant::afficherPersonne(ostream& os) {
    Liste<string>::ListeIterateur it(_experiences);

    Personne::afficherPersonne(os);
    os << "Branche : " << _branche << endl;
    if(!_filiere.empty())
        os << "Filière : " << _filiere << endl;

    os << "Expériences : " << endl;
    while(it.hasNext())
        os << "- " << it.get() << endl;
}