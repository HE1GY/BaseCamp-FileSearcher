include ../common.mk

# Directories
SRC_DIR := src
BUILD_DIR := ../build
BIN_DIR := $(BUILD_DIR)
LIB_DIR := $(BUILD_DIR)

INC_DIR := ../FileSearcher/include
LIB_NAME := FileSearcher

# Output binary name
OUTPUT := FileSearcher

# Source files and object files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Build rules
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(BIN_DIR)/$(OUTPUT): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ_FILES) -L$(LIB_DIR) -l:$(LIB_NAME).a