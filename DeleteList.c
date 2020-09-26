#include <stdio.h>
#include <assert.h>
#include "extensions/linkedlist.c"

void DeleteList(struct node** headRef){
    struct node* current = *headRef; // deref headRef to get the real head
    struct node* next;

    while (current != NULL) {
        next = current->next; // note the next pointer
        free(current); // delete the node
        current = next; // advance to the next node
    }
}

void DeleteListTest() {
    struct node* myList = BuildOneTwoThree(); // build {1, 2, 3}
    DeleteList(&myList); // deletes the three nodes and sets myList to NULL

    assert(myList == NULL);
}

int main(void){
    DeleteListTest();
}
