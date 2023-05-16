CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
LDFLAGS = -lm
OBJECTS = main.o input.o game.o color.o terminal.o linkedlist.o gameutils.o
EXECUTABLE = box

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

main.o: main.c macros.h input.h game.h
	$(CC) $(CFLAGS) -c main.c

input.o: input.c input.h macros.h
	$(CC) $(CFLAGS) -c input.c

game.o: game.c game.h input.h color.h macros.h terminal.h linkedlist.h gameutils.h
	$(CC) $(CFLAGS) -c game.c

color.o: color.c color.h
	$(CC) $(CFLAGS) -c color.c

terminal.o: terminal.c terminal.h
	$(CC) $(CFLAGS) -c terminal.c

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c

gameutils.o: gameutils.c gameutils.h linkedlist.h
	$(CC) $(CFLAGS) -c gameutils.c

clean:
	rm -f $(EXECUTABLE) *.o 
