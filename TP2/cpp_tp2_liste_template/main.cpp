#include <iostream>

// Choisir une implementation (l'une ou l'autre)
//#include "ListeMaillon.h"
#include "ListeMaillon.h"

using namespace std;

int main()
{   
    cout << "Test de la classe liste" << endl;

    Liste<int> l1;// liste de integer
    Liste<float> lf;// liste de float

    cout << l1 << endl;
    cout << lf << endl;
    // Liste<Camion*> lc;// si classe Camion existe

    // Operations sur la liste

    // Ajouter des elements a une position donnee
    int i = 3;
    l1.ajouter(i, 0);
    cout << "liste l1 " << l1 << endl;
    i = 4;
    l1.ajouter(i, 0);
    cout << "liste l1 " << l1 << endl;
    i = 5;
    l1.ajouter(i, 0);
    cout << "liste l1 " << l1 << endl;
    i = 6;
    l1.ajouter(i, 0);

    Liste<int> l4("3-4-5-6");
    cout << "liste l4 " << l4 << endl;
    cout << "liste l1 " << l1 << endl;
    // Suppression d'element
    l1.supprimer(2); // suppression à une position donnee

    // Longeur
    int l = l1.longueur();
    cout << "longeur de l1 " << l << endl;
    cout << "liste l1 " << l1 << endl;

    // Cons par copie
    cout << "l1 : " << l1 << endl;
    Liste<int> l2 = l1;
    cout << "copie de l1 (l2) : " << l2 << endl;
    cout << "address of the head (l1) : " << &l1 << endl;
    cout << "address of the head (l2) : " << &l2 << endl;
    Liste<int> l3;
    // Affectation
    l3 = l2;

    cout << "l2 : " << l2 << endl;
    cout << "copie de l2 (l3): " << l3 << endl;
    cout << "address of the head (l2) : " << &l2 << endl;
    cout << "address of the head (l3) : " << &l3 << endl;
    
    // modifier un element a une position donnee
    l3[2] = 8;

    // Lire un element a une position donnee
    int elt = l3[2];

    cout << "element " << elt << endl;

    cout << "l1 : " << l1 << endl;
    cout << "l2 : " << l2 << endl;
    cout << "l3 : " << l3 << endl;

    l1.autoConcat(l2);
    cout << "l1.autoConcat(l2) : " << l1 << endl;


    l3 = l1.concat(l2);
    cout << "l3 = l1.concat(l2) : " << l3 << endl;
    cout << "l1 : " << l1 << endl;

    l3.supprimer(3);
    cout << "l3 suppr pos=3 : " << l3 << endl;

    // Test des itérateurs
    Liste<int>::ListeIterateur iter(l3);
    int r = 0;
    iter.reset();
    cout << "l3 jusqu'à l'élément 3: ";
    while(iter.hasNext() && r < 4) {
        cout << iter.get() << " ";
        r++;
    }
    cout << endl;
    iter.reset();

    cout << "l3 : ";
    while(iter.hasNext()) {
        cout << iter.get() << " ";
    }
    cout << endl;
    
    cout << "FIN DE TEST" << endl;
    return 0;
}
