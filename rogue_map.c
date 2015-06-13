#include "rogue_header.h"

MAPCTL *mapctl_alloc( MAPCTL *mapctl ){

	MAPCTL *NewCtl = mapctl;
	
	NewCtl->x      = 0;
	NewCtl->y      = 0;
	NewCtl->size_x = 0;
	NewCtl->size_y = 0;
	NewCtl->Bwid   = 0;
	NewCtl->Bhigh  = 0;
	
	return NewCtl;
}

MAPCTL *init_mapctl( void ){
	MAPCTL *tmpctl;
	tmpctl = ( MAPCTL *)malloc( sizeof( MAPCTL )*MAX_MAPNUM );
	if(tmpctl == NULL){
		printf("malloc error\n");
		exit(FALSE);
	}
	return tmpctl;
}

void init_map( char map[MAP_WID][MAP_HIGH] ){
	int i, j;
	for(i = 0; i < MAP_WID; i++){
		for(j = 0; j < MAP_HIGH; j++){
			map[i][j] = '#';
		}
	}
	return;
}

void free_mapctl( MAPCTL *mapctl ){
	free(mapctl);
	return;
}

void mapper( MAPCTL *mapctl, CREATURE *player ){
	int cmd = rand() % 1;
	
	if(cmd == 0){
		create_map_first( mapctl );
		write_map( mapctl );
		create_root_first( mapctl );
		player_put(mapctl, &(*player));
		
	}
	return;
}

void create_map_first( MAPCTL *mapctl ){
	int block_wid = MAP_WID/3;
	int block_hig = MAP_HIGH/3;
	int i, j, k, l;
	
	for(i = 0; i < MAX_MAPNUM; i++){
		mapctl = mapctl_alloc(mapctl);
		mapctl->size_x 	= ( rand() % ( block_wid -5 ) )			 +3;	//9分割した部屋のwidのサイズ
		mapctl->size_y 	= ( rand() % ( block_hig -5 ) )			 +3;	//highのサイズ
		mapctl->x 	= ( rand() % ( block_wid-1 - mapctl->size_x-1 ) ) +1;	//分割されたブロック内の
		mapctl->y 	= ( rand() % ( block_hig-1 - mapctl->size_y-1 ) ) +1;	//部屋の座標
		mapctl->Bwid	= block_wid * (i%3);
		mapctl->Bhigh	= block_hig * (i/3);
		//printf("X:%d Y:%d\nsizeX:%d sizeY:%d\n", mapctl->x, mapctl->y, mapctl->size_x, mapctl->size_y);
		//printf("Bwid:%d Bhigh:%d\n", mapctl->Bwid, mapctl->Bhigh);
		mapctl++;
	}
	//printf("\n\\n\n");
	return;
}

void create_root_first( MAPCTL *mapctl ){
	int i, j, k, tmp;
	int x, y, length;
	int MaxY, MaxX;
	int block_wid = MAP_WID/3;
	int block_hig = MAP_HIGH/3;
	
	MaxY = y = 0;
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 2; j++){
			x = mapctl->Bwid + mapctl->x + mapctl->size_x;
			MaxY = mapctl->Bhigh + ( rand() % mapctl->size_y )+mapctl->y;
			length = block_wid-(mapctl->x + mapctl->size_x);
			//printf("MX:%d MSX:%d ", mapctl->x, mapctl->size_x);
			//printf("block:%d X:%d Y:%d Len:%d\n", block_wid*j, x, MaxY, length);
			line_wide( x, MaxY, length, mapctl->map );
			
			mapctl++;
			
			x = mapctl->Bwid;
			y = mapctl->Bhigh + ( rand() % mapctl->size_y )+mapctl->y;
			length = mapctl->x;
			//printf("MX:%d MSX:%d ", mapctl->x, mapctl->size_x);
			//printf("block:%d X:%d Y:%d Len:%d\n", (j+1)*block_wid, x, y, length);
			line_wide( x, y, length, mapctl->map );
			
			if(y > MaxY){
				tmp = MaxY;
				MaxY = y;
				y = tmp;
			}
			
			for(k = y; k <= MaxY; k++){
				mapctl->map[k][mapctl->Bwid] = '.';
			}
			
		}
		mapctl++;
	}

	mapctl -= 9;
	//printf("mapctl->x:%d\n", mapctl->x);

	for(i = 0; i < 3; i++){
		for(j = 0; j < 2; j++){
			
			MaxX = mapctl->Bwid + ( rand() % mapctl->size_x )+mapctl->x;
			y = mapctl->Bhigh + mapctl->y + mapctl->size_y;
			length = block_hig-(mapctl->y + mapctl->size_y);
			//printf("MX:%d MSX:%d ", mapctl->y, mapctl->size_y);
			//printf("block:%d X:%d Y:%d Len:%d\n", block_wid*j, x, MaxY, length);
			line_narrow( MaxX, y, length, mapctl->map );
			
			mapctl += 3;
			
			x = mapctl->Bwid + ( rand() % mapctl->size_x )+mapctl->x;
			y = mapctl->Bhigh;
			length = mapctl->y;
			//printf("MX:%d MSX:%d ", mapctl->y, mapctl->size_y);
			//printf("block:%d X:%d Y:%d Len:%d\n", (j+1)*block_wid, x, y, length);
			line_narrow( x, y, length, mapctl->map );
			
			if(x > MaxX){
				tmp = MaxX;
				MaxX = x;
				x = tmp;
			}
			
			for(k = x; k <= MaxX; k++){
				mapctl->map[mapctl->Bhigh][k] = '.';
			}
			
		}
		mapctl -= 5;
	}

	return;
}

void line_wide( int StartX, int StartY, int Length, char map[MAP_WID][MAP_HIGH] ){
	int i, j;
	for(i = 0; i < Length; i++){
		map[StartY][StartX+i] = '.';
	}
}

void line_narrow( int StartX, int StartY, int Length, char map[MAP_WID][MAP_HIGH] ){
	int i, j;
	for(i = 0; i < Length; i++){
		map[StartY+i][StartX] = '.';
	}
}

