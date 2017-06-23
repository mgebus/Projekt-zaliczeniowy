#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;

struct Item
{
	string name;
	int value, type;
};
class Character
{
	string charactername;
	int streght, vitality, agillity, luck;
public:
	Character(/*string cn,int strenght, int vitality, int agillity, int luck*/);
	void Advance(int a);
	void Showstats();
	friend class Battle;
	friend class Letsfight;
};
class User :public Character
{
	int money;
	Item equipment[6];// 0- bron, 1-helm, 2-zborja,3-rekawice, 4-tarcza, 5-buty.
public:
	User(/*string cname,*/ int mn/* int a, int b, int c, int d*/);
	void Addmoney(int);
	friend class Shop;
	friend class Battle;
	friend class Letsfight;
};
class Shop
{
	int prices[30];
	Item shop[30];
public:
	Shop();
	void buyItem(User &user, int ID);
	friend int wyborwsklepie(Shop &);
	friend class Menu;

};