#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

    unsigned int oberGrenze, unterGrenze;

    while (true)
    {
        cout << "Geben Sie zuerst die Unter- und dann die Obergrenze an:" << endl;

        cin >> unterGrenze >> oberGrenze;

        cout << endl;

        for (size_t i = unterGrenze; i <= oberGrenze; i++)
        {
            bool prime = true;
            for (size_t j = 2; j <= i && prime; j++)
            {

                if (i % j == 0 && i != j) prime = false;
            }
            if (prime && i != 1 && i != 0) cout << i << " ist eine Primzahl." << endl;
        }
        cout << endl;
    }


    return 200;
}