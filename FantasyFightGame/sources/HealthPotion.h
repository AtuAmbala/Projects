// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#pragma once
#include <string>
#include <iostream>
#include "Potion.h"
using namespace std;

class HealthPotion :public Potion
{
private:
public:
    HealthPotion();
    string showPotion();
};
