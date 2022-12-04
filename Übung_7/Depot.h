#pragma once
class Depot
{
private:
	unsigned int m_position = 0;

	unsigned int m_warenmaenge = 30;
	unsigned int m_warengewicht = 1;
	unsigned int m_warengroesse = 2;
public:
	Depot(unsigned int startPosition);
	unsigned int getPosition();
	unsigned int getWarenmaenge();
	unsigned int getWarengewicht();
	unsigned int getWarengroesse();
};

