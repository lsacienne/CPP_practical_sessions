#include "header/bdd.h"

void BDD::ajouter(Personne* p) {
    Liste::ajouter(p, longueur());
}

void BDD::afficheContenuBDD() {
    // Parcourir la liste des personnes et afficher leurs informations
    Liste<Personne*>::ListeIterateur it(*this);
    Personne* cur_pers = NULL;
    int i = 0;
    cout << "********************************************************************************" << endl;
    cout << "**************** Database UTBM : ***********************************************" << endl;
    cout << "********************************************************************************" << endl << endl;
    while(it.hasNext()){
        cout << "\tEntrée " << ++i << " :" << endl << endl;
        cur_pers = it.get();
        cout << *cur_pers << endl;
    }
    cout << "********************************************************************************" << endl;
    cout << "**************** End of DATABASE ***********************************************" << endl;
    cout << "********************************************************************************" << endl << endl;
        
}