#include "rogue_header.h"

int main(void){
	char data = 0;
	char cmd[16] = {0};
	MAPCTL *mapctl;
	CREATURE player;

	srand((unsigned)time(NULL));
	
	mapctl = init_mapctl();
	
	//system("clear");
	printf( "\033[2J" );

	init_map( mapctl->map );
	mapper( mapctl, &player );
	map_viewer( mapctl->map );
	while(1){
		while(1){
									
			while(1){
				//system("cls");
				//printf( "\033[2J" );
				mapctl->map[player.y][player.x] = '.';
				printf( "\033[%d;%dH", player.y+1, (player.x+1)*2 );
				printf( "%c", '.' );

				action_command( data, &player );

				mapctl->map[player.y][player.x] = '@';
				printf( "\033[%d;%dH", player.y+1, (player.x+1)*2 );
				printf( "%c", '@' );

				
				//map_viewer( mapctl->map );
				
				data = mygetch();
				if( data == (char)0x00 || data == (char)0xe0 ){
					data = mygetch();
				}
				
				//printf("%x\n\r", data);
			
				if(data == ':'){
					printf("Command Mode\n");
					scanf("%s", cmd);
					if( strcmp(cmd, "next") == 0){
						break;
					}
					if( strcmp(cmd, "end") == 0 || strcmp( cmd, "q" ) == 0 ){
						data = 'e';
						break;
					}
				}
			}
			if(data == 'e'){
				break;
			}
		}
		if(data == 'e'){
			break;
		}
	}
	
	free_mapctl( mapctl );
	printf( "\033[2J" );
	//system("clear);
	return 0;
}

