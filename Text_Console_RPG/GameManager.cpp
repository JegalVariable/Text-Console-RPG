#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "GameManager.h"
#include "Monster.h"
#include "Character.h"
#include "Item.h"
#include "GameLogManager.h"

using namespace std;

Monster* GameManager::GenerateMonster(int level)
{
	Monster* monster = nullptr;

	int monsterID = rand() % 3; // 0~2 3가지
	int monsterHP = rand() % 11 + 20; // 체력 20~30
	int monsterAttack = rand() % 6 + 5; // 공격력 5~10

	switch (monsterID)
	{
	case 0:
		monster = new Slime(level * monsterHP, level * monsterAttack);
		break;
	case 1:
		monster = new Goblin(level * monsterHP, level * monsterAttack);
		break;
	case 2:
		monster = new Orc(level * monsterHP, level * monsterAttack);
		break;
	default:
		break;
	}
	return monster;
}

Monster* GameManager::GenerateDragon(int level)
{
	Monster* monster = nullptr;
	int monsterHP = rand() % 11 + 30; // 체력 30~40
	int monsterAttack = rand() % 9 + 7; // 공격력 7~15

	monster = new Dragon(level * monsterHP, level * monsterAttack);
	return monster;
}

void GameManager::CreateCharacter()
{
	string name = "";

	GameIntroOne();
	while (true)
	{
		getline(cin, name);

		bool isOnlySpace = all_of(name.begin(), name.end(),
			[](char c)
			{
				return isspace(c);
			});

		if (name.empty() || isOnlySpace)
		{
			cout << "이름을 다시 입력해주세요." << endl;
			continue;
		}

		break;
	}
	Character* player = Character::GetInstance(name); // 캐릭터 생성
	ClearScreen();
	player->DisplayStatus();
	GameIntroTwo(name);

	AddRandomItem(); // 인벤에 체력회복포션, 공격력증가포션 1개씩 지급

	int hp = player->GetItemIndex("HP Potion");
	int ab = player->GetItemIndex("Attack Boost");
	
	player->GetInventory()[hp]->SetCount(3); // 처음 갯수 3개로 변경
	player->GetInventory()[ab]->SetCount(3);
}

void GameManager::Battle(Character* player)
{
	int itemDropRate = rand() % 100; // 0~99 100가지
	Monster* monster;
	char battleChoice;
	bool bBattle = true;
	bool bAttackBoost = false;
	bool bBoss = false;

	if (player->GetLevel() < 10)
	{
		monster = GenerateMonster(player->GetLevel()); // 일반 몬스터 생성
	}
	else
	{
		monster = GenerateDragon(player->GetLevel()); // 보스몬스터 생성
		bBoss = true;
	}

	monster->PrintMonster();
	cout << monster->GetName() << " 등장! " << "공격력: " << monster->GetAttack();
	cout << " / 체력: " << monster->GetHP() << endl;
	PressAnyKey();

	while (bBattle)
	{
		PrintBattleMenu(monster);
		cin >> battleChoice;

		switch (battleChoice)
		{
		case '1':
		{
			while (true)
			{
				ClearScreen();
				monster->PrintMonster();
				player->DisplayStatus();

				monster->TakeDamage(player->GetAttack());
				LogPlayerAttack(monster); // 내가 때림

				PressAnyKey();
				if (monster->GetHP() <= 0) // 몬스터 죽음
				{
					ClearScreen();
					monster->PrintMonster();
					player->DisplayStatus();

					cout << "유저 승" << endl;
					bBattle = false;
					// 전리품
					if (player->GetLevel() < player->GetMaxLevel()) // 레벨이 10 미만이라면
					{
						LogAddExp(); // 경험치 획득
						if (player->GetExp() >= player->GetMaxExp()) // 레벨업 조건 충족
						{
							LogLevelUp();
						}
					}
					LogAddGold(); // 골드 획득
					if (itemDropRate < 30) // 30% 확률로 아이템 획득
					{
						cout << "30% 확률로 기본물약 2종 1개씩 획득!" << endl;
						AddRandomItem();
					}
					LogAddItem(monster); // 몬스터 드랍템 획득
					if (bAttackBoost)
					{
						LogRemoveAttackBoost(); // 공격력 부스트 해제
					}
					PressAnyKey();
					if (bBoss)
					{
						PrintGameClear();
						bBattle = false;
						bGameOver = false;
					}
					break;
				}
				if (monster->GetHP() > 0)
				{
					player->SetHP(player->GetHP() - monster->GetAttack());
					LogMonsterAttack(monster); // 몬스터가 때림
					PressAnyKey();
					if (player->GetHP() <= 0)
					{
						cout << endl;
						cout << "몬스터 승" << endl; // 여기서 게임 종료해야함
						PrintGameOver();
						bBattle = false;
						bGameOver = false;
						break;
					}
				}
			}
			break;
		}
		case '2':
		{
			char inventoryChoice;
			ClearScreen();
			monster->PrintMonster();
			PrintRandomItem(Character::GetInstance(""));
			PrintRandomItemMenu();

			cin >> inventoryChoice;

			switch (inventoryChoice)
			{
			case '1':
				ClearScreen();
				monster->PrintMonster();
				bAttackBoost = player->RandomUse();
				PressAnyKey();
				break;
			case '0':
				// 뒤로
				break;
			default:
				break;
			}
			break;
		}
		default:
			break;
		}
	}
	delete monster;
	monster = nullptr;
}

void GameManager::PrintInventory(Character* player)
{
	auto& inventory = player->GetInventory();

	for (int i = 0; i < inventory.size(); ++i)
	{
		cout << i + 1 << ". " << inventory[i]->GetName() << " (x" << inventory[i]->GetCount() << ")" << endl;
	}
	cout << endl;
	PressAnyKey();
}

void GameManager::PrintRandomItem(Character* player)
{
	auto& inventory = player->GetInventory();
	int index = 1;

	for (int i = 0; i < inventory.size(); ++i)
	{
		if (inventory[i]->GetItemType() == 1)
		{
			cout << index++ << ". " << inventory[i]->GetName() << " (x" << inventory[i]->GetCount() << ")" << endl;
		}
	}

}

void GameManager::GameRunning()
{
	Character* player = Character::GetInstance("");
	char menuChoice;
	bool bMenu = true;

	while (bGameOver)
	{
		Battle(player);
		bMenu = true;
		if(bGameOver == false)
		{
			break; // 클리어 or 게임오버 라면 게임 종료
		}
		while (bMenu)
		{
			ClearScreen();
			player->DisplayStatus();
			cout << endl;
			cout << "어떻게 할까?" << endl;
			cout << "1. 계속 싸우러 간다." << endl;
			cout << "2. 가방" << endl;
			cout << "3. 상점" << endl;
			cout << endl;
			cout << "입력: ";
			cin >> menuChoice;

			switch (menuChoice)
			{
			case '1': // 계속 싸움
				bMenu = false;
				break;
			case '2': // 가방
			{
				ClearScreen();
				PrintInventory(player);
				break;
			}
			case '3':
				// 상점
				cout << "미구현" << endl;
				break;
			default:
				break;
			}
		}
	}
}

void GameManager::AddRandomItem()
{
	Item* hpItem = new HPPotion();
	Item* attackItem = new AttackBoost();

	Character::GetInstance("")->AddItem(hpItem);
	Character::GetInstance("")->AddItem(attackItem);
}