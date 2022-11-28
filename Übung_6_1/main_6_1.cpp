#include <iostream>

namespace Statistik {
	class Mittelwert {
	private:
		int* array;
		int length;
	public:
		void setArray(int* array);
		void setLength(int length);
		int modalwert();
		float mittelwert();

		Mittelwert(int* array, int length);
	};

	float Mittelwert::mittelwert() {
		/*
		* Warum geht das nicht:
		* int arrayLaenge = *(&array + 1) - array;
		*/
		int sum = 0;
		for (size_t i = 0; i < length; i++)
		{
			sum += *(array + i);
		}
		return float(sum)/length;
	}

	int Mittelwert::modalwert() {
		int counter = 0;
		int currentMax = 0;
		int mode = 0;

		for (size_t i = 0; i < length; i++) {
			for (size_t j = 0; j < length; j++) {
				if (*(array + i) == *(array + j)) counter++;
			}
			if (counter > currentMax) (currentMax = counter) && (mode = *(array + i));

			counter = 0;
		}

		return mode;
	}

	void Mittelwert::setArray(int* array) {
		this->array = array;
	}
	void Mittelwert::setLength(int length) {
		this->length = length;
	}


	Mittelwert::Mittelwert(int* array, int length) {
		this->array = array;
		this->length = length;
	}
}


int main() {
	int werte[] = {1, 2, 3, 4, 5, 6, 7, 8, 8};
	int werteLaenge = *(&werte + 1) - werte;
	Statistik::Mittelwert MW(werte, werteLaenge);
	std::cout << "Mittelwert: " << MW.mittelwert() << "\nModalwert: " << MW.modalwert() << std::endl;
	return 200;
}