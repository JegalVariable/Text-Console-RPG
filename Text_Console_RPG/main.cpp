#include <iostream>
#include <string>

#include "GameManager.h"
#include "Item.h"
#include "Monster.h"
#include "Character.h"

using namespace std;

int main(void)
{
	Character* player = nullptr;

	string name = "";

	char mainMenuChoice = 0;

	bool bMainMenu = true;
	bool bGameRunning = true;

	cout << "이름을 입력하시오: ";
	getline(cin, name);

	player = new Character(name); // 캐릭터 생성
	Battle(player);

	while (bMainMenu)
	{
		cout << "1. 스탯" << endl;
		cout << "2. 전투" << endl;
		cout << "3. 상점" << endl;
		cout << "4. 인벤" << endl;
		cout << "0. 종료" << endl;
		cin >> mainMenuChoice;

		switch (mainMenuChoice)
		{
		case '1':
			cout << "스탯" << endl;
			player->DisplayStatus();
			break;
		case '2':
			cout << "전투" << endl;
			Battle(player);
			break;
		case '3':
			cout << "상점" << endl;
			break;
		case '4':
			cout << "인벤" << endl;
			break;
		case '0':
			bMainMenu = false;
			break;
		default:
			cout << "다시 입력해주세요" << endl;
			// 콘솔창 지우기
			break;
		}
	}

	//while (bGameRunning)
	{

	}
	

	delete player;
	return 0;
}

/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "Player.h"
#include "Job.h"
#include "Monster.h"
#include "Item.h"
#include "Potion.h"

using namespace std;

int main(void)
{
	const int SIZE = 4;
	int stat[SIZE] = { 0 }; // HP, MP, 공격, 방어
	string name = "";
	int HPPotion = 0;
	int MPPotion = 0;

	int choice; // 게임시작
	bool isGameStart = false;

	int jobChoice; // 직업 선택
	bool bJobChoice = false;

	int menuChoice;
	bool bMenu = false;
	Player* player = nullptr;
	Slime slime("Slime", "Slime Jelly", 30, 20, 10, 30, 30); // 슬라임 체30 공20 방10 값30 / 경30
	Goblin goblin("Goblin", "Goblin Leather", 60, 40, 20, 60, 60); // 고블린 체60 공40 방20 값60 / 경60
	//vector<Item> inventory;
	Item droppedItem;
	Inventory<Item> tInventory; // 도전5
	vector<PotionRecipe> potionRecipe;
	PotionInventory potionInventory;

	potionRecipe.push_back({ 1, "HP Potion", {{"Herb", 1 }, { "Clear Water", 1 }} });
	potionRecipe.push_back({ 2, "StaminaPotion", { {"Herb", 1}, { "Berry", 1 }} });
	potionInventory.AddRecipe("HP Potion");
	potionInventory.AddRecipe("MP Potion");
	potionInventory.AddRecipe("empty bottle");


	printBrick();
	cout << "     [ Dungeon Escape Text RPG ]" << endl;
	printBrick();
	cout << "Enter your hero's name: ";
	getline(cin, name);
	cout << endl;

	while (true) // 체력 마나 입력
	{
		cout << "Enter HP and MP: ";
		cin >> stat[0] >> stat[1];
		if (stat[0] > 50 && stat[1] > 50)
		{
			break;
		}
		else
		{
			cout << "HP or MP is too low. Try again." << endl;
		}
	}
	while (true) // 공격 방어 입력
	{
		cout << "Enter ATK and Defense: ";
		cin >> stat[2] >> stat[3];
		if (stat[2] > 50 && stat[3] > 50)
		{
			break;
		}
		else
		{
			cout << "ATK or Defense is too low. Try again." << endl;
		}
	}
	cout << endl;

	printStatus(name, stat);

	cout << "* You received 5 HP Potions and 5 MP Potions." << endl;
	printBrick();
	cout << "< Character Upgrade >" << endl;
	cout << "1. HP UP    2. MP UP    3. ATK x2" << endl;
	cout << "4. Defense x2  5. Show Stats  0. Start Game" << endl;
	printBrick();

	setPotion(5, &HPPotion, &MPPotion); // 포션 5개씩 지급

	while (!isGameStart)
	{
		cout << "Choose: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "Starting the game!" << endl << endl;
			isGameStart = true;
			break;
		case 1:
			if (HPPotion > 0)
			{
				stat[0] += 20;
				HPPotion -= 1;
				cout << "* HP increased by 20. (HP Potion used: " << HPPotion << " left)" << endl;
			}
			else
			{
				cout << "Out of HP Potions!" << endl;
			}
			break;
		case 2:
			if (MPPotion > 0)
			{
				stat[1] += 20;
				MPPotion -= 1;
				cout << "* MP increased by 20. (MP Potion used: " << MPPotion << " left)" << endl;
			}
			else
			{
				cout << "Out of MP Potions!" << endl;
			}
			break;
		case 3:
			stat[2] *= 2;
			cout << "Your ATK has doubled." << endl;
			break;
		case 4:
			stat[3] *= 2;
			cout << "Your defense has doubled." << endl;
			break;
		case 5:
			printStatus(name, stat);
			break;
		default:
			cout << "Invalid input!" << endl;
			break;
		}
	}

	cout << "     < Job Selection >" << endl;
	cout << name << ", choose your job!" << endl;
	cout << "1. Warrior   2. Magician   3. Thief   4. Archer" << endl;


	while (!bJobChoice) // 직업선택
	{
		cout << "Choose: ";
		cin >> jobChoice;
		cout << endl;

		switch (jobChoice)
		{
		case 1:
			player = new Warrior(name, stat[0], stat[1], stat[2], stat[3]);
			bJobChoice = true;
			break;
		case 2:
			player = new Magician(name, stat[0], stat[1], stat[2], stat[3]);
			bJobChoice = true;
			break;
		case 3:
			player = new Thief(name, stat[0], stat[1], stat[2], stat[3]);
			bJobChoice = true;
			break;
		case 4:
			player = new Archer(name, stat[0], stat[1], stat[2], stat[3]);
			bJobChoice = true;
			break;
		default:
			cout << "Invalid input!" << endl;
			break;
		}
	}

	player->printPlayerStatus();
	if (HPPotion > 0) // 포션이 남았다면
	{
		tInventory.AddItem({ "HP Potion", 50, HPPotion, 1 }); // 인벤에 포션 저장
	}
	if (MPPotion > 0)
	{
		tInventory.AddItem({ "MP Potion", 50, MPPotion, 1 });
	}

	while (!bMenu) // 메인메뉴
	{
		cout << "=== Main Menu ===" << endl;
		cout << "1. Enter Dungeon" << endl;
		cout << "2. Check Inventory" << endl;
		cout << "3. Potion Workshop" << endl;
		cout << "4. Potion Inventory" << endl;
		cout << "0. Quit" << endl;
		cout << endl;
		cout << "Choose: ";
		cin >> menuChoice;

		switch (menuChoice)
		{
		case 0:
			cout << "Exiting the game." << endl;
			bMenu = true;
			break;
		case 1:
		{
			int dungeonChoice = 0;
			cout << "Entered the dungeon!" << endl << endl; // 던전입장

			player->setHP(stat[0] + ((player->getLevel() - 1) * 10)); // 던전 입장과 동시에 유저, 몬스터 hp, mp 초기화
			player->setMaxHP(player->getHP());
			player->setMP(stat[1] + ((player->getLevel() - 1) * 5));
			player->setMaxMP(player->getMP());
			slime.setHP(30);
			goblin.setHP(60);

			cout << "A slime appeared!" << endl; // 슬라임 등장
			cout << "[Battle Start!] " << name << "(" << player->getJob() << ") vs " << slime.getName() << endl << endl; // 전투시작

			while (player->getHP() > 0 && slime.getHP() > 0)
			{
				printPlayerTurn();
				cin >> dungeonChoice;

				switch (dungeonChoice)
				{
				case 1:
					player->attack(&slime); // 슬라임 체30 공20 방10 값30

					if (slime.getHP() <= 0) // 유저 승 / 유저가 이긴 경우는 몬스터가 1대 때리고 끝나서 브레이크 추가
					{
						cout << endl;
						cout << "★ Victory!" << endl;
						cout << "  -> Got: " << slime.getDropItemName() << "!" << endl;
						droppedItem.name = slime.getDropItemName(); // 아이템 이름 저장
						droppedItem.price = slime.getDropItemPrice(); // 아이템 값 저장
						droppedItem.count = 1;
						droppedItem.consumables = 0;
						auto it = tInventory.FindIndex(droppedItem.name);

						if (it != (-1))
						{
							++tInventory[it].count;
						}
						else
						{
							tInventory.AddItem(droppedItem); // 중복이 없다면 인벤토리에 저장
						}
						cout << "  -> Saved to inventory." << endl; // 저장완료 출력

						player->setExp(player->getExp() + slime.getExpReward());
						cout << "  -> " << slime.getExpReward() << "EXP! (EXP: " << player->getExp() << "/" << player->getMaxExp() << ")" << endl;
						cout << endl;

						if (player->getExp() >= player->getMaxExp()) // 레벨업 했다면
						{
							player->levelUp();
						}
					}
					else if (player->getHP() <= 0) // 몬스터 승
					{
						cout << "★ defeat..." << endl;
					}
					if (slime.getHP() > 0)
					{
						cout << "--- " << slime.getName() << " Turn ---" << endl; // 몬스터가 이긴 경우는 while 조건에서 끝남
						slime.printAttack();
						slime.attack(player);
					}

					break;
				case 2: // 던전인벤
				{
					int itemChoice = 0;

					cout << "Item" << endl;
					cout << "[ Inventory ]" << endl;

					for (int i = 0; i < tInventory.GetSize(); ++i)
					{
						if (tInventory[i].consumables == 1)
						{
							cout << i + 1 << ". ";
							tInventory[i].PrintInfo();
						}
					}

					cout << endl;
					cout << "Choose item: ";
					cin >> itemChoice;

					switch (itemChoice)
					{
					case 1: // hp 포션 선택
					{
						if (player->getHP() == player->getMaxHP()) // hp가 이미 최대인 경우
						{
							cout << "Your HP is already full" << endl;
						}
						else
						{
							cout << "* HP Potion used! HP restored by 50 (" << player->getHP() << " -> "; // 사용전 hp 출력
							player->setHP(min(player->getHP() + 50, player->getMaxHP())); // 구현항목
							cout << player->getHP() << ")" << endl; // 사용후 hp 출력
							cout << endl;
							player->UseConsumable(tInventory, "HP Potion"); // hp포션 수량 줄이기
						}
						cout << endl;

						break;
					}
					case 2: // mp 포션 선택
					{
						if (player->getMP() == player->getMaxMP()) // hp가 이미 최대인 경우
						{
							cout << "Your MP is already full" << endl;
						}
						else
						{
							cout << "* MP Potion used! MP restored by 50 (" << player->getMP() << " -> ";
							player->setMP(min(player->getMP() + 50, player->getMaxMP()));
							cout << player->getMP() << ")" << endl;
							cout << endl;
							player->UseConsumable(tInventory, "MP Potion");
						}
						cout << endl;

						break;
					}
					default:
						break;
					}
					break;
				}
				default:
					break;
				}
			}

			if (player->getHP() <= 0)
			{
				break;
			}

			cout << "A goblin appeared!" << endl; // 고블린 등장
			cout << "[Battle Start!] " << name << "(" << player->getJob() << ") vs " << goblin.getName() << endl << endl; // 전투시작
			while (player->getHP() > 0 && goblin.getHP() > 0)
			{
				printPlayerTurn();
				cin >> dungeonChoice;

				switch (dungeonChoice)
				{
				case 1:
					player->attack(&goblin); // 고블린 체60 공40 방20 값60

					if (goblin.getHP() <= 0) // 유저 승 / 유저가 이긴 경우는 몬스터가 1대 때리고 끝나서 브레이크 추가
					{
						cout << endl;
						cout << "★ Victory!" << endl;
						cout << "  -> Got: " << goblin.getDropItemName() << "!" << endl;

						auto it = tInventory.FindIndex(goblin.getDropItemName());

						if (it != (-1))
						{
							++tInventory[it].count;
						}
						else
						{
							tInventory.AddItem({ goblin.getDropItemName(), goblin.getDropItemPrice(), 1, 0 }); // 중복이 없다면 인벤토리에 저장
						}
						cout << "  -> Saved to inventory." << endl; // 저장완료 출력

						player->setExp(player->getExp() + goblin.getExpReward());
						cout << "  -> " << goblin.getExpReward() << " EXP! (EXP: " << player->getExp() << "/" << player->getMaxExp() << ")" << endl;
						cout << endl;

						if (player->getExp() >= player->getMaxExp()) // 레벨업 했다면
						{
							player->levelUp();
						}
					}
					else if (player->getHP() <= 0) // 몬스터 승
					{
						cout << "★ defeat..." << endl;
					}

					if (goblin.getHP() > 0) // 몬스터 승
					{
						cout << "--- " << goblin.getName() << " Turn ---" << endl;
						goblin.printAttack();
						goblin.attack(player);
					}
					break;
				case 2:
				{
					int itemChoice = 0;

					cout << "Item" << endl;
					cout << "[ Inventory ]" << endl;

					for (int i = 0; i < tInventory.GetSize(); ++i)
					{
						if (tInventory[i].consumables == 1)
						{
							cout << i + 1 << ". ";
							tInventory[i].PrintInfo();
						}
					}
					cout << endl;
					cout << "Choose item: ";
					cin >> itemChoice;

					switch (itemChoice)
					{
					case 1: // hp 포션 선택
					{
						if (player->getHP() == player->getMaxHP()) // hp가 이미 최대인 경우
						{
							cout << "Your HP is already full" << endl;
						}
						else
						{
							cout << "* HP Potion used! HP restored by 50 (" << player->getHP() << " -> "; // 사용전 hp 출력
							player->setHP(min(player->getHP() + 50, player->getMaxHP()));
							cout << player->getHP() << ")" << endl; // 사용후 hp 출력
							cout << endl;
							player->UseConsumable(tInventory, "HP Potion"); // hp포션 수량 줄이기
						}
						cout << endl;
						break;
					}
					case 2: // mp 포션 선택
					{
						cout << player->getMP() << " / " << player->getMaxMP() << endl;
						if (player->getMP() == player->getMaxMP()) // mp가 이미 최대인 경우
						{
							cout << "Your MP is already full" << endl;
						}
						else
						{
							cout << "* MP Potion used! MP restored by 50 (" << player->getMP() << " -> ";
							player->setMP(min(player->getMP() + 50, player->getMaxMP()));
							cout << player->getMP() << ")" << endl;
							cout << endl;
							player->UseConsumable(tInventory, "MP Potion");
						}
						cout << endl;

						break;
					}
					default:
						break;
					}
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case 2:
		{
			cout << "[ Inventory (" << tInventory.GetSize() << " / " << tInventory.GetCapacity() << ") ]" << endl;
			for (int i = 0; i < tInventory.GetSize(); ++i)
			{
				cout << i + 1 << ". ";
				tInventory[i].PrintInfo();
			}
			cout << endl;
			break;
		}
		case 3: // 포션 제작소
		{
			int potionChoice;
			bool bPotionMenu = false;

			while (!bPotionMenu)
			{
				cout << endl;
				cout << "=== Potion Workshop ===" << endl;
				cout << "1. Show all recipes" << endl;
				cout << "2. Search by potion name" << endl;
				cout << "3. Search by ingredient" << endl;
				cout << "0. Go back" << endl;
				cout << endl;
				cout << "Choose: ";
				cin >> potionChoice;

				switch (potionChoice)
				{
				case 0: // 메인메뉴 돌아가기
					bPotionMenu = true;
					break;
				case 1: // 레시피 전체 출력
					for (const PotionRecipe& pR : potionRecipe)
					{
						pR.ShowAllRecipes();
						cout << endl;
					}
					break;
				case 2: // 포션 검색
				{
					string potionName = "";
					bool found = false;

					cout << "Search potion name: ";
					cin >> potionName;

					for (const PotionRecipe& pR : potionRecipe)
					{
						found = pR.SearchByName(potionName);
						if (found)
						{
							break;
						}
					}
					if (!found)
					{
						cout << "Potion not found..." << endl;
					}
					break;
				}
				case 3: // 재료검색
				{
					string ingredientName = "";
					int count = 0;

					cout << "Search ingredient: ";
					cin.ignore(); // cin이랑 혼용해서 사용
					getline(cin, ingredientName);

					for (const PotionRecipe& pR : potionRecipe)
					{
						if (pR.SearchByIngredient(ingredientName))
						{
							++count;
						}
					}
					if (count == 0)
					{
						cout << "Ingredient not found..." << endl;
					}
					else
					{
						cout << "Found " << count << " recipes." << endl;
					}
					break;
				}
				default:
					cout << "Invalid input!" << endl;
					break;
				}
			}
			break;
		}
		case 4:
		{
			int PI_Choice = 0;
			string potionName = "";
			bool PI_menu = true;

			cout << "=== Potion Inventory ===" << endl;
			cout << "1. Dispense Potion" << endl;
			cout << "2. Return Potion" << endl;
			cout << "3. Print Stock" << endl;
			cout << endl;
			cout << "Choose: ";
			cin >> PI_Choice;
			cin.ignore();

			switch (PI_Choice)
			{
			case 1:
				cout << "name: ";
				getline(cin, potionName);

				potionInventory.DispensePotion(potionName, tInventory);
				cout << endl;
				break;
			case 2:
				cout << "name: ";
				getline(cin, potionName);

				potionInventory.ReturnPotion(potionName, tInventory);
				cout << endl;
				break;
			case 3:
				cout << "name: ";
				getline(cin, potionName);

				potionInventory.GetStock(potionName);
				cout << endl;
				break;
			default:
				break;
			}
			break;
		}
		default:
			cout << "Invalid input!" << endl;
			break;
		}

	}
	delete player;
	return 0;
}
*/