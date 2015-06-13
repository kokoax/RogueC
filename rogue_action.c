#include "rogue_header.h"

void action_command( char cmd, CREATURE *player ){
	if( cmd == 0x41 ){			//Input_Up_Key
			player->y--;
	} else if( cmd == 0x44 ){	//Input_Left_Key
			player->x--;
	}else if( cmd == 0x43 ){	//Input_Right_Key
			player->x++;
	} else if( cmd == 0x42 ){	//Input_Down_Key
			player->y++;
	}
	
	return;
}

