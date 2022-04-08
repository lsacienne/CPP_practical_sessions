#ifndef __LISTE_MAILLON_H
#define __LISTE_MAILLON_H
/*
 * Creer une classe liste generique (avec template)
 * avec une implentation avec Maillon.
 *
 * Auteur : JC. Creput
 * 20/03/2020
 */
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

template <class T>
struct Maillon {
    T val;
    Maillon* suiv;
    Maillon* prec;//si double chainage

    ~Maillon(){
        delete suiv;
    }
};

// Classe Liste
template <class T>
class Liste {
    Maillon<T>* _tete;
    Maillon<T>* _fin;

public:
    // Forme canonique de Coplien (4 operations)
    // Cons. par defaut
    Liste() : _tete(NULL), _fin(NULL) {} //liste vide
    // Cons copie
    Liste(const Liste& l){
        Maillon<T>* it_this;
        Maillon<T>* it_l;

        //Création de la tête de liste
        _tete = new Maillon<T>();
        _tete->val = l._tete->val;
        _tete->prec = NULL;

        it_this = _tete;
        it_l = l._tete->suiv;

        while(it_l != l._fin) {
            it_this->suiv = new Maillon<T>();
            it_this->suiv->val = it_l->val;
            it_this->suiv->prec = it_this;
            it_this = it_this->suiv;
            it_l = it_l->suiv;
        }
        //Création de la fin de liste
        it_this->suiv = new Maillon<T>;
        it_this->suiv->val = l._fin->val;
        _fin = it_this->suiv;
        _fin->prec = it_this;
        _fin->suiv = NULL;

    }
    // Destructeur
    ~Liste(){
        delete _tete;
    }
    // Affectation
    Liste& operator=(const Liste& l) {
        if(this != &l) {
            delete this->_tete;
            Liste l_copy(l);
            this->_tete = l_copy._tete;
            this->_fin = l_copy._fin;
            l_copy._tete = NULL;
        }
        return *this;
    }

    Liste(const string& s) : _tete(NULL),_fin(NULL) {
        stringstream s_str(s);
        string token;
        int toAdd;

        while(getline(s_str, token, '-')){
            toAdd = stoi(token);
            ajouter(toAdd, longueur());
        }
    }

    // Modificateur
    T& operator[](int pos) {
        Maillon<T>* it = _tete;
        int index = 0;
        while(index != pos) {
            it = it->suiv;
            index++;
        }
        return it->val;
    }

    // Longueur
    int longueur() {
        int l = 0;
        Maillon<T>* it_this = _tete;
        while(it_this != NULL) {
            ++l;
            it_this = it_this->suiv;
        }
        return l;
    }

    // Ajout
    void ajouter(T& val, int pos) {
        int i = 0;
        Maillon<T>* it_this = _tete;
        Maillon<T>* nMaillon = new Maillon<T>;
        nMaillon->val = val;
        while(it_this != NULL && it_this->suiv != NULL && i != pos) {
            it_this = it_this->suiv;
            i++;
        }
        if(it_this == NULL) {
            // Case where the list is empty, we must initialize it with one element
            this->_tete = nMaillon;
            this->_tete->prec = NULL;
            this->_tete->suiv = NULL;
            this->_fin = this->_tete;
        } else if(pos == 0) {
            // Case where we insert the element at the first position.
            nMaillon->suiv = it_this;
            nMaillon->prec = NULL;
            it_this->prec = nMaillon;
            this->_tete = nMaillon;
        } else if(it_this->suiv == NULL) {
            // Case where we reach the end of the list.
            it_this->suiv = nMaillon;
            it_this->suiv->prec = it_this;
            it_this->suiv->suiv = NULL;
            this->_fin = it_this->suiv;
        } else {
            // Case where we insert the element at the 'pos' position.
            nMaillon->suiv = it_this;
            nMaillon->prec = it_this->prec;
            it_this->prec->suiv = nMaillon;
            it_this->prec = nMaillon;
        }
    }

    // Suppression
    void supprimer(int pos) {
        int i = 0;
        Maillon<T>* it_this = _tete;
        while(it_this != NULL && it_this->suiv != NULL && i != pos) {
            it_this = it_this->suiv;
            i++;
        }
        if(pos == 0) {
            // Case where we insert the element at the first position.
            it_this->suiv->prec = NULL;
            _tete = it_this->suiv;
            it_this->suiv = NULL;
            delete it_this;
        } else if(it_this->suiv == NULL) {
            // Case where we reach the end of the list.
            it_this->prec->suiv = NULL;
            delete it_this; 
        } else if(i == pos) {
            // Case where we insert the element at the 'pos' position.
            it_this->prec->suiv = it_this->suiv;
            it_this->suiv->prec = it_this->prec;
            it_this->suiv = NULL;
            it_this->prec = NULL;
            delete it_this;
        }
    }

    // Concatenation
    Liste concat(Liste& l) {
        Liste this_copy(*this);
        return this_copy.autoConcat(l);
    }

    // Auto-concatenation
    Liste& autoConcat(Liste l) {
        Liste l_copy(l);
        _fin->suiv = l_copy._tete;
        l_copy._tete->prec = _fin;
        _fin = l_copy._fin;
        l_copy._tete = NULL;
        return *this;
    }

    // Entrees-sorties
    friend ostream& operator<<(ostream &o, Liste &l) {
        Maillon<T>* it = l._tete;
        o << "( ";
        while(it != NULL) {
            o << it->val << " ";
            it = it->suiv;
        }
        return o << ")";
    }

    class ListeIterateur {
        Liste* liste;
        Maillon<T>* it;
    public:
        ListeIterateur(Liste& l): liste(&l),it(liste->_tete){}
        void reset() {
            it = liste->_tete;
        }
        bool hasNext() {
            return it != NULL;
        }
        T& get(){
            T& val = it->val;
            it = it->suiv;
            return val;
        }
    };
};

#endif //__LISTE_MAILLON_H
