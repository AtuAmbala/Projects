// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Weapon.h"
#include "Potion.h"
#include "Armor.h"
#include "DamagePotion.h"
#include "HealthPotion.h"
#include "ClubArmor.h"
#include "GunArmor.h"
#include "SwordArmor.h"
#include "Club.h"
#include "Sword.h"
#include "Gun.h"
using namespace std;

class Store
{
private:
    vector <Weapon*> weapons;
    vector <Armor*> armorOptions;
    vector <Potion*> potions;
public:
    Store();
    string viewPotions();
    string vewWeapons();
    string viewArmor();
    Potion* buyPotion(int);
    Armor* buyArmor(int);
    Weapon* buyWeapon(int);
    ~Store();
    int potionCost(int num);
    int weaponCost(int num);
    int armorCost(int num);
    
};
