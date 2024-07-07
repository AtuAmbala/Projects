// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210
#include "Club.h"

Club::Club() : Weapon()
{
    setName("Club");
    setDescription(" This is a 2 headed club and it delivers 30 damage. The club Costs 300 coins.");
    setCost(300);
    setDamage(30);
    swings=0;
}

string Club::showWeapon()
{
    return "This is a club with 2 heads";
}

void Club ::addSwings(int moreSwings)
{
    swings += moreSwings;
}

string Club :: attack()
{
    addSwings(1);
    return "Yes";
}

