// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#include "Armor.h"

Armor::Armor()
{
    name = "Armor1";
    description = "protects player";
    cost=10;
    value =10;
}

string Armor::getName()
{
    return name;
}

string Armor::getDescription()
{
    return description;
}

int Armor::getCost()
{
    return cost;
}

int Armor::getValue()
{
    return value;
}

void Armor::setName(string newName)
{
    name = newName;
}

void Armor::setDescription(string newDesc)
{
    description=newDesc;
}

void Armor::setCost(int newCost)
{
    cost =newCost;
}

void Armor::setValue(int newValue)
{
    value = newValue;
}


