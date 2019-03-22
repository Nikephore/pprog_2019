CC = gcc
CFLAGS = -g -Wall -ansi -pedantic
EJS = oca set_test die_test inventory_test clear
SET_TEST=set.o set_test.o
DIE_TEST=die.o die_test.o
INVENTORY_TEST=inventory.o inventory_test.o set.o
OCA=game.o game_loop.o graphic_engine.o command.o screen.o space.o player.o object.o game_reader.o die.o set.o inventory.o

all: $(EJS)

oca: $(OCA)
	$(CC) -o oca $(OCA)

set_test: $(SET_TEST)
	$(CC) $(CFLAGS) -o set_test $(SET_TEST)

die_test: $(DIE_TEST)
	$(CC) $(CFLAGS) -o die_test $(DIE_TEST)

inventory_test: $(INVENTORY_TEST)
	$(CC) $(CFLAGS) -o inventory_test $(INVENTORY_TEST)

game.o: game.c game.h command.h space.h object.h die.h player.h
	$(CC) $(CFLAGS) -c -o game.o game.c

game_loop.o: game_loop.c graphic_engine.h
	$(CC) $(CFLAGS) -c -o game_loop.o game_loop.c

graphic_engine.o: graphic_engine.c graphic_engine.h screen.h
	$(CC) $(CFLAGS) -c -o graphic_engine.o graphic_engine.c

command.o: command.c command.h
	$(CC) $(CFLAGS) -c -o command.o command.c

screen.o: screen.c screen.h
	$(CC) $(CFLAGS) -c -o screen.o screen.c

space.o: space.c space.h types.h
	$(CC) $(CFLAGS) -c -o space.o space.c

player.o: player.c player.h
	$(CC) $(CFLAGS) -c -o player.o player.c

object.o: object.c object.h
	$(CC) $(CFLAGS) -c -o object.o object.c

game_reader.o: game_reader.c game_reader.h space.h game.h types.h
	$(CC) $(CFLAGS) -c -o game_reader.o game_reader.c

die.o: die.c die.h
	$(CC) $(CFLAGS) -c -o die.o die.c

set.o: set.c set.h
	$(CC) $(CFLAGS) -c -o set.o set.c

inventory.o: inventory.c inventory.h
	$(CC) $(CFLAGS) -c -o inventory.o inventory.c

clear:
	rm -f *.o

run:
	valgrind --leak-check=yes --tool=memcheck ./oca data.dat

clean:
	rm -f *.o oca die_test set_test inventory_test
