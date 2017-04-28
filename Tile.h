#pragma once
/*  NAME: Tile.h
    AUTHOR: Skyler Curtis (@deadPix3l)
    PURPOSE: To implement the Tile class 
     and supporting functions for Infinite Forest
             
*/
#include <iostream>
#include <cstdio> // printf
#include <cstdlib> // rand
#include <ctime> // time

const char* Tilenames[5] = {"grass", "water", "fire", "tree", "wormhole"};

class Tile
{
    //const unsigned int id;
    //static unsigned int count;
public:
    enum Tiletype { grass, water, fire, tree, wormhole } tileType;
    Tile *n, *s, *e, *w;
    
    Tile();
    Tile(Tiletype explicitTile);
    ~Tile();
    void debugTile(const char* name);
    void debugAllTiles(const char* name);
    void deleteEdges(int mask);
    void createEdges();
    void reverseLink();
    Tile* movePlayer(const char direction);
    Tile* gotoTile(int mask, Tile* dir);
};

Tile::Tile(Tiletype explicitTile)// : id(++count) //Tiletype x=grass
{
    n = NULL;
    s = NULL;
    e = NULL;
    w = NULL;
    tileType = explicitTile;
}

Tile::Tile()// : id(++count) //Tiletype x=grass
{
    n = NULL;
    s = NULL;
    e = NULL;
    w = NULL;

    //logic for deciding the tiletype
    int x = rand() %100;
    if(x == 99) tileType = wormhole;
    else if(x>80) tileType = tree;
    else if(x>50) tileType = water;
    else tileType = grass;
}

//This does not allow for Constructor arguments!!!
void Tile::createEdges() //On the Heap
{
    if(n == NULL) n = new Tile;
    if(s == NULL) s = new Tile;
    if(e == NULL) e = new Tile;
    if(w == NULL) w = new Tile;
    this->reverseLink();
}

void Tile::reverseLink()
{
    if(n != NULL) n->s = this;
    if(s != NULL) s->n = this;
    if(e != NULL) e->w = this;
    if(w != NULL) w->e = this;
}

void Tile::deleteEdges(int mask)
{
    //nsew
    if (mask & 8) {delete n; n = NULL;}
    if (mask & 4) {delete s; s = NULL;}
    if (mask & 2) {delete e; e = NULL;}
    if (mask & 1) {delete w; w = NULL;}
}

Tile* Tile::movePlayer(const char direction)
{
    if(direction=='n') return gotoTile(7, n);
    else if(direction=='s') return gotoTile(11, s);
    else if(direction=='e') return gotoTile(13, e);
    else if(direction=='w') return gotoTile(14, w);

    std::cout << "Umm. What?! How did you..." << std::endl;
    std::cout << "You decide to go an unknown direction, but get confused" << std::endl;
    std::cout << "You stand still in confusion" << std::endl;
    return this;
}

Tile* Tile::gotoTile(int mask, Tile* dir)
{

    switch(dir->tileType)
    {
        //dont go anywhere because trees cant be moved through
        case tree:
            std::cout << "you try running into a tree. you look like an idiot.\n\
            it hurts, but you dont move anywhere." << std::endl;
            return this;
            break;

        //delete all edges, change tile, then regenerate.
        //this simulates teleportation
        case wormhole:
            std::cout << "you decide to step into a wormhole and are magically teleported!" << std::endl;
            this->deleteEdges(15);
            this->createEdges();
            return this;
            break;

        case fire:
            std::cout << "you are on fire!" << std::endl;
            std::cout << "good thing theres not health mechanic. YET!" << std::endl;
            //fallthrough

        //nothing special about these blocks.
        //move the player.
        case grass:
        case water:
            deleteEdges(mask);
            dir->createEdges();
            return dir;
            break;

        default:
            std::cout << "you did something very weird. or i forgot some code xD" << std::endl;
            std::cout << "I guess for now just dont go there? sorry.";
            std::cout << "(you were not moved)" << std::endl;
            return this;

    }
}