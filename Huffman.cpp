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

pair<char, string>* Huffman::EncodeMap(){
  pair<char, string>* map = new pair<char, string>[27];
  for(int i = 0; i < 26; i++)
    map[i] = pair<char, string>(static_cast<char>(i+97), "");
  map[26] = pair<char, string>(' ', "");
  HelpEncodeMap(root, "", map);
  return map;
}

void Huffman::HelpEncodeMap(Node* begin, string code, pair<char, string>* map){
  if(begin->GetOne() != NULL){
    if(begin->GetOne()->GetWordfreq() != NULL){
      code += "1";
      char index = begin->GetOne()->GetWordfreq()->first;
      if(index != ' '){
        map[static_cast<int>(index)].second = code;
      }
      else{
        map[26].second = code;
      }
      return;
    }
    else{
      code += "1";
      HelpEncodeMap(begin->GetOne(), code, map);
    }
  }
  else
    return;
  if(begin->GetZero() != NULL){
    if(begin->GetZero()->GetWordfreq() != NULL){
      code += "0";
      char index = begin->GetZero()->GetWordfreq()->first;
      if(index != ' '){
        map[static_cast<int>(index)].second = code;
      }
      else{
        map[26].second = code;
      }
      return;
    }
    else{
      code += "0";
      HelpEncodeMap(begin->GetZero(), code, map);
    }
  }
  else
    return;
}
