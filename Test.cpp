#include "Heap.h"
#include "Huffman.h"
#include <utility>
#include <fstream>
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
    //Huffman h("aabbbcccddddeeeee");

  ifstream plain("plain.input");
  ifstream encoded("encoded.input");
  string plainInput;
  string encodedInput;
  if(!plain.eof())
    getline(plain, plainInput);
  if(!encoded.eof())
    getline(encoded, encodedInput);
  
  Huffman a(plainInput);
  //a.Print();
  a.PrintEncode();
    //pair<char,int>* freqArray = h.CountFreq("aabbbcccddddeeeee");
    //Heap test = Heap(h.CountFreq("aabbbcccddddeeeee"));
    //test.Print();
    /*for (int i = 0; i < 27;i++)
        {
        cout << freqArray[i].first <<  ": " << freqArray[i].second << "\n";
        }*/
    //h.print();
    //Heap heap(freqArray);
    //heap.Print();
    //heap.Insert(new Node(make_pair('i', 1)));
    //heap.Print();
    //delete [] freqArray;
    //Huffman test("aabbbcccddddeeeee");
    //test.GetHeap().Print();
    //test.Print();
    return 0;
}
