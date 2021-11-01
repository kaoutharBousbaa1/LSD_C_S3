  CC = gcc
  CFLAGS = -c -Wall

  all: Pointer_arithmetic
  Pointer_arithmetic: main.o Pointer_arithmetic.o
			$(CC) main.o Pointer_arithmetic.o -o Pointer_arithmetic
  main.o: main.c
		   $(CC) $(CFLAGS) main.c
  Pointer_arithmetic.o: Pointer_arithmetic.c
			$(CC) $(CFLAGS) Pointer_arithmetic.c

  clean: rw -rf *o Pointer_arithmetic 