CC=gcc
CFLAGS=-Wall -pedantic
EXEC=hangman
OBJ=main.o dictionary.o util.o

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

dictionary.o: dictionary.c dictionary.h
	$(CC) $(CFLAGS) -c dictionary.c -o dictionary.o

util.o: util.c util.h
	$(CC) $(CFLAGS) -c util.c -o util.o

.PHONY: clean

clean:
	rm -rf $(EXEC) $(OBJ)
