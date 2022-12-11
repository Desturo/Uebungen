#pragma once
#include <string>
class Raumschiff
{
protected:
	unsigned int m_energie = 0;
	unsigned int m_energieMax = 0;
	enum KanonenStatus { BEREIT, MUNITIONAUS, FEUERN, ABKÜHLEN };
	std::string m_name = "";
	virtual void Fliegen();
	void Aufladen();
	std::string SendeSignal();
	Raumschiff(unsigned int energieMax, std::string name);
};

