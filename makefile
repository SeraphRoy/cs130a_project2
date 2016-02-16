#CXX = g++
CXX = clang++

#CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES = prog2
all:${BINARIES}

prog2: Heap.o prog2.o Huffman.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o
