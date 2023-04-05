CC = gcc
CFLAGS = -Wall -ansi -pedantic
LDFLAGS = -lm
OBJECTS = main.o arrays.o input.o game.o color.o random.o terminal.o
EXECUTABLE = box

ifdef DEBUG
CFLAGS += -g -DDEBUG
DEBUG: clean $(EXECUTABLE)
endif

ifdef PULL
CFLAGS += -DPULL
DEBUG: clean $(EXECUTABLE)
endif

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

main.o: main.c macros.h arrays.h input.h game.h random.h
	$(CC) $(CFLAGS) -c main.c

arrays.o: arrays.c arrays.h
	$(CC) $(CFLAGS) -c arrays.c

input.o: input.c input.h macros.h
	$(CC) $(CFLAGS) -c input.c

game.o: game.c game.h input.h color.h macros.h random.h terminal.h
	$(CC) $(CFLAGS) -c game.c

color.o: color.c color.h
	$(CC) $(CFLAGS) -c color.c

random.o: random.c random.h
	$(CC) $(CFLAGS) -c random.c

terminal.o: terminal.c terminal.h
	$(CC) $(CFLAGS) -c terminal.c

clean:
	rm -f $(EXECUTABLE) *.o 

