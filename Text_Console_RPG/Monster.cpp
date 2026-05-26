#include <iostream>
#include <string>

#include "Monster.h"

using namespace std;

Slime::Slime(int hp, int attack)
	: name("Slime"), dropItem("Slime Jelly"), hp(hp), attack(attack), id(1) { }

void Slime::TakeDamage(int damage)
{

}

void Slime::AttackMessage()
{
	cout << "슬라임의 몸통박치기!" << endl;
}

Goblin::Goblin(int hp, int attack)
: name("Goblin"),dropItem("Goblin Leather"), hp(hp), attack(attack), id(2) {}

void Goblin::TakeDamage(int damage)
{

}

void Goblin::AttackMessage()
{
	cout << "고블린 펀치!" << endl;
}