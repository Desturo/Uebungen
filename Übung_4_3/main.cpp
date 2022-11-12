#include <iostream>

int main() {
	int eineVariable = 100;
	int *AdresseDerVariable = &eineVariable;
	std::cout << "Ausgabe durch Variable: " << eineVariable << std::endl << "Ausgabe durch Pointer: " << *AdresseDerVariable << std::endl << std::endl;
	std::cout << "Speicherort druch Variable: " << &eineVariable << std::endl << "Speicherort durch Pointer: " << AdresseDerVariable << std::endl << std::endl;
	int& ReverenzEineVariable = eineVariable;
	ReverenzEineVariable += 20;
	std::cout << "Referenz: " << ReverenzEineVariable << std::endl << "Variable: " << eineVariable << std::endl << std::endl;
	std::cout << "Speicherort von Referenz: " << &ReverenzEineVariable << std::endl << "Speicherort von Variable: " << &eineVariable << std::endl << std::endl;

	return 200;
}