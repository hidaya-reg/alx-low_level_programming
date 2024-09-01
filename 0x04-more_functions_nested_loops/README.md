# 0x04. C - More functions, more nested loops

## Overview
This project focuses on deeper understanding of functions and nested loops in C. It includes a series of tasks aimed at strengthening your knowledge and skills in these areas. 



## Resources

- [Learning to Program in C (Part 06)](https://www.youtube.com/watch?v=qMlnFwYdqIw)


### General

<details>
<summary> What are nested loops and how to use them </summary>
Nested loops are loops placed inside another loop. They allow you to perform repeated actions on multi-dimensional data or scenarios requiring multiple layers of repetition.

```c

for (int i = 0; i < outer_limit; i++) {
    for (int j = 0; j < inner_limit; j++) {
        // Operations for the inner loop
    }
    // Operations for the outer loop
}
Example: Multiplication Table

for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
        printf("%d\t", i * j);
    }
    printf("\n");
}
```
Be mindful of performance: nested loops can lead to O(n²) complexity.

</details>

<details>
<summary>What is a function and how to use functions</summary>

A function is a block of code that performs a specific task. It takes inputs (arguments), processes them, and returns an output. Functions help to:

- Encapsulate Code
- Reuse Code
- Improve Readability

**How to Use Functions**

In C, you define a function with a return type, name, parameters, and a body.

```c
//syntax
return_type function_name(parameters) {
    // Code
    return value;  // Optional
}
```

```c

#include <stdio.h>
int add(int a, int b);

int main() {
    int result = add(5, 3);
    printf("Result: %d\n", result);
    return 0;
}

int add(int a, int b) {
    return a + b;
}
//Calling a Function
int result = add(5, 3);
```
</details>

<details>
<summary>What is the difference between a declaration and a definition of a function</summary>

**Declaration** Introduces the function's name, return type, and parameters to the compiler.
Does not include the function's code.
```c
int add(int a, int b);  // Declaration
```
**Definition:** Provides the actual code of the function.
```c
int add(int a, int b) {  // Definition
    return a + b;
}
```
In short:

- Declaration: Tells what the function looks like.
- Definition: Tells what the function does.
</details>
<details>
<summary>What is a prototype</summary>
A function prototype is a declaration of a function that specifies its return type and parameters without defining the actual body of the function.

**Purpose:**

- Informs the compiler about the function's name, return type, and parameters before its definition.
- Ensures correct function usage in the code.
</details>

<details>
<summary>Scope of variables</summary>
The scope of a variable refers to the region of the program where the variable is accessible.

- **Local Scope:** Variables declared inside a function or block, accessible only within that function or block.
- **Global Scope:** Variables declared outside of all functions, accessible from any part of the program.

```c
int globalVar = 20;  // Global scope

void func() {
    printf("%d", globalVar);
}
```

- **Block Scope:** Variables declared inside a block ({}), accessible only within that block.
```c
if (true) {
    int blockVar = 30;  // Block scope
}
```
</details>
<details>
<summary>What are the `gcc` flags `-Wall -Werror -pedantic -Wextra -std=gnu89`</summary>

| **Flag**          | **Description**                                                                                 |
|-------------------|-------------------------------------------------------------------------------------------------|
| `-Wall`           | Enables most warning messages.                                                                  |
| `-Werror`         | Treats all warnings as errors, stopping compilation if any warning is found.                    |
| `-pedantic`       | Enforces strict ISO C compliance, warning about any code that may not be standard.              |
| `-Wextra`         | Enables additional warning messages not covered by `-Wall`.                                      |
| `-std=gnu89`      | Specifies the C standard to use. `gnu89` refers to the GNU dialect of the 1989 C standard (C89). |

</details>
<details>
<summary>What are header files and how to use them with `#include`</summary>

**Header Files:**
Header files in C/C++ contain function declarations, macro definitions, and type definitions that can be shared across multiple source files. They allow for code modularity and reusability.

**Using #include:**
To use the contents of a header file in your program, you use the #include directive. This directive essentially copies the content of the header file into the source file at the point where ``#include`` is written.

**Benefits:**
- Code reusability
- Simplified maintenance
- Separation of declaration and implementation
</details>


## Tasks

### 0. isupper
Write a function that checks for uppercase character.

- **Prototype:** `int _isupper(int c);`
- Returns 1 if `c` is uppercase
- Returns 0 otherwise
```
julien@ubuntu:~/0x04$ cat 0-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
    char c;

    c = 'A';
    printf("%c: %d\n", c, _isupper(c));
    c = 'a';
    printf("%c: %d\n", c, _isupper(c));
    return (0);
}
julien@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-isupper.c -o 0-isuper
julien@ubuntu:~/0x04$ ./0-isuper 
A: 1
a: 0
```

### 1. isdigit
Write a function that checks for a digit (0 through 9).

- **Prototype:** `int _isdigit(int c);`
- Returns 1 if `c` is a digit
- Returns 0 otherwise
```
julien@ubuntu:~/0x04$ cat 1-main.c 
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char c;

    c = '0';
    printf("%c: %d\n", c, _isdigit(c));
    c = 'a';
    printf("%c: %d\n", c, _isdigit(c));
    return (0);
}
julien@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-isdigit.c -o 1-isdigit
julien@ubuntu:~/0x04$ ./1-isdigit 
0: 1
a: 0
```

### 2. Collaboration is multiplication
Write a function that multiplies two integers.

- **Prototype:** `int mul(int a, int b);`
```
julien@ubuntu:~/0x04$ cat 2-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    printf("%d\n", mul(98, 1024));
    printf("%d\n", mul(-402, 4096));
    return (0);
}
julien@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-mul.c -o 2-mul
julien@ubuntu:~/0x04$ ./2-mul 
100352
-1646592
```

### 3. The numbers speak for themselves
Write a function that prints the numbers, from 0 to 9, followed by a new line.

- **Prototype:** `void print_numbers(void);`
- You can only use `_putchar` twice in your code
```
julien@ubuntu:~/0x04$ cat 3-main.c 
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_numbers();
    return (0);
}
julien@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 3-main.c 3-print_numbers.c -o 3-print_numbers
julien@ubuntu:~/0x04$ ./3-print_numbers | cat -e
0123456789$
```

### 4. I believe in numbers and signs
Write a function that prints the numbers, from 0 to 9, followed by a new line.

- **Prototype:** `void print_most_numbers(void);`
- Do not print 2 and 4
- You can only use `_putchar` twice in your code
```
julien@ubuntu:~/0x04$ cat 4-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_most_numbers();
    return (0);
}
julien@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 4-main.c 4-print_most_numbers.c -o 4-print_most_numbers
julien@ubuntu:~/0x04$ ./4-print_most_numbers 
01356789
```

### 5. Numbers constitute the only universal language
Write a function that prints 10 times the numbers, from 0 to 14, followed by a new line.

- **Prototype:** `void more_numbers(void);`
- You can only use `_putchar` three times in your code
```
julien@ubuntu:~/0x04$ cat 5-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    more_numbers();
    return (0);
}
julien@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 5-main.c 5-more_numbers.c -o 5-more_numbers
julien@ubuntu:~/0x04$ ./5-more_numbers 
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
```

### 6. The shortest distance between two points is a straight line
Write a function that draws a straight line in the terminal.

- **Prototype:** `void print_line(int n);`
- You can only use `_putchar` function to print
- Where `n` is the number of times the character ``_`` should be printed
- The line should end with a ``\n``
- If ``n`` is ``0`` or less, the function should only print ``\n``
```
julien@ubuntu:~/0x04$ cat 6-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_line(0);
    print_line(2);
    print_line(10);
    print_line(-4);
    return (0);
}
julien@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 6-main.c 6-print_line.c -o 6-lines
julien@ubuntu:~/0x04$ ./6-lines | cat -e
$
__$
__________$
$
```

### 7. I feel like I am diagonally parked in a parallel universe
Write a function that draws a diagonal line on the terminal.

- **Prototype:** `void print_diagonal(int n);`
- You can only use `_putchar` function to print
- Where `n` is the number of times the character ``\`` should be printed
- The diagonal should end with a ``\n``
- If ``n`` is ``0`` or less, the function should only print ``\n``
```
julien@ubuntu:~/0x04$ cat 7-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_diagonal(0);
    print_diagonal(2);
    print_diagonal(10);
    print_diagonal(-4);
    return (0);
}
julien@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 7-main.c 7-print_diagonal.c -o 7-diagonals
julien@ubuntu:~/0x04$ ./7-diagonals | cat -e
$
\$
 \$
\$
 \$
  \$
   \$
    \$
     \$
      \$
       \$
        \$
         \$
$
```

### 8. You are so much sunshine in every square inch
Write a function that prints a square, followed by a new line.

- **Prototype:** `void print_square(int size);`
- You can only use `_putchar` function to print
- Where ``size`` is the size of the square
- If ``size`` is ``0`` or less, the function should print only a new line
- Use the character ``#`` to print the square
```
julien@ubuntu:~/0x04$ cat 8-main.c 
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_square(2);
    print_square(10);
    print_square(0);
    return (0);
}

julien@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 8-main.c 8-print_square.c -o 8-squares
julien@ubuntu:~/0x04$ ./8-squares 
##
##
##########
##########
##########
##########
##########
##########
##########
##########
##########
##########
```

### 9. Fizz-Buzz
Write a program that prints the numbers from 1 to 100, followed by a new line. For multiples of three print Fizz instead of the number and for the multiples of five print Buzz. For numbers which are multiples of both three and five print FizzBuzz.

- Each number or word should be separated by a space
- You are allowed to use the standard library
```
julien@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 9-fizz_buzz.c -o 9-fizz_buzz
julien@ubuntu:~/0x04$ ./9-fizz_buzz 
1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16 17 Fizz 19 Buzz Fizz 22 23 Fizz Buzz 26 Fizz 28 29 FizzBuzz 31 32 Fizz 34 Buzz Fizz 37 38 Fizz Buzz 41 Fizz 43 44 FizzBuzz 46 47 Fizz 49 Buzz Fizz 52 53 Fizz Buzz 56 Fizz 58 59 FizzBuzz 61 62 Fizz 64 Buzz Fizz 67 68 Fizz Buzz 71 Fizz 73 74 FizzBuzz 76 77 Fizz 79 Buzz Fizz 82 83 Fizz Buzz 86 Fizz 88 89 FizzBuzz 91 92 Fizz 94 Buzz Fizz 97 98 Fizz Buzz
```

### 10. Triangles
Write a function that prints a triangle, followed by a new line.

- **Prototype:** `void print_triangle(int size);`
- You can only use `_putchar` function to print
- Where ``size`` is the size of the triangle
- If ``size`` is ``0`` or less, the function should print only a new line
- Use the character ``#`` to print the triangle
```
julien@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 10-main.c 10-print_triangle.c -o 10-triangles
julien@ubuntu:~/0x04$ ./10-triangles 
 #
##
         #
        ##
       ###
      ####
     #####
    ######
   #######
  ########
 #########
##########
#

julien@ubuntu:~/0x04$ ./10-triangles | tr ' ' . | cat -e
.#$
##$
.........#$
........##$
.......###$
......####$
.....#####$
....######$
...#######$
..########$
.#########$
##########$
#$
$
```
### 11. The problem of distinguishing prime numbers from composite numbers and of resolving the latter into their prime factors is known to be one of the most important and useful in arithmetic
Write a program that finds and prints the largest prime factor of the number 612852475143, followed by a new line.

- You are allowed to use the standard library
- Your program will be compiled with this command: ``gcc -Wall -pedantic -Werror -Wextra -std=gnu89 100-prime_factor.c -o 100-prime_factor -lm``

### 12. Numbers have life; they're not just symbols on paper
Write a function that prints an integer.

- **Prototype:** `void print_number(int n);`
- You can only use `_putchar` function to print
- You are not allowed to use `long`
- You are not allowed to use arrays or pointers
- You are not allowed to hard-code special values

```
julien@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 101-main.c 101-print_number.c -o 101-print_numbers
julien@ubuntu:~/0x04$ ./101-print_numbers 
98
402
1024
0
-98
```
