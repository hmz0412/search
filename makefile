all: search.c linear.o  binary.o hash.o
	gcc search.c linear.o  binary.o hash.o  -o main
linear.o: linear.c linear.h
	gcc -c linear.c -o linear.o
binary.o: binary.c binary.h
	gcc -c binary.c -o binary.o
hash.o: hash.c hash.h
	gcc -c hash.c -o hash.o

clean: 
	rm -f linear.o  binary.o hash.o  main

