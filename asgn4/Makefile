CC = clang
CFLAGS = -Wall -Wpedantic -Wextra -Werror

all: sequence

sequence: sequence.o
	$(CC) -o sequence sequence.o -lm

sequence.o: sequence.c bv.o sieve.o

bv.o: bv.c bv.h
	$(CC) $(CFLAGS) -c bv.c

sieve.o: sieve.c sieve.h
	$(CC) $(CFLAGS) -c sieve.c

clean:
	rm -rf sequence sequence.o bv.o sieve.o infer-out

infer:
	make clean; infer-capture -- make; infer-analyze --make
