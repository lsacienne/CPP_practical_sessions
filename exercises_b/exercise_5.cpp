# include <iostream>
# include <sstream>

using namespace std;

const int UPPER_BORN = 23;
const int BOTTOM_BORN = 8;

void print_integers(int bottom, int top) {
    ostringstream prompt;
    for(int i = bottom; i <= top; ++i) {
        prompt << i << " ";
    }
    cout << "Valeurs : " << prompt.str() << endl;
}

void print_even(int bottom, int top) {
    ostringstream prompt;
    if(bottom % 2 != 0) {
        bottom++;
    }

    for(int i = bottom; i <= top; i+=2) {
        prompt << i << " ";
    }
    cout << "Valeurs : " << prompt.str() << endl;
}

void print_integers_while(int bottom, int top) {
    ostringstream prompt;
    int i = bottom;

    while(i <= top) {
        prompt << i << " ";
        ++i;
    }
    cout << "Valeurs : " << prompt.str() << endl;
}

void print_even_while(int bottom, int top) {
    ostringstream prompt;
    int i = bottom;
    if(bottom % 2 != 0) {
        bottom++;
    }

    while(i <= top) {
        prompt << i << " ";
        i += 2;
    }
    cout << "Valeurs : " << prompt.str() << endl;
}

int main(int argc, char** argv) {
    print_integers(BOTTOM_BORN, UPPER_BORN);
    print_even(BOTTOM_BORN,UPPER_BORN);
    print_integers_while(BOTTOM_BORN,UPPER_BORN);
    print_even_while(BOTTOM_BORN,UPPER_BORN);

    return EXIT_SUCCESS;
}