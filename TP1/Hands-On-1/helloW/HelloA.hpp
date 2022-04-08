#include <iostream>
#include <string>

using namespace std;

class HelloA {
    string* toPrint;

    public:
        HelloA();
        HelloA(const HelloA& h);
        ~HelloA();
        HelloA& operator=(HelloA& h);
        void affiche();
};