# 0x07. C - Even more pointers, arrays and strings


### Struggling with the sandbox? 
Try this: Using Docker & WSL on your local host

## Resources
Read or watch:
- [C - Pointer to Pointer](https://www.tutorialspoint.com/cprogramming/c_pointer_to_pointer.htm)
- [C – Pointer to Pointer with example](https://beginnersbook.com/2014/01/c-pointer-to-pointer/)
- [Multi-dimensional Arrays in C](https://www.tutorialspoint.com/cprogramming/c_multi_dimensional_arrays.htm)
- [Two dimensional (2D) arrays in C programming with example](https://beginnersbook.com/2014/01/2d-arrays-in-c-example/)


## Learning Objectives
At the end of this project, you should be able to explain:
<details>
 <summary>What pointers to pointers are and how to use them</summary>
 Pointers to pointers are variables that store the address of another pointer. They allow for multi-level indirection, enabling more complex data structures, such as dynamically allocated arrays of pointers.
 ```c
int x = 10;
int *p = &x;      // p points to x
int **pp = &p;    // pp points to p
```
 </details>
 <details>
<summary>What multidimensional arrays are and how to use them</summary>
Multidimensional arrays are arrays that have more than one dimension, allowing you to store data in a grid-like format. The most common type is a two-dimensional array, which can be visualized as a table with rows and columns.

**Declaration and Initialization**
Here's how you can declare and initialize a two-dimensional array:

```c
#include <stdio.h>

int main() {
    int array[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Accessing elements
    printf("Element at [1][2]: %d\n", array[1][2]); // Output: 7

    // Modifying elements
    array[0][0] = 10;

    // Looping through the array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

**Dynamic Allocation**
For dynamic multidimensional arrays, you can use pointers:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3, cols = 4;
    int **array = malloc(rows * sizeof(int *)); // Allocate rows

    for (int i = 0; i < rows; i++) {
        array[i] = malloc(cols * sizeof(int)); // Allocate columns
    }

    // Fill the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = i * cols + j + 1; // Example values
        }
    }

    // Print the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
```
</details>
<details>
<summary>What are the most common C standard library functions to manipulate strings </summary>

| Function      | Prototype                                        | Description                                                                                      |
|---------------|--------------------------------------------------|--------------------------------------------------------------------------------------------------|
| `strlen`      | `size_t strlen(const char *str);`               | Returns the length of the string (excluding the null terminator).                              |
| `strcpy`      | `char *strcpy(char *dest, const char *src);`   | Copies the string from `src` to `dest`.                                                         |
| `strncpy`     | `char *strncpy(char *dest, const char *src, size_t n);` | Copies up to `n` characters from `src` to `dest`, padding with null bytes if `src` is shorter. |
| `strcat`      | `char *strcat(char *dest, const char *src);`   | Appends the string `src` to the end of `dest`.                                                 |
| `strncat`     | `char *strncat(char *dest, const char *src, size_t n);` | Appends up to `n` characters from `src` to the end of `dest`.                                   |
| `strcmp`      | `int strcmp(const char *str1, const char *str2);` | Compares two strings. Returns 0 if they are equal, negative if `str1 < str2`, positive if greater. |
| `strncmp`     | `int strncmp(const char *str1, const char *str2, size_t n);` | Compares up to `n` characters of two strings.                                                   |
| `strchr`      | `char *strchr(const char *str, int c);`        | Finds the first occurrence of character `c` in `str`.                                          |
| `strstr`      | `char *strstr(const char *haystack, const char *needle);` | Locates the first occurrence of substring `needle` in `haystack`.                              |
| `strtok`      | `char *strtok(char *str, const char *delim);`  | Tokenizes a string based on specified delimiters. The first call provides the string; subsequent calls use `NULL`. |

</details>


## Tasks

### 0. memset
Write a function that fills memory with a constant byte.

**Prototype:** `char *_memset(char *s, char b, unsigned int n);`  
The `_memset()` function fills the first `n` bytes of the memory area pointed to by `s` with the constant byte `b` and returns a pointer to the memory area `s`.

**FYI:** The standard library provides a similar function: `memset`.

```bash
7$ cat 0-main.c
#include "main.h"
#include <stdio.h>

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
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char buffer[98] = {0x00};

    simple_print_buffer(buffer, 98);
    _memset(buffer, 0x01, 95);
    printf("-------------------------------------------------\n");
    simple_print_buffer(buffer, 98);    
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-memset.c -o 0-memset
$ ./0-memset 
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
-------------------------------------------------
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x00 0x00 0x00
```
### 1. memcpy
Write a function that copies memory area.

**Prototype**: ``char *_memcpy(char *dest, char *src, unsigned int n);``
- The ``_memcpy()`` function copies ``n`` bytes from memory area ``src`` to memory area ``dest``
- Returns a pointer to ``dest``
FYI: The standard library provides a similar function: memcpy. 
```bash
$ cat 1-main.c
#include "main.h"
#include <stdio.h>

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
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char buffer[98] = {0};
    char buffer2[98] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    simple_print_buffer(buffer, 98);
    _memcpy(buffer + 50, buffer2, 10);
    printf("-------------------------------------------------\n");
    simple_print_buffer(buffer, 98);    
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-memcpy.c -o 1-memcpy
$ ./1-memcpy 
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
-------------------------------------------------
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x01 0x02 0x03 0x04 0x05 0x07 0x07 0x08 0x09 0x0a
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
```
### 2. strchr

Write a function that locates a character in a string.

- **Prototype**: ``char *_strchr(char *s, char c);``
- Returns a pointer to the first occurrence of the character c in the string s, or NULL if the character is not found
FYI: The standard library provides a similar function: ``strchr``. 
```bash
$ cat 2-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s = "hello";
    char *f;

    f = _strchr(s, 'l');

    if (f != NULL)
    {
        printf("%s\n", f);
    }
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-strchr.c -o 2-strchr
$ ./2-strchr 
llo
```
### 3. strspn
Write a function that gets the length of a prefix substring.

- **Prototype**: unsigned ``int _strspn(char *s, char *accept);``
- Returns the number of bytes in the initial segment of ``s`` which consist only of bytes from ``accept``
FYI: The standard library provides a similar function: ``strspn``. Run man strspn to learn more.
```bash
$ cat 3-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s = "hello, world";
    char *f = "oleh";
    unsigned int n;

    n = _strspn(s, f);
    printf("%u\n", n);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-strspn.c -o 3-strspn
$ ./3-strspn 
5
```
### 4. strpbrk
Write a function that searches a string for any of a set of bytes.
- **Prototype**: ``char *_strpbrk(char *s, char *accept);``
- The ``_strpbrk()`` function locates the first occurrence in the string ``s`` of any of the bytes in the string ``accept``
- Returns a pointer to the byte in s that matches one of the bytes in ``accept``, or ``NULL`` if no such byte is found
FYI: The standard library provides a similar function: ``strpbrk``.
```bash
$ cat 4-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s = "hello, world";
    char *f = "world";
    char *t;

    t = _strpbrk(s, f);
    printf("%s\n", t);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 4-strpbrk.c -o 4-strpbrk
$ ./4-strpbrk 
llo, world
```  
### 5. strstr
Write a function that locates a substring.
- **Prototype**: ``char *_strstr(char *haystack, char *needle);``
- The ``_strstr()`` function finds the first occurrence of the substring ``needle`` in the string ``haystack``. The terminating null bytes (``\0``) are not compared
- Returns a pointer to the beginning of the located substring, or NULL if the substring is not found.
FYI: The standard library provides a similar function: ``strstr``. 
```bash
$ cat 5-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s = "hello, world";
    char *f = "world";
    char *t;

    t = _strstr(s, f);
    printf("%s\n", t);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-main.c 5-strstr.c -o 5-strstr
$ ./5-strstr 
world
```
### 6. Chess is mental torture
Write a function that prints the chessboard.
- **Prototype**: void print_chessboard(char (*a)[8]);
```bash
$ cat 7-main.c 
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char board[8][8] = {
        {'r', 'k', 'b', 'q', 'k', 'b', 'k', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'K', 'B', 'Q', 'K', 'B', 'K', 'R'},
    };
    print_chessboard(board);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 7-main.c 7-print_chessboard.c -o 7-print_chessboard
$ ./7-print_chessboard 
rkbqkbkr
pppppppp




PPPPPPPP
RKBQKBKR
```  
### 7. The line of life is a ragged diagonal between duty and desire
Write a function that prints the sum of the two diagonals of a square matrix of integers.
- **Prototype**: ``void print_diagsums(int *a, int size);``
- Format: see example
- You are allowed to use the standard library
Note that in the following example we are casting an ``int[][]`` into an ``int*``. This is not something you should do. The goal here is to make sure you understand how an array of array is stored in memory.
```bash
$ cat 8-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int c3[3][3] = {
        {0, 1, 5},
        {10, 11, 12},
        {1000, 101, 102},
    };
    int c5[5][5] = {
        {0, 1, 5, 12124, 1234},
        {10, 11, 12, 123521, 12512},
        {1000, 101, 102, 12545, 214543435},
        {100, 1012451, 11102, 12545, 214543435},
        {10, 12401, 10452, 11542545, 1214543435},
    };
    print_diagsums((int *)c3, 3);
    print_diagsums((int *)c5, 5);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 8-main.c 8-print_diagsums.c -o 8-print_diagsums
$ ./8-print_diagsums 
113, 1016
1214556093, 1137318
```
### 8. Double pointer, double fun
Write a function that sets the value of a pointer to a char.
**Prototype**: ``void set_string(char **s, char *to);``
```bash
$ cat 100-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s0 = "Bob Dylan";
    char *s1 = "Robert Allen";

    printf("%s, %s\n", s0, s1);
    set_string(&s1, s0);
    printf("%s, %s\n", s0, s1);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 100-main.c 100-set_string.c -o 100-set_string
$ ./100-set_string 
Bob Dylan, Robert Allen
Bob Dylan, Bob Dylan
```
### 9. My primary goal of hacking was the intellectual curiosity, the seduction of adventure
Create a file that contains the password for the [crackme2](https://github.com/alx-tools/0x06.c) executable.

- Your file should contain the exact password, no new line, no extra space
- ``ltrace``, ``ldd``, ``gdb`` and ``objdump`` can help
- You may need to install the ``openssl`` library to run the ``crakme2`` program: ``sudo apt install libssl-dev``
- Edit the source list ``sudo nano /etc/apt/sources.list`` to add the following line: ``deb http://security.ubuntu.com/ubuntu xenial-security main`` Then ``sudo apt update and sudo apt install libssl1.0.0``