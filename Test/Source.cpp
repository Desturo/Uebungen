#include <iostream>

int main() {
	for (size_t i = 0; i < 300; i++)
	{
		std::cout << i << ":\t" << char(i) << std::endl;
	}
	return 0;
}