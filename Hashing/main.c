#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}

//Define a Node within the linked list
typedef struct Node {
    int key; // This is the key that is mapped to the hash table
    int value; // Value that's associated with the key
    struct Node* next; // next is a pointer that points to ANOTHER Node memory address. This is defining another struct with the same name.
}Node;
// typedef is used so that Node doesn't need to be defined repeatedly.
// When you define struct Node* next inside the Node structure, it does not create a new Node structure. Instead, it simply declares a pointer that can point to another Node structure that already exists (or will exist in the future).

#define TABLE_SIZE 20
//When you use # this is a preprocessor directive.
//A preprocessor tells the compiler to replace every occurrence of TABLE_SIZE with 10 before the actual compilation of the program begins.
//# in C is typically used to define constants, preventing the value from changing.

Node* hashTable[TABLE_SIZE];

int hashFunction(int key) { //the Hash function. This is used to calculate the index.
    return key % TABLE_SIZE;
}

//Insert function to create key value pair in the Hash table.

void insert(int key, int value) {
    int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node)); //the (Node*) is a type cast.
    //The code above creates a newNode pointer, pointing to a block of memory that can store key, value, and next.
    //malloc(sizeof(Node)) allocates a block of memory large enough to hold a Node structure, but it does not know or initialize the structure.
    //Typecasting ((Node*)) tells the compiler that this memory block should be interpreted as a pointer to a Node structure.
    //The structure definition (typedef struct Node { ... } Node;) tells the compiler how to interpret the memory — it knows that the first part of the block is for the key, the second part is for the value, and the third part is for the next pointer.
    //Initially, this memory is uninitialized (it may contain garbage data), so you need to manually set values for key, value, and next after allocation.

    //Assign the values to the newNode
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    // The -> operator is used to access and modify fields of a structure through a pointer
    // It dereferences the pointer and accesses the field of the structure in a single operation (it’s shorthand for (*pointer).field).

    if(hashTable[index] == NULL) { //if the index/bucket is empty, insert the newNode at that location.
        hashTable[index] = newNode;
    }
    else {
        newNode->next=hashTable[index];
        hashTable[index] = newNode;
    }
}
