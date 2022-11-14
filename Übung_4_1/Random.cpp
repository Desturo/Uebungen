#include "Random.h"
#include <time.h>
#include <cstdlib>
#include <random>

float randomFloat(int min, int max) {	
	int range = max - min;
	return (((float)std::rand() / (RAND_MAX)) * range) + min;
}

int randomInt(int min, int max) {
	int range = max - min;
	return (std::rand() % range) + min;
}


float randFl(float floatMin, float floatMax) {
	std::random_device rd;
	std::uniform_real_distribution<float> dist(floatMin, floatMax);
	return dist(rd);
}