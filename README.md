# linked-lists-problems
Solutions using pointer algorithms in C for common Linked Lists problems.

The problems use the C language syntax, so they require a basic understanding of C and
its pointer syntax. The emphasis is on the important concepts of pointer manipulation and
linked list algorithms rather than the features of the C language.

A base class - `linkedlist.c`, with basic utitlity functions, is defined in [/libs](libs). 
All of the linked list code in this document uses the "classic" singly linked list structure:
* A single head pointer points to the first node in the list. Each node contains a single
.next pointer to the next node. 
* The .next pointer of the last node is NULL. The
empty list is represented by a NULL head pointer. 
* All of the nodes are allocated in the
heap.

For a few of the problems, the solutions present the temporary "dummy node" or a "reference pointer" variation.
They use memory in unusual ways, so they are a nice way to see if you
really understand what's going on :smirk:

The problems roughly in order of difficulty:
1. Count occurences of value i in linked list - Count.c
2. Remove head and return value - Pop.c 
3. Get Nth value from linked list - GetNth.c
4. Move head from source list to destination - moveHead.c
5. Reverse a list - ReverseList.c
6. Delete linked list and free memory - DeleteList.c 
7. Insert value at position N in linked list - InsertNth.c
8. Recursively reverse a list - RecursiveReverse.c



