// GameChallange-1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define MSG_INTRO			"Welcome to the war of humans vs zombies, here we will simulate the battle that will decide the outcome of the human race."
#define MSG_HUMAN_INSERT	"Please enter the size of the human army:"
#define MSG_ZOMBIE_INSERT	"Please enter the size of the zombie army:"
#define MSG_STATS			"Number of zombies left: %i"


struct ARMY_STRUCT
{
	int size;
	int health;
	int attack;
};

// Prototypes
int getArmySizeInput(char * message);
bool isGameOver(int const& armyOneSize, int const& armyTwoSize);
void battle(ARMY_STRUCT &armyOne, ARMY_STRUCT &armyTwo);

int main()
{
	std::cout << MSG_INTRO;

	ARMY_STRUCT humanArmy;
	humanArmy.health = 200;
	humanArmy.attack = 100;

	ARMY_STRUCT zombieArmy;
	zombieArmy.health = 400;
	zombieArmy.attack = 50;

	humanArmy.size = getArmySizeInput(MSG_HUMAN_INSERT);
	zombieArmy.size = getArmySizeInput(MSG_HUMAN_INSERT);

	// Set the random seed.
	srand(time(NULL));

	bool gameOver = false;

	while(!gameOver)
	{
		battle(humanArmy, zombieArmy);

		gameOver = isGameOver(humanArmy.size, zombieArmy.size);
	}

	if(humanArmy.size > 0)
	{
		std::cout << "The Humans won with " << humanArmy.size << " left";
	}
	else
	{
		std::cout << "Zombies won with " << zombieArmy.size << " left";
	}

    return 0;
}

bool isGameOver(int const& armyOneSize, int const& armyTwoSize)
{
	return (armyOneSize <= 0 || armyTwoSize <= 0);
}

void battle(ARMY_STRUCT &armyOne, ARMY_STRUCT &armyTwo)
{
	int healthOne = armyOne.health;
	int healthTwo = armyTwo.health;

	while(healthOne > 0 || healthTwo > 0)
	{
		int diceRoll = rand() % 2 + 1;
		
		if(diceRoll == 2)
		{
			healthOne -= armyTwo.attack;
		}
		else
		{
			healthTwo -= armyOne.attack;
		}
	}
	
	if(healthOne < 0)
	{
		armyOne.size -= 1;
	}
	else
	{
		armyTwo.size -= 1;
	}
}

int getArmySizeInput(char * message)
{
	int armySize = 0;

	std::cout << message;

	std::cin >> armySize;

	return armySize;
}

