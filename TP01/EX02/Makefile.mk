  CC = gcc
  CFLAGS = -c -Wall

  all: Bitwise
  Bitwise: main.o Bitwise.o
		$(CC) main.o Bitwise.o -o Bitwise
  main.o: main.c
		$(CC) $(CFLAGS) main.c
  Bitwise.o: Bitwise.c
		$(CC) $(CFLAGS) Bitwise.c

  clean: rw -rf *o Bitwise 
