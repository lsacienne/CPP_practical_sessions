# include <iostream>
# include <list>
# include <sstream>

using namespace std;

const int LIMIT = 200;

int get_int(string text) {
    int value = 0;
    cout << text +" : ";
    cin >> value;

    return value;
}

list<int> get_values(int nb_values) {
    list<int> l;
    ostringstream prompt;
    for(int i = 0; i < nb_values; ++i) {
        prompt.str("");
        prompt.clear();
        prompt << "Valeur " << i+1;
        l.push_back(get_int(prompt.str()));
    }
    return l;
}

int find_minimal(list<int> l) {
    int min = l.front();
    for (int n : l) {
        if (n < min) {
            min = n;
        }
    }
    return min;
}

int main(int argc, char** argv) {
    cout << "Donner 5 entiers inférieurs à 200 : " << endl;
    list<int> l = get_values(5);
    cout << "Le minimum est : " << find_minimal(l) << endl;

    return EXIT_SUCCESS;
}