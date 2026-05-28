#pragma once
#include <string>

class Monster;
class Character;

void PressAnyKey();
void ClearScreen();
void GameIntroOne();
void GameIntroTwo(std::string name);
void PrintGameOver();
void PrintGameClear();
void PrintBattleMenu(Monster* monster);
void PrintRandomItemMenu();

void LogUseHPPotion(int index);
void LogUseAttackBoost(int index);
void LogRemoveAttackBoost();
void LogPlayerAttack(Monster* monster);
void LogMonsterAttack(Monster* monster);
void LogAddGold();
void LogAddExp();
void LogAddItem(Monster* monster);
void LogLevelUp();