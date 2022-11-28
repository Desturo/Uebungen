#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>

float cbvTranslate(float ang);
void cbrTranslate(float& ang);
void cbpTranslate(float* angAdr);

float cbvReturn(float ang);
void cbrReturn(float& ang);
void cbpReturn(float* angAdr);

int main() {

	float ang1 = 22;

	std::cout << std::setprecision(8) << "Call By Value: " << ang1 << "\370 = ";
	ang1 = cbvTranslate(ang1);
	std::cout << ang1 << " RAD" << std::endl;

	float ang2 = 22;

	std::cout << "Call By Reference: " << ang2 << "\370 = ";
	cbrTranslate(ang2);
	std::cout << ang2 << " RAD" << std::endl;

	float ang3 = 22;

	std::cout << "Call By Pointer: " << ang3 << "\370 = ";
	cbpTranslate(&ang3);
	std::cout << ang3 << " RAD" << std::endl << std::endl;





	std::cout << std::setprecision(8) << "Call By Value: " << ang1 << "RAD = ";
	ang1 = cbvReturn(ang1);
	std::cout << ang1 << "\370" << std::endl;

	std::cout << "Call By Reference: " << ang2 << "RAD = ";
	cbrReturn(ang2);
	std::cout << ang2 << "\370" << std::endl;


	std::cout << "Call By Pointer: " << ang3 << "RAD = ";
	cbpReturn(&ang3);
	std::cout << ang3 << "\370" << std::endl;



	return 200;
}

float cbvTranslate(float ang) {
	return ang * (M_PI / 180);
}

void cbrTranslate(float &ang) {
	ang = ang * (M_PI / 180);
}

void cbpTranslate(float *angAdr) {
	*angAdr = *angAdr * (M_PI / 180);
}

float cbvReturn(float ang) {
	return ang * (180 / M_PI);
}

void cbrReturn(float& ang) {
	ang = ang * (180 / M_PI);
}

void cbpReturn(float* angAdr) {
	*angAdr = *angAdr * (180 / M_PI);
}