#include <iostream>
#include <thread>
#include <chrono>
#include <random>

using std::string;

class Roboter {
public: 
	Roboter(int energieWert, int x, int y, string name);
	void bewegen(int x, int y);
	void regenerieren();
	void setRoboterFreund(Roboter* einRoboterFreund);
	int* getPos();
	string getName();
	void abstand();
private:
	int energieWert;
	int* startPos;
	int* pos;
	Roboter* einRoboterFreund;
	string name;
};

Roboter::Roboter(int energieWert, int x, int y, string name) {
	this->energieWert = energieWert;
	int startPos[2] = { x, y };
	this->startPos = startPos;
	this->pos = this->startPos;
	this->name = name;
}

void Roboter::bewegen(int x, int y) {
	if(pos[0] += x <= 10) pos[0] += x;
	if (pos[1] += y <= 10) pos[1] += y;
	energieWert -= 1;
}

void Roboter::regenerieren() {
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	this->energieWert = 40;
}

void Roboter::setRoboterFreund(Roboter* einRoboterFreund){
	this->einRoboterFreund = einRoboterFreund;
}

int* Roboter::getPos() {
	return this->pos;
}

string Roboter::getName() {
	return this->name;
}

void Roboter::abstand() {
	float abstand = std::sqrt(std::pow(float(pos[1] - pos[0]), 2) + std::pow(float(einRoboterFreund->getPos()[1] - einRoboterFreund->getPos()[0]), 2));

	std::random_device rd;
	std::uniform_real_distribution<int> dist(1, 10);

	if (abstand <= 2 && dist(rd) > 3)
	{
		std::cout << this->name << ": \"Hallo " << einRoboterFreund->getName() << "\"" << std::endl;
	}
	else {
		std::cout << this->name << ": \"Hallo " << einRoboterFreund->getName() << ". Ich mag dich nicht!\"" << std::endl;
		this->energieWert -= 5;
	}
}

int main() {
	Roboter C3PO(22, 1, 2, "C3PO");
	Roboter R2D2(40, 6, 8, "R2D2");
	return 0;
}