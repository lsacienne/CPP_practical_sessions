// Type vecteur
#include "Vecteur.h"
#include <sys/types.h>

// Initialisation du membre static
int Vecteur::appels_constructeur_par_defaut = 0;
int Vecteur::appels_constructeur_par_copie = 0;
int Vecteur::appels_constructeur_avec_dim = 0;

// Constructeurs
Vecteur::Vecteur():dim(0),tab(NULL){
    appels_constructeur_par_defaut++;
};

Vecteur::Vecteur(const Vecteur& v){
    dim = v.dim;
    tab = new float[dim];
    for(int i = 0; i < dim; ++i){
        tab[i] = v.tab[i];
    }
    appels_constructeur_par_copie++;
};

Vecteur::Vecteur(int d):dim(d),tab(new float[dim]){
    appels_constructeur_avec_dim++;
};

// Destructeur
Vecteur::~Vecteur(){
    delete [] tab;
};

// Nombre d'elements
int Vecteur::dimension(void){
	return dim; 
};

// Longueur au carré 
float Vecteur::longueurCarre(void){
    float squared_size = 0;
    for(int i = 0; i < dim; ++i)
        squared_size += tab[i]*tab[i];
    return squared_size;
}

// Acces aux elements
float& Vecteur::operator[](int index){
    return this->tab[index];
}

// affectation : =(vecteur), =(int)
Vecteur& Vecteur::operator=(const Vecteur& v){
    if(this != &v) {
        dim = v.dim;
        delete [] tab;
        tab = new float[dim];
        for(int i = 0;i<dim;++i) {
            tab[i] = v.tab[i];
        }
    }
    return *this;
};

Vecteur& Vecteur::operator=(float i){
	for(int j = 0; j<dim;++j)
		tab[j] = i;
	return *this;
}

// incrementation/decr. : ++, ++(int), --
Vecteur& Vecteur::operator++(void){
    for(int i = 0; i < this->dim; ++i){
        this->tab[i]++;
    }
    return *this;
}

Vecteur Vecteur::operator++(int p){
    Vecteur v = *this;
    ++*this;
    return v;
}

Vecteur& Vecteur::operator--(void){
    for(int i = 0; i < this->dim; ++i){
        this->tab[i]--;
    }
    return *this;
}

Vecteur Vecteur::operator--(int p){
    Vecteur v = *this;
    --*this;
    return v;
}

// op. booleens : ==, <, >, <=, >=
bool Vecteur::operator==(Vecteur& v){
    return longueurCarre() == v.longueurCarre();
}

bool Vecteur::operator<(Vecteur& v){
    return longueurCarre() < v.longueurCarre();
}

bool Vecteur::operator>(Vecteur& v){
    return longueurCarre() > v.longueurCarre();
}

bool Vecteur::operator<=(Vecteur& v){
    return longueurCarre() <= v.longueurCarre();
}

bool Vecteur::operator>=(Vecteur& v){
    return longueurCarre() >= v.longueurCarre();
}

// op. binaires : +, -
Vecteur Vecteur::operator+(const Vecteur& v){
    Vecteur v_f = *this;
    for(int i = 0; i < v.dim; ++i){
        v_f.tab[i] += v.tab[i];
    }
    return v_f;
};

Vecteur Vecteur::operator-(const Vecteur& v){
    Vecteur v_f = *this;
    for(int i = 0; i < v.dim; ++i){
        v_f.tab[i] -= v.tab[i];
    }
    return v_f;
}

// produit scalaire : *
float Vecteur::operator*(const Vecteur& v){
    float prod = 0;
    for(int i = 0; i < this->dim; ++i){
        prod += this->tab[i] * v.tab[i];
    }
    return prod;
}

// produit par un scalaire: n * v, v * n
Vecteur Vecteur::operator*(float f){
    Vecteur v_f = *this;
    for(int i = 0; i < this->dim; ++i){
        v_f.tab[i] *= f;
    }
    return v_f;
}

Vecteur operator*(float f,Vecteur& v){
    return v * f;
}

// auto-adition : +=, -=
Vecteur& Vecteur::operator+=(const Vecteur& v){
    for(int i = 0; i < v.dim; ++i){
        this->tab[i] += v.tab[i];
    }
    return *this;
}

Vecteur& Vecteur::operator-=(const Vecteur& v){
    for(int i = 0; i < v.dim; ++i){
        this->tab[i] -= v.tab[i];
    }
    return *this;
}

// Operateurs d'entree/sortie: <<, >>
ostream& operator<<(ostream& os, Vecteur& v) {
    os << "(";
    for(int i = 0; i < v.dim-1;++i) {
        os << v.tab[i] << ", ";
    }
    os << v.tab[v.dim-1] << ")";
    return os;
}

istream& operator>>(istream& is,Vecteur& v){
    cout << "Taille: ";
    is >> v.dim;
    v.tab = new float[v.dim];
    for(int i = 0; i < v.dim; ++i){
        is >>  v.tab[i];
    }
    return is;
}










