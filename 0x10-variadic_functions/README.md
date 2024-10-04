# 0x10. C - Variadic functions
## Resources
[stdarg.h](https://en.wikipedia.org/wiki/Stdarg.h)
[Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
[Const Keyword](https://www.youtube.com/watch?v=1W4oyuOdXv8&ab_channel=iTzAdam5X)

## Learning Objectives
<details>
<summary>What are variadic functions</summary>

### What Are Variadic Functions?
In C (and other languages like C++), **variadic functions** are functions that can accept a variable number of arguments.

#### Example of a Variadic Function
A classic example of a variadic function in C is printf(), which can take any number of arguments:
```c
printf("Hello, World!\n");        // 1 argument
printf("Number: %d\n", 10);       // 2 arguments
printf("Sum: %d + %d = %d\n", 2, 3, 5); // 4 arguments
```
### Syntax for Defining Variadic Functions
In C, a function is defined as variadic by including an **ellipsis** (``...``) in the parameter list. Before the ellipsis, there should be at least one known argument, which is typically used to manage or determine the variable arguments. ``return_type function_name(fixed_params, ...);``
Example: sum() Function
Here is an example of a variadic function that sums a variable number of integers:
```c
#include <stdio.h>
#include <stdarg.h>  // Required for variadic functions

// A function to sum a variable number of integers
int sum(int count, ...) {
    int total = 0;

    // Declare a variable of type va_list to store the arguments
    va_list args;

    // Initialize the va_list with the number of arguments
    va_start(args, count);

    // Loop through all the arguments
    for (int i = 0; i < count; i++) {
        // Retrieve the next argument and add it to the total
        total += va_arg(args, int);
    }

    // Clean up the va_list
    va_end(args);

    return total;
}

int main() {
    printf("Sum: %d\n", sum(3, 1, 2, 3));   // Output: 6
    printf("Sum: %d\n", sum(5, 10, 20, 30, 40, 50)); // Output: 150

    return 0;
}
```
#### Explanation of Variadic Function Mechanics
1. ``stdarg.h``: To handle variadic functions, you need to include the header ``<stdarg.h>``, which provides macros to access the arguments.

2. ``va_list``: This type is used to declare a variable (args in the example) that will hold the variable argument list.

3. ``va_start``: This macro initializes the ``va_list`` to start processing the variable arguments. It takes two arguments: the ``va_list`` and the last known parameter before the ellipsis (``count`` in this case).

4. ``va_arg``: This macro retrieves the next argument from the ``va_list``. You must specify the type of argument (e.g., ``int``, ``double``, etc.).

5. ``va_end``: This macro performs necessary cleanup when you’re done processing the variable arguments.

### Key Points:
- **Fixed Argument:** A variadic function must have at least one fixed argument before the ellipsis. In the ``sum`` function, ``count`` is the fixed argument.
- **``va_list`` Type:** Used to store the information about the variable arguments.
- **Macros:**
    + ``va_start``: Initializes the ``va_list``.
    + ``va_arg``: Retrieves the next argument in the list.
    + ``va_end``: Cleans up the ``va_list``.

### Use Cases for Variadic Functions:
Printing Functions: Functions like printf and scanf use variadic arguments to handle multiple types and counts of parameters.
Logging: Variadic functions can be useful in logging systems where the number of log details can vary.
Handling Multiple Parameters: For operations where the number of arguments is unknown or varies (e.g., summing an arbitrary number of integers).
</details>
<details>
<summary>Mechanism to determine when to stop processing the variadic arguments.</summary>

### 1. Using Sentinel Value
A sentinel is a special value used to signal the end of the argument list. For example, you can use a special value (like ``NULL``, ``0``, or ``-1``) that indicates the end of the arguments.
#### Example:
```c
#include <stdio.h>
#include <stdarg.h>

// A function to sum integers until a sentinel value (-1)
int sum_until_sentinel(int sentinel, ...) {
    int total = 0;
    va_list args;

    // Initialize the va_list
    va_start(args, sentinel);

    // Retrieve arguments until we hit the sentinel value
    int num;
    while ((num = va_arg(args, int)) != sentinel) {
        total += num;
    }

    // Clean up the va_list
    va_end(args);

    return total;
}

int main() {
    // Use -1 as a sentinel value
    printf("Sum: %d\n", sum_until_sentinel(-1, 1, 2, 3, -1));   // Output: 6
    printf("Sum: %d\n", sum_until_sentinel(-1, 10, 20, 30, 40, 50, -1)); // Output: 150

    return 0;
}
```
#### How It Works:
- In this example, the function keeps reading integers from the variadic list until it encounters the sentinel value ``-1``.
- When the sentinel value is reached, the loop breaks, and the sum is returned.

### 2. Using Format Strings
Another way to handle variadic arguments, especially when dealing with mixed types, is to use a **format string** that tells the function how many arguments there are and what their types are. This is the approach used in functions like ``printf()``.
#### Example:
```c
#include <stdio.h>
#include <stdarg.h>

// Function to print different types based on a format string
void print_values(const char *format, ...) {
    va_list args;
    va_start(args, format);

    for (const char *ptr = format; *ptr != '\0'; ptr++) {
        if (*ptr == 'i') {
            // Integer argument
            int num = va_arg(args, int);
            printf("Integer: %d\n", num);
        } else if (*ptr == 'f') {
            // Double (float) argument
            double num = va_arg(args, double);
            printf("Float: %.2f\n", num);
        } else if (*ptr == 's') {
            // String argument
            char *str = va_arg(args, char*);
            printf("String: %s\n", str);
        }
    }

    va_end(args);
}

int main() {
    // Format string indicates the types: "i" for int, "f" for float, "s" for string
    print_values("ifs", 42, 3.14, "Hello");  
    // Output:
    // Integer: 42
    // Float: 3.14
    // String: Hello

    return 0;
}
```
#### How It Works:
- The ``print_values`` function takes a format string (like ``"ifs"``) that specifies the types and number of arguments.
- For each character in the format string, it processes the corresponding argument from the variadic list.

### Summary:
- If you don't know the number of arguments, you can use strategies like:
    + **Sentinel value:** A special marker value like ``-1`` or ``NULL`` to signal the end of the argument list.
    + **Format string:** A predefined string that describes the number and types of arguments (used in functions like ``printf()``).
- Both approaches allow you to handle a varying number of arguments, but you need some mechanism to know when to stop or how to interpret the arguments.
</details>
<details>

<summary>Why and how to use the ``const`` type qualifier</summary>

The ``const`` type qualifier in C is used to indicate that a variable's value should not be modified after it is initialized. This can help prevent accidental changes to data and improve code readability and maintainability. 

#### Why Use const?
**1. Prevent Unintended Modifications:**

By declaring a variable as ``const``, you signal that the variable should not be changed after its initial assignment. This can help catch bugs caused by unintended modifications.

**2. Code Clarity:**

Using ``const`` makes your intentions clear to anyone reading the code. It indicates that certain values are meant to remain unchanged.

**3. Optimization:**

Compilers can optimize code better when they know certain values won’t change. This can lead to more efficient code.

**4. API Contracts:**

When designing functions that take parameters, using ``const`` in function signatures communicates to the user that the function will not modify the passed argument.

**5. Readability:**

Code that uses ``const`` can be easier to understand, as it clearly indicates which variables are meant to remain constant.

#### How to Use ``const``
**1. Declaring ``const`` Variables**
You can declare a variable as const by placing the const keyword before the type. `const int x = 10;`

**2. Using ``const`` with Pointers**
When using pointers, ``const`` can be applied to the pointer itself or to the value it points to:

- **Pointer to Constant Value:** The value pointed to by the pointer cannot be changed, but the pointer itself can point to a different address.
```c
const int *ptr;
int a = 5;
ptr = &a;
// *ptr = 10; // This will cause a compile-time error
```
- **Constant Pointer:** The pointer itself cannot be changed to point to another address, but the value it points to can be modified.
```c
int b = 10;
int *const ptr2 = &b;
// ptr2 = &a; // This will cause a compile-time error
*ptr2 = 20; // This is valid
```
- **Constant Pointer to Constant Value:** Both the pointer and the value it points to cannot be changed.
```c
const int *const ptr3 = &b;
// ptr3 = &a; // This will cause a compile-time error
// *ptr3 = 30; // This will also cause a compile-time error
```
**3. Using const with Function Parameters**
You can use const in function parameters to indicate that the function will not modify the argument.
```c
#include <stdio.h>

// Function that takes a const pointer to an integer
void display(const int *num) {
    printf("Number: %d\n", *num);
    // *num = 100; // Uncommenting this line will cause a compile-time error
}

int main() {
    const int value = 42;

    display(&value); // Pass the address of value
    // value = 50; // This will cause a compile-time error

    return 0;
}
```
</details>

## Tasks
### 0. Beauty is variable, ugliness is constant
Write a function that returns the sum of all its parameters.
**Prototype:** ``int sum_them_all(const unsigned int n, ...);``
- If ``n == 0``, return ``0``

```bash
$ cat 0-main.c
#include <stdio.h>
#include "variadic_functions.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int sum;

    sum = sum_them_all(2, 98, 1024);
    printf("%d\n", sum);
    sum = sum_them_all(4, 98, 1024, 402, -1024);
    printf("%d\n", sum);    
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-sum_them_all.c -o a
$ ./a 
1122
500
```
### 1. To be is to be the value of a variable
Write a function that prints numbers, followed by a new line.

**Prototype:** ``void print_numbers(const char *separator, const unsigned int n, ...);``
- where ``separator`` is the string to be printed between numbers
- and ``n`` is the number of integers passed to the function
- You are allowed to use ``printf``
- If ``separator`` is ``NULL``, don’t print it
- Print a new line at the end of your function

```bash
$ cat 1-main.c
#include "variadic_functions.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_numbers(", ", 4, 0, 98, -1024, 402);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-print_numbers.c -o b
$ ./b
0, 98, -1024, 402
```  
### 2. One woman's constant is another woman's variable
Write a function that prints strings, followed by a new line.
**Prototype:** ``void print_strings(const char *separator, const unsigned int n, ...);``
- where ``separator`` is the string to be printed between the strings
- and ``n`` is the number of strings passed to the function
- You are allowed to use ``printf``
- If separator is NULL, don’t print it
- If one of the string is NULL, print ``(nil)`` instead
- Print a new line at the end of your function
```bash
$ cat 2-main.c
#include "variadic_functions.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_strings(", ", 2, "Jay", "Django");
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-print_strings.c -o c
$ ./c 
Jay, Django
```  
### 3. To be is a to be the value of a variable
Write a function that prints anything.
**Prototype:** ``void print_all(const char * const format, ...);``
- where ``format`` is a list of types of arguments passed to the function
    + `c`: `char`
    + `i`: `integer`
    + `f`: `float`
    + `s`: `char *` if the string is NULL, print `(nil)` instead
    + any other char should be ignored
- You are not allowed to use `for`, `goto`, ternary operator, `else`, `do ... while`
- You can use a maximum of
    + 2 ``while`` loops
    + 2 ``if``
- You can declare a maximum of ``9`` variables
- You are allowed to use ``printf``
- Print a new line at the end of your function
```bash
$ cat 3-main.c
#include "variadic_functions.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_all("ceis", 'B', 3, "stSchool");
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-print_all.c -o d
$ ./d 
B, 3, stSchool
```