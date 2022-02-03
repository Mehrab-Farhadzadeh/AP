CC_EXEC = g++ -std=c++11
CC_FLAGS = -Wextra -g

CC = $(CC_EXEC) $(CC_FLAGS)

BUILD_DIR = build
EXEC_FILE_NAME = a.out

MAIN = man
DEP_1 = to

all: $(BUILD_DIR)/$(EXEC_FILE_NAME)

$(BUILD_DIR)/$(EXEC_FILE_NAME): $(BUILD_DIR)/$(MAIN).o $(BUILD_DIR)/$(DEP_1).o
	$(CC) $(BUILD_DIR)/$(MAIN).o $(BUILD_DIR)/$(DEP_1).o -o $(BUILD_DIR)/$(EXEC_FILE_NAME)

$(BUILD_DIR)/$(MAIN).o: $(MAIN).cpp $(DEP_1).hpp
	$(CC) -c $(MAIN).cpp -o $(BUILD_DIR)/$(MAIN).o

$(BUILD_DIR)/$(DEP_1).o: $(DEP_1).cpp $(DEP_1).hpp
	$(CC) -c $(DEP_1).cpp -o $(BUILD_DIR)/$(DEP_1).o

run: 
	./$(BUILD_DIR)/$(EXEC_FILE_NAME)

clean:
	rm -rf $(BUILD_DIR)/ && mkdir -p $(BUILD_DIR)
