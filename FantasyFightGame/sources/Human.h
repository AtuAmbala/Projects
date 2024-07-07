// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#pragma once
#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

class Human : public Player
{
private:
public:
    Human();
    int attack();
    bool hit();
    int superHit();
    string showPlayer();
    string yell();
    string groan();
    virtual ~Human() {};


};
