include ../common.mk

INC_DIR := include

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(BUILD_DIR)/$(LIB_NAME): $(OBJ_FILES)
	ar rcs $@ $(OBJ_FILES)


