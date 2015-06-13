#include "rogue_header.h"

void action_command( char cmd, CREATURE *player ){
	if( cmd == 0x48 ){			//↑キー
			player->y--;
	} else if( cmd == 0x4b ){	// ←キー
			player->x--;
	}else if( cmd == 0x4d ){	//→キー
			player->x++;
	} else if( cmd == 0x50 ){	//↓キー
			player->y++;
	}
	
	return;
}

