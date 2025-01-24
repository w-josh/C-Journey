#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const int WORD_LENGTH = 30;

struct dict {
    struct dict *left, *right;
    char word[WORD_LENGTH], definition[200];
}*Root = NULL; //Root node struct pointer. Initially empty with no data. Hence Null.

typedef struct dict dictionary;

int Compare(char a[], char b[]) {

    int lexicographicalChecker;

    for (int i = 0, j = 0; a[i] != '\0' && b[j] != '\0';i++, j++) {
        if (a[i] > b[j]) { // lexicographical order. NOT word length.
            lexicographicalChecker = 1;
        }
        else if (a[i] < b[j]) {
            lexicographicalChecker = -1;
        }
        else {
            lexicographicalChecker = 0;
        }
    }
    return lexicographicalChecker;
}

void Search(char term[]) {
    bool found = false;
    dictionary *current = Root; // start search from root node.

    while (current != NULL) {
        int result = Compare(term, current->word);
        if (result == 1) {
            current = current->right;
            found = true;
        }
        else if (result == -1) {
            current = current->left;
            found = true;
        }
        else {
            printf("definition:", current->definition);
            found = true;
        }
    }
    if (found == false && current == NULL) {
        printf("No term found or Dictionary is empty.");
    }

}
void Insert(dictionary* temp) {

    //empty tree. Insert at root.
    if (Root == NULL) {
        Root = temp;
        printf("\nWord inserted at root: %s", temp->word);
        return;
    }
    dictionary *current = Root;
    dictionary *parent = NULL;

    while (current != NULL) {
        int result = Compare(current->word, temp->word);
        if (result == 0) {
            printf("Word %s, already Exists in the dictionary.", temp->word);
            return;
        }

        parent = current; //update parent node.

        if (result == 1) {
            current = current->right;
        }
        else {
            current = current->left;
        }

    }

    //determine the insertion point.

    if (Compare(temp->word, parent->word) == 1) {
        parent->right = temp;
        printf("\nWord %s inserted to the right of %s", temp->word, parent->word);
    }
    else {
        parent->left = temp;
        printf("\nWord %s inserted to the left of: %s", temp->word, parent->word);
    }

}

void View();



int main(void) {

    int choice;

    while (choice != 4) {


        printf("--Choose an option--\n1 - Insert\n2 - Search\n 3 - View\n 4 - Quit");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                dictionary *temp = (dictionary *)malloc(sizeof(dictionary));
            temp->left = NULL;
            temp->right = NULL;
            printf("Enter Word or Term: ");
            scanf("%s", temp->word);
            printf("Enter Definition: ");
            scanf("%s", temp->definition);
                Insert(temp); break;
            case 2:
                char term[WORD_LENGTH];
                printf("Enter Word or Term to Insert: ");
                scanf("%s", term);
                Search(term); break;
            case 3: View(); break;
            case 4: exit(0);
        }
    }

    return 0;
}