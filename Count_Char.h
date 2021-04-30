#include <iostream>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <string>
#ifndef COUNT_CHAR_COUNT_CHAR_H
#define COUNT_CHAR_COUNT_CHAR_H

struct character_struct
{
    char letter = '\0';
    int rep = 0;
    int huff_length = 0;
    char huffman[8] = {'\0','\0','\0','\0','\0','\0','\0','\0'};
};

struct stats
{
    int total = 0;
    int Up_Case = 0;
    int Low_Case = 0;
    int puntos = 0;
    int comas = 0;
    int diag = 0;
    int caracteres = 0;
    int spaces = 0;
    int other_characters = 0;

};
/*struct MinHeapNode {

    // One of the input characters
    char data;

    // Frequency of the character
    unsigned freq;

    // Left and right child of this node
    struct MinHeapNode *left, *right;
};
struct MinHeap {

    // Current size of min heap
    unsigned size;

    // capacity of min heap
    unsigned capacity;

    // Attay of minheap node pointers
    struct MinHeapNode** array;
};*/       //Estos structs son para crear el huffman tree
struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};

struct comp
{
    bool operator()(Node* l, Node* r)
    {
        // highest priority item has lowest frequency
        return l->freq > r->freq;
    }
};

struct MinHeapNode
{
    char data;
    int freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};

class Count_Char{


public:
     //character_struct (char, *message);
     int leer(/*character_struct[],*/ char []);
    void print(character_struct[], char[],stats);
    void count(character_struct[], char[], int);
    void insert(char, character_struct[]);
    void Estadisticas(character_struct[], stats *);
    void Heapify(character_struct[],int i, int n);
    void HeapSort(character_struct[], int );
    void PrintArray(character_struct[], int);
   /* void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b);
    void minHeapify(struct MinHeap* minHeap, int idx);
    int isSizeOne(struct MinHeap* minHeap);
    void insertMinHeap(struct MinHeap* minHeap,struct MinHeapNode* minHeapNode);
    void buildMinHeap(struct MinHeap* minHeap);
    int isLeaf(struct MinHeapNode* root);
    void printCodes(struct MinHeapNode* root, character_struct arr[], int top);
    void HuffmanCodes( int n, char[], int[]);*/
    void printCodes(struct MinHeapNode* root, std::string str);
    void storeCodes(struct MinHeapNode* root, std::string str);
    void encode(Node* root, std::string str,std::unordered_map<char, std::string> &huffmanCode);
    void decode(Node* root, int &index, std::string str);
    void buildHuffmanTree(std::string text);
private:
    #define POS 255
    #define MAX 1024
    #define MAX_TREE_HT 100
    char mensaje[MAX];
    character_struct letters[POS];
    stats estadisticas;
};

#endif //COUNT_CHAR_COUNT_CHAR_H
