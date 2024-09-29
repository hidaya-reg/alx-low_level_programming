# 0x0B. C - malloc, free

## Resources


[0x0a - malloc & free - quick overview.pdf](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/misc/2021/1/a094c90e7f466bbeaa49cb24c8f04e7f27aaad41.pdf?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20240928%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240928T145626Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=2833df37957bfb9e3cfb9cf3c7ae87109f7d66591a2df399ff722738e1381488)
[Dynamic memory allocation in C - malloc calloc realloc free](https://www.youtube.com/watch?v=xDVC3wKjS64&ab_channel=mycodeschool) (stop at 6:50)


## General
<details>
<summary>What is the difference between automatic and dynamic allocation</summary>

| Feature                  | Automatic Allocation                              | Dynamic Allocation                            |
|--------------------------|--------------------------------------------------|----------------------------------------------|
| **Timing**               | Allocated at compile time                        | Allocated at runtime                          |
| **Storage**              | Stack                                           | Heap                                         |
| **Lifetime**             | Exists for the duration of the block/function   | Exists until explicitly deallocated          |
| **Management**           | Automatically managed by the compiler           | Manually managed by the programmer           |
| **Flexibility**          | Fixed size determined at compile time            | Variable size can be allocated as needed     |

**Automatic Allocation**
```c
void example()
{
    int a = 10; // Automatically allocated
} // 'a' deallocated when function exits
```                                     
**Dynamic Allocation**
```c
void example()
{
    int *array = malloc(10 * sizeof(int));
    // Use the array
    free(array); // Must be explicitly allocated
}
```
</details>
<details>
<summary>What is malloc and free and how to use them</summary>

### Dynamic allocation
**Malloc**
The malloc function allocates a specific number of bytes in memory and returns a pointer to the allocated memory. This memory will have read and write permissions.

**Prototype:** ``void *malloc(size_t size);``
- where ``void *`` means it is a pointer to the type of your choice
- and ``size`` is the number of bytes your need to allocate
```bash
$ cat malloc_example.c 
#include <stdio.h>
#include <stdlib.h>

/**
 * main - introduction to malloc and free
 *
 * Return: 0.
 */
int main(void)
{
    char *str;

    str = malloc(sizeof(char) * 3);
    str[0] = 'O';
    str[1] = 'K';
    str[2] = '\0';
    printf("%s\n", str);
    return (0);
}
$ gcc malloc_example.c -o m
$ ./m
OK
```
Note the use the operator ``sizeof``. It is very important because as you know, the size of the different types will be different on different machines: we want 3 times the size of a ``char`` (which happens to be 3 times 1 byte on our 64-bit machine). Always use ``sizeof`` for a better portability.

**Free**
When you are using ``malloc``, you have to handle the memory yourself. This means that:

- You need to keep track of all the addresses of the allocated memory (in a variable of type pointer)
- You have to deallocate every memory space you previously allocated yourself. If you do not do this, then your program can run out of memory. Your operating system could even kill your program while it is running
```bash
julien@ubuntu:~/c/malloc$ cat while_malloc.c 
#include <stdio.h>
#include <stdlib.h>

/**
 * main - introduction to malloc and free
 *
 * Return: 0.
 */
int main(void)
{
    while (1)
    {
        malloc(sizeof(char) * 1024);
    }
    return (0);
}
julien@ubuntu:~/c/malloc$ gcc while_malloc.c -o killme
julien@ubuntu:~/c/malloc$ ./killme 
Killed
```

The ``free`` function frees the memory space which have been allocated by a previous call to ``malloc`` (or ``calloc``, or ``realloc``).

**Prototype:** ``void free(void *ptr);``
- where ``ptr`` is the address of the memory space previously allocated by and returned by a call to ``malloc``
```bash
$ cat free_mem.c
#include <stdio.h>
#include <stdlib.h>

/**
 * m - stores 3 int in a new allocated space in memory and prints the sum
 * @n0: integer to store and print
 * @n1: integer to store and print
 * @n2: integer to store and print
 *
 * Return: nothing
 */
void m(int n0, int n1, int n2)
{
    int *t;
    int sum;

    t = malloc(sizeof(*t) * 3);
    t[0] = n0;
    t[1] = n1;
    t[2] = n2;
    sum = t[0] + t[1] + t[2];
    printf("%d + %d + %d = %d\n", t[0], t[1], t[2], sum);
    free(t);
}

/**
 * main - introduction to malloc and free
 *
 * Return: 0.
 */
int main(void)
{
    m(98, 402, -1024);
    return (0);
}
```
In the above example, the memory allocated by ``malloc`` is ``free``‘d with a call to the function ``free``.

You should always ``free`` all ``malloc``'ed memory spaces.
</details>
<details>
<summary>How to use valgrind to check for memory leak</summary>

**Valgrind**
When writing big and complex programs, it is not always easy to keep track of all allocated and deallocated memory. We can use the program [Valgrind](https://valgrind.org/) in order to ensure we are freeing all allocated memory. It is a programming tool for memory debugging, memory leak detection, and profiling.
```bash
$ cat malloc_mem.c
#include <stdio.h>
#include <stdlib.h>

/**
 * m - stores 3 int in a new allocated space in memory and prints the sum
 * @n0: integer to store and print
 * @n1: integer to store and print
 * @n2: integer to store and print
 *
 * Return: nothing
 */
void m(int n0, int n1, int n2)
{
    int *t;
    int sum;

    t = malloc(sizeof(*t) * 3);
    t[0] = n0;
    t[1] = n1;
    t[2] = n2;
    sum = t[0] + t[1] + t[2];
    printf("%d + %d + %d = %d\n", t[0], t[1], t[2], sum);
}

/**
 * main - introduction to malloc and free
 *
 * Return: 0.
 */
int main(void)
{
    m(98, 402, -1024);
    return (0);
}
$ gcc malloc_mem.c -o m
$ valgrind ./m
==3749== Memcheck, a memory error detector
==3749== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==3749== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==3749== Command: ./m
==3749== 
98 + 402 + -1024 = -524
==3749== 
==3749== HEAP SUMMARY:
==3749==     in use at exit: 12 bytes in 1 blocks
==3749==   total heap usage: 2 allocs, 1 frees, 1,036 bytes allocated
==3749== 
==3749== LEAK SUMMARY:
==3749==    **definitely lost: 12 bytes in 1 blocks**
==3749==    indirectly lost: 0 bytes in 0 blocks
==3749==      possibly lost: 0 bytes in 0 blocks
==3749==    still reachable: 0 bytes in 0 blocks
==3749==         suppressed: 0 bytes in 0 blocks
==3749== Rerun with --leak-check=full to see details of leaked memory
==3749== 
==3749== For counts of detected and suppressed errors, rerun with: -v
==3749== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
In the above example, we **definitely lost: 12 bytes in 1 blocks.**
```bash
$ cat free_mem.c
#include <stdio.h>
#include <stdlib.h>

/**
 * m - stores 3 int in a new allocated space in memory and prints the sum
 * @n0: integer to store and print
 * @n1: integer to store and print
 * @n2: integer to store and print
 *
 * Return: nothing
 */
void m(int n0, int n1, int n2)
{
    int *t;
    int sum;

    t = malloc(sizeof(*t) * 3);
    t[0] = n0;
    t[1] = n1;
    t[2] = n2;
    sum = t[0] + t[1] + t[2];
    printf("%d + %d + %d = %d\n", t[0], t[1], t[2], sum);
    free(t);
}

/**
 * main - introduction to malloc and free
 *
 * Return: 0.
 */
int main(void)
{
    m(98, 402, -1024);
    return (0);
}
julien@ubuntu:~/c/malloc$ gcc free_mem.c -o f
julien@ubuntu:~/c/malloc$ valgrind ./f
==3763== Memcheck, a memory error detector
==3763== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==3763== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==3763== Command: ./f
==3763== 
98 + 402 + -1024 = -524
==3763== 
==3763== HEAP SUMMARY:
==3763==     in use at exit: 0 bytes in 0 blocks
==3763==   total heap usage: 2 allocs, 2 frees, 1,036 bytes allocated
==3763== 
==3763== All heap blocks were freed -- no leaks are possible
==3763== 
==3763== For counts of detected and suppressed errors, rerun with: -v
==3763== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
``` 

In the above example, we get All heap blocks were freed – no leaks are possible. This is what you should always aim for.

**Don’t trust anyone**
On error, ``malloc`` returns ``NULL``. As for any other C library function, you should always check the ``malloc`` return value before using it. If you don’t you will run into segfaults.
```bash
$ cat malloc_segf.c
#include <stdlib.h>
#include <limits.h>

/**
 * main - introduction to malloc and free
 *
 * Return: 0.
 */
int main(void)
{
    char *s;

    while (1)
    {
        s = malloc(INT_MAX);
        s[0] = 'H';
    }
    return (0);
}
$ gcc malloc_segf.c -o s
$ ./s
Segmentation fault (core dumped)
```
This is an example on how to check the return value of malloc:
```bash
$ cat malloc_check.c
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

/**
 * main - introduction to malloc and free
 *
 * Return: 0.
 */
int main(void)
{
    char *s;
    int i;

    i = 0;
    while (1)
    {
        s = malloc(INT_MAX);
        if (s == NULL)
        {
            printf("Can't allocate %d bytes (after %d calls)\n", INT_MAX, i);
            return (1);
        }
        s[0] = 'H';
        i++;
    }
    return (0);
}
$ gcc malloc_check.c -o c
$ ./c
Can't allocate 2147483647 bytes (after 0 calls)
```
</details>

## Tasks
### 0. Float like a butterfly, sting like a bee

Write a function that creates an array of chars, and initializes it with a specific char.

**Prototype:** ``char *create_array(unsigned int size, char c);``
- Returns ``NULL`` if size = ``0``
- Returns a pointer to the array, or ``NULL`` if it fails
```bash
$ cat 0-main.c 
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of memory to print
 * @size: the size of the memory to print
 *
 * Return: Nothing.
 */
void simple_print_buffer(char *buffer, unsigned int size)
{
    unsigned int i;

    i = 0;
    while (i < size)
    {
        if (i % 10)
        {
            printf(" ");
        }
        if (!(i % 10) && i)
        {
            printf("\n");
        }
        printf("0x%02x", buffer[i]);
        i++;
    }
    printf("\n");
}

/**
 * main - check the code for ALX School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *buffer;

    buffer = create_array(98, 'H');
    if  (buffer == NULL)
    {
        printf("failed to allocate memory\n");
        return (1);
    }
    simple_print_buffer(buffer, 98);
    free(buffer);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-create_array.c -o a
$ ./a 
0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48
0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48
0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48
0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48
0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48
0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48
0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48
0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48
0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48
0x48 0x48 0x48 0x48 0x48 0x48 0x48 0x48
```
### 1. The woman who has no imagination has no wings
Write a function that returns a pointer to a newly allocated space in memory, which contains a copy of the string given as a parameter.

**Prototype:** ``char *_strdup(char *str);``
- The ``_strdup()`` function returns a pointer to a new string which is a duplicate of the string ``str``. Memory for the new string is obtained with ``malloc``, and can be freed with ``free``.
- Returns ``NULL`` if str = NULL
- On success, the ``_strdup`` function returns a pointer to the duplicated string. It returns ``NULL`` if insufficient memory was available
FYI: The standard library provides a similar function: ``strdup``.
```bash
$ cat 1-main.c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code for ALX School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s;

    s = _strdup("ALX SE");
    if (s == NULL)
    {
        printf("failed to allocate memory\n");
        return (1);
    }
    printf("%s\n", s);
    free(s);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-strdup.c -o s
$ ./s 
ALX SE
```
### 2. He who is not courageous enough to take risks will accomplish nothing in life
Write a function that concatenates two strings.

**Prototype:** ``char *str_concat(char *s1, char *s2);``
- The returned pointer should point to a newly allocated space in memory which contains the contents of ``s1``, followed by the contents of ``s2``, and null terminated
- if ``NULL`` is passed, treat it as an empty string
The function should return ``NULL`` on failure
```bash
$ cat 2-main.c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code for ALX School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s;

    s = str_concat("Betty ", "Holberton");
    if (s == NULL)
    {
        printf("failed\n");
        return (1);
    }
    printf("%s\n", s);
    free(s);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-str_concat.c -o c
julien@ubuntu:~/c/curriculum_by_julien/holbertonschool-low_level_programming/0x0a. $ ./c | cat -e
Betty Holberton$
```
### 3. If you even dream of beating me you'd better wake up and apologize

Write a function that returns a pointer to a 2 dimensional array of integers.

**Prototype:** ``int **alloc_grid(int width, int height);``
- Each element of the grid should be initialized to ``0``
- The function should return ``NULL`` on failure
- If ``width`` or ``height`` is `0` or negative, return ``NULL``
```bash
$ cat 3-main.c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_grid - prints a grid of integers
 * @grid: the address of the two dimensional grid
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: Nothing.
 */
void print_grid(int **grid, int width, int height)
{
    int w;
    int h;

    h = 0;
    while (h < height)
    {
        w = 0;
        while (w < width)
        {
            printf("%d ", grid[h][w]);
            w++;
        }
        printf("\n");
        h++;
    }   
}

/**
 * main - check the code for ALX School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    int **grid;

    grid = alloc_grid(6, 4);
    if (grid == NULL)
    {
        return (1);
    }
    print_grid(grid, 6, 4);
    printf("\n");
    grid[0][3] = 98;
    grid[3][4] = 402;
    print_grid(grid, 6, 4);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-alloc_grid.c -o g
$ ./g
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 

0 0 0 98 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 402 0 
```
### 4. It's not bragging if you can back it up
Write a function that frees a 2 dimensional grid previously created by your ``alloc_grid`` function.

**Prototype:** ``void free_grid(int **grid, int height);``
- Note that we will compile with your ``alloc_grid.c`` file. Make sure it compiles.
```bash
$ cat 4-main.c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_grid - prints a grid of integers
 * @grid: the address of the two dimensional grid
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: Nothing.
 */
void print_grid(int **grid, int width, int height)
{
    int w;
    int h;

    h = 0;
    while (h < height)
    {
        w = 0;
        while (w < width)
        {
            printf("%d ", grid[h][w]);
            w++;
        }
        printf("\n");
        h++;
    }   
}

/**
 * main - check the code for ALX School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    int **grid;

    grid = alloc_grid(6, 4);
    if (grid == NULL)
    {
        return (1);
    }
    print_grid(grid, 6, 4);
    printf("\n");
    grid[0][3] = 98;
    grid[3][4] = 402;
    print_grid(grid, 6, 4);
    free_grid(grid, 4);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 3-alloc_grid.c 4-free_grid.c -o f
$ valgrind ./f
==5013== Memcheck, a memory error detector
==5013== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==5013== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==5013== Command: ./f
==5013== 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 

0 0 0 98 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 402 0 
==5013== 
==5013== HEAP SUMMARY:
==5013==     in use at exit: 0 bytes in 0 blocks
==5013==   total heap usage: 6 allocs, 6 frees, 1,248 bytes allocated
==5013== 
==5013== All heap blocks were freed -- no leaks are possible
==5013== 
==5013== For counts of detected and suppressed errors, rerun with: -v
==5013== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
  
### 5. It isn't the mountains ahead to climb that wear you out; it's the pebble in your shoe
Write a function that concatenates all the arguments of your program.

**Prototype:** ``char *argstostr(int ac, char **av);``
- Returns ``NULL`` if ``ac == 0`` or ``av == NULL``
- Returns a pointer to a new string, or ``NULL`` if it fails
Each argument should be followed by a ``\n`` in the new string
```bash
$ cat 100-main.c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code for ALX School students.
 *
 * Return: Always 0.
 */
int main(int ac, char *av[])
{
    char *s;

    s = argstostr(ac, av);
    if (s == NULL)
    {
        return (1);
    }
    printf("%s", s);
    free(s);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 100-main.c 100-argstostr.c -o args
$ ./args I will "show you" how great I am
./args
I
will
show you
how
great
I
am
```  
### 6. I will show you how great I am
Write a function that splits a string into words.

**Prototype:** ``char **strtow(char *str);``
- The function returns a pointer to an array of strings (words)
- Each element of this array should contain a single word, null-terminated
- The last element of the returned array should be ``NULL``
- Words are separated by spaces
- Returns ``NULL`` if ``str == NULL`` or ``str == ""``
- If your function fails, it should return ``NULL``

```bash
$ cat 101-main.c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_tab - Prints an array of string
 * @tab: The array to print
 *
 * Return: nothing
 */
void print_tab(char **tab)
{
    int i;

    for (i = 0; tab[i] != NULL; ++i)
    {
        printf("%s\n", tab[i]);
    }
}

/**
 * main - check the code for ALX School students.
 *
 * Return: 1 if an error occurred, 0 otherwise
 */
int main(void)
{
    char **tab;

    tab = strtow("      ALX School         #cisfun      ");
    if (tab == NULL)
    {
        printf("Failed\n");
        return (1);
    }
    print_tab(tab);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 101-main.c 101-strtow.c -o strtow
$ ./strtow | cat -e
ALX$
School$
#cisfun$
```