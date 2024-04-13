main: main.o astronaut.o flight.o
	g++ -Wall main.o astronaut.o flight.o -o main

main.o: main.cpp
	g++ -c -Wall main.cpp -o main.o

flight.o: impl/flight.cpp
	g++  -Wall -Iinclude impl/flight.cpp impl/astronaut.cpp -o flight.o

astronaut.o: impl/astronaut.cpp
	g++ -c -Wall -Iinclude impl/astronaut.cpp -o astronaut.o

clean:
	rm -f *.o
