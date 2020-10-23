#include <stdio.h>
#include <assert.h>
#include "libs/linkedlist.c"

void MoveHead(struct node** destRef, struct node** sourceRef) {
    struct node* newNode = *sourceRef; // the front source node
    assert(newNode != NULL);

    *sourceRef = newNode->next; // Advance the source pointer
    newNode->next = *destRef; // Link the old dest off the new node
    *destRef = newNode; // Move dest to point to the new node
}

void MoveHeadTest() {
    struct node* a = BuildOneTwoThree(); // the list {1, 2, 3}
    struct node* b = BuildOneTwoThree();
    MoveHead(&a, &b);

    assert(length(a) == 4);
    assert(a->val == 1); // head node = 1
    // a == {1, 1, 2, 3}
    // b == {2, 3}
}


int main(void){
    MoveHeadTest();
}