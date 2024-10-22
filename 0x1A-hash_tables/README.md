# 0x1A. C - Hash tables
## Resources
[What is a HashTable Data Structure - Introduction to Hash Tables , Part 0](https://www.youtube.com/watch?v=MfhjkfocRR0&ab_channel=PaulProgramming)
[Hash function](https://en.wikipedia.org/wiki/Hash_function)
[Hash table](https://en.wikipedia.org/wiki/Hash_table)
[All about hash tables](https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus)
[why hash tables and not arrays](https://stackoverflow.com/questions/31930046/what-is-a-hash-table-and-how-do-you-make-it-in-c)

## Learning Objectives
<details>
<summary>What is a hash function</summary>

### Hash function
A **hash function** is a function that takes an input (or "key") and converts it into a numerical value, typically called a "hash code" or "hash value." This value is used to index data in a structure called a **hash table**. The key property of a hash function is that it should distribute inputs uniformly across possible hash values to minimize collisions (when two keys produce the same hash value).

#### Characteristics of a Good Hash Function:
**1. Deterministic:** The same input must always produce the same hash value.
**2. Efficient:** It should compute the hash value quickly, even for large inputs.
**3. Uniform Distribution:** It should distribute hash values as evenly as possible across the hash table to minimize collisions.
**4. Minimize Collisions:** Although collisions can't be entirely avoided, a good hash function minimizes the likelihood of two different inputs producing the same hash value.
#### Example of a Simple Hash Function
Consider a very basic hash function that sums the ASCII values of the characters in a string:

```c
unsigned int hash(const char *key) {
    unsigned int hashValue = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hashValue += key[i];  // Sum the ASCII values of characters
    }
    return hashValue % TABLE_SIZE;  // Return index within the bounds of the table
}
```

#### Collision Example
Since hash functions map a potentially infinite set of keys to a finite number of indices, different keys can sometimes generate the same hash value. For example, if ``"abc"`` and ``"cab"`` both produce the same hash value, they would collide in the hash table.

To handle **collisions**, various strategies like **chaining** (where multiple keys with the same hash are stored in a linked list at that index) or **open addressing** (probing for the next available slot) are used.

#### Practical Hash Functions
In practice, simple hash functions like summing ASCII values are too basic and result in many collisions for common data sets. More advanced hash functions, such as **SHA-256** or **MD5**, are used in cryptographic contexts where security is important, while other well-known hash functions like **MurmurHash** and **CityHash** are designed for efficient non-cryptographic use.

</details>
<details>
<summary>What is a hash table, how do they work and how to use them</summary>

### Hash table
A **hash table** is a data structure used to store and retrieve key-value pairs efficiently. It uses a **hash function** to convert keys (which can be strings, numbers, or other types of data) into indices in an array where the corresponding values are stored.

Hash tables are used because they provide constant time complexity (``O(1)``) for both insertion and lookup operations in the best case. This makes them one of the most efficient data structures for associative arrays, dictionaries, and databases.

**1. Hash Function:** A hash table relies on a **hash function** that takes a key and generates an index. This index corresponds to a slot in the array where the value is stored. For example, if a string key like "apple" is input, the hash function converts it into a number that serves as the index.
```c
unsigned int hash(const char *key) {
    unsigned int hashValue = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hashValue += key[i];  // Sum of ASCII values
    }
    return hashValue % TABLE_SIZE;  // Constrain to the size of the table
}
```
**2. Inserting a Key-Value Pair:** When inserting a key-value pair (e.g., "name": "Alice"), the hash function computes the index for the key "name". The value "Alice" is then stored at that index in the hash table’s internal array.
- If no other key hashes to the same index, the value is stored directly.
- If another key hashes to the same index (a **collision**), a collision handling mechanism is used (e.g., **chaining**).

**3. Collisions:** Collisions occur when different keys generate the same hash value. This is inevitable because the number of possible keys is larger than the size of the array. Common ways to handle collisions include:
- Chaining: Store multiple key-value pairs at the same index using linked lists.
- Open Addressing: Probe for the next available index when a collision occurs.
**4. Searching for a Value:** To retrieve a value associated with a key, the key is passed to the hash function to calculate its index. The value is then retrieved from that index. If there are multiple items (due to chaining), the linked list at that index is traversed to find the correct key.

**5. Deleting a Key-Value Pair:** Deletion involves finding the key, using the hash function, and then removing the corresponding node from the hash table (or handling it appropriately if chaining is used).

#### Example: Using a Hash Table in C
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node in the hash table (for chaining)
typedef struct hash_node_s {
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

// Hash table structure
typedef struct hash_table_s {
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;

// Hash function (djb2 algorithm)
unsigned long int hash_djb2(const char *str) {
    unsigned long int hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;  // hash * 33 + c
    }
    return hash;
}

// Create a hash table
hash_table_t *create_hash_table(unsigned long int size) {
    hash_table_t *table = malloc(sizeof(hash_table_t));
    table->size = size;
    table->array = malloc(sizeof(hash_node_t *) * size);
    for (unsigned long int i = 0; i < size; i++) {
        table->array[i] = NULL;
    }
    return table;
}

// Insert key-value pair into the hash table
void insert(hash_table_t *table, const char *key, const char *value) {
    unsigned long int index = hash_djb2(key) % table->size;

    hash_node_t *new_node = malloc(sizeof(hash_node_t));
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = table->array[index];  // Chaining for collisions
    table->array[index] = new_node;
}

// Search for a value by its key
char *search(hash_table_t *table, const char *key) {
    unsigned long int index = hash_djb2(key) % table->size;

    hash_node_t *node = table->array[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

// Free the hash table
void free_table(hash_table_t *table) {
    for (unsigned long int i = 0; i < table->size; i++) {
        hash_node_t *node = table->array[i];
        while (node != NULL) {
            hash_node_t *temp = node;
            node = node->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(table->array);
    free(table);
}

int main() {
    hash_table_t *table = create_hash_table(1024);

    insert(table, "name", "Alice");
    insert(table, "age", "30");
    insert(table, "city", "New York");

    printf("Name: %s\n", search(table, "name"));
    printf("Age: %s\n", search(table, "age"));
    printf("City: %s\n", search(table, "city"));

    // Free the table
    free_table(table);
    return 0;
}
```
#### Applications of Hash Tables:
- Dictionaries/Maps: Storing key-value pairs, like in Python dictionaries.
- Database Indexing: Quick lookups of records based on unique keys.
- Caching: Efficiently storing recently accessed data.
- Symbol Tables: Used in compilers to track variable/function names.
#### Advantages:
- Fast lookups: ``O(1)`` average time complexity for search, insert, and delete.
- Efficient: Provides efficient storage and retrieval for large datasets.
#### Disadvantages:
- Collisions: Must be managed with a collision resolution strategy.
- Wasted Space: Hash tables typically require more memory to ensure fewer collisions.
</details>

## More Info
### Data Structures
Please use these data structures for this project:
```c
/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
     char *key;
     char *value;
     struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
     unsigned long int size;
     hash_node_t **array;
} hash_table_t;
```

### Python Dictionaries
Python dictionaries are implemented using hash tables. When you will be done with this project, you will be able to better understand the power and simplicity of Python dictionaries. So much is actually happening when you type ``d = {'a': 1, 'b': 2}``, but everything looks so simple for the user. Python doesn’t use the exact same implementation than the one you will work on today though.

Note that all dictionaries are not implemented using hash tables and there is a difference between a dictionary and a hash table. [Read more here](https://stackoverflow.com/questions/2061222/what-is-the-true-difference-between-a-dictionary-and-a-hash-table) 

## Tasks
### 0. >>> ht = {}
Write a function that creates a hash table.
- Prototype: ``hash_table_t *hash_table_create(unsigned long int size);``
    + where ``size`` is the size of the array
- Returns a pointer to the newly created hash table
- If something went wrong, your function should return ``NULL``
```bash
$ cat 0-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    printf("%p\n", (void *)ht);
    return (EXIT_SUCCESS);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-hash_table_create.c -o a
$ ./a 
0x238a010
$ valgrind ./a
==7602== Memcheck, a memory error detector
==7602== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==7602== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==7602== Command: ./a
==7602== 
0x51fc040
==7602== 
==7602== HEAP SUMMARY:
==7602==     in use at exit: 8,208 bytes in 2 blocks
==7602==   total heap usage: 2 allocs, 0 frees, 8,208 bytes allocated
==7602== 
==7602== LEAK SUMMARY:
==7602==    definitely lost: 16 bytes in 1 blocks
==7602==    indirectly lost: 8,192 bytes in 1 blocks
==7602==      possibly lost: 0 bytes in 0 blocks
==7602==    still reachable: 0 bytes in 0 blocks
==7602==         suppressed: 0 bytes in 0 blocks
==7602== Rerun with --leak-check=full to see details of leaked memory
==7602== 
==7602== For counts of detected and suppressed errors, rerun with: -v
==7602== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
### 1. djb2
Write a hash function implementing the djb2 algorithm.
- Prototype: ``unsigned long int hash_djb2(const unsigned char *str);``
- You are allowed to copy and paste the function from [this page](https://gist.github.com/papamuziko/7bb52dfbb859fdffc4bd0f95b76f71e8)
```bash
$ cat 1-djb2.c 
unsigned long int hash_djb2(const unsigned char *str)
{
    unsigned long int hash;
    int c;

    hash = 5381;
    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return (hash);
}
$ 
$ cat 1-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    char *s;

    s = "cisfun";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    s = "Don't forget to tweet today";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    s = "98";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    return (EXIT_SUCCESS);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-djb2.c -o b
$ ./b 
6953392314605
3749890792216096085
5861846
``` 
### 2. key -> index
Write a function that gives you the index of a key.
- Prototype: ``unsigned long int key_index(const unsigned char *key, unsigned long int size);``
    + where ``key`` is the key
    + and ``size`` is the size of the array of the hash table
- This function should use the ``hash_djb2`` function that you wrote earlier
- Returns the index at which the key/value pair should be stored in the array of the hash table
- You will have to use this hash function for all the next tasks
```bash
$ cat 2-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    char *s;
    unsigned long int hash_table_array_size;

    hash_table_array_size = 1024;
    s = "cisfun";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
    s = "Don't forget to tweet today";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
    s = "98";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));  
    return (EXIT_SUCCESS);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 1-djb2.c 2-key_index.c -o c
$ ./c 
6953392314605
237
3749890792216096085
341
5861846
470
```
### 3. >>> ht['betty'] = 'cool'
Write a function that adds an element to the hash table.
- Prototype: ``int hash_table_set(hash_table_t *ht, const char *key, const char *value);``
    + Where ``ht`` is the hash table you want to add or update the key/value to
    + ``key`` is the key. ``key`` can not be an empty string
    + and value is the value associated with the key. ``value`` must be duplicated. ``value`` can be an empty string
- Returns: ``1`` if it succeeded, ``0`` otherwise
- In case of collision, add the new node at the beginning of the list
```bash
$ cat 3-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    hash_table_set(ht, "betty", "cool");
    return (EXIT_SUCCESS);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c -o d
```
If you want to test for collisions, here are some strings that collide using the djb2 algorithm:
- **hetairas** collides with **mentioner**
- **heliotropes** collides with **neurospora**
- **depravement** collides with **serafins**
- **stylist** collides with **subgenera**
- **joyful** collides with **synaphea**
- **redescribed** collides with **urites**
- **dram** collides with **vivency**

### 4. >>> ht['betty']
Write a function that retrieves a value associated with a key.
- Prototype: ``char *hash_table_get(const hash_table_t *ht, const char *key);``
    + where ``ht`` is the hash table you want to look into
    + and ``key`` is the key you are looking for
- Returns the value associated with the element, or ``NULL`` if ``key`` couldn’t be found
```bash
$ cat 4-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;
    char *value;

    ht = hash_table_create(1024);
    hash_table_set(ht, "c", "fun");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "Bob", "and Kris love asm");
    hash_table_set(ht, "N", "queens");
    hash_table_set(ht, "Asterix", "Obelix");
    hash_table_set(ht, "Betty", "Cool");
    hash_table_set(ht, "98", "Battery Street");
    hash_table_set(ht, "c", "isfun");

    value = hash_table_get(ht, "python");
    printf("%s:%s\n", "python", value);
    value = hash_table_get(ht, "Bob");
    printf("%s:%s\n", "Bob", value);
    value = hash_table_get(ht, "N");
    printf("%s:%s\n", "N", value);
    value = hash_table_get(ht, "Asterix");
    printf("%s:%s\n", "Asterix", value);
    value = hash_table_get(ht, "Betty");
    printf("%s:%s\n", "Betty", value);
    value = hash_table_get(ht, "98");
    printf("%s:%s\n", "98", value);
    value = hash_table_get(ht, "c");
    printf("%s:%s\n", "c", value);
    value = hash_table_get(ht, "javascript");
    printf("%s:%s\n", "javascript", value);
    return (EXIT_SUCCESS);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c -o e
$ ./e 
python:awesome
Bob:and Kris love asm
N:queens
Asterix:Obelix
Betty:Cool
98:Battery Street
c:isfun
javascript:(null)
```

### 5. >>> print(ht)
Write a function that prints a hash table.
- Prototype: ``void hash_table_print(const hash_table_t *ht);``
    + where ``ht`` is the hash table
- You should print the key/value in the order that they appear in the array of hash table
    + Order: array, list
- Format: see example
- If ``ht`` is NULL, don’t print anything
```bash
$ cat 5-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    hash_table_print(ht);
    hash_table_set(ht, "c", "fun");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "Bob", "and Kris love asm");
    hash_table_set(ht, "N", "queens");
    hash_table_set(ht, "Asterix", "Obelix");
    hash_table_set(ht, "Betty", "Cool");
    hash_table_set(ht, "98", "Battery Street");
    hash_table_print(ht);
    return (EXIT_SUCCESS);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c 5-hash_table_print.c -o f
$ ./f 
{}
{'Betty': 'Cool', 'python': 'awesome', 'Bob': 'and Kris love asm', '98': 'Battery Street', 'N': 'queens', 'c': 'fun', 'Asterix': 'Obelix'}
```

### 6. >>> del ht
Write a function that deletes a hash table.
Prototype: ``void hash_table_delete(hash_table_t *ht);``
- where ``ht`` is the hash table
```bash
$ cat 6-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;
    char *key;
    char *value;

    ht = hash_table_create(1024);
    hash_table_set(ht, "c", "fun");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "Bob", "and Kris love asm");
    hash_table_set(ht, "N", "queens");
    hash_table_set(ht, "Asterix", "Obelix");
    hash_table_set(ht, "Betty", "Cool");
    hash_table_set(ht, "98", "Battery Streetz");
    key = strdup("Tim");
    value = strdup("Britton");
    hash_table_set(ht, key, value);
    key[0] = '\0';
    value[0] = '\0';
    free(key);
    free(value);
    hash_table_set(ht, "98", "Battery Street"); 
    hash_table_set(ht, "hetairas", "Bob");
    hash_table_set(ht, "hetairas", "Bob Z");
    hash_table_set(ht, "mentioner", "Bob");
    hash_table_set(ht, "hetairas", "Bob Z Chu");
    hash_table_print(ht);
    hash_table_delete(ht);
    return (EXIT_SUCCESS);
}
$ gcc -Wall -pedantic -Werror -Wextra 6-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c 5-hash_table_print.c 6-hash_table_delete.c -o g
$ valgrind ./g
==6621== Memcheck, a memory error detector
==6621== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==6621== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==6621== Command: ./g
==6621== 
{'Betty': 'Cool', 'mentioner': 'Bob', 'hetairas': 'Bob Z Chu', 'python': 'awesome', 'Bob': 'and Kris love asm', '98': 'Battery Street', 'N': 'queens', 'c': 'fun', 'Tim': 'Britton', 'Asterix': 'Obelix'}
==6621== 
==6621== HEAP SUMMARY:
==6621==     in use at exit: 0 bytes in 0 blocks
==6621==   total heap usage: 37 allocs, 37 frees, 8,646 bytes allocated
==6621== 
==6621== All heap blocks were freed -- no leaks are possible
==6621== 
==6621== For counts of detected and suppressed errors, rerun with: -v
==6621== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

### 7. $ht['Betty'] = 'Cool'
In PHP, hash tables are **ordered**. Wait… WAT? How is this even possible?

For this task, please:
- Read [PHP Internals Book: HashTable](https://www.phpinternalsbook.com/php5/hashtables/basic_structure.html)
- Use the same hash function
- Use these data structures:
```c
/**
 * struct shash_node_s - Node of a sorted hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 * @sprev: A pointer to the previous element of the sorted linked list
 * @snext: A pointer to the next element of the sorted linked list
 */
typedef struct shash_node_s
{
     char *key;
     char *value;
     struct shash_node_s *next;
     struct shash_node_s *sprev;
     struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 * @shead: A pointer to the first element of the sorted linked list
 * @stail: A pointer to the last element of the sorted linked list
 */
typedef struct shash_table_s
{
     unsigned long int size;
     shash_node_t **array;
     shash_node_t *shead;
     shash_node_t *stail;
} shash_table_t;
```
Rewrite the previous functions using these data structures:
- ``shash_table_t *shash_table_create(unsigned long int size);``
- ``int shash_table_set(shash_table_t *ht, const char *key, const char *value);``
    + The key/value pair should be inserted in the sorted list at the right place
    + Note that here we do not want to do exactly like ``PHP``: we want to create a sorted linked list, by key (sorted on ASCII value), that we can print by traversing it. See example.
- ``char *shash_table_get(const shash_table_t *ht, const char *key);``
- ``void shash_table_print(const shash_table_t *ht);``
    + Should print the hash table using the sorted linked list
- ``void shash_table_print_rev(const shash_table_t *ht);``
    + Should print the hash tables key/value pairs in reverse order using the sorted linked list
- ``void shash_table_delete(shash_table_t *ht);``
- You are allowed to have more than 5 functions in your file
```bash
$ cat 100-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    shash_table_t *ht;

    ht = shash_table_create(1024);
    shash_table_set(ht, "y", "0");
    shash_table_print(ht);
    shash_table_set(ht, "j", "1");
    shash_table_print(ht);
    shash_table_set(ht, "c", "2");
    shash_table_print(ht);
    shash_table_set(ht, "b", "3");
    shash_table_print(ht);
    shash_table_set(ht, "z", "4");
    shash_table_print(ht);
    shash_table_set(ht, "n", "5");
    shash_table_print(ht);
    shash_table_set(ht, "a", "6");
    shash_table_print(ht);
    shash_table_set(ht, "m", "7");
    shash_table_print(ht);
    shash_table_print_rev(ht);
        shash_table_delete(ht);
    return (EXIT_SUCCESS);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 100-main.c 100-sorted_hash_table.c 1-djb2.c 2-key_index.c -o sht  
$ ./sht 
{'y': '0'}
{'j': '1', 'y': '0'}
{'c': '2', 'j': '1', 'y': '0'}
{'b': '3', 'c': '2', 'j': '1', 'y': '0'}
{'b': '3', 'c': '2', 'j': '1', 'y': '0', 'z': '4'}
{'b': '3', 'c': '2', 'j': '1', 'n': '5', 'y': '0', 'z': '4'}
{'a': '6', 'b': '3', 'c': '2', 'j': '1', 'n': '5', 'y': '0', 'z': '4'}
{'a': '6', 'b': '3', 'c': '2', 'j': '1', 'm': '7', 'n': '5', 'y': '0', 'z': '4'}
{'z': '4', 'y': '0', 'n': '5', 'm': '7', 'j': '1', 'c': '2', 'b': '3', 'a': '6'}
```