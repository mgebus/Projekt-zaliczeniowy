// projekt na zaliczenie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "postac.h"
#include "walka.h"
#include "wyswietlanie.h"
#include "targetver.h"
#include <iostream>
#include <Windows.h>

Menu mainmenu;

int main()
{
	int l = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
	std::cout << "Witaj w grze o gladiatorach"<<endl;
	Sleep(10);
	User user(500);
	Letsfight fight(user);
	Shop sklep;
 	while (l<5)
	{
		switch (mainmenu.wybor(2))
		{
		case 0: user.Showstats(); break;
		case 1:	sklep.buyItem(user, mainmenu.wyborwsklepie(sklep));
		case 2: {fight.Fight(user, l); l++; } break;
		default:
			break;
		}
	}
	cout << "wygrales";
    return 0;
}

