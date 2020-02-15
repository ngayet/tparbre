BIN=prog
OBJECTS=main.o point.o arbre.o fifo.o
CC=gcc
CFLAGS=-Wall

all: $(BIN)

$(BIN): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BIN) -lm

main.o: main.c fifo.h arbre.h point.h
	$(CC) $(CFLAGS) -c main.c

fifo.o: fifo.c fifo.h point.h arbre.h
	$(CC) $(CFLAGS) -c fifo.c

arbre.o: arbre.c arbre.h point.h fifo.h
	$(CC) $(CFLAGS) -c arbre.c

point.o: point.c point.h
	$(CC) $(CFLAGS) -c point.c

clean:
	rm $(OBJECTS) $(BIN)
