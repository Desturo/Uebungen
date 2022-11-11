#include <iostream>
#include <iomanip>
#define PI 3.14159265359

using std::cout;
using std::string;
using std::endl;

double vol, circ, surf, rad;


int main() {

    cout << "Geben sie den Radius an: ";
    std::cin >> rad;

    circ = 2 * PI * rad;
    vol = (4 * PI) / 3 * rad * rad * rad;
    surf = 4 * PI * rad * rad;
    cout << std::setprecision(12) << "Umfang: " << circ << endl << "Volumen: " << vol << endl << "Flaeche: " << surf << endl;
    return 200;
}