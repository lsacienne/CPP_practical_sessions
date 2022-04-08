// Include de l'application
#include "Vecteur.h"

int
main(int argc, char **argv)
{

	cout << "PROGRAMME DE TEST" << endl;

	// Constructeurs
	Vecteur v1(3);
	Vecteur v2 = v1;
	Vecteur v3;
	Vecteur v4(5),v5(3);
	v1 = v2;

	cout << "Appels constructeur par défaut : " << Vecteur::appels_constructeur_par_defaut << endl;
	cout << "Appels constructeur par copie : " << Vecteur::appels_constructeur_par_copie << endl;
	cout << "Appels constructeur avec dimension : " << Vecteur::appels_constructeur_avec_dim << endl;

	v1[0] = 2;
	v1[1] = 4;
	v1[2] = 6;
	cout << "v1 :	" << v1 << endl;

	// v4 = 4;
	// v5 = v1;
	// cout << "v4 :   " << v4 << endl;
	// cout << "v5 :   " << v5<< endl;
	
	cout << "v1 :	" << v1 << endl;

	
	v2 = v1;
	cout << "v2 = v1 :	" << v2 << endl;

	v2++;
	cout << "v2++ :	" << v2 << endl;
	v2--;
	cout << "v2-- :	" << v2 << endl;
	v3 = --v2;
	cout << "v3   :	" << v3 << " v2   : " << v2 << endl;

	// Comparaisons
	v3[0] = 6;
	v3[1] = 4;
	v3[2] = 2;
	
	//cout << "v1 :	" << v1 << endl;
	//cout << "v2 :	" << v2 << endl;
	cout << "v3 :	" << v3 << endl;
	cout << "v5 :	" << v5 << endl;

	/*
	cout << "v1 == v3 :	" << (v1 == v3) << endl;
	cout << "v1 > v2 :	" << (v1 > v2) << endl;
	cout << "v1 < v2 :	" << (v1 < v2) << endl;
	cout << "v1 <= v1 :	" << (v1 <= v1) << endl;
	cout << "v3 >= v1 :	" << (v3 >= v1) << endl;
	*/

	
	v3 = v1 + v2;
	cout << "v3 = v1 + v2 :	" << v3 << endl;
	//v1 = v3 - v2 + v1;
	//cout << "v1 = v3 - v2 + v1 : " << v1 << endl;
	

	/*
	float scalar_product = v1 * v2;
	cout << "Scalar product :	" << scalar_product << endl;
	*/

	/*
	v5 = v3 * 2;
	cout << "v3 :	" << v3 << endl;
	cout << "v5 :	" << v5 << endl;
	v3 = 2* v3;
	cout << "v3 :	" << v3 << endl;
	cout << "v5 :	" << v5 << endl;
	*/

	/*
	v5 += v3;
	cout << "v5 :	" << v5 << endl;
	v5 += v3;
	cout << "v5 :	" << v5 << endl;
	v3 -= v5;
	cout << "v3 :	" << v3 << endl;
	*/
	
//	v3 = v1 + v2;
//	cout << "v3 = v1 + v2 :	" << v3 << endl;
	cout << "Appels constructeur par défaut : " << Vecteur::appels_constructeur_par_defaut << endl;
	cout << "Appels constructeur par copie : " << Vecteur::appels_constructeur_par_copie << endl;
	cout << "Appels constructeur avec dimension : " << Vecteur::appels_constructeur_avec_dim << endl;

	cout << "SORTIE TEST" << endl;
}


