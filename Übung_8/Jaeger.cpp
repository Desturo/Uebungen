#include "Jaeger.h"
#include <chrono>
#include <thread>
#include <iostream>

#define sleep(t) std::this_thread::sleep_for(std::chrono::seconds(t))

std::string Jaeger::SendeSignal()
{
	return Raumschiff::SendeSignal() + " \"Aus der Bahn Kartoffelschmarrn!\"";
}

Jaeger::Jaeger(unsigned int munitionMax, std::string name):
	Raumschiff(20, name)
{
	m_munition = munitionMax;
	m_munitionMax = munitionMax;
	m_kanonenStatus = BEREIT;
}

void Jaeger::Fliegen()
{
	//Bewegen

	SendeSignal();

	m_energie--;
}

void Jaeger::Feuern()
{
	int counter = 3;
	while (counter > 0 && m_munition > 0)
	{
		m_kanonenStatus = FEUERN;
		sleep(1);
		std::cout << "Feuer! ";
		m_munition--;
		counter--;
	}
	if (m_munition >= m_munitionMax) {
		std::cout << std::endl;
		m_kanonenStatus = ABKÜHLEN;
		sleep(5);
		m_kanonenStatus = BEREIT;
	}
	else
	{
		m_kanonenStatus = MUNITIONAUS;
	}
	
}

void Jaeger::Aufladen()
{
	Raumschiff::Aufladen();
	m_munition = m_munitionMax;
	m_kanonenStatus = BEREIT;
}

