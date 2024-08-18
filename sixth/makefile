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
	kill -SIGUSR1 `pidof $(TARGET)`
	kill -SIGUSR2 `pidof $(TARGET)`
	kill -SIGINT `pidof $(TARGET)`
	kill -SIGTERM `pidof $(TARGET)`
