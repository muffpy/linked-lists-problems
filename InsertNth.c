#include <stdio.h>
#include <assert.h>
#include "getNth.c"

void InsertNth(struct node** headRef, int index, int value){
    if (index == 0) push(headRef, value);
    else{
        struct node* current = *headRef;

        // Find node behind target position
        for (int i = 0; i < index - 1; i++){
            assert(current != NULL); // avoid overshooting index
            current = current->next;
        }
        assert(current!=NULL); // check for index = (lastIndex+2)

        // set .next of new node to current.next(index+1) and set current.next to new node;
        push(&(current->next), value);
    }   
}

void InsertNthTest() {
    struct node* head = NULL; // start with the empty list
    InsertNth(&head, 0, 13); // build {13)
    InsertNth(&head, 1, 42); // build {13, 42}
    InsertNth(&head, 1, 5); // build {13, 5, 42}
    
    int find = GetNth(head, 2);

    assert(find == 42);
    freeListMemory(head);
}

int main(void){
    InsertNthTest();
}
