#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

#include <iostream>
#include "Heap.h"
using namespace std;

class Huffman{
private:
  	Heap* encodeTree;
    string Decode(string cipher, Node* root);
public:
	Huffman(string input);
    Huffman(){};
	//~Huffman();
    string Encode(){return "";};
    string Decode(){return "";};
    void Print(Node root);
    void Print(){ this->encodeTree->Print(); };
    pair<char, int>* CountFreq(string input);
    string Decode(string cipher){ return Decode(cipher,this->encodeTree->GetHeap()); };
};
#endif
