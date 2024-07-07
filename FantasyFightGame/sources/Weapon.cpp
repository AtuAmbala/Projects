// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#include "Weapon.h"

Weapon::Weapon()
{
    name = "weapon1";
    description = "inflicts damage";
    cost=10;
    damage =10;
}

string Weapon::getName()
{
    return name;
}

string Weapon::getDescription()
{
    return description;
}

int Weapon::getCost()
{
    return cost;
}

int Weapon::getDamage()
{
    return damage;
}

void Weapon::setName(string newName)
{
    name = newName;
}

void Weapon::setDescription(string newDesc)
{
    description=newDesc;
}

void Weapon::setCost(int newCost)
{
    cost =newCost;
}

void Weapon::setDamage(int newDamage)
{
    damage = newDamage;
}
