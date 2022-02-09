CC_EXEC = g++ -std=c++11
CC_FLAGS = -Wextra

CC = $(CC_EXEC) $(CC_FLAGS)

BUILD_DIR = build
EXEC_FILE_NAME = a.out
MAIN = main_APS98-A4


all: $(BUILD_DIR)/$(EXEC_FILE_NAME)

$(BUILD_DIR)/$(EXEC_FILE_NAME): $(BUILD_DIR)/$(MAIN).o $(BUILD_DIR)/Core.o $(BUILD_DIR)/Thread.o
	$(CC) $(BUILD_DIR)/$(MAIN).o $(BUILD_DIR)/Core.o $(BUILD_DIR)/Thread.o -o $(BUILD_DIR)/$(EXEC_FILE_NAME)

$(BUILD_DIR)/$(MAIN).o: $(MAIN).cpp Core.hpp Thread.hpp
	$(CC) -c $(MAIN).cpp -o $(BUILD_DIR)/$(MAIN).o

$(BUILD_DIR)/Core.o: Core.cpp Core.hpp Thread.hpp
	$(CC) -c Core.cpp -o $(BUILD_DIR)/Core.o

$(BUILD_DIR)/Thread.o: Thread.cpp Thread.hpp
		$(CC) -c Thread.cpp -o $(BUILD_DIR)/Thread.o


run: 
	./$(BUILD_DIR)/$(EXEC_FILE_NAME)

clean:
	rm -rf $(BUILD_DIR)/ && mkdir -p $(BUILD_DIR)
