#pragma once
class Ware
{
private:
	unsigned int m_groesse = 1;
	unsigned int m_gewicht = 1;
public:
	unsigned int getGroesse();
	unsigned int getGewicht();
	Ware();
	Ware(unsigned int groesse, unsigned int gewicht);
};

