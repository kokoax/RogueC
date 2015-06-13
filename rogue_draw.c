#include "rogue_header.h"

void map_viewer( char map[MAP_WID][MAP_HIGH] ){
	int i, j;
  /*
  for( i = 0; i < 30; i++ ){
    for( j = 0; j < 30; j++ ){
      printf( "%2c", map[i][j] );
    }
    printf( "\n" );
  }
  */
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
  
  for(i = 0; i < 30; i++){
		for(j = 0; j < 30; j++){
			printf( "\033[%d;%dH", i+1, (j+1)*2 );
			printf( "%c", map[i][j] );
		}
  }
 
	return;
}

void map_writer( MAPCTL *mapctl, char map[MAP_HIGH][MAP_WID] ){
	int i, j, k, l;
	//int block_wid = MAP_WID/3;
	//int block_high = MAP_HIGH/3;
	//printf("writerSTART\n");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
      //printf( "%d\n", i+j );
      //printf( "x%d Bx%d Sizex%d\n", mapctl->x, mapctl->Bwid, mapctl->size_x );
      //printf( "y%d By%d Sizey%d\n", mapctl->y, mapctl->Bhigh, mapctl->size_y );
			for(l = mapctl->Bhigh+mapctl->y; l < mapctl->Bhigh+mapctl->y+mapctl->size_y; l++){
				for(k = mapctl->Bwid+mapctl->x; k < mapctl->Bwid+mapctl->x+mapctl->size_x; k++){
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

void put_of_map( char data, CREATURE tmp, char map[MAP_HIGH][MAP_WID] ){
  printf( "\033[%d;%dH", tmp.y+1, (tmp.x+1)*2 );
  printf( "%c", data );
  map[tmp.y][tmp.x] = data;

  return;
}


