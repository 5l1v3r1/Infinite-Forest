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


class Tile
{
    const int id;
    static int count;
    enum Tiletype { grass, water, secretshop, tree } tileType;
    
public:
    Tile *n, *s, *e, *w;
    
    Tile();
    ~Tile();
    void debugTile(const char* name);
    void debugAllTiles(const char* name);
    void deleteEdges(int mask);
    void createEdges();
    void reverseLink();
    Tile* movePlayer(const char direction);
    Tile* gotoTile(int mask, Tile* dir);
};

Tile::Tile() : id(++count) //Tiletype x=grass
{
    n = NULL;
    s = NULL;
    e = NULL;
    w = NULL;
    
    //logic for tileType
    int x = rand() %100;
    if(x == 99) tileType = secretshop;
    else if (x<70) tileType = grass;
    else if (x<80) tileType = tree;
    else tileType = water;

}

//This does not allow for Constructor arguments!!!
void Tile::createEdges() //On the Heap
{
    if(n == NULL) n = new Tile;
    if(s == NULL) s = new Tile;
    if(e == NULL) e = new Tile;
    if(w == NULL) w = new Tile;
    reverseLink();
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

    std::cout << "you decide to go an unknown direction, but get confused" << std::endl;
    std::cout << "you stand still in confusion" << std::endl;
    return this;
}

Tile* Tile::gotoTile(int mask, Tile* dir)
{
    if(dir->tileType==tree)
    {
        std::cout << "you try to walk into a tree.";
        std::cout << "you look like an idiot. nothing happens";
        std::cout << std::endl;
        return this;
    }
    
    deleteEdges(mask);
    dir->createEdges();
    return dir;
}







