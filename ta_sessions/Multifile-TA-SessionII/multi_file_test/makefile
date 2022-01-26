CC_EXEC=g++
CC_FLAGS=-g

CC=${CC_EXEC} ${CC_FLAGS}

BUILD_DIR=build
OUT_FILE_NAME = executable.out

all: ${OUT_FILE_NAME}

${OUT_FILE_NAME}: ${BUILD_DIR}/man.o ${BUILD_DIR}/to.o
	${CC} ${BUILD_DIR}/man.o ${BUILD_DIR}/to.o -o ${BUILD_DIR}/${OUT_FILE_NAME}

${BUILD_DIR}/man.o: man.cpp to.hpp
	${CC} -c man.cpp -o ${BUILD_DIR}/man.o

${BUILD_DIR}/to.o: to.cpp to.hpp
	${CC} -c to.cpp -o ${BUILD_DIR}/to.o	

clean:
	rm -rf build/ && mkdir -p build
