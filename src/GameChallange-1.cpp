// GameChallange-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#define MSG_INTRO			"Welcome to the war of humans vs zombies, here we will simulate the battle that will decide the outcome of the human race."
#define MSG_HUMAN_INSERT	"Please enter the size of the human army:"
#define MSG_ZOMBIE_INSERT	"Please enter the size of the zombie army:"
#define MSG_STATS			"Number of zombies left: %i"



// Prototypes
int getArmySizeInput(char * message);

int main()
{
	std::cout << MSG_INTRO;

	Army humanArmy("HumanArmy");
	Army zombieArmy("ZombieArmy");

	humanArmy.setArmySize(getArmySizeInput(MSG_HUMAN_INSERT);
	zombieArmy.setArmySize(getArmySizeInput(MSG_ZOMBIE_INSERT);

    return 0;
}

int getArmySizeInput(char * message)
{
	int armySize = 0;

	std::cout << message;

	std::cin >> armySize;

	return armySize;
}

