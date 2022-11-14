#include <iostream>
#include "Random.h"
#include <cstdlib>
#include <time.h>
#include <math.h>


int main() {
	std::srand(time(NULL));
	float sum = 0.f;
	for (size_t i = 0; i < 100; i++)
	{
		float random = (randFl(-1, 1) + randFl(-1, 1) + randFl(-1, 1)) / 3;
		sum += random;
		std::cout << randomInt(20, 40) << std::endl;
	}

	std::cout << "Naeherung an 0: " << sum / 100 << std::endl;
	return 200;
}