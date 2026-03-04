all: encoder

encoder: main.o hash.o
	g++ -std=c++11 -o encoder main.o hash.o -lm

main.o: main.cpp hash.h
	g++ -std=c++11 -c main.cpp

hash.o: hash.cpp hash.h
	g++ -std=c++11 -c hash.cpp

clean:
	rm -f *.o encoder
