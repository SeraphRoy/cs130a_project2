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

//NOT DONE YET
Huffman::Huffman(string input){
  Heap* encodeTree = new Heap(CountFreq(input));
  while(encodeTree->GetHeapSize() != 1){
    pair<char, int> min1 = encodeTree->DeleteMin();
    pair<char, int> min2 = encodeTree->DeleteMin();
  }
}

/*
void Huffman::print(){
  this->encodeTree->Print();
}
*/

