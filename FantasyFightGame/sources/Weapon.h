// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Weapon
{
private:
string name;
string description;
int cost;
int damage;

public:
Weapon();
string getName();
string getDescription();
int getCost();
int getDamage();
void setName(string);
void setDescription(string);
void setCost(int);
void setDamage(int);
virtual string showWeapon() =0;
virtual string attack()=0;
virtual ~Weapon() {};
};
