#include <iostream>

//Text Rpg

enum PlayerType
{
	PT_Knight =1,
	PT_Archer =2,
	PT_Mage =3,
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};

struct ObjectInfo
{
	int Type;
	int hp;
	int attack;
	int defence;
};

ObjectInfo playerInfo;
ObjectInfo monsterInfo;


void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();

int main()
{
	//랜덤시드 생성
	srand(time(0));

	EnterLobby();
	return 0;
}

void EnterLobby()
{
	std::cout << "--------------------" << std::endl;
	std::cout << "로비에 입장했습니다!" << std::endl;
	std::cout << "--------------------" << std::endl;

	SelectPlayer();

	std::cout << "------------------------" << std::endl;
	std::cout << "(1)필드입장 (2)게임종료" << std::endl;
	std::cout << "------------------------" << std::endl;

	int input{};
	std::cin >> input;

	if (input == 1)
	{
		EnterField();
	}
	else
	{
		return;
	}
}

void SelectPlayer()
{
	while (true)
	{
		std::cout << "--------------------" << std::endl;
		std::cout << "직업을 골라주세요" << std::endl;
		std::cout << "(1)기사 (2)궁수 (3)법사" << std::endl;
		std::cout << "--------------------" << std::endl;

		std::cin >> playerInfo.Type;

		if (playerInfo.Type == PT_Knight)
		{
			std::cout << "기사 생성중... !" << std::endl;
			playerInfo.hp = 150;
			playerInfo.attack = 10;
			playerInfo.defence = 5;
			break;
		}
		else if (playerInfo.Type == PT_Archer)
		{
			std::cout << "궁수 생성중... !" << std::endl;
			playerInfo.hp = 100;
			playerInfo.attack = 15;
			playerInfo.defence = 3;
			break;
		}
		else if (playerInfo.Type == PT_Mage)
		{
			std::cout << "법사 생성중... !" << std::endl;
			playerInfo.hp = 80;
			playerInfo.attack = 25;
			playerInfo.defence = 0;
			break;
		}
		else
		{
			std::cout << "잘못입력하셧습니다 다시입력해주세요!" << std::endl;
		}
	}
	
}

void EnterField()
{
	while (true)
	{
		std::cout << "--------------------" << std::endl;
		std::cout << "필드에 입장했습니다!" << std::endl;
		std::cout << "--------------------" << std::endl;

		std::cout << "[PLAYER] HP : " << playerInfo.hp << " / ATK : "<< playerInfo.attack
			<< " /DEF : " << playerInfo.defence << std::endl;

		CreateRandomMonster();
		std::cout << "----------------" << std::endl;
		std::cout << "(1)전투 (2)도주" << std::endl;
		std::cout << "----------------" << std::endl;

		int input;
		std::cin >> input;
		if (input == 1)
		{
			EnterBattle();
			if (playerInfo.hp == 0)
			{
				return;
			}
		}
		else
		{
			return;
		}
	}
}

void CreateRandomMonster()
{
	monsterInfo.Type =  1 + (rand() % 3);

	switch (monsterInfo.Type)
	{
	case MT_Slime:
		std::cout << "슬라임 생성중 ...!(HP:15 / ATK:5 / DEF:0)" <<std::endl;
		monsterInfo.hp = 15;
		monsterInfo.attack = 5;
		monsterInfo.defence = 0;
		break;
	case MT_Orc:
		std::cout << "오크 생성중 ...!(HP:40 / ATK:10 / DEF:3)" << std::endl;
		monsterInfo.hp = 40;
		monsterInfo.attack = 10;
		monsterInfo.defence = 3;
		break;
	case MT_Skeleton:
		std::cout << "스켈레톤 생성중 ...!(HP:80 / ATK:15 / DEF:5)" << std::endl;
		monsterInfo.hp = 80;
		monsterInfo.attack = 15;
		monsterInfo.defence = 5;
		break;
	default:
		break;
	}
}

void EnterBattle()
{
	while (true)
	{
		int damage = playerInfo.attack - monsterInfo.defence;
		if (damage < 0)
		{
			damage = 0;
		}

		monsterInfo.hp -= damage;
		if (monsterInfo.hp < 0)
		{
			monsterInfo.hp = 0;
		}

		std::cout << "몬스터 남은 체력 : " << monsterInfo.hp << std::endl;
		if (monsterInfo.hp == 0)
		{
			std::cout << "몬스터를 처치 했습니다 !" << std::endl;
			return;
		}

		int damage2 = monsterInfo.attack - playerInfo.defence;
		if (damage2 < 0)
		{
			damage2 = 0;
		}

		playerInfo.hp -= damage2;
		if (playerInfo.hp < 0)
		{
			playerInfo.hp = 0;
		}
		std::cout << "플레이어 남은 체력 : " << playerInfo.hp << std::endl;
		if (playerInfo.hp == 0)
		{
			std::cout << "당신은 사망했습니다... Game Over" << std::endl;
			return;
		}
	}
}