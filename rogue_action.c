#include "rogue_header.h"

void action_command( char cmd, CREATURE *player ){
	if( cmd == 0x48 ){			//���L�[
			player->y--;
	} else if( cmd == 0x4b ){	// ���L�[
			player->x--;
	}else if( cmd == 0x4d ){	//���L�[
			player->x++;
	} else if( cmd == 0x50 ){	//���L�[
			player->y++;
	}
	
	return;
}

