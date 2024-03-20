#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
//#include <vector>
#include <chrono> 
#include <thread>


#include "enemy.h"
#include "player.h"
#include "gameObject.h"
#include "knight.h"
#include "wizard.h"
#include "orc.h"
#include "undead.h"
#include "generateRandomDamage.h"

using namespace std;

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    this_thread::sleep_for(std::chrono::milliseconds(100));
    srand(time(0));

    while (true)
    {
        Player* player;

        string playerName;
        cout << "Welcome to the battle simulation!" << endl;
        cout << "Enter your character's name: " << endl;
        cin >> playerName;


        cout << "Choose your character: (1) Wizard or (2) Knight: " << endl;
        int choice;
        cin >> choice;


        if (choice != 1 && choice != 2)
        {
            cout << "Wrong input! Please choose 1 or 2." << endl;
            return 1;
        }

        if (choice == 1)
            player = new Wizard(playerName, 60, generateRandomDamage(10, 45));
        else
            player = new Knight(playerName, 80, generateRandomDamage(25, 35));

        Enemy* enemy;
        choice = rand() % 2;
        if (choice == 0)
            enemy = new Orc(100, generateRandomDamage(20, 25));
        else
            enemy = new Undead(120, generateRandomDamage(10, 20));

        cout << "You are facing " << enemy->getName() << "!" << endl;
        cout << "Enemy health: " << enemy->getHealth() << endl;
        cout << "" << "===================================" << endl;
        cout << "Are you ready to witness a battle?" << endl;
        cout << "Press 1 to continue or any other key to exit:" << endl;
        int continueChoice;
        cin >> continueChoice;

        if (continueChoice != 1)
        {
            cout << "Exiting the game." << endl;
            delete player;
            delete enemy;
            return 0;
        }

        cout << "" << "===================================" << endl;

        while (player->getHealth() > 0 && enemy->getHealth() > 0)
        {
            enemy->TauntPlayer();

            player->NormalAttack();
            enemy->decreaseHealth(player->getDamage());
            cout << "Your health: " << player->getHealth() << endl;
            cout << "Enemy's health: " << enemy->getHealth() << endl;
            cout << "" << "===================================" << endl;
            if (enemy->getHealth() <= 0 || player->getHealth() <= 0)
                break;

            enemy->TauntPlayer();

            player->SpecialAttack();
            enemy->decreaseHealth(player->getDamage());
            cout << "Your health: " << player->getHealth() << endl;
            cout << "Enemy's health: " << enemy->getHealth() << endl;
            cout << "" << "===================================" << endl;
            if (enemy->getHealth() <= 0 || player->getHealth() <= 0)
                break;

            enemy->NormalAttack();
            player->decreaseHealth(enemy->getDamage());
            cout << "Your health: " << player->getHealth() << endl;
            cout << "Enemy's health: " << enemy->getHealth() << endl;
            cout << "" << "===================================" << endl;
            if (enemy->getHealth() <= 0 || player->getHealth() <= 0)
                break;

            enemy->NormalAttack();
            player->decreaseHealth(enemy->getDamage());
            cout << "Your health: " << player->getHealth() << endl;
            cout << "Enemy's health: " << enemy->getHealth() << endl;
            cout << "" << "===================================" << endl;
            if (enemy->getHealth() <= 0 || player->getHealth() <= 0)
                break;

            player->SpecialAttack();
            enemy->decreaseHealth(player->getDamage());
            cout << "Your health: " << player->getHealth() << endl;
            cout << "Enemy's health: " << enemy->getHealth() << endl;
            cout << "" << "===================================" << endl;
            if (enemy->getHealth() <= 0 || player->getHealth() <= 0)
                break;

            enemy->TauntPlayer();

            player->SpecialAttack();
            enemy->decreaseHealth(player->getDamage());
            cout << "Your health: " << player->getHealth() << endl;
            cout << "Enemy's health: " << enemy->getHealth() << endl;           
            cout << "" << "===================================" << endl;
            if (enemy->getHealth() <= 0 || player->getHealth() <= 0)
                break;
        }

        
        if (player->getHealth() <= 0)
            cout << "You have been defeated! Game over." << endl;
        else
            cout << "You defeated " << enemy->getName() << "! Congratulations!" << endl;
        cout << "" << "===================================" << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
        

        
        delete player;

        delete enemy;

        cout << "Press 0 to restart or any other key to exit: " << endl; 
        cout << "" << "===================================" << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
        int restartChoice;
        cin >> restartChoice;

        if (restartChoice != 0)
            break;

        clearScreen();
        cin.get(); 
        this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
