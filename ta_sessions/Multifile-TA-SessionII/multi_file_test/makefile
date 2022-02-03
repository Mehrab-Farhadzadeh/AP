CC_EXEC = g++
CC_FLAGS = -g

CC=${CC_EXEC} ${CC_FLAGS}

BUILD_DIR = build
EXEC_FILE_NAME = executable.out

all: ${BUILD_DIR}/${EXEC_FILE_NAME}

${BUILD_DIR}/${EXEC_FILE_NAME}: ${BUILD_DIR}/man.o ${BUILD_DIR}/to.o
	${CC} ${BUILD_DIR}/man.o ${BUILD_DIR}/to.o -o ${BUILD_DIR}/${EXEC_FILE_NAME}

${BUILD_DIR}/man.o: man.cpp to.hpp
	${CC} -c man.cpp -o ${BUILD_DIR}/man.o

${BUILD_DIR}/to.o: to.cpp to.hpp
	${CC} -c to.cpp -o ${BUILD_DIR}/to.o	

clean:
	rm -rf ${BUILD_DIR}/ && mkdir -p ${BUILD_DIR}
