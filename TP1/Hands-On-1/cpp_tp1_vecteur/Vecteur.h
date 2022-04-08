#ifndef VECTEUR_H
#define VECTEUR_H
//
// Type vecteur
//
#include <iostream>

using namespace std;

//
// Type vecteur de float
//
class Vecteur
{
private:
    int dim;
    float* tab;
public:
    static int appels_constructeur_par_defaut;
    static int appels_constructeur_par_copie;
    static int appels_constructeur_avec_dim;

// Constructeurs par defaut(void) , avec la taille du vect.(int), par copie(vecteur&)
Vecteur(); // Constructeur par défaut
Vecteur(const Vecteur& v); // Constructeur par copie
Vecteur(int d); // Constructeur avec taille

// Destructeur
~Vecteur(); 

// Acces a la taille du vecteur
int dimension(void);

// Access à la longueur au carré du vecteur
float longueurCarre(void);

// acces au element []
float& operator[](int index);

// affectation : =(vecteur), =(int)
Vecteur& operator=(const Vecteur& v);
Vecteur& operator=(float i);

// incrementation/decr. : ++(void), ++(int), --(void)
Vecteur& operator++(void);
Vecteur operator++(int p);

Vecteur& operator--(void);
Vecteur operator--(int p);


// op. booleens : ==(vecteur&), <, >, <=, >=
bool operator==(Vecteur& v);
bool operator<(Vecteur& v);
bool operator>(Vecteur& v);
bool operator<=(Vecteur& v);
bool operator>=(Vecteur& v);

// op. binaires : +(vecteur&), -
Vecteur operator+(const Vecteur& v);
Vecteur operator-(const Vecteur& v);

// produit scalaire: *(vecteur&)
float operator*(const Vecteur& v);

// produit par un scalaire: v * n, n * v
Vecteur operator*(float f);
friend Vecteur operator*(float f,Vecteur& v);

// auto-adition : +=(vecteur&), -=
Vecteur& operator+=(const Vecteur& v);
Vecteur& operator-=(const Vecteur& v);

// Operateurs d'entree/sortie: <<, >>
friend ostream& operator<< (ostream&, Vecteur&);
friend istream& operator>> (istream&, Vecteur&);

};
#endif // VECTEUR_H

