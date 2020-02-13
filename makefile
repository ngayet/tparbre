BIN=prog
OBJECTS=point.o arbre.o
CC=gcc
CFLAGS=-g -Wall

all: $(BIN)

$(BIN): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BIN) -lm

arbre.o: arbre.c arbre.h point.h
	$(CC) $(CFLAGS) -c arbre.c

point.o: point.c point.h
	$(CC) $(CFLAGS) -c point.c

clean:
	rm $(OBJECTS) $(BIN)
