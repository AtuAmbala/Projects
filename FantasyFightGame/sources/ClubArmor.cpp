// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#include "ClubArmor.h"

ClubArmor::ClubArmor()
{
    setName("Club Armor");
    setDescription("This Club Armor reduces club damage by 20 and costs 70 coins");
    setCost(70);
    setValue(20);
}

string ClubArmor::showArmor()
{
    return "This is the Club Armor";
}
