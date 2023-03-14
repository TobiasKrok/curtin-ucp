CC = gcc
CFLAGS = -Wall -ansi -pedantic
LDFLAGS = -lm
OBJECTS = main.o http.o ping.o
EXECUTABLE = pinger

ifdef DEBUG
CFLAGS += -g -DDEBUG
DEBUG: clean $(EXECUTABLE)
endif

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

main.o: main.c http.h ping.h
	$(CC) $(CFLAGS) -c main.c

http.o: http.c http.h
	$(CC) $(CFLAGS) -c http.c

ping.o: ping.c ping.h
	$(CC) $(CFLAGS) -c ping.c

clean:
	rm -f $(EXECUTABLE) *.o 