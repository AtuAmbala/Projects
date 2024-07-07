// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#pragma once
#include <string>
#include <iostream>
#include "Armor.h"
using namespace std;

class GunArmor : public Armor

{
private:
 int shots;
public:
    GunArmor();
    string showArmor();
    void addShots(int moreShots);

};
