// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#include "SwordArmor.h"

SwordArmor::SwordArmor()
{
    setName("Sword Armor");
    setDescription("This Sword Armor reduces sword damage by 15 and costs 50 coins");
    setCost(50);
    setValue(15);
}

string SwordArmor::showArmor()
{
 return "This is the Sword Armor";
}