  CC = gcc
  CFLAGS = -c -Wall

  all: print_nth_bit
  print_nth_bit: main.o print_nth_bit.o
			$(CC) main.o print_nth_bit.o -o print_nth_bit
  main.o: main.c
		   $(CC) $(CFLAGS) main.c
  print_nth_bit.o: print_nth_bit.c
			$(CC) $(CFLAGS) print_nth_bit.c

  clean: rw -rf *o print_nth_bit 