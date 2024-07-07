// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#pragma once
#include <string>
#include <iostream>
#include "Potion.h"
using namespace std;

class DamagePotion: public Potion
{
private:
public:
    DamagePotion();
    string showPotion();
};
