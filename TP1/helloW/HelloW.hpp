#include <iostream>
#include <string>

using namespace std;

class HelloW {
    string* toPrint;

    public:
        HelloW();
        HelloW(const HelloW& h);
        ~HelloW();
        HelloW& operator=(HelloW& h);
        friend ostream& operator<< (ostream& os, HelloW& h);
};