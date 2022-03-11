#####################################################################
####################### Makefile Template ###########################
#####################################################################

# Compiler settings
CC_EXEC = g++
CC_FLAGS = -std=c++11 -Wall
LINKER_FLAGS = -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
CC = $(CC_EXEC) $(CC_FLAGS)

# Directories settings
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = hdr
EXECUTABLE_FILE = Warm-up.out


################### Dependencies ###################

OBJECTS = \
	$(BUILD_DIR)/main.o \
	$(BUILD_DIR)/update.o \
	$(BUILD_DIR)/draw.o \
	$(BUILD_DIR)/rsdl.o \

mainDependencies = \
	$(SRC_DIR)/main.cpp \
	$(INCLUDE_DIR)/main.hpp \
	$(INCLUDE_DIR)/draw.hpp \
	$(INCLUDE_DIR)/update.hpp \
	$(INCLUDE_DIR)/rsdl.hpp \

updateDependencies = \
	$(SRC_DIR)/update.cpp \
	$(INCLUDE_DIR)/update.hpp \
	$(INCLUDE_DIR)/rsdl.hpp \

drawDependencies = \
	$(SRC_DIR)/draw.cpp \
	$(INCLUDE_DIR)/draw.hpp \
	$(INCLUDE_DIR)/main.hpp \
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

# Warm-up.out
$(BUILD_DIR)/$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LINKER_FLAGS) -o $(BUILD_DIR)/$(EXECUTABLE_FILE)

# main
$(BUILD_DIR)/main.o: $(mainDependencies)
	$(CC) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

# update
$(BUILD_DIR)/update.o: $(updateDependencies)
	$(CC) -c $(SRC_DIR)/update.cpp -o $(BUILD_DIR)/update.o

# draw
$(BUILD_DIR)/draw.o: $(drawDependencies)
	$(CC) -c $(SRC_DIR)/draw.cpp -o $(BUILD_DIR)/draw.o

# rsdl
$(BUILD_DIR)/rsdl.o: $(rsdlDependencies)
	$(CC) -c $(SRC_DIR)/rsdl.cpp -o $(BUILD_DIR)/rsdl.o


################### Utilities ###################
run: 
	./$(BUILD_DIR)/$(EXECUTABLE_FILE)

clean:
	rm -rf $(BUILD_DIR)/ && mkdir -p $(BUILD_DIR)
