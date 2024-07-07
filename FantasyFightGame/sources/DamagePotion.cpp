// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#include "DamagePotion.h"

DamagePotion::DamagePotion() : Potion()
{
    setName("Damage Potion");
    setDescription("This Damage Potion give the player +5 Damage and cost 50 coins");
    setCost(50);
    setEffect(5);
}

string DamagePotion::showPotion()
{
    return "This is the Damage Potion";
}
