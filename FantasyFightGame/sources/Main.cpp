#include <iostream>
#include "Arena.h"
#include <chrono>
#include <thread>

#include <string>
#include <format>
#include <iostream>
#include <fstream>
#include <utility>
#include <stdexcept>
#include <sstream>
using namespace std;

int main()
{

    Arena arena;
    string choice;
    string saved;

    //int cost;
    int weaponChoice;
    int armorChoice;
    cout << "Welcome to the Fantasy Fighting Game" <<endl;
     std::this_thread::sleep_for(std::chrono::seconds(1));

    cout << "Do you have a saved game? (Y/N)"<<endl;
    cin >> saved;
    if (saved=="Y")
    {   
        fstream fin;
        // Open an existing file
        fin.open("FantasyGameData.csv", ios::in);
        if (!fin.is_open())
        {   
            throw runtime_error("Could not open filepp");
        }
    
        std::stringstream buffer;
        buffer << fin.rdbuf();
        string opened= buffer.str();
        
        arena.loading(opened);

        
        cout<< "Firstly, lets see the beast you are up against"<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout<< arena.opponentstats() <<endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout<<"\n";   
    }
    else if (saved =="N"){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout<< "You have 1000 coins to spend..."<<endl;
     std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "Use them to buy weapons, potions and armor..."<<endl;
     std::this_thread::sleep_for(std::chrono::seconds(1));
    cout<< "Spend them wisely, for a ferocious beast awaits"<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    cout<<"\n";

    //Building the beast
    cout<< "Firstly, lets see the beast you are up against"<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    arena.beastBuild();
    cout<< arena.opponentstats() <<endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout<<"\n";

    cout<< "Now lets build your character."<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "Here is a little hint, look at the beasts weapon and armor to know his strengths...";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout<< "and weaknesses" <<endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout<<"\n";

    //player picks a weapon
    cout<< arena.vewWeapons()<<endl;
    cout<<"\n";
    cout<< "Choose your weapon"<<endl;
    cin>>choice;
    weaponChoice=stoi(choice);
    arena.pBuyWeapon(weaponChoice);
    arena.weaponCost(weaponChoice);
    cout<<"\n";
    cout <<"Excellent Choice!"<<endl;
    cout<<"\n";

    //PLayer picks armor
    cout<< arena.viewArmor()<<endl;
    cout<<"\n";
    cout<< "Choose your armor"<<endl;
    cin>>choice;
    armorChoice=stoi(choice);
    arena.pBuyArmor(armorChoice);
    arena.armorCost(armorChoice);
    cout <<"Great pick!"<<endl;
    cout<<"\n";

    }
    //current build
    cout<<"\n" << "Here is you current build" <<endl<<"\n";
    cout<< arena.stats();
    cout<<"\n" ;

    std::this_thread::sleep_for(std::chrono::seconds(1));
    

    cout<< "Here are the rules:"<<endl;
    cout<< "You and the best take turn striking each other."<<endl;
    cout<< "If you have a successful hit you can wager it for a super hit that can either 4x, 3x or 2x your damage."<<endl;
    cout<< "if you lose the wager, you damage gets cut in half for that strike"<<endl;
    cout<< "You can buy health or damage potions anythime before you play." <<endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout<<"\n" ;
    \
    cout<< "You are all set to fight" << endl;
    cout<<"\n" ;
    cout<<"Goodluck!!" <<endl;

    while (arena.beastWinner()==false)
    {   string option;
        string potionAns;
        string potiontype;
        cout<< "Would you like to buy a potion? (Y/N)"<< endl;
        cin>> potionAns;
        if (potionAns=="Y")
        {
            if (arena.moneyCheck() == true) {
            cout<<arena.viewPotions()<<endl<< "\n";
            cout<<"Please select potion option"<<endl;
            cin >> potiontype;
            if (potiontype== "1"){
                arena.moneyDeduct(50);
                cout<< "Damage increased by 5"<< endl<<"\n";
            }
            else if (potiontype=="2")
            {
                arena.moneyDeduct(75);
                cout << "Health increase by 75"<< endl<<"\n";
            }
            }

            else {cout << "Sorry, You don't have enough money" << endl<<"\n";}

        }
        bool check;
        string pick;
        cout<< "Would you like to wager a super hit? (Y/N)"<<endl;
        cin >> pick;
        if (pick == "Y")
        {
            check = true;
        }
        else {check= false;}
        
        arena.humanAttack(check);
        cout<<"You made a move"<< endl<<"\n";
        if (arena.humanWinner()== true)
            {
            cout<<arena.isWinner()<<endl;
            break;
            }
        
        arena.beastAttack();
        cout<< "The beast made a move"<< endl<<"\n";

        cout<< "Your HP: " << arena.yourHp()<<endl;
        cout<< "opponent HP: "<<arena.enemyHp()<< endl;

        if (arena.yourHp()=="0")
        {
           cout<<arena.isWinner()<<endl;
           cout<<"Thank you for playing. Quiting game...";
            arena.quitgame(); 
        }
        cout<<"\n" ;

        cout << "Would you like to"<<endl;
        cout << "1. Save"<<endl;
        cout << "2. Quit "<<endl;
        cout << "3. Continue"<<endl;

        cin>>option;

        if (option=="1")
        {
            cout << "Thank you for playing. Saving game...";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            arena.saveGame();
            arena.quitgame();
        }

        else if (option =="2")
        {
            cout << "Thank you for playing. Quiting game...";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            arena.quitgame();
        } 

        else continue;


    return 0;
}
}
