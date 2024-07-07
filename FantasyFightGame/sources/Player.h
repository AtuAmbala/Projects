// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#pragma once
#include <string>
#include <iostream>
#include "Armor.h"
#include "Weapon.h"
#include "Potion.h"
using namespace std;

class Player
{
private:
    int hp;
    string name;
    string description;
    int damage;
    Armor* armor;
    Weapon* weapon;
    int armorAmount;
    int money;

public:
    Player();
    int getHp();
    string getName();
    string getDescription();
    int getDamage();
    Armor* getArmor();
    Weapon* getWeapon();
    int getArmorAmount();
    int getMoney();
    void setHp(int);
    void setName(string);
    void setDescription(string );
    void setDamage(int);
    void setArmor(Armor*);
    void setWeapon(Weapon*);
    void setArmorAmount(int);
    void setMoney(int);
    void addHP(int);
    void addDamage(int);
    void takeDamage(Weapon*, int);
    virtual int attack()=0;
    virtual bool hit()=0;
    virtual int superHit()=0;
    virtual string showPlayer()=0;
    virtual string yell()=0;
    virtual string groan()=0;

    ~Player();
};
