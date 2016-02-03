#CXX = g++
CXX = clang++

BINARIES = Heap Huffman


all: Main.o Heap.o Huffman.o
	${CXX} -g Heap.o Huffman.o Main.o -o prog1

Main.o: Main.cpp
	${CXX} -c Main.cpp

Heap.o: Hep.cpp
	${CXX} -c Heap.cpp

Huffman.o: Huffman.cpp
	${CXX} -c Huffman.cpp

clean:
	/bin/rm -f *o *~ \#* ${BINARIES}
