CC_EXEC = g++ -std=c++11
CC_FLAGS = -Wextra

CC = $(CC_EXEC) $(CC_FLAGS)

BUILD_DIR = build
EXEC_FILE_NAME = Scheduler.out
MAIN = main_APS98-A4


all: $(BUILD_DIR)/$(EXEC_FILE_NAME)

# a.out
$(BUILD_DIR)/$(EXEC_FILE_NAME): $(BUILD_DIR)/$(MAIN).o $(BUILD_DIR)/RoundRobinScheduler.o $(BUILD_DIR)/MulticoreProcessor.o $(BUILD_DIR)/Process.o $(BUILD_DIR)/Core.o $(BUILD_DIR)/Thread.o $(BUILD_DIR)/Interface.o
	$(CC) $(BUILD_DIR)/$(MAIN).o $(BUILD_DIR)/RoundRobinScheduler.o $(BUILD_DIR)/MulticoreProcessor.o $(BUILD_DIR)/Process.o $(BUILD_DIR)/Core.o $(BUILD_DIR)/Thread.o $(BUILD_DIR)/Interface.o -o $(BUILD_DIR)/$(EXEC_FILE_NAME)

# main
$(BUILD_DIR)/$(MAIN).o: $(MAIN).cpp RoundRobinScheduler.hpp MulticoreProcessor.hpp Core.hpp Process.hpp Core.hpp Thread.hpp Interface.hpp
	$(CC) -c $(MAIN).cpp -o $(BUILD_DIR)/$(MAIN).o

# RoundRobinScheduler
$(BUILD_DIR)/RoundRobinScheduler.o: RoundRobinScheduler.cpp RoundRobinScheduler.hpp MulticoreProcessor.hpp Process.hpp Thread.hpp
	$(CC) -c RoundRobinScheduler.cpp -o $(BUILD_DIR)/RoundRobinScheduler.o
	
# MulticoreProcessor
$(BUILD_DIR)/MulticoreProcessor.o: MulticoreProcessor.cpp MulticoreProcessor.hpp Process.hpp Core.hpp
	$(CC) -c MulticoreProcessor.cpp -o $(BUILD_DIR)/MulticoreProcessor.o

# Process
$(BUILD_DIR)/Process.o: Process.cpp Process.hpp Thread.hpp
	$(CC) -c Process.cpp -o $(BUILD_DIR)/Process.o

# Core
$(BUILD_DIR)/Core.o: Core.cpp Core.hpp Thread.hpp Process.hpp
	$(CC) -c Core.cpp -o $(BUILD_DIR)/Core.o

# Thread
$(BUILD_DIR)/Thread.o: Thread.cpp Thread.hpp
		$(CC) -c Thread.cpp -o $(BUILD_DIR)/Thread.o

# Interface
$(BUILD_DIR)/Interface.o: Interface.cpp Interface.hpp RoundRobinScheduler.hpp
		$(CC) -c Interface.cpp -o $(BUILD_DIR)/Interface.o

		
run: 
	./$(BUILD_DIR)/$(EXEC_FILE_NAME)

clean:
	rm -rf $(BUILD_DIR)/ && mkdir -p $(BUILD_DIR)
