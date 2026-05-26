#include <iostream>
#include <string>

#include "Monster.h"

using namespace std;

void Monster::TakeDamage(int damage)
{
	hp -= damage;
}

Slime::Slime(int hp, int attack)
	: Monster("Slime", "Slime Jelly", hp, attack, 1) { }

void Slime::AttackMessage()
{
	cout << "슬라임의 몸통박치기!" << endl;
}

Goblin::Goblin(int hp, int attack)
	: Monster("Goblin", "Goblin Leather", hp, attack, 2) { }

void Goblin::AttackMessage()
{
	cout << "고블린 펀치!" << endl;
}