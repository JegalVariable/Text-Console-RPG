#pragma once
#include <iostream>

class Monster;
class Character;

Monster* GenerateMonster(int level);

void Battle(Character* player);

void PrintInventory(Character* player);