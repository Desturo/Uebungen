#include <iostream>
#include <conio.h>
#include <string>

#include "Spielfigur.h"
#include "Raumschiff.h"
#include "Depot.h"
#include "defines.h"

using std::cout;
using std::endl;

void FeldAnzeigen(std::string message = "");

std::string Interaktion();

std::string Information();

Spielfigur* Spieler = new Spielfigur(0);
Raumschiff* Schiff = new Raumschiff(5, 100, 100);
Depot* Lager = new Depot(9);

int main() {
	bool running = true;
	FeldAnzeigen();

	while (running)
	{

		if (_kbhit()) {
			std::string message = "";
			switch (_getch()) {
			case 100:
			case 22477:
				Spieler->Bewegen(RECHTS);
				break;
			case 97:
			case 22475:
				Spieler->Bewegen(LINKS);
				break;
			case 32:
				message = Interaktion();
				break;
			case 27:
				running = false;
				break;
			case 9:
				message = Information();
				break;
			case 113:
				message = Schiff->WareAbwerfen();
				break;
			case 101:
				message = Spieler->Aussteigen();
				break;
			}
			FeldAnzeigen(message);
		}
	}

	delete Spieler;
	delete Schiff;
	delete Lager;
}

void FeldAnzeigen(std::string message)
{
	system("cls");
	for (size_t koordinate = 0; koordinate < MAP_LENGHT; koordinate++)
	{
		if (koordinate == Lager->getPosition()) {
			cout << DEPOT_CHAR;
		}
		else if (koordinate == Schiff->getPosition())
		{
			cout << SHIP_CHAR;
		}
		else if (koordinate == Spieler->getPosition())
		{
			cout << PLAYER_CHAR;
		}
		else
		{
			cout << " ";
		}
	}

	cout << endl;
	for (size_t koordinate = 0; koordinate < MAP_LENGHT; koordinate++)
	{
		if (koordinate == Spieler->getPosition()) {
			cout << char(194);
		}
		else
		{
			cout << char(196);
		}
	}

	if (message != "") cout << endl << message;
}

std::string Interaktion()
{
	std::string returnString;
	if (Spieler->getPosition() == Schiff->getPosition() && !Spieler->hatRaumschiff())
	{
		Spieler->Einsteigen(Schiff);
		returnString = "Ins Schiff eingestiegen.";
	}
	else if (Spieler->getPosition() == Lager->getPosition() && !Spieler->hatRaumschiff())
	{
		returnString = "Am Lager kann ohne Schiff nichts getan werden.";
	}
	else if (Spieler->getPosition() == Lager->getPosition() && Spieler->hatRaumschiff())
	{
		returnString = Schiff->WareLaden(Lager->getWarenmaenge(), Lager->getWarengroesse(), Lager->getWarengewicht());

	}
	else {
		returnString = "Hier gibt es nichts zu tun.";
	}
	return returnString;
}

std::string Information()
{
	std::string returnString = "Keine Information";
	if (Spieler->hatRaumschiff() && Spieler->getPosition() != Lager->getPosition()) {
		returnString = "-----Raumschiff-----\nMaximales Ladegewicht:\t" + std::to_string(Schiff->getMaximallast()) + "\nLadeplaetze:\t\t" + std::to_string(Schiff->getLadeplaetze()) + "\nLagerraum:\t\t";

		if (Schiff->hatWare()) {
			returnString += "Beladen";
		}
		else
		{
			returnString += "Leer";
		}
	}
	else if (Spieler->getPosition() == Lager->getPosition())
	{
		returnString = "-----Waren-----\nAnzahl:\t\t" + std::to_string(Lager->getWarenmaenge()) + "\nGroesse:\t" + std::to_string(Lager->getWarengroesse()) + "\nGewicht:\t" + std::to_string(Lager->getWarengewicht());
	}
	else
	{
		returnString = "-----Steuerung-----\n"\
			"Tab:\tInformationen anzeigen\n"\
			"D|>:\tNach rechts bewegen\n"\
			"A|<:\tNach links bewegen\n"\
			"LEER:\tInteragieren\n"\
			"Q:\tWaren abwerfen\n"\
			"E:\tAussteigen\n";
	}
	return returnString;
}
