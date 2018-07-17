# Makefile for program zeroit

zeroit: zeroit.c
	gcc -o zeroit zeroit.c

clean:
	rm -f zeroit zeroit.o

