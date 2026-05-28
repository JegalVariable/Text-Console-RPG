#pragma once
#include <string>

class Item;

class Monster
{
protected:
	std::string name = "";

	int hp = 0;
	int attack = 0;

public:
	Monster(const std::string& name, int hp, int attack);
	virtual ~Monster() = default;

	const std::string& GetName() const { return name; }
	int GetHP() const { return hp; }
	int GetAttack() const { return attack; }

	void SetHP(int hp) { this->hp = hp; }

	void TakeDamage(int damage);
	virtual Item* DropItem() = 0;
	virtual void PrintMonster() = 0;
};

class Slime : public Monster
{
public:
	Slime(int hp, int attack);

	Item* DropItem() override;
	void PrintMonster() override;
};

class Goblin : public Monster
{
public:
	Goblin(int hp, int attack);

	Item* DropItem() override;
	void PrintMonster() override;
};

class Orc : public Monster
{
public:
	Orc(int hp, int attack);

	Item* DropItem() override;
	void PrintMonster() override;
};

class Dragon : public Monster
{
public:
	Dragon(int hp, int attack);

	Item* DropItem() override;
	void PrintMonster() override;
};