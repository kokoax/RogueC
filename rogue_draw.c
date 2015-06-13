#include "rogue_header.h"

void map_viewer( char map[MAP_WID][MAP_HIGH] ){
	int i, j;
  /*
	for(i = 2; i < 30+2; i++){
		printf( "\033[1;%dH", i*2 );
		printf("%d", i-1);
	}
	//printf("\n");
  
	for(i = 2; i < MAP_HIGH+2; i++){
		printf( "\033[%d;1H", i );
		printf( "%d", i-1 );
		for(j = 2; j < MAP_WID+2; j++){
			printf( "\033[%d;%dH", i, j*2 );
			printf( "%c", map[i-2][j-2] );
		}
		printf("\n");
	}
  */
  for(i = 0; i < MAP_HIGH; i++){
		for(j = 0; j < MAP_WID; j++){
			printf( "\033[%d;%dH", i, j*2 );
			printf( "%c", map[i][j] );
		}
		printf("\n");
	}

	return;
}

void map_writer( MAPCTL *mapctl, char map[MAP_HIGH][MAP_WID] ){
	int i, j, k, l;
	int block_wid = MAP_WID/3;
	int block_hig = MAP_HIGH/3;
	//printf("writerSTART\n");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			for(l = mapctl->Bhigh+mapctl->y; l < mapctl->Bhigh+mapctl->y+mapctl->size_y; l++){
				for(k = mapctl->Bwid+mapctl->x; k < mapctl->Bwid+mapctl->x+mapctl->size_x; k++){
				//printf("%d\n", mapctl->x);
					map[l][k] = '.';
				}
			}
			mapctl++;
		}
	}
	//printf("writerEND\n");
	return;
}


void player_put( MAPCTL *mapctl, CREATURE *player ){
	int RoomRand = rand()%9;
	
	mapctl += RoomRand;
	
	player->x = ( rand() % mapctl->size_x ) + mapctl->x + mapctl->Bwid;
	player->y = ( rand() % mapctl->size_y ) + mapctl->y + mapctl->Bhigh;
	
	return;
}

