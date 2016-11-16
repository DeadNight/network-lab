all: segfault

clean:
	rm -rf segfault segfault.o

segfault: segfault.o
	gcc segfault.o -o segfault

segfault.o: segfault.cpp
	gcc -g -c segfault.cpp -o segfault.o
