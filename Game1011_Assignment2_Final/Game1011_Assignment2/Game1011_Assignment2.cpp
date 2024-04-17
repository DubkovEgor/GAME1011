#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime> 
#include <stack>

using namespace std;

struct Player
{
    string name;
    int health = 200;
    int damage = 5;
    stack<string> inventory;
};

struct Enemy
{
    string name;
    int health = 100;
    int damage = 10;
};



void processInventoryCommand(const string& command, Player& player) 
{
    if (command == "Take item") 
    {
        string item;
        cout << "Enter item name: ";
        getline(cin, item);
        player.inventory.push(item);
        cout << "You took " << item << "." << endl;
    }
    else if (command == "Drop item") 
    {
        if (!player.inventory.empty()) 
        {
            string item = player.inventory.top();
            player.inventory.pop();
            cout << "You dropped " << item << "." << endl;
        }
        else 
        {
            cout << "Your inventory is empty." << endl;
        }
    }
    else if (command == "Check inventory")
    {
        if (!player.inventory.empty()) 
        {
            cout << "Inventory contains:" << endl;
            stack<string> temp = player.inventory;
            while (!temp.empty()) 
            {
                cout << "- " << temp.top() << endl;
                temp.pop();
            }
        }
        else
        {
            cout << "Your inventory is empty." << endl;
        }
    }
    else if (command == "Skip")
    {

    }
   
   
   
}

void processTreasure(const string& command, Player& player)
{
    if (command == "Take treasure")
    {
        string item;
        cout << "Enter item name: ";
        getline(cin, item);
        player.inventory.push(item);
    }

    else
    {
        cout << "You try to take it but you stumble and fall right on the weapon." << endl;
        cout << "You slightly touched it and almost immediately you can't feel anything." << endl;
        cout << "The blade was poisonous and you die from it." << endl;
        cout << "You lost." << endl;
        exit(0);
    }
}
void savePlayerAndEnemy(const Player& player, const Enemy& enemy, const string& filename)
{
    ofstream outFile(filename, ios::binary);
    if (outFile.is_open())
    {
        outFile.write(reinterpret_cast<const char*>(&player), sizeof(Player));

        outFile.write(reinterpret_cast<const char*>(&enemy), sizeof(Enemy));
        outFile.close();
        cout << "Player and enemy data saved successfully." << endl;
    }
    else
    {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

void loadPlayerAndEnemy(Player& player, Enemy& enemy, const string& filename)
{

    ifstream inFile(filename, ios::binary);
    if (inFile.is_open())
    {

        inFile.read(reinterpret_cast<char*>(&player), sizeof(Player));

        inFile.read(reinterpret_cast<char*>(&enemy), sizeof(Enemy));
        inFile.close();
        cout << "Player and enemy data loaded successfully." << endl;
    }
    else
    {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }
}

vector<string> readDialogFromFile(const string& filename)
{

    ifstream file(filename);
    vector<string> dialog;
    string line;
    while (getline(file, line))
    {
        dialog.push_back(line);
    }
    file.close();
    return dialog;
}

void processCommand(const string& command, Player& player, Enemy& enemy, const vector<string>& dialog)
{
    if (command == "Attack enemy")
    {
        player.damage = rand() % player.damage + 10;
        enemy.health = max(enemy.health - player.damage, 0);
        cout << dialog[4] << endl;
        cout << "You attack the " << enemy.name << " for " << player.damage << " damage!" << endl;

        if (enemy.health <= 0)
        {
            cout << "You have defeated the " << enemy.name << "!" << endl;
        }
    }
    if (command == "Use spell")
    {
        player.damage = rand() % player.damage + 50;
        enemy.health = max(enemy.health - player.damage, 0);
        cout << "You attack the " << enemy.name << " for " << player.damage << " damage!" << endl;

        if (enemy.health <= 0)
        {
            cout << "You have defeated the " << enemy.name << "!" << endl;
        }
    }

    if (!(command == "Attack enemy" || command == "Use spell"))
    {
        cout << "=========================================================" << endl;
        cout << "Wrong Input. Please, be careful." << endl;
        exit(0);
    }
}

void enemyTurn(Player& player, Enemy& enemy, const vector<string>& dialog)
{
    enemy.damage = rand() % 41 + 30;
    player.health = max(player.health - enemy.damage, 0);
    cout << "The " << enemy.name << " attacks you for " << enemy.damage << " damage!" << endl;

    if (player.health <= 0)
    {
        cout << "=========================================================" << endl;
        cout << "You have been defeated by the " << enemy.name << "!" << endl;
        cout << "You lost." << endl;
        exit(0);
    }
}

void resetPlayerHealth(Player& player)
{   
    player.health = player.health + 50; 
}
void handleAfterEnemyDefeat(const string& command, Player& player)
{   
    string userInput;
    cout << "=========================================================" << endl;
    cout << "The Guardian lies defeated before you. What would you like to do next?" << endl;
    cout << "Enter your command ('Enter chamber' or 'Check entrance'): " << endl;
    getline(cin, userInput);    
    resetPlayerHealth(player);
    if (userInput == "Enter chamber")
    {    
        cout << "=========================================================" << endl;
        cout << "As you enter the chamber, you trigger a hidden trap and are fatally wounded." << endl;
        player.health = 0;  
        cout << "You are dead." << endl;
        cout << "You lost." << endl;
        exit(0);
    }
    if (userInput == "Check entrance")
    {
        cout << "=========================================================" << endl;
        cout << "You decide to have a look around. After careful inspection, you find a hidden trap and disable it." << endl;
        cout << "Feeling safer, you proceed forward." << endl;
    }    
    if (!(userInput == "Enter chamber" || userInput == "Check entrance"))
    {
        cout << "=========================================================" << endl;
        cout << "Wrong Input. Please, be careful." << endl;
        exit(0);
    }
}
void roomOne(const string& command, Player& player)
{
    string userInput;
    cout << "=========================================================" << endl;
    cout << "You are standing in a complete darkness." << endl;
    cout << "A tiny gap in the celling highlights a little table in near the stone gate." << endl;
    cout << "You see an engraving of Fire and a narrow hole in the middle of the table." << endl;
    cout << "Enter your command ('Look around' or 'Open gate'): " << endl;

    getline(cin, userInput);

    if (userInput == "Look around")
    {
        cout << "=========================================================" << endl;
        cout << "After careful inspection, you find couple chests and the bookshelf between them." << endl;
        cout << "There is nothing inside the chests, but on the book shelf you see a candle wick." << endl;
        cout << "It perfectly fits the hole in the table and first thought is to lighten it up." << endl;
        cout << "When the candle wick almost burned down, the table engravings start to glow and the gate slowly covered in light." << endl;
        cout << "The gate opens and lead you to the next room." << endl;
        cout << "You also see a new blade that appeared as the gates went up." << endl;
    }

    if (userInput == "Open gate")
    {
        cout << "=========================================================" << endl;
        cout << "You come closer to the gate and the second you are a step from it, the floor collapses." << endl;
        cout << "You fall in the pit with spikes." << endl;
        cout << "You are dead." << endl;
        player.health = 0;
        cout << "You lost." << endl;
        exit(0);
    }

    if (!(userInput == "Look around" || userInput == "Open gate"))
    {
        cout << "=========================================================" << endl;
        cout << "Wrong Input. Please, be careful." << endl;
        exit(0);
    }
}
void roomTwo(const string& command, Player& player)
{
    string userInput;  
    cout << "=========================================================" << endl;
    cout << "You get in a room with an iron lattice ceiling full of light and you see the same table near the next gate." << endl;
    cout << "You carefully come closer to the table watching out for any traps or hidden objects." << endl;
    cout << "You see an engraving of Water and a bowl in the middle of the table." << endl;
    cout << "Enter your command ('Take bowl' or 'Look around'): " << endl;

    getline(cin, userInput);

    if (userInput == "Look around")
    {
        cout << "=========================================================" << endl;
        cout << "You start to explore the room for anything that could give you water." << endl;
        cout << "There is nothing in the room, only a small area with plants the corner." << endl;
        cout << "You decide to cut them all of and try to extract any liquid from." << endl;
        cout << "Luckily there were couple flowers that hold a lot of water. " << endl;
        cout << "You extracted as much water from all the plants as you could and pour it all in the bowl." << endl;
        cout << "The bowl and the table started to glow." << endl;       
        cout << "The gate started to open and you go to the next room." << endl;
    }

    if (userInput == "Take bowl")
    {
        cout << "=========================================================" << endl;
        cout << "You decided to take the bowl and as soon as you did that the room started to shake." << endl;
        cout << "Multiple trapdoors opened and the room started to flood." << endl;       
        cout << "The ceiling also started to move and went down." << endl; 
        cout << "You are getting out of air as the water covers you and the ceiling squishes you back." << endl; 
        cout << "You are drowning and there is no escape." << endl; 
        cout << "You are dead." << endl;
        player.health = 0;
        cout << "You lost." << endl;
        exit(0);
    }   

    if (!(userInput == "Look around" || userInput == "Take bowl"))
    {
        cout << "=========================================================" << endl;
        cout << "Wrong Input. Please, be careful." << endl;
        exit(0);
    }
}

void roomThree(const string& command, Player& player)
{
    string userInput; 
    cout << "=========================================================" << endl;
    cout << "You get in a hall full of weapons, armor and dead bodies" << endl;
    cout << "You see a massive figure siting on a throne at the end of the room ." << endl;
    cout << "The moment you enter the room, the figure stands and slowly starts move in your direction" << endl;
    cout << "Enter your command ('Run back' or 'Start fight'): " << endl;

    getline(cin, userInput);

    if (userInput == "Start fight")
    {
        cout << "=========================================================" << endl;
        cout << "You decided to fight and as soon as move forward the enemy throws an axe." << endl;
        cout << "Luckily you evade the axe and get closer to him." << endl;
        cout << "The fight begins." << endl;

    }

    if (userInput == "Run back")
    {
        cout << "=========================================================" << endl;
        cout << "You decided to run and as soon as turn around you get an axe in your back." << endl;
        cout << "You are bleeding and can't move." << endl;
        cout << "The enemy comes to you and says:" << endl;
        cout << "'Nice, one more blade in my collection'" << endl;
        cout << "He stab you with your own weapon." << endl;                
        cout << "You are dead." << endl;
        player.health = 0;
        cout << "You lost." << endl;
        exit(0);
    }  

    if (!(userInput == "Start fight" || userInput == "Run back"))
    {
        cout << "=========================================================" << endl;
        cout << "Wrong Input. Please, be careful." << endl;
        exit(0);
    }
}

void lastFight(const string& command, Player& player, Enemy& enemy, const vector<string>& dialog)
{
    string userInput;   
    cout << "=========================================================" << endl;  
    cout << "Enter your command ('Jump hit' or 'Feint move'): " << endl;

    getline(cin, userInput);

    if (userInput == "Jump hit")
    {
        cout << "=========================================================" << endl;
        cout << "You decided to jump trying to hit the enemy in the neck." << endl;
        cout << "The moment your feet got off the ground the enemy gets in a defensive position and point his spear at you" << endl;
        cout << "The enemy spears you and you hang on the tip of the blade." << endl;
        cout << "Enemy bends over your head and tells you." << endl;
        cout << "'Well, at least you tried, thank you for fun'" << endl;
        cout << "You are dead." << endl;
        player.health = 0;
        cout << "You lost." << endl;
        exit(0);
    }

    if (userInput == "Feint move")
    {
        cout << dialog[4] << endl;
        cout << "=========================================================" << endl;
        cout << "You fake your first movement." << endl;
        cout << "You start your movement to the right and as soon as the enemy started to move and leans on his left leg" << endl;
        cout << "You quickly move to hist right, avoiding his spear and shield" << endl;
        cout << "He loses his balance and you stab him in his back" << endl;
        cout << "He falls on the ground and you finish him by beheading his body" << endl;
        cout << "Now all that is left to take the main treasure" << endl; 
        cout << "The weapon you were looking for" << endl; 
        cout << "=========================================================" << endl;
        cout << "'Magic Dave the epic stick' " << endl;
        cout << "=========================================================" << endl;
        cout << " " << endl;            
    }    
    if (!(userInput == "Jump hit" || userInput == "Feint move"))
    {
        cout << "=========================================================" << endl;
        cout << "Wrong Input. Please, be careful." << endl;
        exit(0);
    }

}
int main()
{
    
    srand(time(0));

    Player player = { "Adventurer", 200, 50 };
    Enemy enemy = { "Guardian", 100, 30 };

    vector<string> dialog = readDialogFromFile("dialog.txt");


    bool restart = true;
    while (restart)
    {
        cout << "=========================================================" << endl;

        savePlayerAndEnemy(player, enemy, "game_data.bin");
        Player loadedPlayer;
        Enemy loadedEnemy;

        
        loadPlayerAndEnemy(loadedPlayer, loadedEnemy, "game_data.bin");
        cout << "=========================================================" << endl;

        cout << dialog[0] << "You see the " << enemy.name << " in front of you." << endl;
        cout << dialog[2] << endl;

        cout << " " << endl;
        cout << "Player: " << loadedPlayer.name << ", Health: " << loadedPlayer.health << ", Damage: " << loadedPlayer.damage << endl;
        cout << "Enemy: " << loadedEnemy.name << ", Health: " << loadedEnemy.health << ", Damage: " << loadedEnemy.damage << endl;

        bool gameOver = false;
        while (!gameOver)
        {
            string userInput;
            cout << "Enter your command (e.g., 'Attack enemy, 'Use spell'): ";
            getline(cin, userInput);

            processCommand(userInput, player, enemy, dialog);

            if (enemy.health <= 0)
            {
                gameOver = true;
                cout << dialog[6] << endl;
                cout << dialog[8] << endl;                
            }
            else
            {
                enemyTurn(player, enemy, dialog);

                if (player.health <= 0)
                {
                    gameOver = true;
                    cout << dialog[10] << endl;
                    cout << "You lost." << endl;
                    exit(0);
                }
            }
        }
        cout << "You found a powerful weapon near the guardian's body. " << endl;
        string command;
        cout << "Enter a command ('Take item', 'Skip'): ";
        getline(cin, command);
        processInventoryCommand(command, player);

        char choice; 
        string userInput;
        cout << "=========================================================" << endl;
        cout << "Press '1' to move forward or any other key to quit: " << endl;
        cin >> choice;

        if (choice == '1')
        {           
            string userInput;
            getline(cin, userInput);
            handleAfterEnemyDefeat(userInput, player);
            string command;
            cout << "Enter a command ('Drop item', 'Check inventory', 'Skip'): ";
            getline(cin, command);
            processInventoryCommand(command, player);
            if (player.health <= 0)
            {
                gameOver = true;
                exit(0);
            }           
        }
        else
        {
            exit(0);
        }

       cout << "=========================================================" << endl;
       cout << "Press '1' to move forward or any other key to quit: " << endl;
       cin >> choice;
      
       if (choice == '1')
       {          
           string userInput = "";
           getline(cin, userInput);
           roomOne(userInput, player);

           string command;
           cout << "Enter a command ('Take item', 'Drop item', 'Check inventory', 'Skip'): ";
           getline(cin, command);
           processInventoryCommand(command, player);

           if (player.health <= 0)
           {
               gameOver = true;
               exit(0);
           }          
       }
       else
       {
           exit(0);
       }
       
       cout << "=========================================================" << endl;
       cout << "Press '1' to move forward or any other key to quit: " << endl;
       cin >> choice;
      
       if (choice == '1')
       {          
           string userInput = "";      
           getline(cin, userInput);
           roomTwo(userInput, player);
           string command;
           cout << "Enter a command ('Drop item', 'Check inventory', 'Skip'): ";
           getline(cin, command);
           processInventoryCommand(command, player);
           if (player.health <= 0)
           {
               gameOver = true;
               exit(0);
           }           
       }
       else
       {
           exit(0);
       }    

       cout << "=========================================================" << endl;
       cout << "Press '1' to move forward or any other key to quit: " << endl;
       cin >> choice;
       if (choice == '1')
       {          
           string userInput = "";      
           getline(cin, userInput);
           roomThree(userInput, player);
           if (player.health <= 0)
           {
               gameOver = true;
               exit(0);
           }
       }
       else
       {
           exit(0);
       }  

       cout << "=========================================================" << endl;
       cout << "Press '1' to move forward or any other key to quit: " << endl;
       cin >> choice;

       if (choice == '1')
       {          
           string userInput = "";
      
           getline(cin, userInput);
           if (player.health <= 0)
           {
               gameOver = true;
               exit(0);
           }
           else
           {               
               lastFight(userInput, player, enemy, dialog);
               string command;
               cout << "Enter a command ('Take treasure'): ";
               getline(cin, command);
               processTreasure(command, player);
               cout << "Enter a command ('Check inventory'): ";
               getline(cin, command);
               processInventoryCommand(command, player);

               exit(0);
           }
       }
       else
       {
           exit(0);
       }  
       return 0;
       
       cin.get();
    }
    return 0;
}