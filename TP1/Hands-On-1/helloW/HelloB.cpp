#include "HelloB.hpp"
#include <ostream>
#include <string>

HelloB::HelloB() : toPrint(new std::string()){
     *toPrint = "HelloB - hello world!";
};
        
HelloB::HelloB(const HelloB& h) : toPrint(new string()){
    *toPrint = *h.toPrint;
}

HelloB::~HelloB(){
    delete toPrint;
}

HelloB& HelloB::operator=(HelloB& h){
    delete toPrint;
    toPrint = h.toPrint;
    return *this;
}

void HelloB::affiche(){
    cout << *toPrint << endl;
}