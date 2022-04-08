#include "HelloW.hpp"

HelloW::HelloW() : toPrint(new std::string()){
     *toPrint = "HelloW - hello world!";
};
        
HelloW::HelloW(const HelloW& h) : toPrint(new string()){
    *toPrint = *h.toPrint;
}

HelloW::~HelloW(){
    delete toPrint;
}

HelloW& HelloW::operator=(HelloW& h){
    delete toPrint;
    toPrint = h.toPrint;
    return *this;
}

ostream& operator<< (ostream& os, HelloW& h){
    os << *h.toPrint;
    return os;
}