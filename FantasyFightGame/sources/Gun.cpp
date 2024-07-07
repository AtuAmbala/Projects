#include "Gun.h"

Gun::Gun() :Weapon()
{
    setName("Gun");
    setDescription(" The gun shoots bullets and delivers 10 damage. The gun Costs 100 coins and comses with 10 bullets.");
    setCost (100);
    setDamage (10);
    ammo= 10;

}

string Gun::showWeapon()
{
    string result = "This is a gun. It has ";
    result += to_string(ammo) + " bullets.";
    return result;
}

void Gun :: moreAmmo(int ammunition)
{
    ammo += ammunition;
}

string Gun :: attack()
{
    if (ammo>1)
    {
    ammo--;
    return "Yes";
    }

    else 
    {
        return "Need more ammo";
    }

}

int Gun :: showAmmo()
{
    return ammo;
}

