#ifndef __PERSONNE_H
#define __PERSONNE_H
#include <iostream>
#include "ListeRecursif.h"
#include <ostream>
#include <string>

using namespace std;

class Personne {
        protected:
                string _nom ;
                string _prenom ;
                string _qualite;
                Liste<string> _experiences;
                virtual void afficherPersonne(ostream&);
	public:
                Personne(string nom, string prenom, string qualite) : _nom(nom), _prenom(prenom), _qualite(qualite) {}
                virtual ~Personne() {}
                string getNom() { return _nom; }
                void experience();
                void ajouterExperience(string exp);

                virtual void affiche();
                virtual void profession() = 0;
                virtual void qualite();
                

                friend ostream& operator<<(ostream&, Personne&);
};

#endif
