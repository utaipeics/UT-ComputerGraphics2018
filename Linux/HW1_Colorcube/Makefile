CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -lpthread -lGL -lGLU -lglut
BIN=colorcube

SRC=$(wildcard *.cpp)

all:
	$(CXX) -o $(BIN) $(SRC) $(CXXFLAGS)

clean:
	rm $(BIN)
