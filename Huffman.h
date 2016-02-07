#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

#include <iostream>
#include "Heap.h"
using namespace std;


class Huffman{
private:
  Node *root;
public:
	Huffman(string input);
	//~Huffman();
    string Encode(){return "";};
    string Decode(){return "";};
    //void print();
    pair<char, int>* CountFreq(string input);

};
#endif
