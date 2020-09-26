#include <stdio.h>
#include <assert.h>
#include "extensions/linkedlist.c"

int Pop(struct node** headRef){
    struct node* head = *headRef;
    int data;
    assert(head != NULL);

    data = head->val;
    *headRef = head->next;
    free(head);

    return data;
}

void PopTest() {
    struct node* head = BuildOneTwoThree(); // build {1, 2, 3}
    int a = Pop(&head); // deletes "1" node and returns 1
    int b = Pop(&head); // deletes "2" node and returns 2
    int c = Pop(&head); // deletes "3" node and returns 3
    int len = length(head); // the list is now empty, so len == 0

    assert(len == 0);
}

int main(void){
    PopTest();
}
