CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -Iinclude

SRC := src/main.cpp src/blackjack.cpp src/deck.cpp src/player.cpp
OBJ := $(patsubst src/%.cpp,obj/%.o,$(SRC))

TARGET := bin/blackjack

all: $(TARGET)

$(TARGET): $(OBJ) | bin
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

# Pattern rule: build obj/file.o from src/file.cpp
obj/%.o: src/%.cpp | obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create bin/ and obj/ if missing
bin:
	mkdir -p bin

obj:
	mkdir -p obj

clean:
	rm -rf obj $(TARGET)