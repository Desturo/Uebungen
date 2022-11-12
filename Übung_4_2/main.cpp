#include <iostream>
#include <cmath>

int median(int *input, size_t arraySize);

float arithMean(int* input, size_t arraySize);

float geoMean(int* input, size_t arraySize);

int mode(int* input, size_t arraySize);

int main() {

	int value[] = { 3, 5, 1, 2, 4, 5, 3, 2, 1, 2, 3, 4, 5, 6, 2 };
	int arraySize = sizeof(value) / sizeof(value[0]);

	std::cout << "Median: " << median(value, arraySize) << std::endl;
	std::cout << "Arithmetisches Mittel: " << arithMean(value, arraySize) << std::endl;
	std::cout << "Geometrisches Mittel: " << geoMean(value, arraySize) << std::endl;
	std::cout << "Modus: " << mode(value, arraySize) << std::endl;
	return 200;
}

int median(int *input, size_t arraySize) {

	if (arraySize % 2 != 0) {
		return input[arraySize / 2];
	}
	else
	{
		std::cout << "Bitte geben Sie eine ungerade Zahl eine." << std::endl;
		return 0;
	}
}

float arithMean(int* input, size_t arraySize) {

	int sum = 0;

	for (size_t i = 0; i < arraySize; i++) {
		sum += input[i];
	}

	return (float)sum / arraySize;
}

float geoMean(int* input, size_t arraySize) {

	int mult = 1;

	for (size_t i = 0; i < arraySize; i++) {
		mult *= input[i];
	}

	return std::pow(mult, 1.f/arraySize);
}


int mode(int* input, size_t arraySize) {

	int counter = 0;
	int currentMax = 0;
	int mode = 0;

	for (size_t i = 0; i < arraySize; i++) {
		for (size_t j = 0; j < arraySize; j++) {
			if (input[i] == input[j]) counter++;
		}
		if (counter > currentMax) (currentMax = counter) && (mode = input[i]);

		counter = 0;
	}

	return mode;
}
