CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17

LIB_NAME := FileSearcherLib.a

SRC_DIR := src
BUILD_DIR := ../build

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))