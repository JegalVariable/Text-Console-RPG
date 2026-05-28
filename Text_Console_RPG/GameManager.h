#pragma once

class Monster;
class Character;

class GameManager
{
private:
	bool bGameOver = true;

public:
	Monster* GenerateMonster(int level);
	Monster* GenerateDragon(int level);

	void CreateCharacter();
	void Battle(Character* player);
	void PrintInventory(Character* player);
	void PrintRandomItem(Character* player);
	void GameRunning();
	void BossRunning();
	void AddRandomItem();

	bool GetBGameOver() const { return bGameOver; }
	void SetBGameOver(bool bGameOver) { this->bGameOver = bGameOver; }
};

