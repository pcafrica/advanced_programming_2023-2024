CXX=g++
CPPFLAGS=-Igradient_descent/
CXXFLAGS=-std=c++17 -Wall -Wpedantic -Werror
LDFLAGS=-Wl,-rpath,gradient_descent -Lgradient_descent/
LDLIBS=-lgradient_descent

SRC=ex2.cpp
OBJ=$(SRC:.cpp=.o)

all: ex2

ex2: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@

%.o: %.cpp
	$(CXX) -c $< $(CPPFLAGS) $(CXXFLAGS) -o $@

clean:
	rm -f *.o ex2
