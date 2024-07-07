// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#pragma once
#include <string>
#include <iostream>
#include "Weapon.h"
using namespace std;

class Gun : public Weapon
{
private:
    int ammo;
public:
    Gun();
    string showWeapon();
    void moreAmmo(int ammunition);
    string attack();
    int showAmmo();
   
};
