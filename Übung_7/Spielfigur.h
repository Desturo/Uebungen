#pragma once
#include "defines.h"
#include <string>

class Spielfigur
{
private:
	unsigned int m_position = 0;
	class Raumschiff* m_Raumschiff = nullptr;
public:
	void Einsteigen(Raumschiff* raumschiff);
	Spielfigur(unsigned int startPosition);
	unsigned int getPosition();
	void setPosition(unsigned int neuePostition);
	void Bewegen(Richtung richtung);
	bool hatRaumschiff();
	std::string Aussteigen();
};

