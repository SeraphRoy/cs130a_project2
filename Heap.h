#ifndef _HEAP_H_
#define _HEAP_H_

#include <iostream>
#include <utility>
using namespace std;
/*
class Node{
private:
	string character;
	int frequency;
public:
	Node(string character, int frequency = 1);
	string GetChar(){ return this->character; };
	int GetFreq(){ return this->frequency; };
	void SetChar(string character){ this->character = character; };
	void SetFreq(int frequency){ this->frequency = frequency; };
};*/

class Heap{
private:
	int occupancy;
	pair<char,int>* heap;
	void CompleteBinaryTree(pair<char,int>* arrayOfCharFrequencyPair, int size);
	void MaxHeapify(pair<char,int>* arrayOfCharFrequencyPair, int startIndex = 0);
public:
	Heap(pair<char,int>* arrayOfCharFrequencyPair, int size = 27);
	~Heap();
	int GetHeapSize(){ return this->occupancy; };
	pair<char,int> DeleteMin();
	void Print();
};

#endif