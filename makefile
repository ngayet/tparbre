BIN=prog
OBJECTS=point.o arbre.o fifo.o
CC=gcc
CFLAGS=-g -Wall

all: $(BIN)

$(BIN): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BIN) -lm

fifo.o: fifo.c fifo.h point.h arbre.h
	$(CC) $(CFLAGS) -c fifo.c

arbre.o: arbre.c arbre.h point.h
	$(CC) $(CFLAGS) -c arbre.c

point.o: point.c point.h
	$(CC) $(CFLAGS) -c point.c

clean:
	rm $(OBJECTS) $(BIN)
