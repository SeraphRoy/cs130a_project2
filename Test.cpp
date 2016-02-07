#include "Heap.h"
#include "Huffman.h"
#include <utility>
using namespace std;

//typedef pair<char,int> PCI;

int main()
{
	/*PCI* arrayOfCharFrequencyPair = NULL;
	arrayOfCharFrequencyPair = new PCI[5];
	PCI a = make_pair('a',10);
	PCI b = make_pair('b',5);
	PCI e = make_pair('e',12);
	PCI o = make_pair('o',7);
	PCI j = make_pair('j',3);
	arrayOfCharFrequencyPair[0] = a;
	arrayOfCharFrequencyPair[1] = b;
	arrayOfCharFrequencyPair[2] = e;
	arrayOfCharFrequencyPair[3] = o;
	arrayOfCharFrequencyPair[4] = j;

	Heap testHeapSize5 = Heap(arrayOfCharFrequencyPair, 5);
	testHeapSize5.Print();*/
  Huffman h("aabbb");
  pair<char,int>* freqArray = h.CountFreq("aabbbcccddddeeeee");
  /*for (int i = 0; i < 27;i++)
    {
    cout << freqArray[i].first <<  ": " << freqArray[i].second << "\n";
    }*/
  //h.print();
  Heap heap(freqArray);
  heap.Print();
  heap.insert(make_pair('i', 1));
  heap.Print();
  delete [] freqArray;
  return 0;
}
