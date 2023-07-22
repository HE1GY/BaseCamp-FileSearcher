include ../common.mk

# Directories
SRC_DIR := src
INC_DIR := include
BUILD_DIR := ../build

# Output library name
LIB_NAME := FileSearcher.a

# Source files and object files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Build rules
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(BUILD_DIR)/$(LIB_NAME): $(OBJ_FILES)
	ar rcs $@ $(OBJ_FILES)


