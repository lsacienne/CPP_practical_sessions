# include <iostream>
# include <list>
# include <sstream>
# include <algorithm>

using namespace std;

const int LIMIT = 10;

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

bool belong_to(list<int> l, int value) {
    auto rslt = find(l.begin(), l.end(), value);
    if (rslt != end(l)) {
        return true;
    }      
    return false;
}

int main(int argc, char** argv) {
    list<int> l = get_values(5);
    int V = get_int("Donnez la valeur de V");
    if(belong_to(l,V)) {
        cout << "V se trouve dans la liste" << endl;
    } else {
        cout << "V ne se trouve pas dans la liste" << endl;
    }
    return EXIT_SUCCESS;
}