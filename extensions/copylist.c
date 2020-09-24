#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct node* CopyListIterative(struct node* head) {
    struct node* current = head; // used to iterate over the original list
    struct node* newList = NULL; // head of the new list
    struct node* tail = NULL; // kept pointing to the last node in the new list

    while (current != NULL) {
        if (newList == NULL) { // special case for the first new node
            newList = createNode(current->val);
            tail = newList;
        }
        else {
            tail->next = createNode(current->val);
        }
        current = current->next;
    }
    return(newList);
}


// Variant of CopyList() that uses push()
struct node* CopyListPush(struct node* head) {
    struct node* current = head; // used to iterate over the original list
    struct node* newList = NULL; // head of the new list
    struct node* tail = NULL; // kept pointing to the last node in the new list

    while (current != NULL) {
        if (newList == NULL) { // special case for the first new node
            push(&newList, current->val);
            tail = newList;
        }
        else {
            push(&(tail->next), current->val); // add each node at the tail
            tail = tail->next; // advance the tail to the new last node
        }
        current = current->next;
    }
    return(newList);
}

// Dummy node variant
struct node* CopyListDummy(struct node* head) {
    struct node* current = head; // used to iterate over the original list
    struct node* tail; // kept pointing to the last node in the new list
    struct node dummy; // build the new list off this dummy node

    dummy.next = NULL;
    tail = &dummy; // start the tail pointing at the dummy
    while (current != NULL) {
        Push(&(tail->next), current->val); // add each node at the tail
        tail = tail->next; // advance the tail to the new last node

        current = current->next;
    }
    return(dummy.next);
}

// Recursive variant
struct node* CopyList(struct node* head) {
    struct node* current = head;
    
    if (head == NULL) return NULL;
    else {
        struct node* newList = malloc(sizeof(struct node)); // make the one node
        newList->val = current->val;
        newList->next = CopyList(current->next); // recur for the rest
        return(newList);
    }
}



int main(void){
    struct node* head = NULL;
    struct node* tail;

    push(&head,7);
    tail = appendNode(&head, 6);
    tail = appendNode(&head, 5);
    push(&head,4);

    printList(head);
    struct node* newList = CopyList2(head);
    printList(newList);
}
