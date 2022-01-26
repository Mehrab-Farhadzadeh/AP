CC_EXEC=g++
CC_FLAGS=-g

CC=${CC_EXEC} ${CC_FLAGS}

BUILD_DIR=build
OUT_FILE_NAME = executable.out

all: ${OUT_FILE_NAME}

${OUT_FILE_NAME}:  ${BUILD_DIR}/main.o  ${BUILD_DIR}/A.o  ${BUILD_DIR}/B.o  ${BUILD_DIR}/C.o
	${CC} ${BUILD_DIR}/main.o ${BUILD_DIR}/A.o ${BUILD_DIR}/B.o ${BUILD_DIR}/C.o -o ${BUILD_DIR}/${OUT_FILE_NAME}

${BUILD_DIR}/main.o: main.cc C.hh B.hh A.hh
	${CC} -c main.cc -o ${BUILD_DIR}/main.o

${BUILD_DIR}/A.o: A.cc A.hh
	${CC} -c A.cc -o ${BUILD_DIR}/A.o

${BUILD_DIR}/B.o: B.cc B.hh A.hh
	${CC} -c B.cc -o ${BUILD_DIR}/B.o

${BUILD_DIR}/C.o: C.cc C.hh B.hh C.hh
	${CC} -c C.cc -o ${BUILD_DIR}/C.o

clean:
	rm -rf build/ && mkdir -p build
