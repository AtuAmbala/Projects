#include "DataAccess.h"
#include <string>
#include <format>
#include <iostream>
#include <fstream>
#include <utility>
#include <stdexcept>
#include <sstream>

DataAccess::DataAccess()
{
    filename="FantasyGameData.csv";
}


void DataAccess::saveData(string title, string humandata, string beastdata)
{
    

    ofstream myFile;
    myFile.open(filename);

    myFile<< title;
    myFile<<humandata;
    myFile<<beastdata;

    myFile.close();
}

void DataAccess::loadData()
{
        fstream fin;
        // Open an existing file
        fin.open("FantasyGameData.csv", ios::in);
        if (!fin.is_open())
        {   
            throw runtime_error("Could not open file");
        }

        std::stringstream buffer;
        buffer << fin.rdbuf();
        //cout<< buffer.str();

        string example= buffer.str();
        auto lines = Split(example, "\n");
        for ( int i =0; i < (int)lines.size(); i++)
            {cout <<lines[i];
                if (i!=0)
                {
                    auto parts = Split(lines[i], ",");
                    cout<<parts[0];
                    if (parts[0]=="Beast")
                    {
                        CPU->setHp(stoi(parts[1]));
                        CPU->setMoney(stoi(parts[2]));

                        if (parts[3] == " Club")
                        {
                            CPU->setWeapon(new Club());
                        }

                        else if (parts[3] == " Gun")
                        {
                            CPU->setWeapon(new Gun());
                        }

                        else if (parts[3] == " Sword")
                        {
                            CPU->setWeapon(new Sword());
                        }

                        if (parts[4] == " Club Armor")
                        {
                            CPU->setArmor(new ClubArmor());
                        }

                        else if (parts[4] == " Gun Armor")
                        {
                            CPU->setArmor(new GunArmor());
                        }

                        else if (parts[4] == " Sword Armor")
                        {
                            CPU->setArmor(new SwordArmor());
                        }
                    }

                    if (parts[0]=="Human")
                    {
                        player->setHp(stoi(parts[1]));
                        player->setMoney(stoi(parts[2]));

                        if (parts[3] == " Club")
                        {
                            player->setWeapon(new Club());
                        }

                        else if (parts[3] == " Gun")
                        {
                            player->setWeapon(new Gun());
                        }

                        else if (parts[3] == " Sword")
                        {
                            player->setWeapon(new Sword());
                        }

                        if (parts[4] == " Club Armor")
                        {
                            player->setArmor(new ClubArmor());
                        }

                        else if (parts[4] == " Gun Armor")
                        {
                            player->setArmor(new GunArmor());
                        }

                        else if (parts[4] == " Sword Armor")
                        {
                            player->setArmor(new SwordArmor());
                        }
                    }
                }
            }

        fin.close();            
                
}

DataAccess::~DataAccess()
{
    delete player;
    delete CPU;

}

vector<string> DataAccess::Split(string str, string token)
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


Human* DataAccess::newHuman()
{
    loadData();
    return player;
}

Beast* DataAccess::newBeast()
{
    loadData();
    return CPU;
}

