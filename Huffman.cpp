#include "Huffman.h"
#include <iostream>
#include <sstream>
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
    while (encodeTree->GetHeapSize()>1)
    {
        Node* rightZero = new Node(*encodeTree->DeleteMin());     
        Node* leftOne = new Node(*encodeTree->DeleteMin());
        Node* weight = new Node(leftOne,rightZero);
        encodeTree->Insert(weight);
    }
}

pair<char, string>* Huffman::EncodeMap(){
    pair<char, string>* map = new pair<char, string>[27];
    for(int i = 0; i < 26; i++)
        map[i] = pair<char, string>(static_cast<char>(i+97), "");
    map[26] = pair<char, string>(' ', "");
    HelpEncodeMap(*(encodeTree->GetHeap()+1), "", map);
    return map;
}

void Huffman::HelpEncodeMap(Node* begin, string code, pair<char, string>* map){
  if (begin == NULL){
    return;
  }
  if (begin->GetChar() != '*'){
      if (begin->GetChar() != ' '){
          map[static_cast<int>(begin->GetChar()-97)].second = code;
      }
      else{
          map[26].second = code;
      }
    return;
  }
  if (begin->GetLeftOne() != NULL)
    HelpEncodeMap(begin->GetLeftOne(), code + "1", map);
  if (begin->GetRightZero() != NULL)
    HelpEncodeMap(begin->GetRightZero(), code + "0", map);
}

void Huffman::PrintEncode(string plain, string encoded){
  pair<char, string>* map = EncodeMap();
  for(size_t i = 0; i < plain.length(); i++){
    if(plain[i] != ' ')
      cout << map[static_cast<int>(plain[i]-97)].second;
    else
      cout << map[26].second;
  }
  cout << "\n";

  string temp = "";
  for(size_t i = 0; i < encoded.length(); i++){
    temp += encoded[i];
    for(int j = 0; j < 27; j++){
      if (temp.length() != 0 && temp.compare(map[j].second) == 0){
        cout << map[j].first;
        temp = "";
      }
    }
  }
}
