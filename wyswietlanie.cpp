#pragma once
#include "stdafx.h"
#include "wyswietlanie.h"
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include "postac.h"
using namespace std;

void gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}

Menu::Menu()
{
	ifstream plik;
	plik.open("menu.txt");
	for (int i = 0; i < 4; i++)
	{
		getline(plik, opcja[i].pytanie);
		plik >> opcja[i].x;
		for (int j = 0; j < opcja[i].x; j++) getline(plik, opcja[i].odpowiedzi[j]);
	}
	plik.close();
}
int Menu:: wybor(int numer)
{
	int ruch;
	int x = 0, y = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
	do
	{
		gotoxy(0, 0);
		cout << opcja[numer].pytanie<<endl;
		for (int a = 0; a<opcja[numer].x; a++)
		{
			int b = 0;
			if (a == (y - 1))
			{
				gotoxy(x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 158);
				cout << opcja[numer].odpowiedzi[a];
				gotoxy(x, y);
				cout<<"-->"<<endl;
			}
			else
			{

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
			cout << opcja[numer].odpowiedzi[a]<<endl;
			}
			///
		}
		ruch = _getch() + 1000;
		if (ruch == 1072) { if (y == 1)y = opcja[numer].x;  else y--; }
		if (ruch == 1080) { if (y == opcja[numer].x) y = 1; else y++; }
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
	} while (ruch != 1077);
	return y - 1;
}
int Menu::wyborwsklepie(Shop &sklep)
{
	int ruch;
	int x = 0, y = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
	do
	{
		gotoxy(0, 0);
		cout << "co chcialbys kupic?" << endl;
		for (int a = 0; a<30; a++)
		{
			int b = 0;
			if (a == (y - 1))
			{
				gotoxy(x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 158);
				cout <<"	"<< sklep.shop[a].name << ". Moc przedmiotu: " << sklep.shop[a].value<<"Cena :"<<sklep.prices[a]<<endl;
				gotoxy(x, y);
				cout << "-->" << endl;
			}
			else
			{

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
				cout <<"	"<< sklep.shop[a].name << ". Moc przedmiotu: " << sklep.shop[a].value << "Cena :" << sklep.prices[a]<<endl;
			}
			///
		}
		ruch = _getch() + 1000;
		if (ruch == 1072) { if (y == 1)y = 30;  else y--; }
		if (ruch == 1080) { if (y == 30) y = 1; else y++; }
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
	} while (ruch != 1077);
	return y - 1;
}