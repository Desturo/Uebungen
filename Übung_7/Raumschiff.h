#pragma once
#include <iostream>
class Raumschiff
{
private:
	unsigned int m_position = 0;
	unsigned int m_ladeplaetze = 1;
	unsigned int m_maximallast = 1;
	class Ware** m_geladeneWare = nullptr;
	unsigned int m_warenAnzahl = 0;
public:
	Raumschiff(unsigned int startPosition, unsigned int ladeplaetze, unsigned int maximallast);
	unsigned int getPosition();
	unsigned int getLadeplaetze();
	unsigned int getMaximallast();
	void setPosition(unsigned int neuePosition);
	std::string WareLaden(unsigned int anzahlWaren, unsigned int warenGroesse, unsigned int warenGewicht);

	bool hatWare();

	std::string WareAbwerfen();
};

