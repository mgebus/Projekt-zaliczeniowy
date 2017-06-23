#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "postac.h"
using namespace std;

struct Gladiator
{
	int health,damage,armor,agility,luck,position;
};
class Battle
{
	static int battlenumber; 
public:
	Gladiator Me, Enemy[10];
	Battle();
	void Attack1(Gladiator,Gladiator);
	void Attack2(Gladiator,Gladiator);
	void Attack3(Gladiator,Gladiator);
	void Move(Gladiator,Gladiator,int);
	~Battle();
};
class Letsfight : public Battle
{
public:
	Letsfight(User &user);
	void Fight( User &,int);
};