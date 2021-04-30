#include "Count_Char.h"
using namespace std;

int Count_Char::leer(char mens [])
{
    int total = 0;
FILE *fp;
for (int i = 0; i < MAX; i++)
{
    mens[i] = '\0';
    }
const char * filename ="C:\\Users\\Ian Karlo\\Dropbox\\Count_Char\\Texto";
fp = fopen(filename, "r");
if (fp == NULL)
{
    cout<<" No se puede abrir el archivo"<<filename;
    return 0;
    }
/*while(1)
{
    total = fgetc(fp);
    if(feof(fp)){
        break;
    }
    printf("%total", total);
}
fclose(fp);*/
while (fgets(mens, MAX, fp)!=NULL);
fclose(fp);
while (mens[total])
    total++;
    return total;
}
void Count_Char::count(character_struct array[], char mens[], int total)
{
    for (int i = 0; i < total; i++)
    {
        insert(mens[i], array);
    }
}
void Count_Char::insert(char l, character_struct array[])
{
    for (int i = 0; i < POS; i++) {
        if (array[i].letter == l) {
            array[i].rep++;
            return;
        }
        if (array[i].letter == '\0') {
            array[i].letter = l;
            array[i].rep++;
            return;
        }
    }
}

void Count_Char::print(character_struct array[], char mens[], stats estadisticas)
{
    for (int i = 0; i < estadisticas.total ; i++)
    cout<< mens[i];
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<"El total de letras es : "<<estadisticas.total<<endl;
    cout<<"El total de minusculas es : "<<estadisticas.Low_Case<<endl;
    cout<<"El total de Mayusculas es : "<<estadisticas.Up_Case<<endl;
    cout<<"El total de caracteres es : "<<estadisticas.caracteres<<endl;
    cout<<"El total de espacios es : "<<estadisticas.spaces<<endl;
    cout<<"El total de comas es : "<<estadisticas.comas<<endl;
    cout<<"El total de diagonales es : "<<estadisticas.diag<<endl;
    cout<<"El total otros tipos de caracteres es : "<<estadisticas.other_characters<<endl;
    cout<<"El total de puntos es : "<<estadisticas.puntos<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    for (int i = 0; i < POS && array[i].letter != '\0'; i++)
    cout<<setw(3)<<array[i].letter<<setw(7)<<array[i].rep<<endl;
    cout<<"\n";
}
void Count_Char::Estadisticas(character_struct array[], stats *estadisticas)
{
    for (int i = 0; i < POS; i++)
    {
        if (array[i].letter =='\0')
            return;
        if (array[i].letter >='A'&& array[i].letter <= 'Z')
            estadisticas->Up_Case+=array[i].rep;
        else
        if (array[i].letter >='a'&& array[i].letter <= 'z')
            estadisticas->Low_Case+=array[i].rep;
        else
            switch (array[i].letter) {
                case ' ':
                    estadisticas->spaces += array[i].rep;
                    break;
                case '.':
                    estadisticas->puntos += array[i].rep;
                    break;
                case ',':
                    estadisticas->comas += array[i].rep;
                    break;
                case ';':
                    estadisticas->caracteres += array[i].rep;
                    break;
                case '/':
                    estadisticas->diag += array[i].rep;
                    break;
                default:
                    estadisticas->other_characters += array[i].rep;
                    break;

            }
    }
    return;
}
void Count_Char::Heapify(character_struct array[], int i, int n)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && array[l].rep > array[largest].rep)
        largest = l;
if (r < n && array[r].rep > array[largest].rep)
    largest = r;
if (largest != i)
{
    swap(array[i], array[largest]);
    Heapify(array, n, largest);
}

}
void Count_Char::HeapSort(character_struct array[], int n)
{
    for (int i = n/2-1; i > 0 ; i--)
    {
        Heapify(array, n, i);
    }
    for (int i = n-1; i >= 0 ; i--)
    {
        swap(array[0], array[i]);
        Heapify(array, i, 0);

    }

}
void Count_Char::PrintArray(character_struct array[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << array[i].rep << " ";
    cout << "\n";
}
/*struct MinHeapNode* newNode(char data, unsigned freq)
{
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));

    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}

struct MinHeap* createMinHeap(unsigned capacity)

{

    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));

    minHeap->size = 0;

    minHeap->capacity = capacity;

    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}
void /*Count_Char::*//*swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b)
        {
            struct MinHeapNode* t = *a;
            *a = *b;
            *b = t;
        }
void /*Count_Char::*//*minHeapify(struct MinHeap *minHeap, int idx)
        {
            int smallest = idx;
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;

            if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
                smallest = left;

            if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
                smallest = right;

            if (smallest != idx) {
                swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
                minHeapify(minHeap, smallest);
            }

        }
struct MinHeapNode* extractMin(struct MinHeap* minHeap)

{

    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0]
            = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}
void /*Count_Char::*//*insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode)
        {
            ++minHeap->size;
            int i = minHeap->size - 1;

            while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
                minHeap->array[i] = minHeap->array[(i - 1) / 2];
                i = (i - 1) / 2;
            }

            minHeap->array[i] = minHeapNode;
        }
        void /*Count_Char::*//*buildMinHeap(struct MinHeap *minHeap)
                {
                    int n = minHeap->size - 1;
                    int i;

                    for (i = (n - 1) / 2; i >= 0; --i)
                        minHeapify(minHeap, i);
                }
                int Count_Char::isLeaf(struct MinHeapNode *root)
                        {
                            return !(root->left) && !(root->right);
                        }
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int n)
{

    struct MinHeap* minHeap = createMinHeap(n);

    for (int i = 0; i < n; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = n;
    buildMinHeap(minHeap);

    return minHeap;
}
int /*Count_Char::*//*isSizeOne(struct MinHeap *minHeap)
{
    return (minHeap->size == 1);
}
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int n)

{
    struct MinHeapNode *left, *right, *top;

    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, n);

    while (!isSizeOne(minHeap)) {

        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}
/*void Count_Char::printArr(character_struct array[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout<< array[i].huffman;

    cout<<"\n";
}*/
/*void Count_Char::printCodes(struct MinHeapNode* root, character_struct array[], int top)

{
    if (root->left) {

        array[top].rep = 0;
        printCodes(root->left, array, top + 1);
    }
    if (root->right) {

        array[top].rep = 1;
        printCodes(root->right, array, top + 1);
    }
    if (isLeaf(root)) {

        cout<< root->data <<": ";
         PrintArray(array, top);
    }
}
void Count_Char::HuffmanCodes( int n, char data[],int freq[])

{
    int top=0;e
    struct MinHeapNode* root = buildHuffmanTree(data, freq, n);

     character_struct array[MAX_TREE_HT];
 printCodes(root, array, top);
}*/

//Funciones en comentarios que estan arriba activan el huffman tree

Node* getNode(char ch, int freq, Node* left, Node* right)
{
    Node* node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}
void Count_Char::encode(Node* root, string str,unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
        return;

    if (!root->left && !root->right)
    {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}
void Count_Char::decode(Node* root, int &index, string str)
{
    if (root == nullptr) {
        return;
    }
    if (!root->left && !root->right)
    {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] =='0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}
void Count_Char::buildHuffmanTree(string text)
{
    unordered_map<char, int> freq;
    for (char ch: text) {
        freq[ch]++;
    }
    priority_queue<Node*, vector<Node*>, comp> pq;

    for (auto pair: freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }
    while (pq.size() != 1)
    {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top();	pq.pop();

        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }
    Node* root = pq.top();

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "Huffman Codes :\n" << endl;
    for (auto pair: huffmanCode) {
        cout << pair.first << " " << pair.second << '\n';
    }

    cout << "String Original :\n" << text << endl;
    string str = "";
    for (char ch: text) {
        str += huffmanCode[ch];
    }

    cout << "Encoded String :\n" << str << endl;
    int index = -1;
    cout << "Decoded String : \n";
    while (index < (int)str.size() - 2) {
        decode(root, index, str);
    }
}


