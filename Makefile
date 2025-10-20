# Compiler and flags
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Executable name
TARGET = $(BIN_DIR)/programme.exe

# Source and object files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default rule
all: build

# Build rule
build: $(TARGET)
	@echo "✅ Build complete: $(TARGET)"

# Linking the final executable
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)
	@echo "🚀 Linked successfully!"

# Compiling each .c file into .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "🧩 Compiled $<"

# Clean rule
clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "🧹 Cleaned all build files."

# Run the program (optional)
run: build
	@./$(TARGET)
