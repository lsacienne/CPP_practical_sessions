#include "HelloW.hpp"
#include "HelloA.hpp"
#include "HelloB.hpp"
#include <cstdlib>

int main(int argc, char* argv[]) {
    HelloW hello;
    HelloA helloA;
    HelloB helloB;
    cout << hello << endl;
    helloA.affiche();
    helloB.affiche();
    
    return EXIT_SUCCESS;

}