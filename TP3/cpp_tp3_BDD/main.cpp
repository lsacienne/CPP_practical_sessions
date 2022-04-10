#include <iostream>
#include "header/Etudiant.h"
#include "header/Enseignant.h"
#include "header/Administratif.h"
#include "header/bdd.h"

using namespace std;

int main()
{
	/* Populate the database */
    BDD bdd;

    Personne* etd1 = new Etudiant("Jean", "Pierre", "Info", "CS12");

    bdd.ajouter(etd1);

	Personne* etd2 = new Etudiant("Alexandre","Viala","Info");

	bdd.ajouter(etd2);
	etd2->ajouterExperience("ST10 chez Exxelia");
	etd2->ajouterExperience("ST40");

	Personne* etd3 = new Etudiant("Amelie ", "Rodriguez", "Info", "CS13");

	bdd.ajouter(etd3);

	Personne* ensg1 = new Enseignant("Lewis", "Hamilton", "FISE" , "CIAD Lab" , "M405");
	
	bdd.ajouter(ensg1);

	Personne* ensg2 = new Enseignant("Alexis", "Flech", "TC", "P101");

	ensg2->ajouterExperience("Classe préparatoire");
	ensg2->ajouterExperience("Enseignant de mathématiques");
	bdd.ajouter(ensg2);

	Personne* admin1 = new Administratif("Elanor", "Courtney", "IT-Support", "H023");

	bdd.ajouter(admin1);

	/* Display the database */

	bdd.afficheContenuBDD();

	/* Test of the "affiche()" method */
	etd1->affiche();
	etd2->affiche();
	etd3->affiche();
	ensg1->affiche();
	ensg2->affiche();
	admin1->affiche();

	cout << endl;

	/* Test of the "profession()" method */
	etd1->profession();
	etd2->profession();
	etd3->profession();
	ensg1->profession();
	ensg2->profession();
	admin1->profession();

	cout << endl;

	/* Test of the "qualite()" method */
	etd1->qualite();
	etd2->qualite();
	etd3->qualite();
	ensg1->qualite();
	ensg2->qualite();
	admin1->qualite();

	cout << endl;

	/* Test of the "experience()" method */
	etd1->experience();
	etd2->experience();
	etd3->experience();
	ensg1->experience();
	ensg2->experience();
	admin1->experience();

	cout << endl;

	/* Test of the "getNom()" method */
	cout << etd1->getNom() << endl;
	cout << etd2->getNom() << endl;
	cout << etd3->getNom() << endl;
	cout << ensg1->getNom() << endl;
	cout << ensg2->getNom() << endl;
	cout << admin1->getNom() << endl;



    return 0;
}
