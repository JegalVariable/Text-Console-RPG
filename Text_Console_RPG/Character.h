#pragma once
#include <string>
#include <vector>

struct Item;

class Character
{
private:
	std::string name = "";

	int level = 0;
	int hp = 0;
	int maxHP = 0;
	int attack = 0;
	int exp = 0;
	int gold = 0;
	
	static constexpr int MAX_EXP = 100;

	std::vector<Item*> inventory;

public:
	Character(std::string name)
	: name(name), level(1), hp(200), attack(30) { }

	void DisplayStatus();
	void LevelUp();
	void UseItem(int index);
	
	int GetLevel() const { return level; }
	int GetHP() const { return hp; }
	int GetMaxHP() const { return maxHP; }
	int GetAttack() const { return attack; }
	int GetExp() const { return exp; }
	int GetGold() const { return gold; }

	void SetLevel(int level) { this->level; }
	void SetHP(int hp) { this->hp; }
	void SetMaxHP(int maxHP) { this->maxHP; }
	void SetAttack(int attack) { this->attack; }
	void SetExp(int exp) { this->exp; }
	void SetGold(int gold) { this->gold; }
};