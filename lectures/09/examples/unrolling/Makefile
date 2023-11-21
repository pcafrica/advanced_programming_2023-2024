CXX=g++
CPPFLAGS=-O3
CXXFLAGS=-Wall -Wpedantic -Werror

SRC=unrolling.cpp
OBJ=$(SRC:.cpp=.o)

all: unrolling

unrolling: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.o unrolling
