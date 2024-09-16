# 0x05. C - Pointers, Arrays and Strings


## Resources
Read or watch:
- [C - Arrays](https://www.tutorialspoint.com/cprogramming/c_arrays.htm)
- [C - Pointers](https://www.tutorialspoint.com/cprogramming/c_pointers.htm)
- [C - Strings](https://www.tutorialspoint.com/cprogramming/c_strings.htm)
- [Memory Layout](https://aticleworld.com/memory-layout-of-c-program/)


### General

- What are pointers and how to use them.
- What are arrays and how to use them.
- What are the differences between pointers and arrays.
- How to use strings and how to manipulate them.
- Scope of variables.


## Tasks

### 0. 98 Battery st.
 
Write a function that takes a pointer to an `int` as parameter and updates the value it points to to 98.

**Prototype:** `void reset_to_98(int *n);`

```c
#include "main.h"
#include <stdio.h>

int main(void)
{
    int n;

    n = 402;
    printf("n=%d\n", n);
    reset_to_98(&n);
    printf("n=%d\n", n);
    return (0);
}
```
### 1. Don't swap horses in crossing a stream
Write a function that swaps the values of two integers.

**Prototype:** `void swap_int(int *a, int *b);`

```c
#include "main.h"
#include <stdio.h>

int main(void)
{
    int a;
    int b;

    a = 98;
    b = 42;
    printf("a=%d, b=%d\n", a, b);
    swap_int(&a, &b);
    printf("a=%d, b=%d\n", a, b);
    return (0);
}
```
### 2. This report, by its very length, defends itself against the risk of being read
Write a function that returns the length of a string.

**Prototype:** `int _strlen(char *s);`
FYI: The standard library provides a similar function: strlen. Run man strlen to learn more.

```c
#include "main.h"
#include <stdio.h>

int main(void)
{
    char *str;
    int len;

    str = "My first strlen!";
    len = _strlen(str);
    printf("%d\n", len);
    return (0);
}
```
### 3. I do not fear computers. I fear the lack of them
Write a function that prints a string, followed by a new line, to stdout.

**Prototype:** `void _puts(char *str);`

```c
#include "main.h"

int main(void)
{
    char *str;

    str = "I do not fear computers. I fear the lack of them - Isaac Asimov";
    _puts(str);
    return (0);
}
```
### 4. I can only go one way. I've not got a reverse gear
Write a function that prints a string, in reverse, followed by a new line.

**Prototype:** `void print_rev(char *s);`
```bash
$ cat 4-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *str;

    str = "I do not fear computers. I fear the lack of them - Isaac Asimov";
    print_rev(str);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 4-main.c 4-print_rev.c -o 4-print_rev
$ ./4-print_rev 
vomisA caasI - meht fo kcal eht raef I .sretupmoc raef ton od I
```
### 5. A good engineer thinks in reverse and asks himself about the stylistic consequences of the components and systems he proposes
Write a function that reverses a string.

**Prototype:** `void rev_string(char *s);`
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
    char s[10] = "My School";

    printf("%s\n", s);
    rev_string(s);
    printf("%s\n", s);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-main.c 5-rev_string.c -o 5-rev_string
$ ./5-rev_string 
My School
loohcS yM
```
### 6. Half the lies they tell about me aren't true
Write a function that prints every other character of a string, starting with the first character, followed by a new line.

**Prototype:** `void puts2(char *str);`
```bash
$ cat 6-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *str;

    str = "0123456789";
    puts2(str);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 6-main.c 6-puts2.c -o 6-puts2
$ ./6-puts2 
02468
```
### 7. Winning is only half of it. Having fun is the other half
Write a function that prints half of a string, followed by a new line.

**Prototype:** `void puts_half(char *str);`
The function should print the second half of the string
If the number of characters is odd, the function should print the last n characters of the string, where ``n = (length_of_the_string - 1) / 2``
```bash
$ cat 7-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *str;

    str = "0123456789";
    puts_half(str);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 7-main.c 7-puts_half.c -o 7-puts_half
$ ./7-puts_half 
56789
```
### 8. Arrays are not pointers
mandatory
Write a function that prints n elements of an array of integers, followed by a new line.

**Prototype:** `void print_array(int *a, int n);`
where n is the number of elements of the array to be printed
Numbers must be separated by comma, followed by a space
The numbers should be displayed in the same order as they are stored in the array
You are allowed to use printf
```bash
$ cat 8-main.c
#include "main.h"

/**
 * main - check the code for
 *
 * Return: Always 0.
 */
int main(void)
{
    int array[5];

    array[0] = 98;
    array[1] = 402;
    array[2] = -198;
    array[3] = 298;
    array[4] = -1024;
    print_array(array, 5);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 8-main.c 8-print_array.c -o 8-print_array
$ ./8-print_array 
98, 402, -198, 298, -1024
```
### 9. strcpy
**Prototype:** `char *_strcpy(char *dest, char *src);`
Write a function that copies the string pointed to by src, including the terminating null byte ``(\0)``, to the buffer pointed to by dest.

Return value: the pointer to dest
FYI: The standard library provides a similar function: strcpy. Run man strcpy to learn more.
```bash
$ cat 9-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char s1[98];
    char *ptr;

    ptr = _strcpy(s1, "First, solve the problem. Then, write the code\n");
    printf("%s", s1);
    printf("%s", ptr);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 9-main.c 9-strcpy.c -o 9-strcpy
$ ./9-strcpy 
First, solve the problem. Then, write the code
First, solve the problem. Then, write the code
```
### 10. Great leaders are willing to sacrifice the numbers to save the people. Poor leaders sacrifice the people to save the numbers
Write a function that convert a string to an integer.

**Prototype:** `int _atoi(char *s);`
- The number in the string can be preceded by an infinite number of characters
- You need to take into account all the - and + signs before the number
- If there are no numbers in the string, the function must return 0
- You are not allowed to use long
- You are not allowed to declare new variables of “type” array
- You are not allowed to hard-code special values
We will use the -fsanitize=signed-integer-overflow gcc flag to compile your code.
FYI: The standard library provides a similar function: atoi. Run man atoi to learn more.
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
    int nb;

    nb = _atoi("98");
    printf("%d\n", nb);
    nb = _atoi("-402");
    printf("%d\n", nb);
    nb = _atoi("          ------++++++-----+++++--98");
    printf("%d\n", nb);
    nb = _atoi("214748364");
    printf("%d\n", nb);
    nb = _atoi("0");
    printf("%d\n", nb);
    nb = _atoi("Suite 402");
    printf("%d\n", nb);
    nb = _atoi("         +      +    -    -98 Battery Street; San Francisco, CA 94111 - USA             ");
    printf("%d\n", nb);
    nb = _atoi("---++++ -++ Sui - te -   402 #cisfun :)");
    printf("%d\n", nb);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 -fsanitize=signed-integer-overflow 100-main.c 100-atoi.c -o 100-atoi
$ ./100-atoi 
98
-402
-98
214748364
0
402
98
402
```