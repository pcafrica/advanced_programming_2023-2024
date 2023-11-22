CXX      ?= g++
CPPFLAGS ?= -O3 -Wall
CXXFLAGS ?= -std=c++17

EXEC     = static loop_unrolling data_alignment

.PHONY = all $(EXEC) clean distclean

all: $(EXEC)

$(EXEC): %: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	$(RM) *.o

distclean: clean
	$(RM) $(EXEC)
	$(RM) *~
