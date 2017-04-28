#include <iostream>
#include <string>
#include "Tile.h"
#include "Debug.h"
using namespace std;

//unsigned int Tile::count = 0;

int main(int argc, char** argv)
{
    // ##############################
    // #         INIT PHASE         #
    // ##############################

    //produce good randomness
    srand(time(NULL));

    //create all tiles
    Tile *player = new Tile(Tile::grass);
    player->createEdges();

    // welcome message.
    cout << "==================================================" << endl;
    cout << "Welcome to Infinite Forest." << endl;
    cout << "A Generated Forest game that goes on forever." << endl;
    cout << "==================================================" << endl;

    // Mini How-To-Play
    string helptext = "\ncontrols:\n\
    [Enter] - repeat previous command\n\
    n/s/e/w - move in the respective cardinal direction.\n\
    h - show this help message\n\
    d - show debug information.\n\
    q - quit game.\n\n";
    cout << helptext;

    // ##############################
    // #     GAME LOOP - REPL       #
    // ##############################

    string input;
    char action;
    while(1)
    {
        cout << "command> ";
        getline(cin, input);
        if(input.length()) action = input[0];

        switch(tolower(action))
        {
            case 'h':
                cout << helptext;
                break;

            case 'n':
            case 's':
            case 'e':
            case 'w':
                player = player->movePlayer(action);
                break;

            case 'q':
                //game cleanup - quitting
                player->deleteEdges(15); // 1111 -> remove all nodes
                delete player;
                return 0;
                break;

            case 'd':
                player->debugTile("Player");
                break;

            default:
                cout << "Sorry, we havent inplemented that yet! ";
                cout << "('" << action << "')" << endl;
                break;
        }
    }

    cout << "the loop ended improperly." << endl;
    cout << "attempting cleanup...";
    player->deleteEdges(15); // 1111 -> remove all nodes
    delete player;
    cout << "Goodbye!";
    return 0;
}


//init phase
//1. create player tile.
//2. create all tiles around player.

//game loop - REPL
//1. ask player for action
//2. process action
//3.. any output needed

// Tile* init(void)
// {
//     //seed rand()
//     srand(time(NULL));

//     //create all tiles
//     Tile *player = new Tile;
//     player->createEdges();

//     return player;
// }
