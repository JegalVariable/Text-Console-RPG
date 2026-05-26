#pragma once
#include <iostream>

class Monster;
class Character;

void MainMenu();

Monster* GenerateMonster(int level);

void Battle(Character* player);

void PrintInventory(Character* player);