#include <stdio.h>
#include <stdlib.h>

const int WORD_LENGTH = 30;

struct dict {
    struct dict *left, *right;
    char word[WORD_LENGTH], definition[200];
}*Root = NULL; //Root node struct pointer. Initially empty with no data. Hence Null.

typedef struct dict dictionary;

void Insert() {

}
void Search() {
    char term[WORD_LENGTH];
    dictionary *current = Root; // start search from root node.
    printf("Enter Word or Term");
    scanf("%s", term);

    while (current != NULL) {
        int result = Compare(term, current->word);

        if (result == 1) {



        }
    }


};
void View();

int Compare(char a[], char b[]) {

    int lexicographicalChecker;

    for (int i = 0, j =0; a[i] != '\0' && b[j] != '\0';i++, j++) {
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


int main(void) {

    int choice;

    while (choice != 4) {
        printf("--Choose an option--\n1 - Search\n2 - Insert\n 3 - View\n 4 - Quit");
        scanf("%d", &choice);
        switch (choice) {
            case 1: Insert(); break;
            case 2: Search(); break;
            case 3: View(); break;
            case 4: exit(0);
        }
    }

    return 0;
}