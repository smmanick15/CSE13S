CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c99

all: sorting

sort: sorting.o
	$(CC) -o sort sorting.o

sorting.o: sorting.c bubble.o shell.o quick.o binary.o

bubble.o: bubble.c bubble.h
	$(CC) $(CFLAGS) -c bubble.c

shell.o: shell.c shell.h
	$(CC) $(CFLAGS) -c shell.c

quick.o: quick.c quick.h
	$(CC) $(CFLAGS) -c quick.c

binary.o: binary.c binary.h
	$(CC) $(CFLAGS) -c binary.c

clean:
	rm -rf sorting sorting.o bubble.o shell.o quick.o binary.o infer-out

infer:
	make clean; infer-capture -- make; infer-analyze -- make

valgrind: sorting.c
	valgrind -- make;
