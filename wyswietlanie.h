#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include "postac.h"
using namespace std;

void gotoxy(int x, int y);

struct Opcje
{ 
	string pytanie;
	int x;
	string odpowiedzi[5] ;
};

class Menu
{
	Opcje opcja[4];
public:
	Menu();
	int wybor(int);
	int wyborwsklepie(Shop &);
};