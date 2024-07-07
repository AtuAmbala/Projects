// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#include "Potion.h"

Potion::Potion()
{
    name = "Potion1";
    description = "Extra Perks";
    cost=10;
    effect=10;
}

string Potion::getName()
{
    return name;
}

string Potion::getDescription()
{
    return description;
}

int Potion::getCost()
{
    return cost;
}

int Potion::getEffect()
{
    return effect;
}

void Potion::setName(string newName)
{
    name = newName;
}

void Potion::setDescription(string newDesc)
{
    description=newDesc;
}

void Potion::setCost(int newCost)
{
    cost =newCost;
}

void Potion::setEffect(int newEffect)
{
   effect= newEffect;
}


