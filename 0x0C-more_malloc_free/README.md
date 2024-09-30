# 0x0C. C - More malloc, free
## General
<details>
<summary>How to use the exit function</summary>
The ``exit`` function in C is used to terminate a program and can be included from the ``<stdlib.h>`` header. It allows you to specify an exit status, which can be useful for indicating whether the program completed successfully or encountered an error.
#### Syntax
```c
#include <stdlib.h>

void exit(int status);
```
**status:** An integer value that is returned to the operating system. By convention, a status of ``0`` indicates success, while a non-zero value indicates an error.
#### Example
```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num;

    printf("Enter a positive number: ");
    if (scanf("%d", &num) != 1 || num < 0) {
        fprintf(stderr, "Error: Invalid input.\n");
        exit(1); // Exit with a non-zero status indicating an error
    }

    printf("You entered: %d\n", num);
    exit(0); // Exit successfully
}
```

#### Key Points
- **Include** ``<stdlib.h>``: Always include this header to use ``exit``.
- **Use for Error Handling:** Use non-zero status codes to indicate errors, which can be helpful in scripts or programs that check for successful execution.
- **Immediate Termination:** ``exit`` terminates the program immediately, so any code after it won't execute.
- **Cleanup:** Any cleanup functions registered with ``atexit()`` will be called before the program exits.
#### return vs exit

| Feature                     | `exit`                                   | `return`                                  |
|-----------------------------|------------------------------------------|-------------------------------------------|
| **Context of Use**          | Can be called from anywhere              | Typically used within functions           |
| **Exit Status**             | Takes an integer status code             | Returns an integer value (in `main`)     |
| **Cleanup**                 | Calls functions registered with `atexit()` | Cleanup happens when `main` returns      |
| **Scope**                   | Terminates the entire program            | Exits only the current function           |
| **Further Code Execution**   | No further code executes after `exit`   | Code after `return` in the caller continues |

### Example code 
```c
#include <stdio.h>
#include <stdlib.h>

void someFunction() {
    printf("Exiting from someFunction using exit.\n");
    exit(1); // Terminates the program immediately
}

int main() {
    printf("This will print.\n");
    
    // Call someFunction which will call exit
    someFunction();
    
    // This line will not execute
    printf("This will not print.\n");

    return 0; // This won't be reached
}
```
</details>
<details>
<summary>What are the functions calloc and realloc from the standard library and how to use them</summary>
``calloc`` and ``realloc`` are memory management functions from the C standard library that are used to allocate and manage dynamic memory.

#### ``calloc``
- **Purpose:** Allocates memory for an array of elements, initializing all bytes to zero.

- **Prototype:**
    ```c
    void *calloc(size_t num, size_t size);
    ```
- **Parameters:**
    + ``num``: Number of elements to allocate.
    + ``size``: Size of each element in bytes.
- **Return Value:** Returns a pointer to the allocated memory if successful, or ``NULL`` if the allocation fails.

**Usage Example:**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    size_t n = 5;

    // Allocate memory for an array of 5 integers
    arr = calloc(n, sizeof(int));
    if (arr == NULL) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    // Print initialized values
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]); // All should be 0
    }
    printf("\n");

    free(arr); // Free the allocated memory
    return EXIT_SUCCESS;
}
```
#### ``realloc``
- **Purpose:** Resizes previously allocated memory, potentially moving it to a new location.

- **Prototype:**

    ```c
    void *realloc(void *ptr, size_t size);
    ```
- **Parameters:**
    + ``ptr``: Pointer to the previously allocated memory block.
    + ``size``: New size for the memory block in bytes.
- **Return Value:** Returns a pointer to the reallocated memory if successful. If the function fails, it returns ``NULL``, and the original block remains unchanged.

**Usage Example:**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    size_t n = 5;

    // Allocate memory for 5 integers
    arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    // Initialize array
    for (size_t i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // Resize the array to hold 10 integers
    n = 10;
    arr = realloc(arr, n * sizeof(int));
    if (arr == NULL) {
        perror("Failed to reallocate memory");
        return EXIT_FAILURE;
    }

    // Print new size
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]); // First 5 will have values, the rest will be uninitialized
    }
    printf("\n");

    free(arr); // Free the allocated memory
    return EXIT_SUCCESS;
}
```
#### malloc vs calloc vs realloc
| Function   | Description                                           | Parameters                    | Return Value                     |
|------------|-------------------------------------------------------|-------------------------------|----------------------------------|
| `malloc`   | Allocates a specified number of bytes                | `size_t size`                | Pointer to allocated memory, or `NULL` on failure |
| `calloc`   | Allocates memory for an array and initializes it to zero | `size_t num, size_t size`    | Pointer to allocated memory, or `NULL` on failure |
| `realloc`  | Resizes a previously allocated memory block          | `void *ptr, size_t size`     | Pointer to reallocated memory, or `NULL` on failure (original pointer is unchanged if failed) |

**Key Points:**
- **Initialization:** ``malloc`` does not initialize memory, while ``calloc`` initializes all bytes to zero.
- **Resizing:** ``realloc`` can increase or decrease the size of an existing memory block.
- **Return Behavior:** Both ``malloc`` and ``calloc`` return ``NULL`` on failure, and realloc will return ``NULL`` without freeing the original pointer if it fails.
</details>

## Tasks
### 0. Trust no one
Write a function that allocates memory using ``malloc``.

**Prototype:** ``void *malloc_checked(unsigned int b);``
- Returns a pointer to the allocated memory
- if ``malloc`` fails, the ``malloc_checked`` function should cause normal process termination with a status value of ``98``
```bash
$ cat 0-main.c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *c;
    int *i;
    float *f;
    double *d;

    c = malloc_checked(sizeof(char) * 1024);
    printf("%p\n", (void *)c);
    i = malloc_checked(sizeof(int) * 402);
    printf("%p\n", (void *)i);
    f = malloc_checked(sizeof(float) * 100000000);
    printf("%p\n", (void *)f);
    d = malloc_checked(INT_MAX);
    printf("%p\n", (void *)d);
    free(c);
    free(i);
    free(f);
    free(d);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-malloc_checked.c -o a
$ ./a 
0x1e39010
0x1e39830
0x7f31f6c19010
$ echo $?
98
```
  
### 1. string_nconcat
Write a function that concatenates two strings.

**Prototype:** ``char *string_nconcat(char *s1, char *s2, unsigned int n);``
- The returned pointer shall point to a newly allocated space in memory, which contains ``s1``, followed by the first ``n`` bytes of ``s2``, and null terminated
- If the function fails, it should return ``NULL``
- If ``n`` is greater or equal to the length of ``s2`` then use the entire string ``s2``
- if ``NULL`` is passed, treat it as an empty string
```bash
$ cat 1-main.c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *concat;

    concat = string_nconcat("Best ", "School !!!", 6);
    printf("%s\n", concat);
    free(concat);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-string_nconcat.c -o 1-string_nconcat
$ ./1-string_nconcat
Best School
```
### 2. _calloc
Write a function that allocates memory for an array, using ``malloc``.

**Prototype:** ``void *_calloc(unsigned int nmemb, unsigned int size);``
- The ``_calloc`` function allocates memory for an array of ``nmemb`` elements of ``size`` bytes each and returns a pointer to the allocated memory.
- The memory is set to zero
- If ``nmemb`` or ``size`` is ``0``, then ``_calloc`` returns ``NULL``
- If ``malloc`` fails, then ``_calloc`` returns ``NULL``
FYI: The standard library provides a different function: ``calloc``.
```bash
$ cat 2-main.c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char *a;

    a = _calloc(98, sizeof(char));
    strcpy(a, "Best");
    strcpy(a + 4, " School! :)\n");
    a[97] = '!';
    simple_print_buffer(a, 98);
    free(a);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-calloc.c -o 2-calloc
$ ./2-calloc
0x42 0x65 0x73 0x74 0x20 0x53 0x63 0x68 0x6f 0x6f
0x6c 0x21 0x20 0x3a 0x29 0x0a 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x21
```

### 3. array_range
Write a function that creates an array of integers.

**Prototype:** ``int *array_range(int min, int max);``
- The array created should contain all the values from ``min`` (included) to ``max`` (included), ordered from ``min`` to ``max``
- Return: the pointer to the newly created array
- If ``min > max,`` return ``NULL``
- If ``malloc`` fails, return ``NULL``
```bash
$ cat 3-main.c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of memory to print
 * @size: the size of the memory to print
 *
 * Return: Nothing.
 */
void simple_print_buffer(int *buffer, unsigned int size)
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
    int *a;

    a = array_range(0, 10);
    simple_print_buffer(a, 11);
    free(a);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-array_range.c -o 3-array_range
$ ./3-array_range
0x00 0x01 0x02 0x03 0x04 0x05 0x06 0x07 0x08 0x09
0x0a
```
### 4. _realloc
Write a function that reallocates a memory block using ``malloc`` and ``free``

**Prototype:** ``void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);``
- where ``ptr`` is a pointer to the memory previously allocated with a call to ``malloc``: ``malloc(old_size)``
- ``old_size`` is the size, in bytes, of the allocated space for ``ptr``
- and ``new_size`` is the new size, in bytes of the new memory block
- The contents will be copied to the newly allocated space, in the range from the start of ``ptr`` up to the minimum of the old and new sizes
- If ``new_size > old_size``, the “added” memory should not be initialized
- If ``new_size == old_size`` do not do anything and return ``ptr``
- If ``ptr`` is ``NULL``, then the call is equivalent to ``malloc(new_size)``, for all values of ``old_size`` and ``new_size``
- If ``new_size`` is equal to zero, and ``ptr`` is not ``NULL``, then the call is equivalent to ``free(ptr)``. Return ``NULL``
- Don’t forget to ``free`` ``ptr`` when it makes sense
FYI: The standard library provides a different function: ``realloc``.
```bash
$ cat 100-main.c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 * main - check the code for
 *
 * Return: Always 0.
 */
int main(void)
{
    char *p;
    int i;

    p = malloc(sizeof(char) * 10);
    p = _realloc(p, sizeof(char) * 10, sizeof(char) * 98);
    i = 0;
    while (i < 98)
    {
        p[i++] = 98;
    }
    simple_print_buffer(p, 98);
    free(p);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 100-main.c 100-realloc.c -o 100-realloc
$ ./100-realloc
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
```

### 5. We must accept finite disappointment, but never lose infinite hope
Write a program that multiplies two positive numbers.

- ``Usage: mul num1 num2``
- ``num1`` and ``num2`` will be passed in base 10
- Print the result, followed by a new line
- If the number of arguments is incorrect, print ``Error``, followed by a new line, and exit with a status of ``98``
- ``num1`` and ``num2`` should only be composed of digits. If not, print ``Error``, followed by a new line, and exit with a status of ``98``
-You are allowed to use more than 5 functions in your file
You can use ``bc`` (``man bc``) to check your results.
```bash
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 101-mul.c _putchar.c -o 101-mul
$ ./101-mul 10 98
980
$ ./101-mul 235234693269436436223446526546334576437634765378653875874687649698659586695898579 28658034365084365083426083109679137608216408631430814308651084650816406134060831608310853086103769013709675067130586570832760732096730978014607369739567864508634086304807450973045703428580934825098342095832409850394285098342509834209583425345267413639235755891879970464524226159074760914989935413350556875770807019893069201247121855122836389417022552166316010013074258781583143870461182707893577849408672040555089482160343085482612348145322689883025225988799452329290281169927532160590651993511788518550547570284574715925006962738262888617840435389140329668772644708
6741363923575589187997046452422615907476091498993541335055687577080701989306920124712185512283638941702255216631601001307425878158314387046118270789357784940867204055508948216034308548261234814532268988302522598879945232929028116992753216059081057377926651337612618248332113256902485974371969385156015068813868274000683912187818601667058605418678284322237297213673482412392922068159291496274311170208689056585352782844484721140846367741649962638649229509281867896067208474178402156294978940712959518351846413859141792380853313812015295333546716634344284086426775480775747808150030732119704867805688704303461042373101473485092019906795014369069932
```