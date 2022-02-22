CC_EXEC = g++
CC_FLAGS = -std=c++11 -Wextra
CC = $(CC_EXEC) $(CC_FLAGS)

BUILD_DIR = build
EXECUTABLE_FILE = APS98-A1.out

OBJECTS = \
	$(BUILD_DIR)/APS98-A1.o \

APS98-A1Dependencies = \
	APS98-A1.cpp \


all: $(BUILD_DIR) $(BUILD_DIR)/$(EXECUTABLE_FILE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# APS98-A1.out
$(BUILD_DIR)/$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BUILD_DIR)/$(EXECUTABLE_FILE)

# APS98-A1.o
$(BUILD_DIR)/APS98-A1.o: $(APS98-A1Dependencies)
	$(CC) -c APS98-A1.cpp -o $(BUILD_DIR)/APS98-A1.o

		
run: 
	./$(BUILD_DIR)/$(EXECUTABLE_FILE)

clean:
	rm -rf $(BUILD_DIR)/ && mkdir -p $(BUILD_DIR)
