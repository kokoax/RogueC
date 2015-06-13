
#ifndef _ROGUE_HEDDER_
#define _ROGUE_HEDDER_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <termios.h>
#include <unistd.h>

//#include <conio.h>

#define TURE   0
#define FALSE -1

#define MAX_MAPNUM  9
#define MAP_WID  30
#define MAP_HIGH  30
#define MAP_CREATE_WAY 1

typedef struct creature{
	int x, y;
} CREATURE;

typedef struct mapctl{
	int x, y;
	int size_x, size_y;
	int Bwid, Bhigh;
} MAPCTL;

/*rogue_main.c*/

/*rogue_map.c*/
void mapctl_alloc( MAPCTL *mapctl );
MAPCTL *init_mapctl( void );
void free_mapctl( MAPCTL *mapctl );
void init_map( char map[MAP_WID][MAP_HIGH] );
void mapper( MAPCTL *mapctl, CREATURE *player, char map[MAP_HIGH][MAP_WID] );

void create_map_first( MAPCTL *mapctl );
void create_root_first( MAPCTL *mapctl, char map[MAP_HIGH][MAP_WID] );

void line_wide( int StartX, int StartY, int Length, char map[MAP_WID][MAP_HIGH] );
void line_narrow( int StartX, int StartY, int Length, char map[MAP_WID][MAP_HIGH] );
void player_put( MAPCTL *mapctl, CREATURE *player );

/*rogue_action.c*/
void action_command( char cmd, CREATURE * player, char map[MAP_HIGH][MAP_WID] );

/*rogue_draw.c*/
void map_writer( MAPCTL *mapctl, char map[MAP_HIGH][MAP_WID] );
void map_viewer( char map[MAP_WID][MAP_HIGH] );
void player_put( MAPCTL *mapctl, CREATURE *player );
void put_of_map( char data, CREATURE tmp, char map[MAP_HIGH][MAP_WID] );

/*archive.c*/
char mygetch( void );

#endif //_ROGUE_HEDDER_

