#include <stdio.h>
#include <assert.h>
#include "libs/linkedlist.c"

void RecursiveReverse(struct node** headRef) {
    struct node* first;
    struct node* rest;
    if (*headRef == NULL) return; // empty list base case
    first = *headRef; // suppose first = {1, 2, 3}
    rest = first->next; // rest = {2, 3}
    if (rest == NULL) return; // empty rest base case
    RecursiveReverse(&rest); // Recursively reverse the smaller {2, 3} case
    // after: rest = {3, 2}
    first->next->next = first; // put the first elem on the end of the list
    first->next = NULL; // (tricky step -- make a drawing)
    *headRef = rest; // fix the head pointer
}

void ReverseListTest(){
    struct node* list = BuildOneTwoThree(); // build {1, 2, 3}
    int first = list->val;
    int second = list->next->val;
    int third = list->next->next->val;

    RecursiveReverse(&list); // returns 1 since there's 1 '2' in the list

    assert(list->val == third);
    assert(list->next->val == second);
    assert(list->next->next->val == first);
}

int main(void){
    ReverseListTest();
}

