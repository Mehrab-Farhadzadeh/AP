CC_EXEC = g++
CC_FLAGS = -std=c++11 -Wextra
CC = $(CC_EXEC) $(CC_FLAGS)

BUILD_DIR = build
EXECUTABLE_FILE = 5th_Slide.out

OBJECTS = \
	$(BUILD_DIR)/main.o \
	$(BUILD_DIR)/date.o \

mainDependencies = \
	main.cpp \
	date.h \

dateDependencies = \
	date.cpp \
	date.h \


all: $(BUILD_DIR) $(BUILD_DIR)/$(EXECUTABLE_FILE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# 5th_Slide.out
$(BUILD_DIR)/$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BUILD_DIR)/$(EXECUTABLE_FILE)

# main
$(BUILD_DIR)/main.o: $(mainDependencies)
	$(CC) -c main.cpp -o $(BUILD_DIR)/main.o

# date
$(BUILD_DIR)/date.o: $(dateDependencies)
	$(CC) -c date.cpp -o $(BUILD_DIR)/date.o

		

ARG_1 = students.txt
run: 
	./$(BUILD_DIR)/$(EXECUTABLE_FILE) $(ARG_1)

clean:
	rm -rf $(BUILD_DIR)/ && mkdir -p $(BUILD_DIR)
