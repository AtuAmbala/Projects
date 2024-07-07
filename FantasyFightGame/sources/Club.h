// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#pragma once
#include <string>
#include <iostream>
#include "Weapon.h"
using namespace std;

class Club : public Weapon
{
private:
    int swings;
public:
    Club();
    string showWeapon();
    void addSwings(int);
    string attack();
};
