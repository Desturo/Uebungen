#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

    int value;

    cout << "Geben sie den Wert an der Umgerechnet werden soll: ";
    cin >> value;

    string result;

    while (value != 0) {
        result = (value % 2 == 0 ? "0" : "1") + result;
        value = value / 2;
    }

    cout << result << endl;


    return 200;
}