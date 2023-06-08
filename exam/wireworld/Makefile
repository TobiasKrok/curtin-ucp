CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
LDFLAGS = -lm
OBJECTS = main.o input.o newSleep.o color.o simulation.o arrays.o
EXECUTABLE = wireworld

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

main.o: main.c macros.h input.h simulation.h
	$(CC) $(CFLAGS) -c main.c

newSleep.o: newSleep.c newSleep.h
	$(CC) $(CFLAGS) -c newSleep.c

color.o: color.c color.h
	$(CC) $(CFLAGS) -c color.c

input.o: input.c input.h macros.h arrays.h
	$(CC) $(CFLAGS) -c input.c

simulation.o: simulation.c simulation.h color.h arrays.h newSleep.h
	$(CC) $(CFLAGS) -c simulation.c

arrays.o: arrays.c arrays.h
	$(CC) $(CFLAGS) -c arrays.c

clean:
	rm -f $(EXECUTABLE) *.o 
