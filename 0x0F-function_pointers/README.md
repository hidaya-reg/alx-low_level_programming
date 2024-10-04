# 0x0F. C - Function pointers
## Resources

[Function Pointer in C](https://sourceforge.net/projects/udis86/)
[Pointers to functions](https://publications.gbdirect.co.uk//c_book/chapter5/function_pointers.html)
[Function Pointers in C / C++](https://www.youtube.com/watch?v=ynYtgGUNelE&ab_channel=mycodeschool)
[why pointers to functions?](https://www.youtube.com/watch?v=sxTFSDAZM8s&ab_channel=mycodeschool)
[Everything you need to know about pointers in C](https://boredzo.org/pointers/)

## Learning Objectives
<details>
<summary>What are function pointers and how to use them</summary>
Function pointers in C allow you to store the address of a function and invoke it indirectly. This feature is powerful because it enables **dynamic function calls, callback functions, and more flexible program structures**.

#### Declaring a Function Pointer
To declare a function pointer, you specify the return type of the function, followed by an asterisk (``*``) and the pointer name in parentheses, with the parameter types in the parentheses.

``return_type (*pointer_name)(parameter_types);``

#### Example of Function Pointer Declaration
```c
int add(int a, int b) {
    return a + b;
}

int main() {
    // Declare a function pointer
    int (*funcPtr)(int, int);
    
    // Assign the address of the 'add' function to the pointer
    funcPtr = add;

    // Call the function using the pointer
    int result = funcPtr(3, 4); // result is now 7
    return 0;
}
```
#### Using Function Pointers
**1. Assigning a Function to a Pointer:** You can assign the address of a function to a function pointer.
**2. Invoking the Function:** You can call the function through the pointer using the pointer's name followed by parentheses.

#### Callback Function
Function pointers are often used for callbacks:
```c
#include <stdio.h>

// Function that takes two integers and returns their sum
int add(int a, int b) {
    return a + b;
}

// Function that takes two integers and returns their difference
int subtract(int a, int b) {
    return a - b;
}

// Function to perform an operation based on a function pointer
void performOperation(int (*operation)(int, int), int x, int y) {
    int result = operation(x, y); // Call the function pointed to by 'operation'
    printf("Result: %d\n", result);
}

int main() {
    // Declare a function pointer
    int (*funcPtr)(int, int);

    // Assign the function pointer to 'add'
    funcPtr = add;
    performOperation(funcPtr, 5, 3); // Output: Result: 8

    // Assign the function pointer to 'subtract'
    funcPtr = subtract;
    performOperation(funcPtr, 5, 3); // Output: Result: 2

    return 0;
}
```
#### Array of Function Pointers
You can also create an array of function pointers, which allows you to choose from multiple functions dynamically.
```c
#include <stdio.h>

// Function prototypes
void hello() {
    printf("Hello!\n");
}

void goodbye() {
    printf("Goodbye!\n");
}

int main() {
    // Array of function pointers
    void (*funcArray[2])() = {hello, goodbye};

    // Call each function using the function pointers in the array
    for (int i = 0; i < 2; i++) {
        funcArray[i](); // Invoke the function pointed to
    }

    return 0;
}
```
#### Summary
- **Definition:** Function pointers allow you to store and invoke functions indirectly.
- **Use Cases:** They are commonly used for callbacks, implementing event-driven programs, and for managing multiple functions dynamically.
- **Syntax:** The declaration and invocation syntax may seem complex at first, but it becomes clearer with practice.
</details>
<details>
<summary>What does a function pointer exactly hold</summary>

A function pointer in C holds the memory address of a function. Instead of storing the address of a variable (as with regular pointers), a function pointer stores the starting address of executable code corresponding to a specific function in memory. This allows you to indirectly call the function that the pointer references.

#### Breakdown of What a Function Pointer Holds:
- **Function’s Address:** A function pointer contains the address of the first instruction of the function’s code in memory.
- **Function’s Signature:** When you declare a function pointer, you also specify the function's signature (i.e., return type and parameter types). This ensures that the function pointer can only point to functions that match this signature.

#### Example of Function Pointer Holding a Function’s Address
```c
#include <stdio.h>

// A simple function
int add(int a, int b) {
    return a + b;
}

int main() {
    // Declare a function pointer
    int (*funcPtr)(int, int);

    // Assign the address of the 'add' function to the pointer
    funcPtr = add;

    // Call the function via the pointer
    int result = funcPtr(5, 3);

    printf("Result: %d\n", result); // Output: Result: 8

    return 0;
}
```
In this example:

- he pointer ``funcPtr`` holds the address of the function ``add``.
- When ``funcPtr(5, 3)`` is called, the program jumps to the address where ``add`` is stored, executes it, and returns the result.
</details>
<details>
<summary>Where does a function pointer point to in the virtual memory</summary>

In virtual memory, a function pointer points to the **code segment** (also called the **text segment**) of a process's memory. This segment contains the executable code of the program, including the machine instructions for all functions, both user-defined and system-provided (like standard library functions).

### Overview of the Code Segment (Text Segment)
**1. Executable Instructions:** The code segment stores the compiled machine code of functions, and the function pointer points to the address of the function's first instruction within this segment.
**1. Read-Only:** Typically, the code segment is marked as **read-only** to prevent accidental or malicious modification of executable code at runtime.

### Typical Layout of a Process’s Virtual Memory
A process’s memory is generally divided into several segments. The key regions are:

#### 1. Code Segment (Text Segment): 
Contains the actual executable code (machine instructions). Function pointers point to addresses within this segment.

#### 2. Data Segment:
- **Initialized Data:** Stores global and static variables that are initialized.
- **Uninitialized Data (BSS):** Stores global and static variables that are uninitialized.
#### 3. Heap:
Used for dynamic memory allocation (e.g., ``malloc`` in C).

#### 4. Stack:
Stores function call frames, local variables, and return addresses.

#### 5. Memory Mapped Segment:
May include shared libraries, memory-mapped files, and more.

#### 6. Kernel Space:
Reserved for the operating system, not accessible by user code.

#### Function Pointer Example in Virtual Memory
Here’s a conceptual example of where a function pointer points in memory:
```c
#include <stdio.h>

// A simple function
void greet() {
    printf("Hello, World!\n");
}

int main() {
    // Declare a function pointer and assign the address of 'greet'
    void (*funcPtr)() = greet;

    // Call the function using the pointer
    funcPtr();

    return 0;
}
```
In this example:

- The function ``greet()`` is stored in the **code segment** of the program's virtual memory.
- The function pointer ``funcPtr`` holds the address of the first instruction of ``greet`` in the code segment.
- When ``funcPtr()`` is called, the program jumps to the address stored in funcPtr and starts executing the instructions for ``greet()``.

#### Example Layout of Virtual Memory (Simplified):
| **Memory Segment**    | **Contents**                             |
|-----------------------|------------------------------------------|
| **Stack**             | Local variables, function call frames    |
| **Heap**              | Dynamically allocated memory             |
| **Data Segment**      | Global and static variables              |
| **Code Segment**      | Executable code (functions)              |

</details>

## Tasks
### 0. What's my name
Write a function that prints a name.
**Prototype:** ``void print_name(char *name, void (*f)(char *));``
```bash
$ cat 0-main.c
#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name_as_is - prints a name as is
 * @name: name of the person
 *
 * Return: Nothing.
 */
void print_name_as_is(char *name)
{
    printf("Hello, my name is %s\n", name);
}

/**
 * print_name_uppercase - print a name in uppercase
 * @name: name of the person
 *
 * Return: Nothing.
 */
void print_name_uppercase(char *name)
{
    unsigned int i;

    printf("Hello, my uppercase name is ");
    i = 0;
    while (name[i])
    {
        if (name[i] >= 'a' && name[i] <= 'z')
        {
            putchar(name[i] + 'A' - 'a');
        }
        else
        {
            putchar(name[i]);
        }
        i++;
    }
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_name("Bob", print_name_as_is);
    print_name("Bob Dylan", print_name_uppercase);
    printf("\n");
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-print_name.c -o a
$ ./a 
Hello, my name is Bob
Hello, my uppercase name is BOB DYLAN
```  
### 1. If you spend too much time thinking about a thing, you'll never get it done
Write a function that executes a function given as a parameter on each element of an array.
**Prototype:** ``void array_iterator(int *array, size_t size, void (*action)(int));``
- where ``size`` is the size of the array
- and ``action`` is a pointer to the function you need to use
```bash
$ cat 1-main.c
#include <stdio.h>
#include "function_pointers.h"

/**
 * print_elem - prints an integer
 * @elem: the integer to print
 *
 * Return: Nothing.
 */
void print_elem(int elem)
{
    printf("%d\n", elem);
}

/**
 * print_elem_hex - prints an integer, in hexadecimal
 * @elem: the integer to print
 *
 * Return: Nothing.
 */
void print_elem_hex(int elem)
{
    printf("0x%x\n", elem);
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int array[5] = {0, 98, 402, 1024, 4096};

    array_iterator(array, 5, &print_elem);
    array_iterator(array, 5, &print_elem_hex);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-array_iterator.c -o b
$ ./b 
0
98
402
1024
4096
0x0
0x62
0x192
0x400
0x1000
```
### 2. To hell with circumstances; I create opportunities
Write a function that searches for an integer.
**Prototype:** ``int int_index(int *array, int size, int (*cmp)(int));``
- where ``size`` is the number of elements in the array ``array``
- ``cmp`` is a pointer to the function to be used to compare values
- ``int_index`` returns the index of the first element for which the ``cmp`` function does not return ``0``
- If no element matches, return ``-1``
- If size <= ``0``, return ``-1``
```bash
$ cat 2-main.c
#include <stdio.h>
#include "function_pointers.h"

/**
 * is_98 - check if a number is equal to 98
 * @elem: the integer to check
 *
 * Return: 0 if false, something else otherwise.
 */
int is_98(int elem)
{
    return (98 == elem);
}

/**
 * is_strictly_positive - check if a number is greater than 0
 * @elem: the integer to check
 *
 * Return: 0 if false, something else otherwise.
 */
int is_strictly_positive(int elem)
{
    return (elem > 0);
}


/**
 * abs_is_98 - check if the absolute value of a number is 98
 * @elem: the integer to check
 *
 * Return: 0 if false, something else otherwise.
 */
int abs_is_98(int elem)
{
    return (elem == 98 || -elem == 98);
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int array[20] = {0, -98, 98, 402, 1024, 4096, -1024, -98, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 98};
    int index;

    index = int_index(array, 20, is_98);
    printf("%d\n", index);
    index = int_index(array, 20, abs_is_98);
    printf("%d\n", index);
    index = int_index(array, 20, is_strictly_positive);
    printf("%d\n", index);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-int_index.c -o c
$ ./c 
2
1
2
```  
### 3. A goal is not always meant to be reached, it often serves simply as something to aim at
Write a program that performs simple operations.
- You are allowed to use the standard library
- Usage: ``calc num1 operator num2``
- You can assume ``num1`` and ``num2`` are integers, so use the ``atoi`` function to convert them from the string input to ``int``
- ``operator`` is one of the following:
    + ``+``: addition
    + ``-``: subtraction
    + ``*``: multiplication
    + ``/``: division
    + ``%``: modulo
- The program prints the result of the operation, followed by a new line
- You can assume that the result of all operations can be stored in an ``int``
- if the number of arguments is wrong, print ``Error``, followed by a new line, and exit with the status ``98``
- if the ``operator`` is none of the above, print ``Error``, followed by a new line, and exit with the status ``99``
- if the user tries to divide (``/`` or ``%``) by ``0``, print ``Error``, followed by a new line, and exit with the status ``100``

This task requires that you create four different files. 

**3-calc.h**
This file should contain all the function prototypes and data structures used by the program. You can use this structure:
```c
/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
    char *op;
    int (*f)(int a, int b);
} op_t;
```
**3-op_functions.c**
This file should contain the 5 following functions (not more):

- ``op_add``: returns the sum of ``a`` and ``b``. Prototype: ``int op_add(int a, int b);``
- ``op_sub``: returns the difference of ``a`` and ``b``. Prototype: ``int op_sub(int a, int b);``
- ``op_mul``: returns the product of ``a`` and ``b``. Prototype: ``int op_mul(int a, int b);``
- ``op_div``: returns the result of the division of ``a`` by ``b``. Prototype: ``int op_div(int a, int b);``
- ``op_mod``: returns the remainder of the division of ``a`` by ``b``. Prototype: ``int op_mod(int a, int b);``

**3-get_op_func.c**

This file should contain the function that selects the correct function to perform the operation asked by the user. You’re not allowed to declare any other function.

- Prototype: ``int (*get_op_func(char *s))(int, int);``
- where ``s`` is the operator passed as argument to the program
- This function returns a pointer to the function that corresponds to the operator given as a parameter. Example: ``get_op_func("+")`` should return a pointer to the function ``op_add``
- You are not allowed to use ``switch`` statements
- You are not allowed to use ``for`` or ``do ... while`` loops
- You are not allowed to use ``goto``
- You are not allowed to use ``else``
- You are not allowed to use more than one ``if`` statement in your code
- You are not allowed to use more than one ``while`` loop in your code
- If s does not match any of the 5 expected operators (``+``, ``-``, ``*``, ``/``, ``%``), return ``NULL``
- You are only allowed to declare these two variables in this function:
```c
    op_t ops[] = {
        {"+", op_add},
        {"-", op_sub},
        {"*", op_mul},
        {"/", op_div},
        {"%", op_mod},
        {NULL, NULL}
    };
    int i;
```

**3-main.c**

This file should contain your ``main`` function only.

- You are not allowed to code any other function than ``main`` in this file
- You are not allowed to directly call ``op_add``, ``op_sub``, ``op_mul``, ``op_div`` or ``op_mod`` from the ``main`` function
- You have to use atoi to convert arguments to int
- You are not allowed to use any kind of loop
- You are allowed to use a maximum of 3 if statements

**Compilation and examples**
```c
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-op_functions.c 3-get_op_func.c -o calc
$ ./calc 1 + 1
2
$ ./calc 97 + 1
98
$ ./calc 1024 / 10
102
$ ./calc 1024 '*' 98
100352
$ ./calc 1024 '\*' 98
Error
$ ./calc 1024 - 98
926
$ ./calc 1024 '%' 98
44
```

### 4. Most hackers are young because young people tend to be adaptable. As long as you remain adaptable, you can always be a good hacker
Write a program that prints the [opcodes](https://en.wikipedia.org/wiki/Opcode) of its own main function.

- Usage: ``./main number_of_bytes``
- Output format:
    + the opcodes should be printed in hexadecimal, lowercase
    + each opcode is two char long
    + listing ends with a new line
    + see example
- You are allowed to use ``printf`` and ``atoi``
- You have to use ``atoi`` to convert the argument to an ``int``
- If the number of argument is not the correct one, print ``Error``, followed by a new line, and exit with the status ``1``
- If the number of bytes is negative, print ``Error``, followed by a new line, and exit with the status ``2``
- You do not have to compile with any flags

Note: if you want to translate your opcodes to assembly instructions, you can use, for instance [udcli](https://sourceforge.net/projects/udis86/).
```bash
$ gcc -std=gnu89 100-main_opcodes.c -o main
$ ./main 21
55 48 89 e5 48 83 ec 30 89 7d dc 48 89 75 d0 83 7d dc 02 74 14
$ objdump -d -j.text -M intel main
[...]
00000000004005f6 <main>:
  4005f6:   55                      push   rbp
  4005f7:   48 89 e5                mov    rbp,rsp
  4005fa:   48 83 ec 30             sub    rsp,0x30
  4005fe:   89 7d dc                mov    DWORD PTR [rbp-0x24],edi
  400601:   48 89 75 d0             mov    QWORD PTR [rbp-0x30],rsi
  400605:   83 7d dc 02             cmp    DWORD PTR [rbp-0x24],0x2
  400609:   74 14                   je     40061f <main+0x29>
[...]
$ ./main 21 | udcli -64 -x -o 4005f6
00000000004005f6 55               push rbp                
00000000004005f7 4889e5           mov rbp, rsp            
00000000004005fa 4883ec30         sub rsp, 0x30           
00000000004005fe 897ddc           mov [rbp-0x24], edi     
0000000000400601 488975d0         mov [rbp-0x30], rsi     
0000000000400605 837ddc02         cmp dword [rbp-0x24], 0x2
0000000000400609 7414             jz 0x40061f             
```
- *Note 0*: ``je`` is equivalent to ``jz``
- *Note 1*: depending on how you write your ``main`` function, and on which machine you compile your program, the opcodes (and by extension the assembly code) might be different than the above example