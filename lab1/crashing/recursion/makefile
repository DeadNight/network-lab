all: recursion

clean:
	rm -rf recursion recursion.o

recursion: recursion.o
	gcc recursion.o -o recursion

recursion.o: recursion.cpp
	gcc -g -c recursion.cpp -o recursion.o