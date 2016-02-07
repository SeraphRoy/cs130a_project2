#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

#include <iostream>
#include "Heap.h"
using namespace std;

class Huffman{
private:
	//Heap encodeTree;
	
public:
	Huffman(){};
	//~Huffman();
    string Encode(){return "";};
    string Decode(){return "";};
	pair<char, int>* CountFreq(string input);

};
#endif