CC = gcc
CFLAGS = -Wall -ansi -pedantic
LDFLAGS = -lm
OBJECTS = numbers.o order.o
EXECUTABLE = number

ifdef DEBUG
CFLAGS += -g -DDEBUG
DEBUG: clean $(EXECUTABLE)
endif

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

numbers.o: numbers.c order.h
	$(CC) $(CFLAGS) -c numbers.c

order.o: order.c order.h
	$(CC) $(CFLAGS) -c order.c

clean:
	rm -f $(EXECUTABLE) *.o 