#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;

const char fillSymbol = '*';

int main() {

    cout << std::setw(40) << std::setfill(fillSymbol) << std::left << "All Characters" << endl;
    cout << std::setfill(' ');
    cout << setw(9) << std::right << "ASCII" << "|" << setw(9) << std::left << "DEC" << "|" << setw(9) << std::right << "OCT" << "|" << setw(9) << std::left << "HEX" << "|" << endl;

    for (unsigned int c = 32; c < 256; c++) {
        cout << setw(9) << std::right << (unsigned char)c << "|" << std::dec << setw(9) << std::left << (unsigned char)c + 0 << "|" << std::hex << setw(9) << std::right << (unsigned char)c + 0 << "|" << std::oct << setw(9) << std::left << (unsigned char)c + 0 << "|" << endl;
    }

    cin.get();
    return 200;
}