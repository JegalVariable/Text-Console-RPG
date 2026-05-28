#include <iostream>

#include "Item.h"
#include "Character.h"

using namespace std;

Item::Item(const ItemData& itemData)
	: itemData(itemData) { }

void Item::Use(Character* player)
{
	cout << "사용못함" << endl;
}

HPPotion::HPPotion()
	: Item({"HP Potion", 50, 1 }) { }

void HPPotion::Use(Character* player)
{
	if (player->GetMaxHP() > player->GetHP() + HEAL_AMOUNT)
	{
		player->SetHP(player->GetHP() + HEAL_AMOUNT);
	}
	else
	{
		player->SetHP(player->GetMaxHP());
	}
}

AttackBoost::AttackBoost()
	: Item({ "Attack Boost", 40, 1 }) { }

void AttackBoost::Use(Character* player)
{
	player->SetAttack(player->GetAttack() + ATTACK_INCREASE);
}
