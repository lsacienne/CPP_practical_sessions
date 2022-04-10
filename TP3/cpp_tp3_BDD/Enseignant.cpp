#include "header/Enseignant.h"

void Enseignant::affiche(){
    Personne::affiche();
    cout << "et je suis enseignant" << endl;
}

void Enseignant::profession(){
    Personne::qualite();
    if (_laboratoire.empty())
        cout << " en " << _type_formation << " et mon bureau est le " << _bureau << endl;
    else
        cout << " en " << _type_formation << " au laboratoire " << _laboratoire << " et mon bureau est le " << _bureau << endl;
}

void Enseignant::qualite() {
    Personne::qualite();
    cout << endl;
}

void Enseignant::afficherPersonne(ostream& os) {
    Liste<string>::ListeIterateur it(_experiences);

    Personne::afficherPersonne(os);
    os << "Type de formation : " << _type_formation << endl;
    os << "Bureau : " << _bureau << endl;
    if (!_laboratoire.empty())
        os << "Laboratoire : " << _laboratoire << endl;

    os << "Expériences : " << endl;
    while(it.hasNext())
        os << "- " << it.get() << endl;
}