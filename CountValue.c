#include <stdio.h>
#include <assert.h>
#include "libs/linkedlist.c"

int Count(struct node* current, int value){
    int count = 0;
    while (current != NULL){
        if (current->val == value){
            count++;
        }
        current = current->next;
    }
    return count;
}

void CountTest() {
    struct node* list = BuildOneTwoThree(); // build {1, 2, 3}
    int count = Count(list, 2); // returns 1 since there's 1 '2' in the list

    assert(count == 1);
}

int main(void){
    CountTest();
}