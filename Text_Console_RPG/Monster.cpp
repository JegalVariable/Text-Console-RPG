#include <iostream>

#include "Monster.h"
#include "Item.h"
#include "GameLogManager.h"

using namespace std;

Monster::Monster(const std::string& name, int hp, int attack)
	: name(name), hp(hp), attack(attack) { }

void Monster::TakeDamage(int damage)
{
	hp -= damage;
}

Slime::Slime(int hp, int attack)
	: Monster("Slime", hp, attack) { }

Item* Slime::DropItem()
{
	return new SlimeJelly();
}

void Slime::PrintMonster()
{
    ClearScreen();
	cout << R"(
         ______
      .-"      "-.
    .'  ^    ^    '.
   /      ¡ä         \
   \    \___/       /
    '.___________.'

)";
}

Goblin::Goblin(int hp, int attack)
	: Monster("Goblin", hp, attack) { }

Item* Goblin::DropItem()
{
	return new GoblinLeather();
}

void Goblin::PrintMonster()
{
    ClearScreen();
    cout << R"(
          ,      ,
         /(.-""-.)\
     |\  \/      \/  /|
     | \ / =.  .= \ / |
     \( \   o\/o   / )/
      \_, '-/  \-' ,_/
        /   \__/   \
        \ \__/\__/ /
      ___\ \|--|/ /___
    /`    \      /    `\
   /       '----'       \

)";
}

Orc::Orc(int hp, int attack)
    : Monster("Orc", hp, attack) { }

Item* Orc::DropItem()
{
    return new OrcHammer();
}
void Orc::PrintMonster()
{
    ClearScreen();
    cout << R"(
        __,='`````'=/__
        '//  (o) \(o) \ `'         _,-,
        //|     ,_)   (`\      ,-'`_,-\
       ,-~~~\  `'==='  /-,      \==```` \
      /        `----'     `\     \       \
   ,-`                  ,   \  ,.-\       \
  /      ,               \,-`\`_,-`\_,..--'\
 ,`    ,/,              ,>,   )     \--`````\
 (      `\`---'`  `-,-'`_,<   \      \_,.--'`
  `.      `--. _,-'`_,-`  |    \
   [`-.___   <`_,-'`------(    /
   (`` _,-\   \ --`````````|--`
    >-`_,-`\,-` ,          |
  <`_,'     ,  /\          /
   `  \/\,-/ `/  \/`\_/V\_/

)";
}

Dragon::Dragon(int hp, int attack)
    : Monster("Dragon", hp, attack) { }

Item* Dragon::DropItem()
{
    return new DragonHorn();
}

void Dragon::PrintMonster()
{
    ClearScreen();
    cout << R"(
                      / \  //\
         |\___/|      /   \//  \\
         /0  0  \__  /    //  | \ \
        /     /  \/_/    //   |  \  \
        @_^_@'/   \/_   //    |   \   \
        //_^_/     \/_ //     |    \    \
     ( //) |        \///      |     \     \
   ( / /) _|_ /   )  //       |      \     _\
 ( // /) '/,_ _ _/  ( ; -.    |    _ _\.-~        .-~~~^-.
(( / / )) ,-{        _      `-.|.-~-.           .~         `.
(( // / ))  '/\      /                 ~-. _ .-~      .-~^-.  \
(( /// ))      `.   {            }                   /      \  \
 (( / ))     .----~-.\        \-'                 .~         \  `. \^-.
            ///.----..>        \             _ -~             `.  ^-`  ^-_
              ///-._ _ _ _ _ _ _}^ - - - - ~                     ~-- ,.-~

)";
}