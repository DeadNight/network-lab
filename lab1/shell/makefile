all: shell

clean:
	rm -rf shell shell.o

shell: shell.o
	gcc shell.o -o shell

shell.o: shell.cpp
	gcc -g -c shell.cpp -o shell.o