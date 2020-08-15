# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o game.o matrix.o player.o queue.o 
	$(CXX) $(CXXFLAGS) main.o game.o matrix.o player.o queue.o -o main

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

game.o: game.cpp game.h
	$(CXX) $(CXXFLAGS) -c game.cpp

matrix.o: matrix.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c matrix.cpp

player.o: player.cpp player.h
	$(CXX) $(CXXFLAGS) -c player.cpp

queue.o: queue.cpp queue.h
	$(CXX) $(CXXFLAGS) -c queue.cpp

clean:
	rm *.o main

