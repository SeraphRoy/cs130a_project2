#CXX = g++
CXX = clang++
#CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

#BINARIES = Heap Huffman
BINARIES = test
all:${BINARIES}

test: Heap.o Test.o Huffman.o
	${CXX} $^ -o $@
#	./test > myout.txt
#	diff expected_output.txt myout.txt

#all: Main.o Heap.o Huffman.o
#	${CXX} -g Heap.o Huffman.o Main.o -o prog1

#Main.o: Main.cpp
#	${CXX} -c Main.cpp

#Heap.o: Hep.cpp
#	${CXX} -c Heap.cpp

#Huffman.o: Huffman.cpp
#	${CXX} -c Huffman.cpp

clean:
	/bin/rm -f ${BINARIES} *.o