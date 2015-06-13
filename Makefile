CFLAGS 	= -c -O2 -Wall
OBJECT 	= rogue_main.o rogue_map.o rogue_draw.o\
	  rogue_action.o achive.o
RM	= rm 

#初期実行
default : $(OBJECT)
	gcc $(OBJECT) -o rogue -lm

#ファイル生成規則
rogue_main.o : rogue_header.h rogue_main.c
	gcc $(CFLAGS) rogue_main.c
   
rogue_map.o : rogue_header.h rogue_map.c
	gcc $(CFLAGS) rogue_map.c

rogue_draw.o : rogue_header.h rogue_draw.c
	gcc $(CFLAGS) rogue_draw.c

rogue_action.o : rogue_header.h rogue_action.c
	gcc $(CFLAGS) rogue_action.c

achive.c : rogue_header.h achive.c
	gcc $(CFLAGS) achive.c


#コマンド
run : $(OBJECT)
	gcc $(OBJECT) -o rogue -lm
	./rogue.exe

clean : 
	$(RM) *.o
	$(RM) *.exe

