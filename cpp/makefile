# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

#main: main.o Point.o Rectangle.o
test: test.o game.o matrix.o player.o queue.o 
	$(CXX) $(CXXFLAGS) -o test.o game.o matrix.o player.o queue.o 


test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp

game.o: game.cpp matrix.h queue.h
	$(CXX) $(CXXFLAGS) -c game.cpp

matrix.o: matrix.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c matrix.cpp

player.o: player.cpp matrix.h queue.h player.h
	$(CXX) $(CXXFLAGS) -c player.cpp

queue.o: queue.cpp matrix.h queue.h
	$(CXX) $(CXXFLAGS) -c queue.cpp


