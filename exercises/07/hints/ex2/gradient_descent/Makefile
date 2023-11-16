CXX=g++
CPPFLAGS=-I.
CXXFLAGS=-std=c++17 -Wall -Wpedantic -Werror

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
DEPS=$(wildcard *.hpp)

LIB_NAME=libgradient_descent.so
LIB_VERSION_MAJOR=1
LIB_VERSION_MINOR=0

LIB_NAME_REAL=$(LIB_NAME).$(LIB_VERSION_MAJOR).$(LIB_VERSION_MINOR)

all: $(LIB_NAME_REAL)

$(LIB_NAME_REAL): $(OBJ)
	g++ $(CXXFLAGS) -shared $^ -Wl,-soname,$(LIB_NAME).$(LIB_VERSION_MAJOR) -o $@
	ln -sf $(LIB_NAME_REAL) $(LIB_NAME).$(LIB_VERSION_MAJOR)
	ln -sf $(LIB_NAME).$(LIB_VERSION_MAJOR) $(LIB_NAME)

%.o: %.cpp $(DEPS)
	$(CXX) -c -fPIC $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o *.so*
