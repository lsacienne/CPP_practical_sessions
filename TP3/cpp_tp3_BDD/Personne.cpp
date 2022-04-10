#include "header/Personne.h"
#include <ostream>

void Personne::affiche() {
	cout << "Mon nom est " << _nom <<" et mon prenom " << _prenom << " ";
}

void Personne::qualite() {
	cout << "Je suis " << _qualite;
}
void Personne::ajouterExperience(string exp) {
	_experiences.ajouter(exp, 0);
}

void Personne::experience() {
	Liste<string>::ListeIterateur it(_experiences);
	cout << "Expériences : " << endl;
	while(it.hasNext())
        cout << "- " << it.get() << endl;
}

void Personne::afficherPersonne(ostream& os) {
	os << "Nom : " << _nom << endl;
	os << "Prénom : " << _prenom << endl;
	os << "Qualité : " << _qualite << endl;
}

ostream& operator<<(ostream& os, Personne& pers) {
	pers.afficherPersonne(os);
	return os;
}