#####################################################################
####################### Makefile Template ###########################
#####################################################################

# Compiler settings
CC_EXEC = g++
CC_FLAGS = -std=c++11 -Wall -I $(INCLUDE_DIR)
LINKER_FLAGS = -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
CC = $(CC_EXEC) $(CC_FLAGS)

# Directories settings
BUILD_DIR = build
SRC_DIR = .
INCLUDE_DIR = .
EXECUTABLE_FILE = rsdl_test.out


################### Dependencies ###################

OBJECTS = \
	$(BUILD_DIR)/main.o \
	$(BUILD_DIR)/rsdl.o \

mainDependencies = \
	$(SRC_DIR)/main.cpp \
	$(INCLUDE_DIR)/rsdl.hpp \

rsdlDependencies = \
	$(SRC_DIR)/rsdl.cpp \
	$(INCLUDE_DIR)/rsdl.hpp \


#################################################################
############################ Targets ############################
#################################################################

all: $(BUILD_DIR) $(BUILD_DIR)/$(EXECUTABLE_FILE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# rsdl_test.out
$(BUILD_DIR)/$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LINKER_FLAGS) -o $(BUILD_DIR)/$(EXECUTABLE_FILE)

# main
$(BUILD_DIR)/main.o: $(mainDependencies)
	$(CC) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

# rsdl
$(BUILD_DIR)/rsdl.o: $(rsdlDependencies)
	$(CC) -c $(SRC_DIR)/rsdl.cpp -o $(BUILD_DIR)/rsdl.o



################### Utilities ###################
run: 
	./$(BUILD_DIR)/$(EXECUTABLE_FILE)

clean:
	rm -rf $(BUILD_DIR)/ && mkdir -p $(BUILD_DIR)
