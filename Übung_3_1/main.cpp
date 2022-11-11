#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

    unsigned int year;

    while (true)
    {
        cout << "Geben Sie ein Jahr an: " << endl;

        cin >> year;

        if (year <= 0) break;

        (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? cout << "Schaltjahr\n" << endl : cout << "Kein Schaltjahr\n" << endl;
    }
    return 200;
}