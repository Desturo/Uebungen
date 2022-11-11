#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    double result;

    double x;

    cout << " Geben sie X an: ";

    cin >> x;

    result = ((3 * pow(x, 3)) + (2 * pow(x, 2))) / (2 * x);

    cout << std::setprecision(12) << result << endl;

    getch();
    return 200;
}