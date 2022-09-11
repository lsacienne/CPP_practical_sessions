# include <iostream>

using namespace std;

int get_int(string text) {
    int value = 0;
    cout << text +" : ";
    cin >> value;

    return value;
}

void switch_int(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main(int argc, char** argv) {
    int a = get_int("A");
    int b = get_int("B");

    switch_int(a,b);

    cout << "A : " << a << ", B : " << b << endl;
    return EXIT_SUCCESS;
}