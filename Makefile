linkedlist: linkedlist.c
	gcc -std=c99 linkedlist.c -o linkedlist

launch: linkedlist
	./linkedlist
