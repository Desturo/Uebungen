#include "Raumschiff.h"

void Raumschiff::Fliegen()
{
}

void Raumschiff::Aufladen()
{
	m_energie = m_energieMax;
}

std::string Raumschiff::SendeSignal()
{
	return "Achtung! Hier ist Raumschiff " + m_name + ":";
}

Raumschiff::Raumschiff(unsigned int energieMax, std::string name)
{
	m_energie = energieMax;
	m_energieMax = energieMax;
	m_name = name;
}
