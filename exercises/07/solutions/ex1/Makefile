CXX=g++
CPPFLAGS=-Imuparserx/parser/
CXXFLAGS=-std=c++17 -Wall -Wpedantic -Werror
LDFLAGS=-Wl,-rpath,muparserx/parser -Lmuparserx/parser
LDLIBS=-lmuparserx

SRC=ex1.cpp
OBJ=$(SRC:.cpp=.o)

all: ex1

ex1: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@

%.o: %.cpp
	$(CXX) -c $< $(CPPFLAGS) $(CXXFLAGS) -o $@

clean:
	rm -f *.o ex1
