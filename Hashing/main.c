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

//The conditional Operator explained for collisions:

//The if statement checks if the current index is empty. If it is, the newNode is inserted at that location/index.
//if there is already data/node at the index, then a collision occurs. Therefore, these steps happen:
// STEP 1: The newNode next pointer will be set to point to the current hashTable index that it's colliding with.
//By doing this, the current Node data at that collided location is kept safely in the next pointer of the newNode
//STEP 2: Now newNode can replace the current node, whilst holding the previous nodes data in its next pointer.

void display() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = hashTable[i];
        printf("index %d:", i);
        while(temp != NULL) {
            printf("%d, %d -> ", temp->key, temp->value);
            temp = temp->next;
        }
    }
}
//why use temp?
//temp variable assignment prevents original linked list node data from being lost
//if you were to use hashTable[0] = hashTable[0]->next, you would be assigning the next pointer to null at the end of the list iteration.
//This would mean you'd lose all references of the linked list at that index after iteration is complete.
//Example: hashTable[0] -> [Node1: key=1, value=100, next=Node2] -> [Node2: key=2, value=200, next=Node3] -> [Node3: key=3, value=300, next=NULL]
//In the example above, the hashTable will iterate and print each Node. However once the end is reached, the Node next pointer at that index will be replaced with null.
//This results in all node references at that index being lost.



int search(int key) {
    int index = hashFunction(key); //call the hashFunction for the key you're searching for. This will return the index the key is located at.
    Node* temp = hashTable[index]; // assign a temp Node pointer to preserve data.

    //traverse the linked list at the index that was calculated from the hashFunction for the searched key.
    while (temp != NULL) { //if nothing is at the index, temp == NULL and will exit with -1 return.
        if(temp->key == key) {
            return temp->value;
        }
        temp = temp->next; //move to the next node by assigning temp to the next node in the linked list.
    }
    return -1; //nothing found for the given key. Return -1.
}
