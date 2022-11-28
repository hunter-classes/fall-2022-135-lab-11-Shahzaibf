main: main.o profile.o
	g++ -o main main.o profile.o

tests: tests.o profile.o
	g++ -o tests tests.o profile.o

main.o: main.cpp profile.h

profile.o: profile.cpp profile.h

tests.o: tests.cpp doctest.h profile.h
	g++ -c -std=c++11 tests.cpp

clean:
	rm -f *.o main tests