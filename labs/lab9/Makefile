OBJC = gcc -c -Wall
C = gcc -Wall


all: lab9

lab9: lab9.o county.o sort.o utils.o
	$(C) lab9.o county.o sort.o utils.o -o lab9

lab9.o: lab9.c
	$(OBJC) lab9.c

county.o: county.c
	$(OBJC) county.c

sort.o: sort.c
	$(OBJC) sort.c

utils.o: utils.c
	$(OBJC) utils.c

clean: 
	rm -rf *.o main
