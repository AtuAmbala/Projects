#include "Human.h"

Human::Human(): Player()
{
    setHp(100);
    this->setName("Human");
    this->setDescription( "This is a Human PLayer");
}

int Human::attack()
{

    yell();

    return getDamage();
}
bool Human::hit()
{
    int random = std::rand() % 100;
    if (random <= 30)
    {
        return false;
    }

    return true;
}
int Human::superHit()
{
    double mutiplier=0.5;
    if (hit() ==true )
    {int random = std::rand() % 100;
    
    if (random >95)
    {
        yell();
        mutiplier= 5.0;
    }

    else if (random >90)
    {   
        yell();
        mutiplier= 4.0;
    }

    else if (random >85)
    {
        yell();
        mutiplier= 3.0;
    }

    else if (random >80)
    {
        yell();
        mutiplier= 2.0;
    }
    
    }
    
    int thuck = round (getDamage() * mutiplier);

    return thuck;


    
}
string Human::showPlayer()
{
    string result = getDescription() + " with " +getArmor()->getName()+ "armor and a " +getWeapon()->getName()+ " as a weapon. \n";
    result += "The player has " +to_string(getHp()) + " hp";

    return result;
}
string Human::yell()
{
    return "Yesss!!!";
}
string Human::groan()
{
    return "Noooo";
}