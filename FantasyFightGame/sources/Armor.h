// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Armor
{
private:
string name;
string description;
int cost;
int value;

public:
Armor();
string getName();
string getDescription();
int getCost();
int getValue();
void setName(string);
void setDescription(string);
void setCost(int);
void setValue(int);
virtual string showArmor() =0;
virtual ~Armor() {};
};
