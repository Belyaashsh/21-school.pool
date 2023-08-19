CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
LDFLAGS=
EXE=../build/graph

all: clean $(OBJECTS)
	$(CC) $(CFLAGS) -c graph.c -o graph.o
	$(CC) $(CFLAGS) -c input.c -o input.o
	$(CC) $(CFLAGS) -c operations.c -o operations.o
	$(CC) $(CFLAGS) -c draw.c -o draw.o
	$(CC) $(CFLAGS) -c calc.c -o calc.o
	$(CC) $(LDFLAGS) graph.o input.o operations.o draw.o calc.o -o $(EXE)


clean:
	rm -rf *.o