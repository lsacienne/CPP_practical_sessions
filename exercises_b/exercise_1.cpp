# include <iostream>

using namespace std;

int get_int(string text);

class Rectangle {
    private:
        int length;
        int width;
    public:
        Rectangle():length(0),width(0){}
        Rectangle(int length, int width):length(length),width(width){}

       int get_perimter() {
            return 2 * (length + width);
        }

        int get_aera() {
            return length * width;
        } 
};

int main(int argc, char** argv) {
    int length = get_int("Length");
    int width = get_int("Width");

    Rectangle rect(length,width);

    cout << "Perimeter : " << rect.get_perimter() << ", " << rect.get_aera() << endl;

    return EXIT_SUCCESS;
}

int get_int(string text) {
    int value = 0;
    cout << text +" : ";
    cin >> value;

    return value;
}