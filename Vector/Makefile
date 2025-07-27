CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = example
SOURCES = example.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

test: $(TARGET)
	./$(TARGET)

.PHONY: all clean test
