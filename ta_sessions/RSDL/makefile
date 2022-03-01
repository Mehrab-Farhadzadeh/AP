CC_EXEC = g++
CC_FLAGS = -std=c++11 -Wextra -I $(INCLUDE_DIR)
CC = $(CC_EXEC) $(CC_FLAGS)

BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
EXECUTABLE_FILE = RSDL.out

OBJECTS = \
	$(BUILD_DIR)/main.o \

mainDependencies = \
	$(SRC_DIR)/main.cpp \

DepTestDependencies = \
	$(SRC_DIR)/DepTest.cpp \
	$(INCLUDE_DIR)/DepTest.hpp \


all: $(BUILD_DIR) $(BUILD_DIR)/$(EXECUTABLE_FILE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# a.out
$(BUILD_DIR)/$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BUILD_DIR)/$(EXECUTABLE_FILE)

# main
$(BUILD_DIR)/main.o: $(mainDependencies)
	$(CC) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

# DepTest
$(BUILD_DIR)/DepTest.o: $(DepTestDependencies)
	$(CC) -c $(SRC_DIR)/DepTest.cpp -o $(BUILD_DIR)/DepTest.o

		
run: 
	./$(BUILD_DIR)/$(EXECUTABLE_FILE)

clean:
	rm -rf $(BUILD_DIR)/ && mkdir -p $(BUILD_DIR)
