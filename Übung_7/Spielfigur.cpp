#include "Spielfigur.h"
#include "Raumschiff.h"

void Spielfigur::Einsteigen(Raumschiff* raumschiff)
{
	this->m_Raumschiff = raumschiff;
}

Spielfigur::Spielfigur(unsigned int startPosition)
{
	this->m_position = startPosition;
	this->m_Raumschiff = nullptr;
}

unsigned int Spielfigur::getPosition()
{
	return m_position;
}

void Spielfigur::setPosition(unsigned int neuePostition)
{
	this->m_position = neuePostition;
}

void Spielfigur::Bewegen(Richtung richtung)
{
	switch (richtung)
	{
	case 0:
		if (m_position < MAP_LENGHT - 1) m_position++;
		break;
	case 1:
		if (m_position > 0) m_position--;
	default:
		break;
	}

	if (hatRaumschiff()) {
		m_Raumschiff->setPosition(m_position);
	}
}

bool Spielfigur::hatRaumschiff()
{
	bool retrunBool;
	m_Raumschiff != nullptr ? retrunBool = true : retrunBool = false;
	return retrunBool;
}

std::string Spielfigur::Aussteigen()
{
	m_Raumschiff = nullptr;
	return "Ausgestiegen";
}

