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
void Node::SetCharFreqPair(pair<char,int> charFreqPair)
{
    this->charFreqPair = charFreqPair;
}

Node::Node(const Node& orig)
{
   
    this->charFreqPair = orig.charFreqPair;
    this->leftOne = orig.leftOne;
    this->rightZero = orig.rightZero;
}
/*
Node& Node::operator=(const Node &input) // why no specification of Node?
{
	this->charFreqPair = input.charFreqPair;
	this->leftOne = input.leftOne;
	this->rightZero = input.rightZero;
	return *this;
}*/

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
	
	for (int i = 1; i <= size;i++)
	{
		if (arrayOfCharFrequencyPair[i-1].second > 0)
		{
            this->occupancy++;
			this->heap[occupancy]->SetCharFreqPair(arrayOfCharFrequencyPair[i-1]);
		}
	}
}

void Heap::MinHeapify(Node** minHeap,int startIndex)
{       
	if (startIndex > occupancy)
		return;
	int left =  startIndex * 2;
	int right = left + 1;
	int smallest = startIndex;
	if (right <= occupancy && heap[right]->GetFreq() < heap[smallest]->GetFreq())
		smallest = right;
	if (left <= occupancy && heap[left]->GetFreq() < heap[smallest]->GetFreq())
		smallest = left;
	if (smallest != startIndex)
	{
		Node* temp = minHeap[startIndex];
		minHeap[startIndex] = minHeap[smallest];
		minHeap[smallest] = temp;
		this->MinHeapify(minHeap, smallest);
	}
}

Heap::Heap(pair<char,int>* arrayOfCharFrequencyPair, int size)
{
	this->occupancy = 0;
    this->heap = new Node* [size+1];
    for (int i = 0; i <=size; i++)
    {
        this->heap[i] = new Node();
    }
	this->CompleteBinaryTree(arrayOfCharFrequencyPair, size);   
	for (int i = occupancy/2; i>=1; i--)
	{
		this->MinHeapify(this->heap, i);
	}
}

Heap::~Heap()
{
	delete [] this->heap;
}

Node* Heap::DeleteMin()
{
	Node* minFreqChar = heap[1];
	this->heap[1] = this->heap[occupancy];
	this->occupancy--;
	this->MinHeapify(this->heap,1);
	return minFreqChar;
}

void Heap::Print()
{
    ostringstream output;
    for (int i = 1; i <= occupancy; i++)
    {
        output << heap[i]->ToString();
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
	occupancy ++;
  	this->heap[occupancy] = input;
 
  	
  	for (int i = occupancy/2; i>=1; i--)
	{
		this->MinHeapify(this->heap, i);
	}
}
