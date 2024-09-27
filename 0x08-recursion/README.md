# 0x08. C - Recursion

## Resources
- [C - Recursion](https://www.tutorialspoint.com/cprogramming/c_recursion.htm)

### Additional Resources
- [Recursion & Recursive functions in C Programming](#)

### General
<details>
<summary>What is recursion</summary>
Recursion is a programming technique where a function calls itself to solve a problem. It typically breaks down a problem into smaller, more manageable subproblems. This process continues until a base case is reached, which provides a straightforward answer without further recursion.

#### Key Concepts of Recursion:
**Base Case**: The condition under which the recursion stops. It's essential to prevent infinite recursion.

**Recursive Case**: The part of the function that includes the recursive call. This usually involves reducing the problem's size with each call.
</details>
<details>
<summary>How to implement recursion</summary>
To implement recursion, follow these steps:

**1. Define the Function:** Start by defining the function that will call itself.

**2. Identify Base Case(s):** Determine the condition under which the function will stop calling itself. This is crucial to prevent infinite recursion.

**3. Define Recursive Case:** Within the function, write the logic that reduces the problem size and includes the recursive call to the function.
</details>
<details>
<summary>In what situations you should implement recursion</summary>

- **Naturally Recursive Problems:** When the problem can be divided into smaller, similar subproblems, such as tree traversals (e.g., pre-order, in-order, post-order).

- **Mathematical Computations:** For problems like calculating factorials, Fibonacci numbers, or powers, where a straightforward recursive formula exists.

- **Backtracking Algorithms:** In scenarios like solving mazes, puzzles (e.g., N-Queens, Sudoku), or generating permutations and combinations.

- **Divide and Conquer:** When the problem can be solved by breaking it into smaller subproblems and combining their results, such as in sorting algorithms (e.g., quicksort, mergesort).

- **Dynamic Programming:** When overlapping subproblems are present, and recursion can be combined with memoization to optimize performance.

- **Simplifying Code:** In cases where a recursive solution is clearer and more intuitive than an iterative one, making the code easier to understand and maintain.

Use recursion when it enhances clarity and aligns with the problem's structure, but be cautious of potential performance issues and stack overflow with deep recursion.

</details>
<details>
<summaru>In what situations you shouldn’t implement recursion</summary>

- **Deep Recursion Depth:** When the problem size is large, recursion can lead to stack overflow errors due to limited call stack space.

- **Performance Concerns:** If a recursive solution has exponential time complexity or excessive overhead (like repeated calculations without memoization), an iterative approach may be more efficient.

- **Simple Iterative Solutions:** If the problem can be easily solved using loops without adding complexity, prefer iterative methods for clarity and performance.

- **Limited Resources:** In environments with strict memory constraints, recursion can consume more stack space compared to iterative solutions.

- **Non-tail Recursive Functions:** If the recursion is not tail-recursive, it can lead to increased memory usage with each function call, which can be problematic for large inputs.

- **Code Readability:** If recursion complicates the logic or makes the code harder to understand, an iterative approach might be preferable.

In such cases, an iterative solution is usually more practical and efficient.
</details>

## Tasks
### 0. She locked away a secret, deep inside herself, something she once knew to be true... but chose to forget 
Write a function that prints a string, followed by a new line.

**Prototype:** `void _puts_recursion(char *s);`  
FYI: The standard library provides a similar function: `puts`
```bash
$ cat 0-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    _puts_recursion("Puts with recursion");
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 0-main.c 0-puts_recursion.c -o 0-puts_recursion
$ ./0-puts_recursion 
Puts with recursion
```

### 1. Why is it so important to dream? Because, in my dreams we are together
Write a function that prints a string in reverse.

**Prototype:** `void _print_rev_recursion(char *s);`
```bash
$ cat 1-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    _print_rev_recursion("\nColton Walker");
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 1-main.c 1-print_rev_recursion.c -o 1-print_rev_recursion
$ ./1-print_rev_recursion 
reklaW notloC
```
### 2. Dreams feel real while we're in them. It's only when we wake up that we realize something was actually strange
Write a function that returns the length of a string.

**Prototype:** ``int _strlen_recursion(char *s);``
FYI: The standard library provides a similar function: strlen
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
    int n;

    n = _strlen_recursion("Corbin Coleman");
    printf("%d\n", n);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89  2-main.c 2-strlen_recursion.c -o 2-strlen_recursion
$ ./2-strlen_recursion 
14
```
### 3. You mustn't be afraid to dream a little bigger, darling
Write a function that returns the factorial of a given number.

**Prototype:** ``int factorial(int n);``
- If `n` is lower than `0`, the function should return `-1` to indicate an error
- Factorial of `0` is `1`
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
    int r;

    r = factorial(1);
    printf("%d\n", r);
    r = factorial(5);
    printf("%d\n", r);
    r = factorial(10);
    printf("%d\n", r);
    r = factorial(-1024);
    printf("%d\n", r);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-factorial.c -o 3-factorial
$ ./3-factorial 
1
120
3628800
-1
```
### 4. Once an idea has taken hold of the brain it's almost impossible to eradicate
Write a function that returns the value of x raised to the power of y.

**Prototype:** `int _pow_recursion(int x, int y);`
- If `y` is lower than `0`, the function should return `-1`
FYI: The standard library provides a different function: `pow`. 
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
    int r;

    r = _pow_recursion(1, 10);
    printf("%d\n", r);
    r = _pow_recursion(1024, 0);
    printf("%d\n", r);
    r = _pow_recursion(2, 16);
    printf("%d\n", r);
    r = _pow_recursion(5, 2);
    printf("%d\n", r);
    r = _pow_recursion(5, -2);
    printf("%d\n", r);
    r = _pow_recursion(-5, 3);
    printf("%d\n", r);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 4-pow_recursion.c -o 4-pow
$ ./4-pow 
1
1
65536
25
-1
-125
```
### 5. Your subconscious is looking for the dreamer
Write a function that returns the natural square root of a number.

**Prototype:** `int _sqrt_recursion(int n);`
- If `n` does not have a natural square root, the function should return `-1`
FYI: The standard library provides a different function: `sqrt`.
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
    int r;

    r = _sqrt_recursion(1);
    printf("%d\n", r);
    r = _sqrt_recursion(1024);
    printf("%d\n", r);
    r = _sqrt_recursion(16);
    printf("%d\n", r);
    r = _sqrt_recursion(17);
    printf("%d\n", r);
    r = _sqrt_recursion(25);
    printf("%d\n", r);
    r = _sqrt_recursion(-1);
    printf("%d\n", r);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-main.c 5-sqrt_recursion.c -o 5-sqrt
$ ./5-sqrt 
1
32
4
-1
5
-1
```
### 6. Inception. Is it possible?
Write a function that returns `1` if the input integer is a prime number, otherwise return `0`.

**Prototype:** `int is_prime_number(int n);`
```bash
$ cat 6-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int r;

    r = is_prime_number(1);
    printf("%d\n", r);
    r = is_prime_number(1024);
    printf("%d\n", r);
    r = is_prime_number(16);
    printf("%d\n", r);
    r = is_prime_number(17);
    printf("%d\n", r);
    r = is_prime_number(25);
    printf("%d\n", r);
    r = is_prime_number(-1);
    printf("%d\n", r);
    r = is_prime_number(113);
    printf("%d\n", r);
    r = is_prime_number(7919);
    printf("%d\n", r);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 6-main.c 6-is_prime_number.c -o 6-prime
$ ./6-prime 
0
0
0
1
0
0
1
1
```
### 7. They say we only use a fraction of our brain's true potential. Now that's when we're awake. When we're asleep, we can do almost anything
Write a function that returns `1` if a string is a palindrome and `0` if not.

**Prototype:** `int is_palindrome(char *s);`
- An empty string is a palindrome
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
    int r;

    r = is_palindrome("level");
    printf("%d\n", r);
    r = is_palindrome("redder");
    printf("%d\n", r);
    r = is_palindrome("test");
    printf("%d\n", r);
    r = is_palindrome("step on no pets");
    printf("%d\n", r);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 100-main.c 100-is_palindrome.c -o 100-palindrome
$ ./100-palindrome 
1
1
0
1
```
### 8. Inception. Now, before you bother telling me it's impossible...
Write a function that compares two strings and returns `1` if the strings can be considered identical, otherwise return `0`.

**Prototype:** `int wildcmp(char *s1, char *s2);`
- `s2` can contain the special character `*`.
- The special char `*` can replace any string (including an empty string)
```bash
$ cat 101-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int r;

    r = wildcmp("main.c", "*.c");
    printf("%d\n", r);
    r = wildcmp("main.c", "m*a*i*n*.*c*");
    printf("%d\n", r);
    r = wildcmp("main.c", "main.c");
    printf("%d\n", r);
    r = wildcmp("main.c", "m*c");
    printf("%d\n", r);
    r = wildcmp("main.c", "ma********************************c");
    printf("%d\n", r);
    r = wildcmp("main.c", "*");
    printf("%d\n", r);
    r = wildcmp("main.c", "***");
    printf("%d\n", r);
    r = wildcmp("main.c", "m.*c");
    printf("%d\n", r);
    r = wildcmp("main.c", "**.*c");
    printf("%d\n", r);
    r = wildcmp("main-main.c", "ma*in.c");
    printf("%d\n", r);
    r = wildcmp("main", "main*d");
    printf("%d\n", r);
    r = wildcmp("abc", "*b");
    printf("%d\n", r);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 101-main.c 101-wildcmp.c -o 101-wildcmp
$ ./101-wildcmp 
1
1
1
1
1
1
1
0
1
1
0
0
```