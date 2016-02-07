#include "Huffman.h"
#include <iostream>
using namespace std;

pair<char, int>* Huffman::CountFreq(string input){
    pair<char, int> *map = new pair<char, int>[27];
    for(int i = 0; i < 26; i++)
    {
	    pair<char, int> *temp = new pair<char, int>(static_cast<char>(i+97), 0);
	    map[i] = *temp;
    }
    pair<char, int> *temp = new pair<char, int>(' ', 0);
    map[26] = *temp;

    for(size_t i = 0; i < input.length(); i++)
    {
	    if(input[i] == ' ')
	        map[26].second ++;
	    else
	        map[static_cast<int>(input[i])-97].second ++;
    }
    return map;
}
Huffman::Huffman(string input){
  encodeTree = new Heap(CountFreq(input));
}

/*
void Huffman::print(){
  this->encodeTree->Print();
}
*/

