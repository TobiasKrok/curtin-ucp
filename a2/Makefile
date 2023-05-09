CC = gcc
CFLAGS = -Wall -ansi -pedantic
LDFLAGS = -lm
OBJECTS = main.o input.o
EXECUTABLE = box

ifdef DEBUG
CFLAGS += -g -DDEBUG
DEBUG: clean $(EXECUTABLE)
endif

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

main.o: main.c macros.h input.h
	$(CC) $(CFLAGS) -c main.c

input.o: input.c input.h macros.h
	$(CC) $(CFLAGS) -c input.c


clean:
	rm -f $(EXECUTABLE) *.o 

