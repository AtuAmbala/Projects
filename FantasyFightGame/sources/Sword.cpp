// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#include "Sword.h"

Sword::Sword(): Weapon()
{
    setName("Sword");
    setDescription(" This is a sword delivers 20 damage. The sword Costs 200 coins.");
    setCost(200);
    setDamage(20);
    swings=0;
}


string Sword::showWeapon()
{
    return "This is a sword";
}

void Sword::addSwings(int moreSwings)
{
    swings+=moreSwings;
}

string Sword :: attack()
{
    addSwings(1);
    return "Yes";
}
