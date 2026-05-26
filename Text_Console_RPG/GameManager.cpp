#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "GameManager.h"
#include "Monster.h"
#include "Character.h"

using namespace std;

Monster* GenerateMonster(int level)
{
	Monster* monster = nullptr;

	srand(static_cast<unsigned int>(time(nullptr)));

	int monsterID = rand() % 2 + 1; // id 1~2
	int monsterHP = rand() % 11 + 20; // 체력 20~30
	int monsterAttack = rand() % 6 + 5; // 공격력 5~10

	cout << monsterID << endl;
	cout << monsterHP << endl;
	cout << monsterAttack << endl;

	switch (monsterID)
	{
	case 1:
		monster = new Slime(level * monsterHP, level * monsterAttack);
		break;
	case 2:
		monster = new Goblin(level * monsterHP, level * monsterAttack);
		break;
	default:
		break;
	}
	return monster;
}

void Battle(Character* player)
{
	srand(static_cast<unsigned int>(time(nullptr)));

	bool bBattle = true;

	int dropGold = rand() % 11 + 10; // 10~20
	int itemDropRate = rand() % 100; // 0~99 100가지


	Monster* monster = GenerateMonster(player->GetLevel()); // 몬스터 생성

	cout << monster->GetName() << " 등장!" << endl;

	while (bBattle)
	{
		cout << "내가 때림" << endl;
		monster->TakeDamage(player->GetAttack());
		if (monster->GetHP() <= 0) // 몬스터 죽음
		{
			cout << "유저 승" << endl;
			// 전리품
			if (player->GetLevel() < player->GetMaxLevel()) // 10 미만이라면
			{
				player->AddExp(); // 경험치 획득
				if (player->GetExp() >= player->GetMaxExp())
				{
					player->LevelUp();
				}
			}
			if (itemDropRate < 30)
			{
				cout << "아이템 먹음" << endl;
			}
			break;
		}

		cout << "몬스터가 때림" << endl;
		player->SetHP(player->GetHP() - monster->GetAttack());
		if (player->GetHP() <= 0)
		{
			cout << "몬스터 승" << endl; // 여기서 게임 종료해야함
			break;
		}
	}

	

	delete monster;
}

void PrintInventory(Character* player)
{

}