all: divide0

clean:
	rm -rf divide0 divide0.o

divide0: divide0.o
	gcc divide0.o -o divide0

divide0.o: divide0.cpp
	gcc -g -c divide0.cpp -o divide0.o