#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

#include <iostream>
#include "Heap.h"
using namespace std;

class Huffman{
private:
  Node *root;
  void HelpEncodeMap(Node* begin, string code, pair<char, string>* map);
public:
	Huffman(string input);
    Huffman(){};
	//~Huffman();
    string Encode(){return "";};
    string Decode(){return "";};
    void Print(Node root);
    void Print(){ this->encodeTree->Print(); };
    pair<char, int>* CountFreq(string input);
    pair<char, string>* EncodeMap();
};
#endif
