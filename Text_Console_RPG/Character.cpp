#include <iostream>

#include "Character.h"

void Character::DisplayStatus()
{
	std::cout << "==============================" << std::endl;
	std::cout << "이름: " << name << std::endl;
	std::cout << "공격력: " << attack << std::endl;
	std::cout << "체력: " << hp << std::endl;
	std::cout << "현재 경험치: " << exp << std::endl;
	std::cout << "==============================" << std::endl;
	std::cout << std::endl;
}

void Character::LevelUp()
{

}

void Character::UseItem(int index)
{

}