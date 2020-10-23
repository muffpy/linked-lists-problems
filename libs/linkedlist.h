#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node{
    int val;
    struct node * next;
};
struct node* createNode(int);
struct node* appendNode(struct node **, int);
struct node* BuildOneTwoThree();
void printList(struct node*);
void freeListMemory(struct node*);
struct node* searchNumber(struct node *, int);
int length (struct node*);
struct node* push(struct node**, int);

#endif