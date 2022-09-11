# include <iostream>

using namespace std;

const int UPPER_BORN = 78;
const int BOTTOM_BORN = 56;

int get_int(string text) {
    int value = 0;
    cout << text +" : ";
    cin >> value;

    return value;
}

bool check_in_interval(int x) {
    if (x <= 78 && x >= 56) {
        return true;
    }
    return false;
}

int main(int argc, char** argv) {
    int value = get_int("Donner un nombre entier entre 56 et 78");

    if(check_in_interval(value)) {
        cout << "GAGNE" << endl;
    } else {
        cout << "PERDU" << endl;
    }

    return EXIT_SUCCESS;
}