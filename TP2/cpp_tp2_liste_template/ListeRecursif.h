#ifndef __LISTE_RECURSIF_H
#define __LISTE_RECURSIF_H
/*
 * Creer une classe liste generique (avec template)
 * avec une implentation en recursif.
 *
 * Auteur : JC. Creput - A. Viala
 * 23/03/2022
 */
#include <iostream>
#include <new>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

// Classe liste
template <class T>
class Liste {
    T val; // tete de liste = element
    Liste* reste; // suivi d'une liste

public:
    // Forme canonique de Coplien (4 operations)
    // Cons. par defaut
    Liste() : reste(NULL) {} //liste vide, val est bidon
    // Cons. copie
    Liste(const Liste& l) {
        if(l.reste == NULL)
            reste = NULL;
        else {
            val = l.val;
            reste = new Liste(*l.reste);
        }
    }
    // Destructeur
    ~Liste() {
        delete reste;
    }
    // Affectation
    Liste& operator=(const Liste& l) {
        if(this != &l){
            delete reste;
            reste = NULL;
            if(l.reste == NULL)
                reste = NULL;
            else {
                val = l.val;
                reste = new Liste(*l.reste);
            }
        }
        return *this;
    }

    //Constructeur par un string d'une liste d'entiers
    Liste(const string& s) : reste(NULL) {
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
        return (reste == NULL || pos == 0) ? val : (*reste)[pos-1];
    }
    // Longueur
    int longueur(){
        return reste == NULL ? 0 : 1+reste->longueur();
    }
    // Ajout
    void ajouter(T& val, int pos) {
        if(reste == NULL || pos == 0){
            Liste* l = new Liste();
            l->val = this->val;
            l->reste = reste;
            reste = l;
            this->val = val;
        } else
            reste->ajouter(val,pos-1);
    }
    // Suppression
    void supprimer(int pos) {
        if(reste != NULL) {
            if(pos == 0) {
                val = reste->val;
                Liste* l = reste;
                reste = reste->reste;
                l->reste = NULL;
                delete l;
            } else
                reste->supprimer(pos-1);
        }
    }

    // Concatenation
    Liste concat(Liste& l) {
        Liste l_f(*this);
        return l_f.autoConcat(l);
    }

    // Auto-concatenation
    Liste& autoConcat(Liste& l) {
        if(reste == NULL) {
            val = l.val;
            reste = new Liste(*l.reste);
        } else {
            reste->autoConcat(l);
        }
        return *this;
    }
    // Entrees-sorties
    friend ostream& operator<<(ostream &o, Liste &l) {
        // This flag is only here for aesthetic purpose.
        static bool flag = true;
        if (flag == true)
            o << "( ";

        if(l.reste == NULL) {
            flag = true;
            return o << ")";
        } else {
            flag = false;
            o << l.val <<" ";
            return o << *l.reste;
        }
    }

    class ListeIterateur {
        Liste* tete;
        Liste* it;
    public:
        ListeIterateur(Liste& l): tete(&l),it(&l){}
        void reset() {
            it = tete;
        }
        bool hasNext() {
            return it->reste != NULL;
        }
        T& get(){
            T& val = it->val;
            it = it->reste;
            return val;
        }
    };
};

#endif //__LISTE_RECURSIF_H
