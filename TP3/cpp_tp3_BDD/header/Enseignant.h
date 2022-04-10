#ifndef __ENSEIGNANT_H
#define __ENSEIGNANT_H

#include "Personne.h"

using namespace std;

class Enseignant : public Personne {
	private :
		// donnees specifiques a enseignant
		string _type_formation;
		string _laboratoire;
                string _bureau;
                virtual void afficherPersonne(ostream&);

	public :
        Enseignant(string prenom,
                 string nom,
                 string type_formation,
                 string laboratoire,
                 string bureau) : Personne(nom, prenom, "enseignant(e)-chercheur"), _type_formation(type_formation), _laboratoire(laboratoire), _bureau(bureau) {}
        
        Enseignant(string nom,
                 string prenom,
                 string type_formation,
                 string bureau) : Personne(nom, prenom, "professeur(e) agrégé(e)"), _type_formation(type_formation), _laboratoire(), _bureau(bureau) {}

        virtual void affiche(void);

        virtual void profession();
        virtual void qualite();
        
};

#endif
