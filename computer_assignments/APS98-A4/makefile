CC_EXEC = g++
CC_FLAGS = -std=c++11 -Wextra -I $(INCLUDE_DIR)
CC = $(CC_EXEC) $(CC_FLAGS)

BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
EXECUTABLE_FILE = Scheduler.out

OBJECTS = \
	$(BUILD_DIR)/Main.o \
	$(BUILD_DIR)/RoundRobinScheduler.o \
	$(BUILD_DIR)/MulticoreProcessor.o \
	$(BUILD_DIR)/Process.o \
	$(BUILD_DIR)/Core.o \
	$(BUILD_DIR)/Thread.o \
	$(BUILD_DIR)/Interface.o

MainDependencies = \
	$(SRC_DIR)/Main.cpp \
	$(INCLUDE_DIR)/RoundRobinScheduler.hpp \
	$(INCLUDE_DIR)/MulticoreProcessor.hpp \
	$(INCLUDE_DIR)/Core.hpp \
	$(INCLUDE_DIR)/Process.hpp \
	$(INCLUDE_DIR)/Core.hpp \
	$(INCLUDE_DIR)/Thread.hpp \
	$(INCLUDE_DIR)/Interface.hpp \

RoundRobinSchedulerDependencies = \
	$(SRC_DIR)/RoundRobinScheduler.cpp \
	$(INCLUDE_DIR)/RoundRobinScheduler.hpp \
	$(INCLUDE_DIR)/MulticoreProcessor.hpp \
	$(INCLUDE_DIR)/Process.hpp \
	$(INCLUDE_DIR)/Thread.hpp \

MulticoreProcessorDependencies = \
	$(SRC_DIR)/MulticoreProcessor.cpp \
	$(INCLUDE_DIR)/MulticoreProcessor.hpp \
	$(INCLUDE_DIR)/Process.hpp \
	$(INCLUDE_DIR)/Core.hpp \

ProcessDependencies = \
	$(SRC_DIR)/Process.cpp \
	$(INCLUDE_DIR)/Process.hpp \
	$(INCLUDE_DIR)/Thread.hpp \

CoreDependencies = \
	$(SRC_DIR)/Core.cpp \
	$(INCLUDE_DIR)/Core.hpp \
	$(INCLUDE_DIR)/Thread.hpp \
	$(INCLUDE_DIR)/Process.hpp \

ThreadDependencies = \
	$(SRC_DIR)/Thread.cpp \
	$(INCLUDE_DIR)/Thread.hpp \

InterfaceDependencies = \
	$(SRC_DIR)/Interface.cpp \
	$(INCLUDE_DIR)/Interface.hpp \
	$(INCLUDE_DIR)/RoundRobinScheduler.hpp \


all: $(BUILD_DIR) $(BUILD_DIR)/$(EXECUTABLE_FILE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Scheduler.out
$(BUILD_DIR)/$(EXECUTABLE_FILE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BUILD_DIR)/$(EXECUTABLE_FILE)

# Main
$(BUILD_DIR)/Main.o: $(MainDependencies)
	$(CC) -c $(SRC_DIR)/Main.cpp -o $(BUILD_DIR)/Main.o

# RoundRobinScheduler
$(BUILD_DIR)/RoundRobinScheduler.o: $(RoundRobinSchedulerDependencies)
	$(CC) -c $(SRC_DIR)/RoundRobinScheduler.cpp -o $(BUILD_DIR)/RoundRobinScheduler.o
	
# MulticoreProcessor
$(BUILD_DIR)/MulticoreProcessor.o: $(MulticoreProcessorDependencies)
	$(CC) -c $(SRC_DIR)/MulticoreProcessor.cpp -o $(BUILD_DIR)/MulticoreProcessor.o

# Process
$(BUILD_DIR)/Process.o: $(ProcessDependencies)
	$(CC) -c $(SRC_DIR)/Process.cpp -o $(BUILD_DIR)/Process.o

# Core
$(BUILD_DIR)/Core.o: $(CoreDependencies)
	$(CC) -c $(SRC_DIR)/Core.cpp -o $(BUILD_DIR)/Core.o

# Thread
$(BUILD_DIR)/Thread.o: $(ThreadDependencies)
		$(CC) -c $(SRC_DIR)/Thread.cpp -o $(BUILD_DIR)/Thread.o

# Interface
$(BUILD_DIR)/Interface.o: $(ThreadDependencies)
		$(CC) -c $(SRC_DIR)/Interface.cpp -o $(BUILD_DIR)/Interface.o

		
run: 
	./$(BUILD_DIR)/$(EXECUTABLE_FILE)

clean:
	rm -rf $(BUILD_DIR)/ && mkdir -p $(BUILD_DIR)
