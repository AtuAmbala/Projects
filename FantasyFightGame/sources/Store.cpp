// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210
#include "Store.h"
#include "Potion.h"

Store::Store()
{
    potions.push_back(new DamagePotion());
    potions.push_back(new HealthPotion());

    armorOptions.push_back(new GunArmor());
    armorOptions.push_back(new ClubArmor());
    armorOptions.push_back(new SwordArmor());

    weapons.push_back(new Gun());
    weapons.push_back(new Club());
    weapons.push_back(new Sword());
}

string Store::viewPotions()
{
    string result= "Here are the potion options: \n 1. ";
    result += potions[0]->getDescription() + "\n2. ";
    result += potions[1]->getDescription() ;

    return result;
}

string Store::vewWeapons()
{
    string result= "Here are the weapon options: \n1. ";
    result += weapons[0]->getDescription() + "\n2. ";
    result += weapons[1]->getDescription() + "\n3.";
    result += weapons[2]->getDescription() ;
    return result;
}

string Store::viewArmor()
{
    string result= "Here are the weapon options: \n1. ";
    result += armorOptions[0]->getDescription() + "\n2. ";
    result += armorOptions[1]->getDescription() + "\n3.";
    result += armorOptions[2]->getDescription() ;
    return result;
}

Potion* Store::buyPotion(int num)
{  
    return potions[num-1];
}

Armor* Store::buyArmor(int num)
{
    return armorOptions[num-1];
}

Weapon* Store::buyWeapon(int num)
{
    return weapons[num-1];
}

int Store::potionCost(int num)
{
    return potions[num-1]->getCost();
}

int Store::weaponCost(int num)
{
    return weapons[num-1]->getCost();
}

int Store::armorCost(int num)
{
    return armorOptions[num-1]->getCost();
}
Store::~Store()
{
    /*for (int i = 0; i < weapons.size(); i++) {
    delete weapons[i];
    }

    for (int i = 0; i < armorOptions.size(); i++) {
    delete armorOptions[i];
    }

    for (int i = 0; i < potions.size(); i++) {
    delete potions[i];
    } */
    weapons.clear();
    armorOptions.clear();
    potions.clear();


}