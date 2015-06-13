#include "rogue_header.h"

int main(void){
  int i;
	char data = 0;
	char cmd[16] = {0};
  char map[MAP_HIGH][MAP_WID];
	MAPCTL *mapctl;
	CREATURE player;

	srand( (unsigned)time(NULL) );
	
	mapctl = init_mapctl();
	
	//system("clear");
	printf( "\033[2J" );

	init_map( map );
	mapper( mapctl, &player, map );
  map_writer( mapctl, map );
	map_viewer( map );
  put_of_map( '@', player, map );
  
  CREATURE monstor[5];
  for( i = 0; i < 5; i++ ){
    creature_put( mapctl, &monstor[i] );
    put_of_map( 'a'+i, monstor[i], map );
  }

  while(1){
    while(1){
      //system("cls");
      //printf( "\033[2J" );
      if( data == 0x41 || data == 0x42 || data == 0x43 || data == 0x44 ){
        action_command( data, &player, map );
      }

      //map_viewer( mapctl->map );

      data = mygetch();
      if( data == (char)0x00 || data == (char)0xe0 ){
        data = mygetch();
      }

      //printf("%x\n\r", data);

      if(data == ':'){
        printf( "\033[31;0H" );
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
      /*
         init_map( map );
         mapper( mapctl, &player, map );
         map_writer( mapctl, map );
         map_viewer( map );
       */

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

