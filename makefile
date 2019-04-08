CC = gcc
CFLAGS = -g -Wall -ansi -pedantic
EJS = oca set_test die_test inventory_test
SET_TEST= ./obj/set.o ./obj/set_test.o
DIE_TEST= ./obj/die.o ./obj/die_test.o
INVENTORY_TEST= ./obj/inventory.o ./obj/inventory_test.o ./obj/set.o
OCA= ./obj/game.o ./obj/game_loop.o ./obj/graphic_engine.o ./obj/command.o ./obj/screen.o ./obj/space.o ./obj/player.o ./obj/object.o ./obj/game_reader.o ./obj/die.o ./obj/set.o ./obj/link.o ./obj/inventory.o

all: $(EJS)

oca: $(OCA)
	$(CC) -o oca $(OCA)
	@echo "Enlazado completo!"

set_test: $(SET_TEST)
	$(CC) $(CFLAGS) -o set_test $(SET_TEST)

die_test: $(DIE_TEST)
	$(CC) $(CFLAGS) -o die_test $(DIE_TEST)

inventory_test: $(INVENTORY_TEST)
	$(CC) $(CFLAGS) -o inventory_test $(INVENTORY_TEST)

./obj/game.o: ./src/game.c ./include/game.h ./include/command.h ./include/space.h ./include/object.h ./include/die.h ./include/player.h
	$(CC) $(CFLAGS) -I./include -c ./src/game.c -o ./obj/game.o

./obj/game_loop.o: ./src/game_loop.c ./include/graphic_engine.h
	$(CC) $(CFLAGS) -I./include -c ./src/game_loop.c -o ./obj/game_loop.o

./obj/graphic_engine.o: ./src/graphic_engine.c ./include/graphic_engine.h ./include/screen.h
	$(CC) $(CFLAGS) -I./include -c ./src/graphic_engine.c -o ./obj/graphic_engine.o

./obj/command.o: ./src/command.c ./include/command.h
	$(CC) $(CFLAGS) -I./include -c ./src/command.c -o ./obj/command.o

./obj/screen.o: ./src/screen.c ./include/screen.h
	$(CC) $(CFLAGS) -I./include -c ./src/screen.c -o ./obj/screen.o

./obj/space.o: ./src/space.c ./include/space.h ./include/types.h
	$(CC) $(CFLAGS) -I./include -c ./src/space.c -o ./obj/space.o

./obj/player.o: ./src/player.c ./include/player.h ./include/inventory.h
	$(CC) $(CFLAGS) -I./include -c ./src/player.c -o ./obj/player.o

./obj/object.o: ./src/object.c ./include/object.h
	$(CC) $(CFLAGS) -I./include -c ./src/object.c -o ./obj/object.o

./obj/game_reader.o: ./src/game_reader.c ./include/game_reader.h ./include/space.h ./include/game.h ./include/types.h
	$(CC) $(CFLAGS) -I./include -c ./src/game_reader.c -o ./obj/game_reader.o

./obj/die.o: ./src/die.c ./include/die.h
	$(CC) $(CFLAGS) -I./include -c ./src/die.c -o ./obj/die.o

./obj/set.o: ./src/set.c ./include/set.h
	$(CC) $(CFLAGS) -I./include -c ./src/set.c -o ./obj/set.o

./obj/inventory.o: ./src/inventory.c ./include/inventory.h
	$(CC) $(CFLAGS) -I./include -c ./src/inventory.c -o ./obj/inventory.o

./obj/link.o: ./src/link.c ./include/link.h
	$(CC) $(CFLAGS) -I./include -c ./src/link.c -o ./obj/link.o

./obj/set_test.o: ./src/set_test.c ./include/set.h
	$(CC) $(CFLAGS) -I./include -c ./src/set_test.c -o ./obj/set_test.o

./obj/die_test.o: ./src/die_test.c ./include/die.h
	$(CC) $(CFLAGS) -I./include -c ./src/die_test.c -o ./obj/die_test.o

./obj/inventory_test.o: ./src/inventory_test.c ./include/inventory.h ./include/set.h
	$(CC) $(CFLAGS) -I./include -c ./src/inventory_test.c -o ./obj/inventory_test.o

clear:
	rm -f ./obj/*.o
	rm -f $(EJS)
	@echo "Limpieza completo!"

run:
	valgrind --leak-check=yes --tool=memcheck ./oca data.dat

clean:
	rm -f *.o oca die_test set_test inventory_test
