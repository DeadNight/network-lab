all: hello

clean:
		rm -rf hello hello.o

hello: hello.o
		gcc hello.o -o hello

hello.o: hello.cpp
		gcc -c hello.cpp -o hello.o