#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "GameManager.h"
#include "Monster.h"

using namespace std;

void MainMenu()
{

}

Monster* GenerateMonster(int level)
{
	Monster* monster = nullptr;

	srand(static_cast<unsigned int>(time(nullptr)));

	int monsterID = rand() % 2 + 1; // id 1~2
	int monsterHP = rand() % 11 + 20; // 체력 20~30
	int monsterAttack = rand() % 6 + 5; // 공격력 5~10

	cout << monsterID << endl;
	cout << monsterHP << endl;
	cout << monsterAttack << endl;

	switch (monsterID)
	{
	case 1:
		monster = new Slime(level * monsterHP, level * monsterAttack);
		break;
	case 2:
		monster = new Goblin(level * monsterHP, level * monsterAttack);
		break;
	default:
		break;
	}
	return monster;
}

void Battle(Character* player)
{

}

void PrintInventory(Character* player)
{

}