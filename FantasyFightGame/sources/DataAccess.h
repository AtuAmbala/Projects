// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#pragma once
#include <string>
#include <iostream>
#include "Beast.h"
#include "Human.h"
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

class DataAccess
{
private:
    string filename;
    Human* player;
    Beast* CPU;

public:
    DataAccess();
    void saveData(string, string, string);
    void loadData();
    vector<string> Split(string str, string token);
    ~DataAccess();
    Human* newHuman();
    Beast* newBeast();
};
