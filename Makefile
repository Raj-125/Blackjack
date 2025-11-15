CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -Iinclude

SRC := src/main.cpp src/blackjack.cpp src/deck.cpp src/player.cpp
OBJ := $(SRC:.cpp=.o)
TARGET := bin/blackjack

all: $(TARGET)

$(TARGET): $(OBJ) | bin
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

bin:
	mkdir -p bin

clean:
	rm -f $(OBJ) $(TARGET)