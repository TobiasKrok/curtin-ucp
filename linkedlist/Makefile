CC = gcc
CFLAGS = -Wall -ansi -pedantic
LDFLAGS = -lm
OBJECTS = linkedlist.o main.o
EXECUTABLE = ll

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

linkedist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c