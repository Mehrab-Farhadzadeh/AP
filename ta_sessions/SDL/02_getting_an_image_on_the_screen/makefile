########################################################################
####################### Makefile Template ##############################
########################################################################

# Compiler settings
CC_EXEC = g++
CC_FLAGS = -std=c++11 -Wextra -I $(INCLUDE_DIR)
LINKER_FLAGS = -lSDL2
CC = $(CC_EXEC) $(CC_FLAGS)

# Directories settings
BUILD_DIR = build
SRC_DIR = .
INCLUDE_DIR = include
EXECUTABLE_FILE = RSDL.out


################### Dependencies ###################

OBJECTS = \
	$(BUILD_DIR)/02_getting_an_image_on_the_screen.o \

02_getting_an_image_on_the_screenDependencies = \
	$(SRC_DIR)/02_getting_an_image_on_the_screen.cpp \

DepTestDependencies = \
	$(SRC_DIR)/DepTest.cpp \
	$(INCLUDE_DIR)/DepTest.hpp \


###################################################################
############################ Targets ##############################
###################################################################

all: $(BUILD_DIR) $(BUILD_DIR)/$(EXECUTABLE_FILE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# a.out
$(BUILD_DIR)/$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BUILD_DIR)/$(EXECUTABLE_FILE) $(LINKER_FLAGS)

# 02_getting_an_image_on_the_screen
$(BUILD_DIR)/02_getting_an_image_on_the_screen.o: $(02_getting_an_image_on_the_screenDependencies)
	$(CC) -c $(SRC_DIR)/02_getting_an_image_on_the_screen.cpp -o $(BUILD_DIR)/02_getting_an_image_on_the_screen.o

# DepTest
$(BUILD_DIR)/DepTest.o: $(DepTestDependencies)
	$(CC) -c $(SRC_DIR)/DepTest.cpp -o $(BUILD_DIR)/DepTest.o



################### Utilities ###################
run: 
	./$(BUILD_DIR)/$(EXECUTABLE_FILE)

clean:
	rm -rf $(BUILD_DIR)/ && mkdir -p $(BUILD_DIR)
