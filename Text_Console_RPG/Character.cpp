#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "Character.h"
#include "Item.h"
#include "GameLogManager.h"

using namespace std;

Character* Character::instance = nullptr;

Character::~Character()
{
	for (Item* item : inventory)
	{
		delete item;
	}
}

Character* Character::GetInstance(string name)
{
	if (instance == nullptr)
	{
		instance = new Character(name);
	}

	return instance;
}

void Character::DisplayStatus()
{
	cout << "==============================" << endl;
	cout << "        이름: " << name << endl;
	cout << "------------------------------" << endl;
	cout << "공격력: " << attack << " | " << "체력: " << hp << endl;
	cout << "Level : " << level << " | " << "Exp: " << exp << endl;
	cout << "==============================" << endl;
	cout << endl;
}

void Character::LevelUp()
{
	SetLevel(GetLevel() + 1);
	SetExp(0);
	SetMaxHP(GetMaxHP() + (GetLevel() * 20));
	SetAttack(GetAttack() + (GetLevel() * 5));

	SetHP(GetMaxHP()); // 체력 회복
}

void Character::UseItem(int index)
{
	if (index < 0 || index >= static_cast<int>(inventory.size()))
	{
		return;
	}

	if (inventory[index]->GetCount() > 0)
	{
		inventory[index]->Use(this);
		inventory[index]->SetCount(inventory[index]->GetCount() - 1);
		if (inventory[index]->GetCount() <= 0)
		{
			delete inventory[index];
			inventory[index] = nullptr;

			inventory.erase(inventory.begin() + index);
		}
	}
	else
	{
		cout << inventory[index]->GetName() << " 아이템이 다 떨어졌습니다." << endl;
	}
}

void Character::AddItem(Item* item)
{
	auto iter = find_if(inventory.begin(),inventory.end(),
		[item](Item* invenItem)
		{
			return invenItem->GetName() == item->GetName();
		});
	
	if (iter != inventory.end()) // 중복이라면
	{
		(*iter)->SetCount((*iter)->GetCount() + 1);
		delete item;
	}
	else
	{
		inventory.push_back(item);
		sort(inventory.begin(), inventory.end(),
			[](const Item* a, const Item* b)
			{
				return a->GetName() < b->GetName();
			});
	}
}

bool Character::RandomUse() // 50% 확률로 아이템 사용
{
	int random = rand() % 2;
	int hpPotionIndex = -1;
	int attackBoostIndex = -1;
	bool bCheck = false;

	hpPotionIndex = GetItemIndex("HP Potion");
	attackBoostIndex = GetItemIndex("Attack Boost");

	bool hasHPPotion = hpPotionIndex != -1;
	bool hasAttackBoost = attackBoostIndex != -1;
	
	// 둘 다 없음
	if (!hasHPPotion && !hasAttackBoost)
	{
		cout << "아이템이 다 떨어졌습니다." << endl;
		return false;
	}

	// 체력포션만 있음
	if (hasHPPotion && !hasAttackBoost)
	{
		LogUseHPPotion(hpPotionIndex);
		return false;
	}

	// 공격부스터만 있음
	if (!hasHPPotion && hasAttackBoost)
	{
		LogUseAttackBoost(attackBoostIndex);
		return true;
	}

	// 둘 다 있음
	if (random == 0)
	{
		LogUseHPPotion(hpPotionIndex);
		return false;
	}
	else
	{
		LogUseAttackBoost(attackBoostIndex);
		bCheck = true;
	}
	return bCheck;
}

int Character::GetItemIndex(const string& itemName) const
{
	int index = -1;

	for (int i = 0; i < static_cast<int>(inventory.size()); ++i)
	{
		if (inventory[i]->GetName() == itemName)
		{
			index = i;
			break;
		}
	}

	return index;
}