// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#include "HealthPotion.h"

HealthPotion::HealthPotion() :Potion()
{
    setName("Health Potion");
    setDescription("This Health Potion give the player 75 health and cost 75 coins");
    setCost(75);
    setEffect(75);
}

string HealthPotion::showPotion()
{
    return "This is the health potion";
}
