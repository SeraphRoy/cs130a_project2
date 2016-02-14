#include <iostream>
#include <sstream>
#include "Heap.h"

Node::Node()
{
	charFreqPair = make_pair('*',0);
	leftOne = NULL;
	rightZero = NULL;
}

Node::Node(Node* leftOne, Node* rightZero)
{
	charFreqPair = make_pair('*',leftOne->GetFreq()+rightZero->GetFreq());
	this->leftOne = leftOne;
	this->rightZero = rightZero;
}

Node::Node(pair<char,int> input)
{
	charFreqPair = input;
	leftOne = NULL;
	rightZero = NULL;
}

Node::Node(const Node& orig)
{
	this->charFreqPair = orig.charFreqPair;
    this->leftOne = orig.leftOne;
    this->rightZero = orig.rightZero;
}

Node& Node::operator=(const Node &input) // why no specification of Node?
{
	this->charFreqPair = input.charFreqPair;
	this->leftOne = input.leftOne;
	this->rightZero = input.rightZero;
	return *this;
}

string Node::ToString()
{
    ostringstream output;
    output << this->GetChar() << ": " << this->GetFreq() << "\n";
    if (this->GetLeftOne())
        output << "Left: " << this->GetLeftOne()->ToString();
    if (this->GetRightZero())
        output << "Right: " << this->GetRightZero()->ToString();
    return output.str();
}

void Heap::CompleteBinaryTree(pair<char,int>* arrayOfCharFrequencyPair, int size)
{	
	this->heap = new Node [size];
	for (int i = 0; i < size;i++)
	{
		if (arrayOfCharFrequencyPair[i].second > 0)
		{
			
			this->heap[occupancy].SetCharFreqPair(arrayOfCharFrequencyPair[i]);
			this->occupancy++;
		}
	}
	//this->Print();
}

void Heap::MaxHeapify(Node* minHeap,int startIndex)
{
	if (startIndex >= occupancy)
		return;
	int left =  startIndex * 2;
	int right = left + 1;
	int smallest = startIndex;
	if (left < occupancy && heap[left].GetFreq() < heap[startIndex].GetFreq())
		smallest = left;
	if (right < occupancy && heap[right].GetFreq() < heap[startIndex].GetFreq())
		smallest = right;
	if (smallest != startIndex)
	{
		Node temp = Node(minHeap[startIndex]);
		minHeap[startIndex] = minHeap[smallest];
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

Node Heap::DeleteMin()
{
	Node minFreqChar = heap[0];
	this->heap[0] = this->heap[occupancy-1];
	this->occupancy--;
    this->MaxHeapify(this->heap,0);
	return minFreqChar;
}
/*
void Heap::Print()
{
	ostringstream result ;
	for (int i = 0; i < occupancy; i++)
	{
		result << this->heap[i].GetChar();
		result << ": ";
		result << this->heap[i].GetFreq();
		result << "\n";
	}
	result << "\n\n";
	cout << result.str();
}
*/

void Heap::Print()
{
    ostringstream output;
    for (int i = 0; i < occupancy; i++)
    {
        output << heap[i].ToString();
    }
    output << "\n";
    cout << output.str();
}

void Heap::Insert(Node* input){
	if (occupancy >= 27)
	{
		cout << "Error: Not enough space for inserting!\n";	
		return;
	}
  	heap[occupancy] = *input;
  	//int index = occupancy;
  	occupancy ++;
  	for (int i = occupancy/2; i>=0; i--)
	{
		this->MaxHeapify(this->heap, i);
	}
}
