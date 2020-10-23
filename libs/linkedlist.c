#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// int main (void){
//     struct node* head = NULL;
//     struct node* tail;

//     push(&head,7);
//     tail = appendNode(&head, 6);
//     tail = appendNode(&head, 5);
//     push(&head,4);

//     printList(head);

//     // search for a value in linked list
//     int searchNum = 5;
//     struct node * ptr = searchNumber(head, searchNum);
//     if (ptr!=NULL) {
//         printf("Found digit %d at location %p.\n", searchNum, ptr);
//     } else {
//         printf("Digit %d not found.\n", searchNum);
//     }
    
//     freeListMemory(head); // free memory
//     return 0;
// }

struct node* BuildOneTwoThree(){
    struct node* head = NULL;
    struct node* tail;
    int i;

    // Deal with head node and set tail pointer
    push(&head, 1);
    tail = head;

    for (i = 2; i < 4; i++){
        push(&(tail->next), i);
        tail = tail->next;
    }
    return (head); // list = {1,2,3}
}

struct node* createNode(int value){
    struct node* ptr;
    ptr = (struct node *) malloc(sizeof(struct node));
    ptr -> val = value;
    ptr -> next = NULL;

    return ptr;
}

struct node* appendNode(struct node** headRef, int data){
    struct node* current = *headRef;

    // special case for the empty list
    if (current == NULL) {
        push(headRef, data);
    } else {
    // Locate the last node
        while (current->next != NULL) {
            current = current->next;
        }
        push(&(current->next),data);
    }

    return (current->next);
}

/*  Given an int and a reference to the head pointer (i.e. a struct
    node** pointer to the head pointer), add a new node at the head of the
    list and set its .next to point to the current head, 
    and finally change the head (of the whole list) to point to the new node.
*/
struct node* push(struct node** headRef, int data){
    struct node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

void printList(struct node *start){
    struct node * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeListMemory(struct node* start){
    struct node* ptr = start;
    struct node* tmp;

    while (ptr != NULL){
        tmp = ptr -> next;
        free(ptr);
        ptr = tmp;
    }
}

struct node * searchNumber(struct node * start, int number) {
    struct node * ptr = start;
    while ((ptr!=NULL) && (ptr->val!=number)) {
        ptr = ptr->next;
    }
    return ptr;
}

/*
 Given a linked list head pointer, compute
 and return the number of nodes in the list.
*/
int length (struct node* head){
    struct node* current = head;
    int i = 0;
    while (current != NULL){
        i++;
        current = current->next;
    }
    return i;
}

