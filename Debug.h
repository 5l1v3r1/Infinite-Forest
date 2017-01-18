#pragma once

//debugging constants and macros
#define REVCHK(a,b) ((a->b==(this))? "true" : "false")
const char* DEBUGFMT = "%c id: %d\t loc: %p\t rev: %s\n";

void Tile::debugTile(const char* name="Tile") 
{
    printf("---------------------------\n");
    printf("%s - %p\n", name, (void *)this);
    printf("---------------------------\n");
    printf("id: %d\t count: %d\t type: %d\n", id, count, tileType);
    
    if(n == NULL) {printf("N\t loc: NULL\n");}
    else {printf(DEBUGFMT, 'N', n->id, (void *)n, REVCHK(n,s));}
    
    if(s == NULL) {printf("S\t loc: NULL\n");}
    else {printf(DEBUGFMT, 'S', s->id, (void *)s, REVCHK(s,n));}
    
    if(e == NULL) {printf("E\t loc: NULL\n");}
    else {printf(DEBUGFMT, 'E', e->id, (void *)e, REVCHK(e,w));}
    
    if(w == NULL) {printf("W\t loc: NULL\n");}
    else {printf(DEBUGFMT, 'W', w->id, (void *)w, REVCHK(w,e));}
    
    printf("\n");
}

Tile::~Tile()
{
    printf("GoodBye Cruel World %p\n", (void *)this);
    --count;
}

void Tile::debugAllTiles(const char* name="Initial Tile")
{
    debugTile(name);
    if(n) n->debugTile("N");    
    if(s) s->debugTile("S"); 
    if(e) e->debugTile("E"); 
    if(w) w->debugTile("W"); 
}