#include <iostream>
#include <cstdlib>

#include "GameLogManager.h"
#include "Character.h"
#include "Monster.h"
#include "Item.h"

using namespace std;

void PressAnyKey()
{
	system("pause");
}

void ClearScreen() // 콘솔창 지우기
{
	system("cls");
}

void GameIntroOne()
{
	cout << "===================================" << endl;
	cout << endl;
	cout << "        Text_Console_RPG" << endl;
	cout << endl;
	cout << "===================================" << endl;
	cout << endl;
	PressAnyKey();

	ClearScreen();
	cout << "\"윽... 방금 드래곤의 공격으로 기절했던 건가 ?\"" << endl;
	cout << "\"잠깐! 내 이름이 뭐였지?\"" << endl;
	cout << endl;
	cout << "이름을 입력하시오: ";
}

void GameIntroTwo(std::string name)
{
	cout << "\"맞아 내 이름은 " << name << " 이었지\"" << endl;
	cout << endl;
	cout << "고개를 들어 정면을 바라본다." << endl;
	cout << "게이트에서 몬스터가 나오려고 하는게 보인다." << endl;
	cout << endl;
	cout << "\"그래...지금 이럴때가 아니야...\"" << endl;
	cout << endl;
	cout << "검을 들고 몬스터를 막으러 달려간다." << endl;
	cout << endl;
	PressAnyKey();
	ClearScreen();
}

void PrintGameOver()
{
	cout << "당신은 죽었습니다." << endl;
	cout << "GAME OVER!" << endl;
	cout << "게임이 종료됩니다." << endl;
}

void PrintRandomItemMenu()
{
	cout << endl;
	cout << "아이템은 50% 확률로 체력회복, 50% 확률로 공격력이 증가합니다." << endl;
	cout << "아이템을 사용하시겠습니까?" << endl;
	cout << endl;
	cout << "1. 예" << endl;
	cout << "0. 아니오(뒤로)" << endl;
	cout << endl;
	cout << "입력: ";
}

void PrintBattleMenu(Monster* monster)
{
	monster->PrintMonster();
	cout << endl;
	Character::GetInstance("")->DisplayStatus();
	cout << "어떻게 할까?" << endl;
	cout << "1. 공격 " << endl;
	cout << "2. 물약 가방" << endl;
	cout << endl;
	cout << "입력: ";
}

void PrintGameClear()
{
	cout << endl;
	cout << "당신은 게이트를 막았습니다" << endl;
	cout << "GAME CLEAR!" << endl;
	cout << "게임이 종료됩니다." << endl;
}

void LogUseHPPotion(int index)
{
	Character* player = Character::GetInstance("");

	if (player->GetHP() >= player->GetMaxHP())
	{
		cout << "이미 최대 체력입니다." << endl;
	}
	else
	{
		cout << "체력이 회복되었습니다. " << player->GetHP() << " -> ";

		player->UseItem(index);

		cout << player->GetHP() << endl;
	}
}

void LogUseAttackBoost(int index)
{
	Character* player = Character::GetInstance("");

	cout << "공격력이 증가하였습니다 . " << player->GetAttack() << " -> ";

	player->UseItem(index);

	cout << player->GetAttack() << endl;
}

void LogRemoveAttackBoost()
{
	Character* player = Character::GetInstance("");

	cout << "전투가 종료되어 공격력이 돌아옵니다." << player->GetAttack();
	player->SetAttack(player->GetAttack() - 10);
	cout << " -> " << player->GetAttack() << endl;
}

void LogPlayerAttack(Monster* monster)
{
	Character* player = Character::GetInstance("");

	cout << player->GetName() << "의 공격! " << monster->GetName();
	cout << "의 체력: " << monster->GetHP() << endl;
}

void LogMonsterAttack(Monster* monster)
{
	Character* player = Character::GetInstance("");

	cout << monster->GetName() << "의 공격! " << player->GetName();
	cout << "의 체력: " << player->GetHP() << endl;
}

void LogAddGold()
{
	int dropGold = rand() % 11 + 10; // 10~20
	Character::GetInstance("")->SetGold(Character::GetInstance("")->GetGold() + dropGold);
	cout << dropGold << "골드 획득! 현재 골드: " << Character::GetInstance("")->GetGold() << endl;
}

void LogAddExp()
{
	Character::GetInstance("")->AddExp(); // 경험치 획득
	cout << "50 경험치 획득! 현재Exp: " << Character::GetInstance("")->GetExp() << endl;
}

void LogAddItem(Monster* monster)
{
	Item* dropItem = monster->DropItem();

	string itemName = dropItem->GetName();

	Character::GetInstance("")->AddItem(dropItem); // 몬스터 드랍템은 100% 획득
	
	cout << itemName << " 획득!" << endl;
	cout << "아이템은 모두 가방에 저장되었습니다." << endl;
	cout << endl;
}

void LogLevelUp()
{
	cout << "레벨 UP! Lv." << Character::GetInstance("")->GetLevel();
	Character::GetInstance("")->LevelUp();
	cout << " -> Lv." << Character::GetInstance("")->GetLevel() << endl;
}