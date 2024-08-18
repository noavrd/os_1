CXX = g++
CXXFLAGS = -Wall -pg

all: naive improved kadane

naive: main.cpp
	$(CXX) $(CXXFLAGS) -DVERSION_NAIVE -o naive main.cpp

improved: main.cpp
	$(CXX) $(CXXFLAGS) -DVERSION_IMPROVED -o improved main.cpp

kadane: main.cpp
	$(CXX) $(CXXFLAGS) -DVERSION_KADANE -o kadane main.cpp

clean:
	rm -f naive improved kadane
