#include <iostream>
#include <sstream>
#include "Heap.h"

void Heap::CompleteBinaryTree(pair<char,int>* arrayOfCharFrequencyPair, int size)
{	
    this->heap = new pair<char, int> [size];
    for (int i = 0; i < size;i++)
    {
        if (arrayOfCharFrequencyPair[i].second > 0)
        {
            
            this->heap[occupancy] = arrayOfCharFrequencyPair[i];
            this->occupancy++;
        }
    }
    this->Print();
}

void Heap::MaxHeapify(pair<char,int>* minHeap,int startIndex)
{
    if (startIndex >= occupancy)
        return;
	int left =  startIndex * 2;
	int right = left + 1;
	int smallest = startIndex;
	if (left < occupancy && heap[left].second < heap[startIndex].second)
		smallest = left;
	if (right < occupancy && heap[right].second < heap[startIndex].second)
		smallest = right;
	if (smallest != startIndex)
    {
        pair<char, int> temp = minHeap[startIndex];
        minHeap[startIndex].first = minHeap[smallest].first;
        minHeap[startIndex].second = minHeap[smallest].second;
        minHeap[smallest] = temp;
        //this->Print();
		this->MaxHeapify(minHeap, smallest);
    }
}

Heap::Heap(pair<char,int>* arrayOfCharFrequencyPair, int size)
{
    this->occupancy = 0;
	this->CompleteBinaryTree(arrayOfCharFrequencyPair, size);
    //this->Print();
    for (int i = occupancy/2; i>=0; i--)
    {
        this->MaxHeapify(this->heap, i);
    }
}

Heap::~Heap()
{
	delete [] this->heap;
}

pair<char,int> Heap::DeleteMin()
{
	pair<char,int> minFreqChar = this->heap[0];
	this->heap[0] = this->heap[occupancy];
	this->occupancy--;
	return minFreqChar;
}

void Heap::Print()
{
	ostringstream result ;
	for (int i = 0; i < occupancy; i++)
	{
		result << this->heap[i].first;
		result << ": ";
		result << this->heap[i].second;
		result << "\n";
	}
    result << "\n\n";
	cout << result.str();
}

void Heap::insert(pair<char, int> input){
  pair<char, int> *insert = new pair<char, int>(input);
  heap[occupancy] = *insert;
  int index = occupancy;
  occupancy ++;
  while(index != 0 && heap[index] >= heap[index/2]){
    pair<char, int>* temp = new pair<char, int>(heap[index]);
    heap[index] = heap[(index-1)/2];
    heap[(index-1)/2] = *temp;
    delete temp;
    index /= 2;
  }
}
