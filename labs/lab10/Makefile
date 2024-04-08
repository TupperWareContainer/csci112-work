CC=gcc
CFLAGS = -c -Wall

all: lab10

lab10: main.o Character.o
	$(CC) main.o Character.o -o lab10 -lm

main.o: main.c
	$(CC) main.c $(CFLAGS)

Character.o: Character.c
	$(CC) Character.c $(CFLAGS)


clean:
	rm -rf *.o lab10
