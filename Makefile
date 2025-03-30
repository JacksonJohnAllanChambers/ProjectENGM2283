# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude

# Directories
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build
BIN_DIR := bin

# Files
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
TARGET := $(BIN_DIR)/library_system

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile each .cpp file to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run

# Create directories if they don't exist
$(BUILD_DIR):
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
$(BIN_DIR): $(BUILD_DIR)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)