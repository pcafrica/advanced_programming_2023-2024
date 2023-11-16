CXX=g++
CPPFLAGS=
CXXFLAGS=-std=c++17 -Wall -Wpedantic -Werror
LDFLAGS=
LDLIBS=-ldl

SRC=ex4.cpp
OBJ=$(SRC:.cpp=.o)

all: libfunctions.so ex4

libfunctions.so: functions.o
	$(CXX) $(CXXFLAGS) -shared $< -o $@

ex4: ex4.o
	$(CXX) $(CXXFLAGS) $< $(LDFLAGS) $(LDLIBS) -o $@

%.o: %.cpp
	$(CXX) -c $< $(CPPFLAGS) $(CXXFLAGS) -o $@

clean:
	rm -f *.o *.so ex4
