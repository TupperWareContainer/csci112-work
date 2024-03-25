CC = gcc
CFLAGS = -c -Wall


all : main.o planet.o
	$(CC) main.o planet.o -o a.out

main.o : main.c
	$(CC) $(CFLAGS) main.c

planet.o : planet.c planet.h
	$(CC) $(CFLAGS) planet.c

clean :
	rm -f *.o


