#include <iostream>
#include "Jaeger.h"
#include "Transporter.h"

int main() {

	Transporter transporter("Brummi");
	Jaeger jaeger(100, "X-Wing");
	std::cout << jaeger.SendeSignal() << std::endl << transporter.SendeSignal() << std::endl;
	jaeger.Feuern();
	return 0;
}