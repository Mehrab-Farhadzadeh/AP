CC_EXEC = g++
CC_FLAGS = -std=c++11 -Wextra
CC = $(CC_EXEC) $(CC_FLAGS)

BUILD_DIR = build
SRC_DIR = sources
INCLUDE_DIR = headers
EXECUTABLE_FILE = Billiards.out

OBJECTS = \
	$(BUILD_DIR)/Main.o \
	$(BUILD_DIR)/Ball.o \
	$(BUILD_DIR)/Table.o \

MainDependencies = \
	$(SRC_DIR)/Main.cpp \
	$(INCLUDE_DIR)/Ball.hpp \
	$(INCLUDE_DIR)/Table.hpp \

BallDependencies = \
	$(SRC_DIR)/Ball.cpp \
	$(INCLUDE_DIR)/Ball.hpp \

TableDependencies = \
	$(SRC_DIR)/Table.cpp \
	$(INCLUDE_DIR)/Table.hpp \


all: $(BUILD_DIR) $(BUILD_DIR)/$(EXECUTABLE_FILE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Billiards.out
$(BUILD_DIR)/$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BUILD_DIR)/$(EXECUTABLE_FILE)

# Main
$(BUILD_DIR)/Main.o: $(MainDependencies)
	$(CC) -c $(SRC_DIR)/Main.cpp -o $(BUILD_DIR)/Main.o

# Table
$(BUILD_DIR)/Ball.o: $(BallDependencies)
	$(CC) -c $(SRC_DIR)/Ball.cpp -o $(BUILD_DIR)/Ball.o
	
# Ball
$(BUILD_DIR)/Table.o: $(TableDependencies)
	$(CC) -c $(SRC_DIR)/Table.cpp -o $(BUILD_DIR)/Table.o

		
run: 
	./$(BUILD_DIR)/$(EXECUTABLE_FILE)

clean:
	rm -rf $(BUILD_DIR)/ && mkdir -p $(BUILD_DIR)
