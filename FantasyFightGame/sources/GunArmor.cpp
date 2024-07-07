// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#include "GunArmor.h"

GunArmor::GunArmor()
{
    setName("Gun Armor");
    setDescription("This Gun Armor reduces Gun damage by 7 and costs 30 coins");
    setCost(30);
    setValue(7);
}

string GunArmor::showArmor()
{
    return "This is the Gun Armor";
}
    
void GunArmor::addShots(int moreShots)
{
    shots +=moreShots;
}
