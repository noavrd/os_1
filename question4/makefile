# Makefile for Dijkstra's algorithm with coverage

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -fprofile-arcs -ftest-coverage -Wall -Wextra
LDFLAGS = -lgcov

# Target binary
TARGET = dijkstra

# Source files
SRCS = dijkstra.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(TARGET) $(OBJS) *.gcov *.gcda *.gcno

# Run coverage analysis
coverage: $(TARGET)
	./$(TARGET) < input.txt
	gcov $(SRCS)

.PHONY: all clean coverage
