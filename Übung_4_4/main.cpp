#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>

float cbvTranslate(float ang);
void cbrTranslate(float& ang);

int main() {

	float ang1 = 1;

	std::cout << std::setprecision(8) << "Call By Value: " << ang1 << "\370 = ";
	ang1 = cbvTranslate(ang1);
	std::cout << ang1 << " RAD" << std::endl;

	float ang2 = 1;

	std::cout << "Call By Reference: " << ang2 << "\370 = ";
	cbrTranslate(ang2);
	std::cout << ang2 << " RAD" << std::endl;

	return 200;
}

float cbvTranslate(float ang) {
	return ang * (M_PI / 180);
}

void cbrTranslate(float &ang) {
	ang = ang * (M_PI / 180);
}