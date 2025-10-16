#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char ch;
    int freq;
    struct node *left, *right;
} Node;

typedef struct {
    int size, capacity;
    Node **arr;
} MinHeap;

Node* newNode(char ch, int freq) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->ch = ch;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

MinHeap* createHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->arr = (Node**)malloc(capacity * sizeof(Node*));
    return minHeap;
}

void swapNode(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int l = 2*idx + 1;
    int r = 2*idx + 2;
    if(l < heap->size && heap->arr[l]->freq < heap->arr[smallest]->freq)
        smallest = l;
    if(r < heap->size && heap->arr[r]->freq < heap->arr[smallest]->freq)
        smallest = r;
    if(smallest != idx) {
        swapNode(&heap->arr[smallest], &heap->arr[idx]);
        minHeapify(heap, smallest);
    }
}

Node* extractMin(MinHeap* heap) {
    Node* temp = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return temp;
}

void insertHeap(MinHeap* heap, Node* node) {
    heap->size++;
    int i = heap->size - 1;
    while(i && node->freq < heap->arr[(i-1)/2]->freq) {
        heap->arr[i] = heap->arr[(i-1)/2];
        i = (i-1)/2;
    }
    heap->arr[i] = node;
}

MinHeap* buildHeap(char alph[], int freq[], int n) {
    MinHeap* heap = createHeap(n);
    for(int i=0; i<n; i++) {
        heap->arr[i] = newNode(alph[i], freq[i]);
    }
    heap->size = n;
    for(int i=(heap->size-2)/2; i>=0; i--)
        minHeapify(heap, i);
    return heap;
}

Node* buildHuffmanTree(char alph[], int freq[], int n) {
    MinHeap* heap = buildHeap(alph, freq, n);
    while(heap->size > 1) {
        Node* left = extractMin(heap);
        Node* right = extractMin(heap);
        Node* top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertHeap(heap, top);
    }
    return extractMin(heap);
}

void inorder(Node* root) {
    if(root) {
        inorder(root->left);
        if(root->ch != '$')
            printf("%c ", root->ch);
        inorder(root->right);
    }
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);
    char alph[n];
    int freq[n];
    printf("Enter the alphabets: ");
    for(int i=0; i<n; i++)
        scanf(" %c", &alph[i]);
    printf("Enter its frequencies: ");
    for(int i=0; i<n; i++)
        scanf("%d", &freq[i]);

    Node* root = buildHuffmanTree(alph, freq, n);
    printf("In-order traversal of the tree (Huffman): ");
    inorder(root);
    printf("\n");
    return 0;
}
