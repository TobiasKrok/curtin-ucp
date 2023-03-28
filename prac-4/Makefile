CC = gcc
CFLAGS = -Wall -ansi -pedantic
LDFLAGS = -lm
OBJECTS = arrays.o
EXECUTABLE = arrays

ifdef DEBUG
CFLAGS += -g -DDEBUG
DEBUG: clean $(EXECUTABLE)
endif

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

arrays.o: arrays.h arrays.c
	$(CC) $(CFLAGS) -c arrays.c

clean:
	rm -f $(EXECUTABLE) *.o 