#include "Heap.h"
#include "Huffman.h"
#include <utility>
#include <fstream>
using namespace std;

int main()
{
    ifstream plain("plain.input");
    ifstream encoded("encoded.input");
    string plainInput;
    string encodedInput;
    if(!plain.eof())
        getline(plain, plainInput);
    if(!encoded.eof())
        getline(encoded, encodedInput);
  
    Huffman a(plainInput);
    a.PrintEncode(plainInput, encodedInput);
    return 0;
}
