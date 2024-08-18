TARGET = signal_program
CXX = g++
CXXFLAGS = -Wall -Wextra -O2

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

signal: $(TARGET)
	kill -USR1 `pidof $(TARGET)`
	kill -USR2 `pidof $(TARGET)`
	kill -INT `pidof $(TARGET)`
	kill -TERM `pidof $(TARGET)`
