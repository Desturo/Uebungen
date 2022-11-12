#include <conio.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

using std::this_thread::sleep_for;
using std::cout;
using std::endl;
using std::chrono::milliseconds;
using std::setw;

void drawField(unsigned int playerPos[2], unsigned int enemyPos[2], unsigned int bombs[5][3], bool gameState, unsigned long long &gameTime);

void movePlayer(unsigned int playerPos[2], unsigned char &direction);
void moveEnemy(unsigned int enemyPos[2], unsigned char &direction);

void placeBomb(unsigned int playerPos[2], unsigned int bombs[5][3], unsigned char *bombCount, unsigned long long &gameTime);

int main() {
	bool running = true;
	unsigned char bombCount = 0;
	unsigned long long gameTime = 0;

	unsigned int playerPos[] = { 15, 10 };
	unsigned int enemyPos[] = { 12, 12 };
	//the third value is their time code, for knowing when they have to explode
	unsigned int bombs[5][3] = { {0,0,0},{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} };

	/*
		0 -> UP [W]
		1 -> LEFT [A]
		2 -> DOWN [S]
		3 -> RIGHT [D]
	*/
	unsigned char direction = 0;
	unsigned char enemyDirection = 1;
	
	while (running)
	{
		sleep_for(milliseconds(500));

		//Input handling
		if (_kbhit()) {
			switch (_getch())
			{
				case 32:
					placeBomb(playerPos, bombs, &bombCount, gameTime);
					break;
				//A
				case 97:
					direction = 1;
					break;
				//D
				case 100:
					direction = 3;
					break;
				//S
				case 115:
					direction = 2;
					break;
				//W
				case 119:
					direction = 0;
					break;
				//ESC
				case 27:
					running = false;
					break;
				default:
					break;
			}
		}
		//check if any bomb exploded
		for (size_t i = 0; i < 5; i++)
		{
			if (gameTime - bombs[i][2] >= 6) {
				bombs[i][0] = 0;
				bombs[i][1] = 0;
				bombs[i][2] = 0;
			}
		}

		movePlayer(playerPos, direction);
		moveEnemy(enemyPos, enemyDirection);
		//Draw Field
		drawField(playerPos, enemyPos, bombs, running, gameTime);

		gameTime++;
	}


	return 200;
}

void drawField(unsigned int playerPos[2], unsigned int enemyPos[2], unsigned int bombs[5][3], bool gameState, unsigned long long &gameTime) {
	system("cls");
	cout << setw(31) << std::setfill('-') << "-" << endl;
	bool bomb = false;

	for (size_t i = 1; i <= 20; i++)
	{
		cout << "|";

		for (size_t j = 1; j <= 30; j++)
		{
			for (size_t k = 0; k < 5; k++)
			{
				if (bombs[k][0] == j && bombs[k][1] == i)
				{
					bomb = true;
				}
			}

			//Order of IFs decides what get's rendered if two entities overlap
			if (playerPos[0] == j && playerPos[1] == i) {
				cout << "P";
			}
			else if (enemyPos[0] == j && enemyPos[1] == i) {
				cout << "E";
			}
			else if (bomb)
			{
				cout << "X";
			}
			else
			{
				cout << " ";
			}
			bomb = false;
		}
			
		cout << "|" << endl;
	}
	cout << setw(31) << std::setfill('-') << "-" << endl;
	cout << (gameState ? "Playing..." : "Game Over!") << " Tick: " << gameTime << endl;
}

void movePlayer(unsigned int playerPos[2], unsigned char &direction) {

	switch (direction)
	{
		case 0:
			if (playerPos[1] != 1) {
				playerPos[1] = playerPos[1] - 1;
			}
			break;
		case 1:
			if (playerPos[0] != 1) {
				playerPos[0] = playerPos[0] - 1;
			}
			break;
		case 2:
			if (playerPos[1] != 20) {
				playerPos[1] = playerPos[1] + 1;
			}
			break;
		case 3:
			if (playerPos[0] != 30) {
				playerPos[0] = playerPos[0] + 1;
			}
			break;
		default:
			break;
	}
}

void moveEnemy(unsigned int enemyPos[2], unsigned char& direction) {

	if (enemyPos[0] == 1) direction = 3;
	if (enemyPos[0] == 30) direction = 1;

	switch (direction)
	{
		case 0:
			if (enemyPos[1] != 1) {
				enemyPos[1] = enemyPos[1] - 1;
			}
			break;
		case 1:
			if (enemyPos[0] != 1) {
				enemyPos[0] = enemyPos[0] - 1;
			}
			break;
		case 2:
			if (enemyPos[1] != 20) {
				enemyPos[1] = enemyPos[1] + 1;
			}
			break;
		case 3:
			if (enemyPos[0] != 30) {
				enemyPos[0] = enemyPos[0] + 1;
			}
			break;
		default:
			break;
	}
}

void placeBomb(unsigned int playerPos[2], unsigned int bombs[5][3], unsigned char *bombCount, unsigned long long &gameTime)
{
	for (size_t i = 0; i < 5; i++)
	{
		if (bombs[i][0] == 0 && bombs[i][1] == 0 && bombs[i][2] == 0) {
			bombs[i][0] = playerPos[0];
			bombs[i][1] = playerPos[1];
			bombs[i][2] = gameTime;
			break;
		}
	}
}
