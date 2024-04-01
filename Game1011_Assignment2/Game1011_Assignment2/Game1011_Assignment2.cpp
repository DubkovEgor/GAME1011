#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime> 

using namespace std;


//  Hello, professor 
//I guess I have a problem with binary file, because I have an error in my xmemory.
struct Player 
{
    string name;
    int health;
    int damage;    
};


struct Enemy 
{
    string name;
    int health;
    int damage;    
};

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
    else {
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
    else {
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
    if (command == "Attack Enemy") 
    {
        
        int damage = rand() % player.damage + 10; 
        enemy.health -= damage;
        cout << "You attack the " << enemy.name << " for " << damage << " damage!" << endl;
        

       
        if (enemy.health <= 0) 
        {
            cout << "You have defeated the " << enemy.name << "!" << endl;
            
        }
    }    
    
    if (command == "Use Spell")
    {
        int damage = rand() % player.damage + 30; 
        enemy.health -= damage;
        cout << "You attack the " << enemy.name << " for " << damage << " damage!" << endl;

        
        if (enemy.health <= 0)
        {
            cout << "You have defeated the " << enemy.name << "!" << endl;
            
        }
    }
        
}


void enemyTurn(Player& player, Enemy& enemy, const vector<string>& dialog)
{
    int damage = rand() % enemy.damage + 5; 
    player.health -= damage;
    cout << "The " << enemy.name << " attacks you for " << damage << " damage!" << endl;

   
    if (player.health <= 0) 
    {
        cout << "You have been defeated by the " << enemy.name << "!" << endl;
        //cout << dialog[4] << endl;
    }
}

int main() 
{
    
    srand(time(0));

    
    Player player = { "Adventurer", 200, 50 };
    
    Enemy enemy = { "Guardian", 100, 30 };
    
    savePlayerAndEnemy(player, enemy, "game_data.bin");

    Player loadedPlayer;
    Enemy loadedEnemy;
    loadPlayerAndEnemy(loadedPlayer, loadedEnemy, "game_data.bin");

    cout << "Loaded Player: " << loadedPlayer.name << ", Health: " << loadedPlayer.health << ", Damage: " << loadedPlayer.damage << endl;
    cout << "Loaded Enemy: " << loadedEnemy.name << ", Health: " << loadedEnemy.health << ", Damage: " << loadedEnemy.damage << endl;

    
    vector<string> dialog = readDialogFromFile("dialog.txt");
    cout << "You are standing in a dark chamber. You see the " << enemy.name << " in front of you." << endl;

    bool gameOver = false;
    while (!gameOver) 
    {
        
        string userInput;
        cout << "Enter your command (e.g., 'Attack Enemy, 'Use Spell'): ";
        getline(cin, userInput);

        
        processCommand(userInput, player, enemy, dialog);

        
        if (enemy.health <= 0) 
        {
            gameOver = true;            
            //cout << "Congratulations! You have defeated the " << enemy.name << " and won the game!" << endl;
            cout << dialog[6] << endl;
            cout << dialog[8] << endl;
        }
        else 
        {
            
            enemyTurn(player, enemy, dialog);

            
            if (player.health <= 0) 
            {
                gameOver = true;                
                //cout << "Game over! You have been defeated by the " << enemy.name << "." << endl;
                cout << dialog[10] << endl;
            }
        }
    }

    return 0;
}
