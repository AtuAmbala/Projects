// Atuhaire Ambala
// Fantasy Fighting Game
// CST 210

#pragma once
#include <string>
#include <iostream>
#include "Beast.h"
#include "Human.h"
#include "Store.h"
#include "DataAccess.h"

using namespace std;

class Arena
{
private:
    Store shop;
    Beast* opponent;
    Human* user;
    Weapon* opponentWeapon;
    Weapon* userWeapon;
    Armor* opponentArmor;
    Armor* userArmor;
    int userHp;
    int opponentHp;
    DataAccess data;
public:
    Arena();
    string stats();
    string opponentstats();
    void setBeast();
    void setHuman();
    string viewPotions();
    string vewWeapons();
    string viewArmor();
    void pBuyPotion(int num);
    void pBuyArmor(int num);
    void pBuyWeapon(int num);
    void saveGame();
    void quitgame();
    void loadGame();
    void loadData();
    void loading(string);
    ~Arena();
    string beastToString();
    string humanToString();
    void potionCost(int num);
    void weaponCost(int num);
    void armorCost(int num);
    void beastBuild();
    bool beastWinner();
    bool humanWinner();
    string isWinner();
    void humanAttack(bool);
    void beastAttack();
    string yourHp();
    string enemyHp();
    bool moneyCheck();
    void moneyDeduct(int);
    vector<string> splitter(string str, string token);


};
