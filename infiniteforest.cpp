#include <iostream>
#include <string>
#include "Tile.h"
#include "Debug.h"
using namespace std;

int Tile::count = 0;

int main(int argc, char** argv)
{
    //seed rand()
    srand(time(NULL));
    
    //create all tiles
    Tile *player = new Tile;
    player->createEdges();
    
    //the game loop here
    string input;
    while(1)
    {
        cout << "command> ";
        getline(cin, input);
        

        //support for full words (north, south, etc.) coming later
        if(input=="s" || input=="n"|| input=="e"|| input=="w")
        { player = player->movePlayer(input[0]); }

        //Debug
        else if(input=="debug") { player->debugTile("Player"); }
        else if(input=="debug all") { player->debugAllTiles("Player"); }
        
        else if(input=="quit") { break; }
        else { cout << "sorry - we have not implemented that command - " << input[0] << endl; }
    }
    
    
    //game cleanup
    player->deleteEdges(15); // 1111 -> remove all nodes
    delete player;
    return 0;
}