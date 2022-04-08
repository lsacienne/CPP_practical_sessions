#include <iostream>
#include <string>

using namespace std;

class HelloB {
    string* toPrint;

    public:
        HelloB();
        HelloB(const HelloB& h);
        ~HelloB();
        HelloB& operator=(HelloB& h);
        void affiche();
};