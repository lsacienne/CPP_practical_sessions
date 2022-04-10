#ifndef __ADMINISTRATIF_H
#define __ADMINISTRATIF_H

#include "Personne.h"

using namespace std;

class Administratif : public Personne {
	private :
		// donnees specifiques a administratif
		string _fonction;
                string _bureau;
                virtual void afficherPersonne(ostream&);
	public :
        Administratif(string prenom,
                string nom,
                string fonction,
                string bureau) : Personne(nom, prenom, "personnel administratif"), _fonction(fonction), _bureau(bureau) {}

        virtual void affiche(void);

        virtual void profession();
        virtual void qualite();
        

};

#endif