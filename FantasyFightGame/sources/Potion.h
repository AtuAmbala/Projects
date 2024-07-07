// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Potion
{
private:
string name;
string description;
int cost;
int effect;

public:
Potion();
string getName();
string getDescription();
int getCost();
int getEffect();
void setName(string);
void setDescription(string);
void setCost(int);
void setEffect(int);
virtual string showPotion() =0;
virtual ~Potion() {};

};
