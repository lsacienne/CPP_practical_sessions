# include <iostream>
# include <sstream>

using namespace std;

int get_int(string text) {
    int value = 0;
    cout << text +" : ";
    cin >> value;

    return value;
}

int get_value_sum(int nb_values) {
    int sum = 0;
    int value;
    ostringstream prompt;
    for(int i = 0; i < nb_values; ++i) {
        prompt.str("");
        prompt.clear();
        prompt << "Valeur " << i+1;
        value = get_int(prompt.str());
        sum += value;
    }
    return sum;
} 

float get_average(int nb_values) {
    float avg =(float) get_value_sum(nb_values);
    avg /= nb_values;
    return avg;
}

int main(int agrc, char** argv) {
    float avg = get_average(5);
    cout << "Average : " << avg << endl;
    return EXIT_SUCCESS;
}