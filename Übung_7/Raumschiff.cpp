#include "Raumschiff.h"
#include "Ware.h"

Raumschiff::Raumschiff(unsigned int startPosition, unsigned int ladeplaetze, unsigned int maximallast)
{
	this->m_position = startPosition;
	this->m_ladeplaetze = ladeplaetze;
	this->m_maximallast = maximallast;
	this->m_geladeneWare = nullptr;
	this->m_warenAnzahl = 0;
}

unsigned int Raumschiff::getPosition()
{
	return m_position;
}

unsigned int Raumschiff::getLadeplaetze()
{
	return m_ladeplaetze;
}

unsigned int Raumschiff::getMaximallast()
{
	return m_maximallast;
}

void Raumschiff::setPosition(unsigned int neuePosition)
{
	this->m_position = neuePosition;
}

std::string Raumschiff::WareLaden(unsigned int anzahlWaren, unsigned int warenGroesse, unsigned int warenGewicht)
{
	this->m_warenAnzahl = anzahlWaren;
	
	m_geladeneWare = new Ware* [anzahlWaren];

	if (warenGewicht * anzahlWaren <= m_maximallast && warenGroesse * anzahlWaren <= m_ladeplaetze) {
		return (std::string)"Waren Geladen.";
	}
	else if(warenGewicht * anzahlWaren == 0 || warenGroesse * anzahlWaren == 0) {
		return (std::string)"Keine Waren vorhanden.";
	}
	else if(warenGewicht * anzahlWaren > m_maximallast) {
		m_geladeneWare = nullptr;
		return (std::string)"Waren zu schwer.";
	}
	else if (warenGroesse * anzahlWaren > m_ladeplaetze) {
		m_geladeneWare = nullptr;
		return (std::string)"Waren zu gross.";
	}
	else
	{
		m_geladeneWare = nullptr;
		return (std::string)"Fehler beim Laden der Waren.";
	}
}

bool Raumschiff::hatWare()
{
	if (m_geladeneWare == nullptr) return false;
	for (size_t index = 0; index < m_warenAnzahl; index++)
	{
		m_geladeneWare[index] = new Ware(1, 2);
	}
	return m_geladeneWare == nullptr ? false : true;
}

std::string Raumschiff::WareAbwerfen()
{
	if (m_geladeneWare != nullptr) {
		delete[] m_geladeneWare;
		m_geladeneWare = nullptr;
		return "Ware abgeworfen!";
	}
	else
	{
		return "Keine Waren zum abwerfen";
	}
	
}
