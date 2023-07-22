include ../common.mk


APP_NAME := FileSearcherApp
INC_DIR := ../FileSearcher/include

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(BUILD_DIR)/$(APP_NAME): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ_FILES) -L$(BUILD_DIR) -l:$(LIB_NAME)