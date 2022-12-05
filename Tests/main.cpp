#include <conio.h>
#include <iostream>

int main() {
	while (true)
	{
		if (_kbhit()) {
			std::cout << "Key: " << _getch() << std::endl;
		}
	}
}
