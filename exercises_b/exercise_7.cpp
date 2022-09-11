# include <iostream>
# include <list>
# include <sstream>

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

int check_greater_than(int limit, list<int> l) {
    int nb_greater_than = 0;
    for(int n : l)
        if( n >= limit)
            nb_greater_than++;
    
    return nb_greater_than;
}

int main(int argc, char** argv) {
    list<int> l = get_values(5);
    cout << check_greater_than(LIMIT,l) << " values are greater than " << LIMIT << endl;

    return EXIT_SUCCESS;
}