#ifndef _HEAP_H_
#define _HEAP_H_

#include <iostream>
#include <utility>
using namespace std;

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
    void insert(pair<char, int> input);
};

#endif
