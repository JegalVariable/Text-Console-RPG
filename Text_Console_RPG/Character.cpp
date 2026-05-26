#include <iostream>

#include "Character.h"

void Character::DisplayStatus()
{
	std::cout << "==============================" << std::endl;
	std::cout << "이름: " << name << std::endl;
	std::cout << "공격력: " << attack << std::endl;
	std::cout << "체력: " << hp << std::endl;
	std::cout << "현재 경험치: " << exp << std::endl;
	std::cout << "현재 레벨" << level << std::endl;
	std::cout << "==============================" << std::endl;
	std::cout << std::endl;
}

void Character::LevelUp()
{
	std::cout << "레벨업" << std::endl;
	
	SetLevel(GetLevel() + 1);
	SetExp(0);
	SetMaxHP(GetMaxHP() + (GetLevel() * 20));
	SetAttack(GetAttack() + (GetLevel() * 5));

	SetHP(GetMaxHP()); // 체력 회복
}

void Character::UseItem(int index)
{

}