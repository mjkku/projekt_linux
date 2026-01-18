CXX := clang++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g

TARGET := tiktak
SRC := main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean

