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
	$(BUILD_DIR)/03_event_driven_programming.o \

03_event_driven_programmingDependencies = \
	$(SRC_DIR)/03_event_driven_programming.cpp \

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

# 03_event_driven_programming
$(BUILD_DIR)/03_event_driven_programming.o: $(03_event_driven_programmingDependencies)
	$(CC) -c $(SRC_DIR)/03_event_driven_programming.cpp -o $(BUILD_DIR)/03_event_driven_programming.o

# DepTest
$(BUILD_DIR)/DepTest.o: $(DepTestDependencies)
	$(CC) -c $(SRC_DIR)/DepTest.cpp -o $(BUILD_DIR)/DepTest.o



################### Utilities ###################
run: 
	./$(BUILD_DIR)/$(EXECUTABLE_FILE)

clean:
	rm -rf $(BUILD_DIR)/ && mkdir -p $(BUILD_DIR)
