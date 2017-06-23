#include "stdafx.h"
#include"walka.h"
#include<iostream>
#include "wyswietlanie.h"
#include "postac.h"
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

const int mbn = 4;

Menu menuu;
Battle::Battle()
{
	ifstream plik;
	plik.open("enemies.txt");
	for (int a = 0; a < 4; a++) 
	{
		int skills[4];
		for (int a = 0; a < 4; a++)plik >> skills[a];
		Enemy[a].damage = 10+15 * (skills[0] + (rand() % 7));
		Enemy[a].health = 100 + 15 * skills[1];
		Enemy[a].agility = skills[2];
		Enemy[a].luck = skills[3];
		Enemy[a].position = 6;
	}
	plik.close();
}
void Battle::Attack1(Gladiator a, Gladiator b)
{
	if (abs(a.position - b.position) == 1) {
		if (((rand() % 100) - 5 * a.luck + 5 * b.agility) <= 100)
		{
			cout << "Trafiles przeciwnika i zadales mu " << a.damage/2 <<endl;
			cout << " obrazen\n ";
			//if (b.armor > 0)b.armor -= a.damage * 0, 5;
			/*else*/ b.health = b.health - a.damage/2;
			cout << "Przeciwnik ma teraz " << b.health << " hp";
		}
		else cout << "Przciwnik wykonal unik";
	}
	else cout << "Machanie mieczem z dala od przwciwnika jest bez sensu" << endl;
}
void Battle::Attack2(Gladiator a, Gladiator b)
{
	if (abs(a.position - b.position) == 1) {
	if (((rand() % 100) - 5 * a.luck + 5 * b.agility) <= 75)
	{
		cout << "Trafiles przeciwnika i zadales mu " << a.damage*3/4 << endl;
		cout << " obrazen\n ";
		//if (b.armor > 0)b.armor -= a.damage * 0,75;
		/*else*/ b.health = b.health - a.damage *3/4;
		cout << "Przeciwnik ma teraz " << b.health << " hp"<<endl;
	}
	else cout << "Przciwnik wykonal unik" << endl;
	}
	else cout << "Machanie mieczem z dala od przwciwnika jest bez sensu" << endl;
}
void Battle::Attack3(Gladiator a, Gladiator b)
{
	if (abs(a.position - b.position) == 1) {
	if (((rand() % 100) - 5 * a.luck + 5 * b.agility) <= 50)
	{
		cout << "Trafiles przeciwnika i zadales mu " << a.damage << " obrazen\n " << endl;
		//if (b.armor > 0)b.armor -= a.damage * 1;
		/*else*/ b.health = b.health - a.damage * 1;
		cout << "Przeciwnik ma teraz " << b.health << " hp"<<endl;
	}
	else cout << "Przciwnik wykonal unik" << endl;
	}
	else cout << "Machanie mieczem z dala od przwciwnika jest bez sensu" << endl;
}
void Battle::Move(Gladiator a,Gladiator c, int b)
{
	if (b == 0) 
	{
		if (a.position == 0) cout << "Probowales sie cofnac ale odbiles sie od konca areny" << endl;
		else
		{
			if (abs(a.position - c.position) == 1) cout << "Probowales wskoczyc na przeciwnika ale sie nie udalo" << endl;
			else a.position--;  cout << "Poruszyles sie" << endl;
		}
	}
	else {
		if (abs(a.position - c.position)==1) cout << "Probowales wskoczyc na przeciwnika ale sie nie udalo" << endl;
		else
		{
			if (a.position == 9) cout << "Probowales sie cofnac ale odbiles sie od konca areny" << endl;
			else a.position++; cout << "Poruszyles sie" << endl;
		}
	}
}

Letsfight::Letsfight(User &user) :Battle() {};

void Letsfight::Fight(User &user,int nr)
{
	Me.agility = user.agillity;
	Me.damage = 10+ 15 * (user.streght + user.equipment[0].value);
	Me.health = 100;// +15 * user.vitality;
	Me.luck = user.luck;
	Me.armor = 0; for (int a = 1; a <= 6; a++)Me.armor += user.equipment[a].value;
	Me.position = 3;
	int b = 0;
	system("cls");
	do
	{
		Sleep(1300);
		system("cls");
		switch (menuu.wybor(1))///////////////////////////////////////////////////////////////////////////////////////////////////////////////
		{
		case 0: Attack1(Me, Enemy[nr]); break;
		case 1: Attack2(Me, Enemy[nr]); break;
		case 2: Attack3(Me, Enemy[nr]); break;
		case 3: Move(Me,Enemy[nr], 0); break;
		case 4: Move(Me,Enemy[nr],1); break;
		default: cout << "Pib pop, straszny blad"; break;
		}
		if (Enemy[nr].health <= 0) break;
		switch (1)
		{
		case 0: Attack1(Enemy[nr], Me); break;
		case 1: Attack2(Enemy[nr], Me); break;
		case 2: Attack3(Enemy[nr], Me); break;
		case 3: Move(Enemy[nr],Me, 0); break;
		case 4: Move(Enemy[nr],Me, 1); break;
		default: cout << "Pib pop, straszny blad"; break;
		}
		if (Me.health <= 0)
		{
			cout << endl<<" Koniec gry. Umierasz!";
			exit(0);
		}
		b++;
	} while (1);
	cout << "Pokonales przeciwnika";
	user.Addmoney(200);
}
Battle::~Battle()
{};
