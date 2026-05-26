#pragma once
#include <string>

class Monster
{
public:
	virtual std::string GetName() { return ""; }
	virtual int GetHP() { return 0; }
	virtual int GetAttack() { return 0; }
	virtual void TakeDamage(int damage) {}
	virtual void AttackMessage() {}
};

class Slime : public Monster
{
private:
	std::string name = "";
	std::string dropItem = "";
	int hp = 0;
	int attack = 0;
	int id = 0;

public:
	Slime(int hp, int attack);

	std::string GetName() { return name; }
	int GetHP() { return hp; }
	int GetAttack() { return attack; }
	void TakeDamage(int damage);
	void AttackMessage();
};

class Goblin : public Monster
{
private:
	std::string name = "";
	std::string dropItem = "";
	int hp = 0;
	int attack = 0;
	int id = 0;

public:
	Goblin(int hp, int attack);

	std::string GetName() { return name; }
	int GetHP() { return hp; }
	int GetAttack() { return attack; }
	void TakeDamage(int damage);
	void AttackMessage();
};