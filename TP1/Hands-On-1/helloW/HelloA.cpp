#include "HelloA.hpp"
#include <ostream>
#include <string>

HelloA::HelloA() : toPrint(new std::string()){
     *toPrint = "HelloA - hello world!";
};
        
HelloA::HelloA(const HelloA& h) : toPrint(new string()){
    *toPrint = *h.toPrint;
}

HelloA::~HelloA(){
    delete toPrint;
}

HelloA& HelloA::operator=(HelloA& h){
    delete toPrint;
    toPrint = h.toPrint;
    return *this;
}

void HelloA::affiche(){
    cout << *toPrint << endl;
}