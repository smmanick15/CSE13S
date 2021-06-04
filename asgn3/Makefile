CC = clang
CFLAGS = -Wall -Wpedantic -Wextra -Werror

all: tower

tower: tower.o
	$(CC) -o tower tower.o

tower.o: tower.c stack.o

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -rf tower tower.o stack.o infer-out

infer:
	make clean; infer-capture -- make; infer-analyze --make
