CC = gcc
CFLAGS = -c -Wall


all : lab11


lab11: main.o team.o
	$(CC) main.o team.o -o lab11

main.o: main.c
	$(CC) $(CFLAGS) main.c

team.o: team.c
	$(CC) $(CFLAGS) team.c

clean:
	rm -rf *.o

clean_all:
	rm -rf *.o lab11
