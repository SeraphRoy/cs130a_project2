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
        //cout << encodeTree->GetHeapSize() << "\n";
        //encodeTree->Print();
        //Node min1 = encodeTree->DeleteMin();
        //Node min2 = encodeTree->DeleteMin();
        //cout << "min left: ";
        //min1.ToString();
        //cout << "min right: ";
        //min2.ToString();
        Node* leftOne = new Node(*encodeTree->DeleteMin());
        Node* rightZero = new Node(*encodeTree->DeleteMin());
        Node* weight = new Node(leftOne,rightZero);
        encodeTree->Insert(weight);
        //encodeTree->Print();
    }
    //this->encodeTree->Print();
}

/*
 void Huffman::print(){
 this->encodeTree->Print();
 }
 */
/*
pair<char, string>* Huffman::EncodeMap(){
    pair<char, string>* map = new pair<char, string>[27];
    for(int i = 0; i < 26; i++)
        map[i] = pair<char, string>(static_cast<char>(i+97), "");
    map[26] = pair<char, string>(' ', "");
    HelpEncodeMap(encodeTree->GetHeap(), "", map);
    return map;
}

void Huffman::HelpEncodeMap(Node* begin, string code, pair<char, string>* map){
    if(begin->GetLeftOne() != NULL){
        if(begin->GetLeftOne() != NULL){
            code += "1";
            char index = begin->GetLeftOne()->GetChar();
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
            HelpEncodeMap(begin->GetLeftOne(), code, map);
        }
    }
    else
        return;
    if(begin->GetRightZero() != NULL){
        if(begin->GetRightZero() != NULL){
            code += "0";
            char index = begin->GetRightZero()->GetChar();
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
            HelpEncodeMap(begin->GetRightZero(), code, map);
        }
    }
    else
        return;
}
*/
