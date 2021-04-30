#include "Count_Char.h"

using namespace std;

int main()
{
Count_Char character1;
#define POS 255
#define MAX 1024
    char mensaje[MAX];
    character_struct letters[POS];
    stats estadisticas;
   // MinHeapNode root; Huffman Tree
    //char data[POS]; Huffman Tree
   // int top=0; Huffman Tree
    int n = sizeof(letters) / sizeof(letters[0]);
    //int freq[n]; // Huffman Tree

    estadisticas.total = character1.leer(mensaje);
    character1.count(letters, mensaje, estadisticas.total);
    character1.Estadisticas(letters, &estadisticas);
    character1.print(letters,mensaje,estadisticas);
    character1.HeapSort(letters, n);

 cout<< "The Sorted Array is :"<<endl;
 character1.PrintArray(letters, n);
    char text =  mensaje[MAX];
   character1.buildHuffmanTree(mensaje);

 //character1.HuffmanCodes(n,data,freq);
   // character1.printCodes(&root, letters, top);

   //Ultimas dos funciones activan huffman tree

    return 0;
}
