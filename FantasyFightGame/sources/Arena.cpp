#include "Arena.h"
#include "DataAccess.h"

Arena::Arena()
{
    opponent =new Beast();
    user = new Human();
}


string Arena::stats()
{
    int dmg =user->getWeapon()->getDamage();
    int armAM= user->getArmorAmount();
    int health= user->getHp();
    int chumz= user->getMoney();

    userWeapon=  user->getWeapon();
    userArmor= user->getArmor();

    string result = "Human \n";
    result+= "Weapon: " + user->getWeapon()->getName() + "\n";
    result+= "Damage: " + to_string(dmg) + "\n";
    result+= "Armor: " + user->getArmor()->getName() + "\n";
    result+= "ArmorAmount: " + to_string(armAM)+ "\n";
    result+= "HP: " + to_string(health)+ "\n";
    result+= "Money: " + to_string(chumz) + "\n";
    return result;
}

string Arena::opponentstats()
{
    int dmg =opponent->getWeapon()->getDamage();
    int armAM= opponent->getArmorAmount();
    int health= opponent->getHp();
    int chumz= opponent->getMoney();

    opponentWeapon=  opponent->getWeapon();
    opponentArmor= opponent->getArmor();

    string result= "Beast \n";
    result+= "Weapon: " + opponent->getWeapon()->getName() + "\n";
    result+= "Damage: " + to_string(dmg) + "\n";
    result+= "Armor: " + opponent->getArmor()->getName() + "\n";
    result+= "ArmorAmount: " + to_string(armAM)+ "\n";
    result+= "HP: " + to_string(health)+ "\n";
    result+= "Money: " + to_string(chumz) + "\n";

    return result;

}
void Arena::setBeast()
{
    opponent = data.newBeast();
}

void Arena::setHuman()
{
    user = data.newHuman();
}

string Arena::beastToString()
{
    string result = "Beast,"+ to_string(opponent->getHp()) + "," +to_string(opponent->getMoney()) +", ";
    result += opponent->getWeapon()->getName() + ", "+opponent->getArmor()->getName() +"\n";
    return result;
}

string Arena::humanToString()
{
    string result = "Human,"+ to_string(user->getHp()) + "," +to_string(user->getMoney()) +", ";
    result += user->getWeapon()->getName() + ", "+user->getArmor()->getName() +"\n";
    return result;

}
void Arena::saveGame()
{
    string title=  "Type, Hp, Money, Weapon, Armor \n";
    string humanstring= humanToString();
    string beaststring = beastToString();

    string full = title + humanstring + beaststring;

    data.saveData(title, humanstring, beaststring);

}

void Arena::loadGame()
{
    data.loadData();
    opponent = data.newBeast();
    user = data.newHuman();
    
}

void Arena::loading(string opened)
{
    auto parts = splitter(opened, "\n");
    string human= parts[1];
    string beast = parts[2];
    auto humanParts = splitter(human, ",");
    user->setHp(stoi(humanParts[1]));
    user->setMoney(stoi(humanParts[2]));
    if (humanParts[3] == " Club")
    {
      user->setWeapon(new Club());
    }

    else if (humanParts[3] == " Gun")
    {
       user->setWeapon(new Gun());
    }

    else if (humanParts[3] == " Sword")
    {
        user->setWeapon(new Sword());
    }

    if (humanParts[4] == " Club Armor")
    {
        user->setArmor(new ClubArmor());
    }

    else if (humanParts[4] == " Gun Armor")
    {
        user->setArmor(new GunArmor());
    }

    else if (humanParts[4] == " Sword Armor")
    {
        user->setArmor(new SwordArmor());
    }

    auto beastParts = splitter(beast, ",");
    opponent->setHp(stoi(beastParts[1]));
    opponent->setMoney(stoi(beastParts[2]));
    if (beastParts[3] == " Club")
    {
      opponent->setWeapon(new Club());
    }

    else if (beastParts[3] == " Gun")
    {
       opponent->setWeapon(new Gun());
    }

    else if (beastParts[3] == " Sword")
    {
        opponent->setWeapon(new Sword());
    }

    if (beastParts[4] == " Club Armor")
    {
        opponent->setArmor(new ClubArmor());
    }

    else if (beastParts[4] == " Gun Armor")
    {
        opponent->setArmor(new GunArmor());
    }

    else if (beastParts[4] == " Sword Armor")
    {
        opponent->setArmor(new SwordArmor());
    }
}

void Arena::quitgame()
{   
    delete this;
    exit(0);
}

Arena::~Arena()
{
    delete opponent;
    delete user;
    delete opponentWeapon;
    delete userWeapon;
    delete opponentArmor;
    delete userArmor;

}

string Arena::viewPotions()
{
    return shop.viewPotions();
}
string Arena::vewWeapons()
{
    return shop.vewWeapons();
}
string Arena::viewArmor()
{
    return shop.viewArmor();
}

void Arena::pBuyPotion(int num)
{
    shop.buyPotion(num);
}

void Arena::pBuyArmor(int num)
{
    user->setArmor(shop.buyArmor(num));
}

void Arena::pBuyWeapon(int num)
{
    user->setWeapon(shop.buyWeapon(num));
}

void Arena::potionCost(int num)
{
    int old =user->getMoney();
    user->setMoney ( old-shop.potionCost(num));
    
}
void Arena::weaponCost(int num)
{
    int old =user->getMoney();
    user->setMoney ( old-shop.weaponCost(num));
}

void Arena::armorCost(int num)
{
    int old =user->getMoney();
    user->setMoney ( old-shop.armorCost(num));
}

void Arena::beastBuild()
{
    int armorNum = std::rand() % 3;
    int weaponNum= std::rand() % 3;
    opponent->setArmor(shop.buyArmor(armorNum));
    opponent->setWeapon(shop.buyWeapon(weaponNum));
}

bool Arena::beastWinner()
{
    if ( user->getHp()<=0)
    {
        return true;
    }
    return false;
}
bool Arena::humanWinner()
{
    if ( opponent->getHp()<=0)
    {
        return true;
    }
    return false;
}

string Arena:: isWinner()
{
    if (opponent->getHp() <=0)
    {
       return "Congatualtions!!!!You defeated the beast.";
    }

    else 
    {
        return "You lost";
    }
}

void Arena::beastAttack()
{
    int value= opponent->attack();
    int old = user->getHp();
    user->setHp(old-value);
    
}

void Arena::humanAttack(bool check)
{
    if (check ==true)
    {
        int value= user->superHit();
        int old = opponent->getHp();
        opponent->setHp(old-value);
    } 

    else {
    int value=user->attack();
    int old = opponent->getHp();
    opponent->setHp(old-value);
    }
}

string Arena::yourHp()
{
    return to_string(user->getHp());
}

string Arena::enemyHp()
{
    return to_string(opponent->getHp());
}

bool Arena::moneyCheck()
{
    return user->getMoney() >74;
}
void Arena::moneyDeduct(int num)
{
    int old = user->getMoney();
    user->setMoney( old-num);

    if (num == 75)
    {
        user->addHP(75);
    }

    if (num == 50)
    {
        user->addDamage(5);
    }
}

vector<string> Arena::splitter(string str, string token)
    {
    vector<string>result;
    while (str.size())
    {
        int index = str.find(token);
        if (index != (int)string::npos)
        {
            result.push_back(str.substr(0, index));
            str = str.substr(index + token.size());
            if (str.size() == 0)
            {
                result.push_back(str);
            }
        }
        else
        {
            result.push_back(str);
            str = "";
        }
    }

    return result;
    }