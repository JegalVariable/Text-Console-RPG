#pragma once
#include <string>

class Monster
{
protected:
	std::string name = "";
	std::string dropItem = "";
	int hp = 0;
	int attack = 0;
	int id = 0;

public:
	Monster(std::string name, std::string dropItem, int hp, int attack, int id)
		: name(name), dropItem(dropItem), hp(hp), attack(attack), id(id) { }

	std::string GetName() const { return name; }
	int GetHP() const { return hp; }
	int GetAttack() const { return attack; }

	void SetHP(int hp) { this->hp; }

	void TakeDamage(int damage);
	virtual void AttackMessage() {}
};

class Slime : public Monster
{
public:
	Slime(int hp, int attack);

	void AttackMessage();
};

class Goblin : public Monster
{
public:
	Goblin(int hp, int attack);

	void AttackMessage();
};