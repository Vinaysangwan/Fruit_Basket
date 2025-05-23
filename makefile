# Compiler
CXX = g++
CXXFLAGS = -I./include -std=c++23 -Wall -Wextra -O3

# Linker
LDFLAGS = -L./lib -lraylib

# Directories
SRC_DIR = src
OBJ_DIR = output

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Executable
EXE = main.exe

# Target
all: $(EXE) run

# Compilation rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Linking rule
$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJS) $(LDFLAGS)

# Run the executable
run: $(EXE)
	./$(EXE)

# Debug
debug:
	gdb ./$(EXE)

# Clean output
clean:
	rm -rf $(OBJ_DIR)/* $(EXE)