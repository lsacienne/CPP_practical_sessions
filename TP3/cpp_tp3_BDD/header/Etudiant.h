#ifndef __ETUDIANT_H
#define __ETUDIANT_H

#include "Personne.h"
#include <ostream>

using namespace std;

class Etudiant : public Personne {
	private :
		// donnees specifiques a etudiant
		string _branche;
		string _filiere;
                virtual void afficherPersonne(ostream&);

	public :
        Etudiant(string prenom,
                 string nom,
                 string branche,
                 string filiere) : Personne(nom, prenom, "étudiant(e)"), _branche(branche), _filiere(filiere) {}

        Etudiant(string prenom,
                 string nom,
                 string branche) : Personne(nom, prenom, "étudiant(e)"), _branche(branche), _filiere() {}

        virtual void affiche(void);

        virtual void profession();
        virtual void qualite();
        

        
};

#endif
