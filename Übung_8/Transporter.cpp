#include "Transporter.h"

std::string Transporter::SendeSignal()
{
	return Raumschiff::SendeSignal() + " \"Lasst mich in Ruhe! Ich hab was zum Essen dabei!\"";
}

Transporter::Transporter(std::string name):
	Raumschiff(40, name)
{
}

void Transporter::Fliegen()
{
	SendeSignal();

	m_energie -= 2;
}
