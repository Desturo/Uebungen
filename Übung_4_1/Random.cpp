#include "Random.h"
#include <time.h>
#include <cstdlib>

float randomFloat(int min, int max) {	
	int range = max - min;
	return (((float)std::rand() / (RAND_MAX)) * range) + min;
}

int randomInt(int min, int max) {
	int range = max - min;
	return (std::rand() % max) + min;
}
