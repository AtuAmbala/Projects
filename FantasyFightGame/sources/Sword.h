// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#pragma once
#include <string>
#include <iostream>
#include "Weapon.h"
using namespace std;

class Sword: public Weapon
{
private:
    int swings;
public:
    Sword();
    string showWeapon();
    void addSwings(int moreSwings);
    string attack();
};
