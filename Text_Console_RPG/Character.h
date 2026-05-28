#pragma once
#include <string>
#include <vector>

class Item;

class Character
{
private:
	Character(std::string name)
		: name(name), level(1), hp(200), maxHP(200), attack(30) { }

	static Character* instance;

	std::string name = "";

	int level = 0;
	int hp = 0;
	int maxHP = 0;
	int attack = 0;
	int exp = 0;
	int gold = 0;
	
	static constexpr int DROP_EXP = 50;
	static constexpr int MAX_EXP = 100;
	static constexpr int MAX_LEVEL = 10;

	std::vector<Item*> inventory;

public:
	~Character();

	static Character* GetInstance(std::string name);

	void DisplayStatus();
	void LevelUp();
	void UseItem(int index);
	void AddItem(Item* item);
	bool RandomUse();
	void AddExp() { this->exp += DROP_EXP; }
	
	int GetLevel() const { return level; }
	int GetMaxLevel() const { return MAX_LEVEL; }
	int GetHP() const { return hp; }
	int GetMaxHP() const { return maxHP; }
	int GetAttack() const { return attack; }
	int GetExp() const { return exp; }
	int GetMaxExp() const { return MAX_EXP; }
	int GetGold() const { return gold; }
	std::vector<Item*>& GetInventory() { return inventory; }
	int GetItemIndex(const std::string& itemName) const;
	const std::string& GetName() const { return name; }

	void SetLevel(int level) { this->level = level; }
	void SetHP(int hp) { this->hp = hp; }
	void SetMaxHP(int maxHP) { this->maxHP = maxHP; }
	void SetAttack(int attack) { this->attack = attack; }
	void SetExp(int exp) { this->exp = exp; }
	void SetGold(int gold) { this->gold = gold; }
};