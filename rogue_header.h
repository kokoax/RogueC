
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

typedef struct creature{
	int x, y;
} CREATURE;

typedef struct mapctl{
	int x, y;
	int size_x, size_y;
	int Bwid, Bhigh;
	char map[MAP_HIGH][MAP_WID];
} MAPCTL;

/*rogue_main.c*/

/*rogue_map.c*/
MAPCTL *mapctl_alloc( MAPCTL *mapctl );
MAPCTL *init_mapctl( void );
void free_mapctl( MAPCTL *mapctl );
void init_map( char map[MAP_WID][MAP_HIGH] );
void mapper( MAPCTL *mapctl, CREATURE *player );

void create_map_first( MAPCTL *mapctl );
void create_root_first( MAPCTL *mapctl );

void line_wide( int StartX, int StartY, int Length, char map[MAP_WID][MAP_HIGH] );
void line_narrow( int StartX, int StartY, int Length, char map[MAP_WID][MAP_HIGH] );
void player_put( MAPCTL *mapctl, CREATURE *player );

/*rogue_action.c*/

/*rogue_draw.c*/
void write_map( MAPCTL *mapctl );
void map_viewer( char map[MAP_WID][MAP_HIGH] );
void player_put( MAPCTL *mapctl, CREATURE *player );

#endif //_ROGUE_HEDDER_
