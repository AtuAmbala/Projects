#include "Player.h"

Player::Player()
{
    hp=100;
    name = "Default Player";
    description= "Base class player constructor";
    money= 1000;

}

int Player::getHp()
{
    return hp;
}

string Player::getName()
{
    return name;
}

string Player::getDescription()
{
    return description;
}
int Player::getDamage()
{
    return weapon->getDamage();
}  
Armor* Player::getArmor()
{
    return armor;
}
Weapon* Player::getWeapon()
{
    return weapon;
}
int Player::getArmorAmount()
{
    return armor->getValue();
}
int Player::getMoney()
{
    return money;
}
void Player::setHp(int newHp)
{
    hp = newHp;
}
void Player::setName(string newName)
{
    name = newName;
}
void Player::setDescription(string desc)
{
    description= desc;
}
void Player::setDamage(int newDamage)
{
    weapon->setDamage(newDamage);
}
void Player::setArmor(Armor* newArmor)
{
    armor = newArmor;
    armorAmount = armor->getValue();
}
void Player::setWeapon(Weapon* newWeapon)
{
    weapon =newWeapon;
}
void Player::setArmorAmount(int newArmorAmount)
{
    armor->setValue(newArmorAmount);
}
void Player::setMoney(int newMoney)
{
    money=newMoney;
}
void Player::addHP(int moreHp)
{
    hp+=moreHp;
}
void Player::addDamage(int moreDmg)
{
    int current = damage;
    weapon->setDamage (current +moreDmg);
}
void Player::takeDamage(Weapon* otherWeapon, int damageValue)
{
    int blocked = armor->getValue();
    int last = blocked -damageValue;
    if (armor->getName() == "Club Armor" && otherWeapon->getName()== "Club")
    {
        hp -=last;
    }

    else if (armor->getName() == "Gun Armor" && otherWeapon->getName()== "Gun")
    {
        hp -=last;
    }

    else if (armor->getName() == "Sword Armor" && otherWeapon->getName()== "Sword")
    {
        hp -=last;
    }

    else { hp-=damageValue;}
}

Player::~Player()
{
    delete armor;
    delete weapon;
}