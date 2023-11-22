CXX      ?= g++
CPPFLAGS ?= -g -O0 -Wall -pedantic
CXXFLAGS ?= -std=c++17

EXEC = assert1 assert2 debug_macro defensive \
       pause print student1 student2 \
       undefined_behaviour

.PHONY = all $(EXEC) clean distclean

all: $(EXEC)

$(EXEC): %: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

clean:
	$(RM) *.o

distclean: clean
	$(RM) $(EXEC)
	$(RM) *~
