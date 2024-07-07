#include "Beast.h"

Beast::Beast()
{
    setHp(100);
    this->setName("Beast");
    this->setDescription( "This is a Beast Player");
    setMoney (500);
}

int Beast::attack()
{
    if (hit() ==true)
    {
        double mutiplier = superHit();

        int thuck = round (getDamage() * mutiplier);

        return thuck;
    }

    yell();

    return getDamage();
}
bool Beast::hit()
{
    int random = std::rand() % 100;
    if (random <= 75)
    {
        return false;
    }

    return true;
}
int Beast::superHit()
{
    double mutiplier=0.5;
    if (hit() ==true )
    {int random = std::rand() % 100;
    
    if (random >97)
    {
        yell();
        mutiplier= 5.0;
    }

    else if (random >94)
    {   
        yell();
        mutiplier= 4.0;
    }

    else if (random >91)
    {
        yell();
        mutiplier= 3.0;
    }

    else if (random >88)
    {
        yell();
        mutiplier= 2.0;
    }
    
    }
    int thuck = round (getDamage() * mutiplier);

    return thuck;
    

}
string Beast::showPlayer()
{
    string result = getDescription() + " with " +getArmor()->getName()+ "armor and a " +getWeapon()->getName()+ " as a weapon. \n";
    result += "The player has " +to_string(getHp()) + " hp";

    return result;
}
string Beast::yell()
{
    return "AAAGGGHHH!!!";
}
string Beast::groan()
{
    return "UUUHHHH";
}