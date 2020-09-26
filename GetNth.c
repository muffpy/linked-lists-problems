#include <stdio.h>
#include <assert.h>
#include "extensions/linkedlist.c"
#include "getNth.h"

int GetNth(struct node* current, int index){
    while (current != NULL){
        if (index == 0){
            return current->val;
        }
        current = current->next;
        index--;
    }
    assert(0);
}

void GetNthTest() {
    struct node* myList = BuildOneTwoThree(); // build {1, 2, 3}
    int lastNode = GetNth(myList, 2); // returns the value 3

    assert(lastNode == 3);
}
