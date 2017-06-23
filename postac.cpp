#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "postac.h"
#include "wyswietlanie.h"
#include "walka.h"
using namespace std;

Menu menu;

Character ::Character()
{
	streght = 0; vitality = 0; agillity = 0; luck=0;
	cout << "Podaj imie swojej postaci\n";
	getline(cin, charactername);
	system("cls");
	for (int a = 0; a < 10; a++) this->Advance(menu.wybor(0));////////////////////////////////////////////
	cout << endl << "Stworzyles nowa postac";
	Sleep(1500);
}

void Character :: Advance(int a)
{
	switch (a)
	{
	case 0: streght++; break;
	case 1: vitality++; break;
	case 2: agillity++; break;
	case 3: luck++; break;
	default: cout << "Wybierz inna umiejetnosc"; break;
	}

}

User::User(int mn) : Character()
{
	for (int i = 0; i < 6; i++)
	{
		equipment[i].name = "Brak";
		equipment[i].value = 0;
	}
	money = mn;
}

void User::Addmoney(int a)
{
	this->money += a;
}
Shop::Shop()
{
	fstream plik;
	plik.open("shop.txt");
	for (int a = 0; a <30; a++)
	{
		getline(plik, shop[a].name);
		plik >> shop[a].type;
		plik >> shop[a].value;
		plik >> prices[a];
	}
	plik.close();
}

void Shop::buyItem(User &user, int ID)
{ 
	if (user.money >= prices[ID])
	{
		user.equipment[shop[ID].type] = shop[ID];
		user.money -= prices[ID];
	}
	else cout << "Masz za ma³o pieniedzy";
}
void Character::Showstats()
{
	system("cls");
	cout << " Sila: " << streght << endl;
	cout << " witalonsc: " << vitality << endl;
	cout << " szybkosc: " << agillity << endl;
	cout << " szczescie: " << luck << endl;
	Sleep(1800);
}