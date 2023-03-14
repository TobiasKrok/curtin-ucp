CC = gcc
CFLAGS = -Wall -ansi -pedantic
LDFLAGS = -lm
OBJECTS = powers.o bounds.o
EXECUTABLE = program

ifdef DEBUG
CFLAGS += -g -DDEBUG
DEBUG: clean $(EXECUTABLE)
endif

$(EXECUTABLE): $(OBJECTS)
	gcc $(OBJECTS) $(LDFLAGS) -o $(EXECUTABLE) 

powers: powers.c powers.h
	$(CC) $(CFLAGS) -c powers.c

bounds: bounds.c macros.h powers.h
	$(CC) $(CFLAGS) -c bounds.c

clean:
	rm -f $(EXECUTABLE) *.o 
