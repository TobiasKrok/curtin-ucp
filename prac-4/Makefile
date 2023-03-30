CC = gcc
CFLAGS = -Wall -ansi -pedantic
LDFLAGS = -lm
OBJECTS = arrays.o main.o
EXECUTABLE = arrays

ifdef DEBUG
CFLAGS += -g -DDEBUG
DEBUG: clean $(EXECUTABLE)
endif

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

arrays.o: arrays.h arrays.c
	$(CC) $(CFLAGS) -c arrays.c

main.o: arrays.h main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(EXECUTABLE) *.o 