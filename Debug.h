#pragma once

//debugging constants and macros
#define REVCHK(a,b) ((a->b==(this))? "true" : "false")
//const char* DEBUGFMT = "%c id: %d\t loc: %p\t rev: %s\n";
const char* DEBUGFMT = "%c --- type: %s\t loc: %p\t rev: %s\n";
extern const char* Tilenames[];

void Tile::debugTile(const char* name="Tile") 
{
    printf("---------------------------\n");
    printf("%s - %p\n", name, (void *)this);
    printf("---------------------------\n");
    //printf("id: %d\t count: %d\t type: %d\n", id, count, tileType);
    printf("type: %s\n", Tilenames[tileType]);
    
    if(n == NULL) {printf("N\t loc: NULL\n");}
    else {printf(DEBUGFMT, 'N', Tilenames[n->tileType], (void *)n, REVCHK(n,s));}
    
    if(s == NULL) {printf("S\t loc: NULL\n");}
    else {printf(DEBUGFMT, 'S', Tilenames[s->tileType], (void *)s, REVCHK(s,n));}
    
    if(e == NULL) {printf("E\t loc: NULL\n");}
    else {printf(DEBUGFMT, 'E', Tilenames[e->tileType], (void *)e, REVCHK(e,w));}
    
    if(w == NULL) {printf("W\t loc: NULL\n");}
    else {printf(DEBUGFMT, 'W', Tilenames[w->tileType], (void *)w, REVCHK(w,e));}
    
    printf("\n");
}

Tile::~Tile()
{
    //printf("GoodBye Cruel World %p\n", (void *)this);
    //--count;
}

void Tile::debugAllTiles(const char* name="Initial Tile")
{
    debugTile(name);
    if(n) n->debugTile("N");    
    if(s) s->debugTile("S"); 
    if(e) e->debugTile("E"); 
    if(w) w->debugTile("W"); 
}