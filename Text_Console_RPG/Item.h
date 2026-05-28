#pragma once
#include <string>

class Character;

struct ItemData
{
	std::string name = "";
	int price = 0;
	int itemType = 0; // 0이면 사용X, 1이면 소모품이라 사용가능
	int count = 1;
};

class Item
{
protected:
	ItemData itemData;
	static constexpr int HEAL_AMOUNT = 50;
	static constexpr int ATTACK_INCREASE = 10;

public:
	Item(const ItemData& itemData);
	virtual ~Item() = default;

	const std::string& GetName() const { return itemData.name; }
	int GetCount() const { return itemData.count; }
	int GetItemType() const { return itemData.itemType; }
	void SetCount(int count) { this->itemData.count = count; }
	virtual void Use(Character* player);
};

class HPPotion : public Item
{
public:
	HPPotion();

	void Use(Character* player) override;
};

class AttackBoost : public Item
{
public:
	AttackBoost();

	void Use(Character* player) override;
};

class SlimeJelly : public Item
{
public:
	SlimeJelly()
		: Item({ "Slime Jelly", 10, 0 }) { }
};

class GoblinLeather : public Item
{
public:
	GoblinLeather()
		: Item({ "Goblin Leather", 20, 0 }) { }
};

class OrcHammer : public Item
{
public:
	OrcHammer()
		: Item({ "Orc Hammer", 30, 0 }) { }
};

class DragonHorn : public Item
{
public:
	DragonHorn()
		: Item({ "Dragon Horn", 40, 0 }) { }
};