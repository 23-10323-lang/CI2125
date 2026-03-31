
TARGET := usb.exe

CXXFLAGS := -Wall -MMD -MP

CXX := g++

# List of source files and corresponding object files
SRC := $(wildcard *.cxx)
OBJ := $(SRC:.cxx=.o)
DEP := $(SRC:.cxx=.d)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@

-include $(DEP)

%.o: %.cxx Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ) a.out
