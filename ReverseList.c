#include <stdio.h>
#include <assert.h>
#include "libs/linkedlist.c"

/*
 Iterative list reverse.
 Iterate through the list left-right.
*/
static void Reverse(struct node** headRef) {
    struct node* result = NULL;
    struct node* current = *headRef;
    struct node* next;
    while (current != NULL) { // MoveHead can be used instead
        next = current->next;
        current->next = result; // move the node onto the result
        result = current;
        current = next;
    }
    *headRef = result;
}

// Reverses the given linked list by changing its .next pointers and
// its head pointer. Takes a pointer (reference) to the head pointer.
void Reverse2(struct node** headRef) {
    if (*headRef != NULL) { // special case: skip the empty list
        struct node* middle = *headRef; // the main pointer
        struct node* front = middle->next; // the two other pointers (NULL ok)
        struct node* back = NULL;
        while (1) {
            middle->next = back; // fix the middle node
            if (front == NULL) break; // test if done
            
            back = middle; // advance the three pointers
            middle = front;
            front = front->next;
        }
        *headRef = middle; // fix the head pointer to point to the new front
    }
}


void ReverseListTest(){
    struct node* list = BuildOneTwoThree(); // build {1, 2, 3}
    int first = list->val;
    int second = list->next->val;
    int third = list->next->next->val;

    struct node* head = reverse(list); // returns 1 since there's 1 '2' in the list

    assert(head->val == third);
    assert(head->next->val == second);
    assert(head->next->next->val == first);
}


int main(void){
    ReverseListTest();
}