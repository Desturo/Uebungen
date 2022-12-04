#include "Depot.h"

Depot::Depot(unsigned int startPosition)
{
	this->m_position = startPosition;
}

unsigned int Depot::getPosition()
{
	return m_position;
}

unsigned int Depot::getWarenmaenge()
{
	return m_warenmaenge;
}

unsigned int Depot::getWarengewicht()
{
	return m_warengewicht;
}

unsigned int Depot::getWarengroesse()
{
	return m_warengroesse;
}
