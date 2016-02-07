#include <iostream>
#include <sstream>
#include "Heap.h"

void Heap::CompleteBinaryTree(pair<char,int>* arrayOfCharFrequencyPair, int size)
{	
	this->occupancy = 0;
	//int size = 27;
    this->heap = new pair<char, int>[size];
	for (int i = 0; i < size;i++)
	{
		if (arrayOfCharFrequencyPair[i].second != 0)
		{
			heap[i] = arrayOfCharFrequencyPair[i];
			this->occupancy++;
			//cout << heap[i].first << " " << heap[i].second << endl;
		}
	}
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
        minHeap[startIndex] = minHeap[smallest];
        minHeap[smallest] = temp;
        //this->Print();
		this->MaxHeapify(minHeap, smallest);
    }
}

Heap::Heap(pair<char,int>* arrayOfCharFrequencyPair, int size)
{
	//int size = 27;
	this->CompleteBinaryTree(arrayOfCharFrequencyPair, size);
    //this->Print();
    for (int i = size/2; i>=0; i--)
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