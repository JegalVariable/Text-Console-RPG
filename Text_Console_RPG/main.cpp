#include <iostream>
#include <string>

#include "GameManager.h"
#include "Item.h"
#include "Monster.h"
#include "Character.h"

using namespace std;

int main(void)
{
	srand(static_cast<unsigned int>(time(nullptr)));

	GameManager gameManager;

	gameManager.CreateCharacter(); // 캐릭터 생성

	gameManager.GameRunning();

	delete Character::GetInstance("");

	return 0;
}		