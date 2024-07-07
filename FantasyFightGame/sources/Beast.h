// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#pragma once
#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

class Beast : public Player
{
private:
public:
    Beast();
    int attack();
    bool hit();
    int superHit();
    string showPlayer();
    string yell();
    string groan();
    virtual ~Beast() {}

};
