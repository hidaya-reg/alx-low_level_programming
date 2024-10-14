# 0x17-doubly_linked_lists
## Resources
[What is a Doubly Linked List](https://www.youtube.com/watch?v=k0pjD12bzP0&ab_channel=PaulProgramming)

## Learning Objectives
<details>
<summary>What is a doubly linked list</summary>

### Doubly Linked List
A doubly linked list in C is a data structure where each node contains three parts:

**1. Data:** The value or data stored in the node.
**2. Next pointer:** A pointer to the next node in the list.
**3. Previous pointer:** A pointer to the previous node in the list.
This allows traversal of the list in both directions, from the head (start) to the tail (end) and vice versa, unlike a singly linked list which can only be traversed in one direction.

#### Structure of a Doubly Linked List Node in C:
```c
// Define the structure for a node in the doubly linked list
struct Node {
    int data;               // Data part
    struct Node* next;      // Pointer to the next node
    struct Node* prev;      // Pointer to the previous node
};
```
#### Basic Operations:
- **Insertion:** You can insert a node at the beginning, end, or at a specific position in the list.
- **Deletion:** You can delete a node from the beginning, end, or from a specific position.
- **Traversal:** You can traverse the list forward (from head to tail) or backward (from tail to head).

#### Example Code to Create and Traverse a Doubly Linked List:
```c
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to print the list in forward direction
void printListForward(struct Node* head) {
    struct Node* temp = head;
    printf("List in forward direction: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to print the list in reverse direction
void printListReverse(struct Node* tail) {
    struct Node* temp = tail;
    printf("List in reverse direction: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    // Create the doubly linked list
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    // Link the nodes
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    // Traverse the list in both directions
    printListForward(head);
    printListReverse(third);

    return 0;
}
```
**Output:**
```
List in forward direction: 10 20 30 
List in reverse direction: 30 20 10
```
</details>
<details>
<summary>How to use doubly linked lists</summary>

### Doubly linked lists operations
#### 1. Node Definition
Each node in a doubly linked list contains data, a pointer to the next node, and a pointer to the previous node.
```c
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
```
#### 2. Creating a New Node
A function that creates and returns a new node is useful for various operations like insertion.
```c
struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
```
#### 3. Insertion Operations
You can insert a node in various positions:
- At the beginning
- At the end
- At a specific position

**3.1. Insertion at the Beginning:**
```c
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode; // Update the head pointer
}
```
**3.2. Insertion at the End:**
```c
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Traverse to the end
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}
```
#### 4. Deletion Operations
You can delete a node from:
- The beginning
- The end
- A specific position

**4.1. Deletion from the Beginning:**
```c
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = *head;
    *head = (*head)->next;
    
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    
    free(temp);
}
```
**4.2 Deletion from the End:**
```c
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = *head;
    
    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL; // The list becomes empty
    }
    
    free(temp);
}
```
#### 5. Traversal Operations
You can traverse the doubly linked list in both directions.
**5.1 Traversing Forward:**
```c
void printListForward(struct Node* head) {
    struct Node* temp = head;
    printf("List in forward direction: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
```
**5.2 Traversing Backward:**
```c
void printListBackward(struct Node* tail) {
    struct Node* temp = tail;
    printf("List in backward direction: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
```
#### 6. Finding the Tail (for reverse traversal)
To traverse backward, you need the tail of the list. Here's how you can find it:
```c
struct Node* getTail(struct Node* head) {
    struct Node* temp = head;
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    return temp;
}
```

</details>
<details>
<summary>singly linked lists vs doubly linked lists</summary>

### singly linked lists vs doubly linked lists

| **Feature**                   | **Singly Linked List**                           | **Doubly Linked List**                          |
|--------------------------------|--------------------------------------------------|-------------------------------------------------|
| **Memory Usage**               | Lower (only stores `next` pointer)               | Higher (stores both `next` and `prev` pointers) |
| **Traversal**                  | Only in one direction (forward)                  | Can traverse in both directions (forward & backward) |
| **Node Structure**             | Contains data and `next` pointer                 | Contains data, `next` pointer, and `prev` pointer |
| **Insertion (At Head)**        | Easy (just adjust the head pointer)              | Easy (adjust both `next` and `prev` pointers)    |
| **Insertion (At Tail)**        | Requires traversing the entire list              | Easy if tail pointer is maintained               |
| **Deletion (At Head)**         | Simple (adjust head pointer)                     | Simple (adjust head pointer and `prev` of the next node) |
| **Deletion (At Tail)**         | Requires traversal to find the previous node     | Easy (directly access the previous node using `prev` pointer) |
| **Deletion (From Middle)**     | Requires traversal to find the previous node     | Directly access previous node using `prev` pointer |
| **Use Cases**                  | Stack, queue, simple list operations             | Deque, browser history, undo/redo, LRU cache     |
| **Memory Efficiency**          | More memory-efficient (stores less data)         | Less memory-efficient (needs more pointers)      |
| **Implementation Complexity**  | Simple to implement                              | More complex (due to managing both `next` and `prev` pointers) |
| **Preferred When**             | Forward-only traversal, memory is a concern      | Bidirectional traversal is needed, frequent insertion/deletion in the middle |
| **Example Applications**       | Stacks, queues, playlists, task scheduling       | Undo/redo, LRU cache, browser history navigation |

</details>


## More Info
- Please use this data structure for this project:
```c
/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * 
 */
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;
```

## Tasks
### 0. Print list
Write a function that prints all the elements of a ``dlistint_t`` list.
**Prototype:** ``size_t print_dlistint(const dlistint_t *h);``
- Return: the number of nodes
- Format: see example
```bash
$ cat 0-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;
    dlistint_t *new;
    dlistint_t hello = {8, NULL, NULL};
    size_t n;

    head = &hello;
    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
    {
        dprintf(2, "Error: Can't malloc\n");
        return (EXIT_FAILURE);
    }
    new->n = 9;
    head->prev = new;
    new->next = head;
    new->prev = NULL;
    head = new;
    n = print_dlistint(head);
    printf("-> %lu elements\n", n);
    free(new);
    return (EXIT_SUCCESS);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-print_dlistint.c -o a
$ ./a 
9
8
-> 2 elements
```
### 1. List length
Write a function that returns the number of elements in a linked ``dlistint_t`` list.
**Prototype:** ``size_t dlistint_len(const dlistint_t *h);``
```bash
$ cat 1-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;
    dlistint_t *new;
    dlistint_t hello = {8, NULL, NULL};
    size_t n;

    head = &hello;
    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
    {
        dprintf(2, "Error: Can't malloc\n");
        return (EXIT_FAILURE);
    }
    new->n = 9;
    head->prev = new;
    new->next = head;
    new->prev = NULL;
    head = new;
    n = dlistint_len(head);
    printf("-> %lu elements\n", n);
    free(new);
    return (EXIT_SUCCESS);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-dlistint_len.c -o b
$ ./b 
-> 2 elements
```
### 2. Add node
Write a function that adds a new node at the beginning of a ``dlistint_t`` list.
**Prototype:** ``dlistint_t *add_dnodeint(dlistint_t **head, const int n);``
- Return: the address of the new element, or ``NULL`` if it failed
```bash
$ cat 2-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;

    head = NULL;
    add_dnodeint(&head, 0);
    add_dnodeint(&head, 1);
    add_dnodeint(&head, 2);
    add_dnodeint(&head, 3);
    add_dnodeint(&head, 4);
    add_dnodeint(&head, 98);
    add_dnodeint(&head, 402);
    add_dnodeint(&head, 1024);
    print_dlistint(head);
    return (EXIT_SUCCESS);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-add_dnodeint.c 0-print_dlistint.c -o c
$ ./c 
1024
402
98
4
3
2
1
0
```
### 3. Add node at the end
Write a function that adds a new node at the end of a ``dlistint_t`` list.
**Prototype:** ``dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);``
- Return: the address of the new element, or ``NULL`` if it failed
```bash
$ cat 3-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;

    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    print_dlistint(head);
    return (EXIT_SUCCESS);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-add_dnodeint_end.c 0-print_dlistint.c -o d
$ ./d 
0
1
2
3
4
98
402
1024
```
### 4. Free list
Write a function that frees a ``dlistint_t`` list.
**Prototype:** ``void free_dlistint(dlistint_t *head);``
```bash
$ cat 4-main.c
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;

    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    print_dlistint(head);
    free_dlistint(head);
    head = NULL;
    return (EXIT_SUCCESS);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c -o e
$ valgrind ./e 
==4197== Memcheck, a memory error detector
==4197== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==4197== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==4197== Command: ./e
==4197== 
0
1
2
3
4
98
402
1024
==4197== 
==4197== HEAP SUMMARY:
==4197==     in use at exit: 0 bytes in 0 blocks
==4197==   total heap usage: 9 allocs, 9 frees, 1,216 bytes allocated
==4197== 
==4197== All heap blocks were freed -- no leaks are possible
==4197== 
==4197== For counts of detected and suppressed errors, rerun with: -v
==4197== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
### 5. Get node at index
Write a function that returns the nth node of a ``dlistint_t`` linked list.
**Prototype:** ``dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);``
- where ``index`` is the index of the node, starting from ``0``
- if the node does not exist, return ``NULL``
```bash
$ cat 5-main.c
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;
    dlistint_t *node;

    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    print_dlistint(head);
    node = get_dnodeint_at_index(head, 5);
    printf("%d\n", node->n);
    free_dlistint(head);
    head = NULL;
    return (EXIT_SUCCESS);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-main.c 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c 5-get_dnodeint.c -o h
$ ./h
0
1
2
3
4
98
402
1024
98
```
### 6. Sum list
Write a function that returns the sum of all the data (n) of a ``dlistint_t`` linked list.
**Prototype:** ``int sum_dlistint(dlistint_t *head);``
- if the list is empty, return ``0``
```bash
$ cat 6-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;
    int sum;

    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    sum = sum_dlistint(head);
    printf("sum = %d\n", sum);
    free_dlistint(head);
    head = NULL;
    return (EXIT_SUCCESS);
}
$ gcc -Wall -pedantic -Werror -Wextra 6-main.c -std=gnu89 3-add_dnodeint_end.c 4-free_dlistint.c 6-sum_dlistint.c -o i
$ ./i 
sum = 1534
```
### 7. Insert at index
Write a function that inserts a new node at a given position.
**Prototype:** ``dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);``
- where ``idx`` is the index of the list where the new node should be added. Index starts at ``0``
- Returns: the address of the new node, or ``NULL`` if it failed
- if it is not possible to add the new node at index ``idx``, do not add the new node and return ``NULL``

Your files ``2-add_dnodeint.c`` and ``3-add_dnodeint_end.c`` will be compiled during the correction
```bash
$ cat 7-main.c
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;

    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    print_dlistint(head);
    printf("-----------------\n");
    insert_dnodeint_at_index(&head, 5, 4096);
    print_dlistint(head);
    free_dlistint(head);
    head = NULL;
    return (EXIT_SUCCESS);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 7-main.c 2-add_dnodeint.c 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c 7-insert_dnodeint.c -o j
$ ./j 
0
1
2
3
4
98
402
1024
-----------------
0
1
2
3
4
4096
98
402
1024
```
### 8. Delete at index
Write a function that deletes the node at index index of a ``dlistint_t`` linked list.
**Prototype:** ``int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);``
- where ``index`` is the index of the node that should be deleted. Index starts at ``0``
- Returns: ``1`` if it succeeded, ``-1`` if it failed
```bash
$ cat 8-main.c
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;

    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    print_dlistint(head);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 5);
    print_dlistint(head);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 8-main.c 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c 8-delete_dnodeint.c -o k
$ ./k
0
1
2
3
4
98
402
1024
-----------------
0
1
2
3
4
402
1024
-----------------
1
2
3
4
402
1024
-----------------
2
3
4
402
1024
-----------------
3
4
402
1024
-----------------
4
402
1024
-----------------
402
1024
-----------------
1024
-----------------
-----------------
-----------------
-----------------
-----------------
-----------------
-----------------
-----------------
-----------------
-----------------
```
### 9. Crackme4
Find the password for [crackme4](https://github.com/alx-tools/0x17.c).
- Save the password in the file ``100-password``
- Your file should contain the exact password, no new line, no extra space
- Hint: The program prints “OK” when the password is correct

### 10. Palindromes
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is ``9009`` = ``91`` × ``99``.
Find the largest palindrome made from the product of two 3-digit numbers.
- Save the result in the file ``102-result``
- Your file should contain the exact result, no new line, no extra space

### 11. crackme5
Write a keygen for [crackme5](https://github.com/alx-tools/0x17.c).

- Usage of the crackme: ``./crackme5 username key``
- The crackme will segfault if you do not enter the correct key for the user
- Usage for your keygen: ``./keygen5 username``
- Your keygen should print a valid key for the ``username``
```bash
julien@ubuntu:~/0x17$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 103-keygen.c -o keygen5
julien@ubuntu:~/0x17$ ./crackme5 julien javascript
Segmentation fault (core dumped)
julien@ubuntu:~/0x17$ ./crackme5 julien `./keygen5 julien`
Congrats!
```