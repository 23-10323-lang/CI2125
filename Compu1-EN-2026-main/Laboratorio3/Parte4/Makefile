
TARGET := test

CXXFLAGS :=

CXX := g++

# List of source files and corresponding object files
SRC := $(wildcard *.cxx)
OBJ := $(SRC:.cxx=.o)

# Pattern rule: compile .cxx to .o
%.o: %.cxx %.h Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@

clean:
	rm -f $(TARGET) $(OBJ) test *.exe a.out
