#ifndef _HEAP_H_
#define _HEAP_H_

#include <iostream>
#include <utility>
using namespace std;

class Node{
private:
	// use symbol "*" as signal for weight
	pair<char,int> charFreqPair; 
	Node* leftOne;
	Node* rightZero;
public:
	Node();
	Node(Node* leftOne, Node* rightZero); // cautious
	Node(pair<char,int> input);
	Node(const Node &input);
	pair<char,int> GetCharFreqPair(){ return this->charFreqPair; };
	char GetChar(){ return this->charFreqPair.first; };
	int GetFreq(){ return this->charFreqPair.second; };
    void SetCharFreqPair(pair<char,int> charFreqPair){ this->charFreqPair = charFreqPair; };
	Node& operator=(const Node &input);
    Node* GetLeftOne(){ return this->leftOne; };
    Node* GetRightZero(){ return this->rightZero; };
    string ToString();
};


class Heap{
private:
	int occupancy;
	Node* heap;
	void CompleteBinaryTree(pair<char,int>* arrayOfCharFrequencyPair, int size);
	void MaxHeapify(Node* minHeap, int startIndex = 0);
public:
	Heap(pair<char,int>* arrayOfCharFrequencyPair, int size = 27);
	~Heap();
	int GetFreqOfIndex(int index){ return this->heap[index].GetFreq(); };
	int GetHeapSize(){ return this->occupancy; };
	Node DeleteMin();
	void Print();
	void Insert(Node* input);
    Node* GetHeap(){ return this->heap; };
};

/*
class Node{
private:
	pair<char, int>* wordfreq;
	int totalfreq;
	Node* one;
	Node* zero;
public:
	Node(){wordfreq = NULL; totalfreq = 0; one = NULL; zero = 0;}
	
	Node(pair<char, int> input){
		wordfreq = new pair<char, int>(input);
		totalfreq = 0;
		one = NULL;
		zero = NULL;
	}
	
	Node(const Node &input){
		*this = input;
	}
	
	Node& operator=(const Node &input){
		pair<char, int>* temp = new pair<char, int>(*(input.wordfreq));
		this->wordfreq = temp;
		this->totalfreq = input.totalfreq;
		this->one = input.one;
		this->zero = input.zero;
		return *this;
	}
	
	pair<char, int>* GetWordfreq(){ return this->wordfreq;}
	
	int GetTotalfreq(){ return totalfreq;}
	
	void setWordfreq(pair<char, int> input){
		pair<char, int> *temp = new pair<char, int>(input);
		wordfreq = temp;
	}
	
	void setOne(Node input){ this->one = input.one;}
	
	Node* GetOne(){
		return one;
	}
	
	void setZero(Node input){ this->zero = input.zero;}

	Node* GetZero(){
		return zero;
	}
};
*/



#endif
