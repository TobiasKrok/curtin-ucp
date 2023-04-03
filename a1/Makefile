CC = gcc
CFLAGS = -Wall -ansi -pedantic
LDFLAGS = -lm
OBJECTS = main.o arrays.o input.o game.o color.o
EXECUTABLE = box

ifdef DEBUG
CFLAGS += -g -DDEBUG
DEBUG: clean $(EXECUTABLE)
endif


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

main.o: main.c macros.h arrays.h input.h game.h
	$(CC) $(CFLAGS) -c main.c

arrays.o: arrays.c arrays.h
	$(CC) $(CFLAGS) -c arrays.c

input.o: input.c input.h macros.h
	$(CC) $(CFLAGS) -c input.c

game.o: game.c game.h input.h color.h
	$(CC) $(CFLAGS) -c game.c

color.o: color.c color.h
	$(CC) $(CFLAGS) -c color.c

clean:
	rm -f $(EXECUTABLE) *.o 

