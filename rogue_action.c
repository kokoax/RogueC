#include "rogue_header.h"

void action_command( char cmd, CREATURE *player, char map[MAP_HIGH][MAP_WID] ){
  if( cmd == 0x41 || cmd == 0x42 || cmd == 0x43 || cmd == 0x44 ){
    map[player->y][player->x] = '.';
    printf( "\033[%d;%dH", player->y, (player->x)*2 );
    printf( "%c", '.' );
    if( cmd == 0x41 && map[player->y-1][player->x] == '.' ){			//Input_Up_Key
      player->y--;
    }else if( cmd == 0x44  && map[player->y][player->x-1] == '.' ){	//Input_Left_Key
      player->x--;
    }else if( cmd == 0x43  && map[player->y][player->x+1] == '.' ){	//Input_Right_Key
      player->x++;
    }else if( cmd == 0x42  && map[player->y+1][player->x] == '.' ){	//Input_Down_Key
      player->y++;
    }
    map[player->y][player->x] = '@';
    printf( "\033[%d;%dH", player->y, (player->x)*2 );
    printf( "%c", '@' );
  }
	return;
}

