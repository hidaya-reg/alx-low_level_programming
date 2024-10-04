d# 0x0D. C - Preprocessor
## Resources
[Understanding C program Compilation Process](https://www.youtube.com/watch?v=eW5he5uFBNM&ab_channel=HowTo)
[Object-like Macros](https://gcc.gnu.org/onlinedocs/gcc-5.1.0/cpp/Object-like-Macros.html#Object-like-Macros)
[Macro Arguments](https://gcc.gnu.org/onlinedocs/gcc-5.1.0/cpp/Macro-Arguments.html#Macro-Arguments)
[Pre Processor Directives in C](https://www.youtube.com/watch?v=X6HiYbY3Uak&ab_channel=BestITCourses)
[The C Preprocessor](https://www.cprogramming.com/tutorial/cpreprocessor.html)
[Standard Predefined Macros](https://gcc.gnu.org/onlinedocs/gcc-5.1.0/cpp/Standard-Predefined-Macros.html#Standard-Predefined-Macros)
[include guard](https://en.wikipedia.org/wiki/Include_guard)
[Common Predefined Macros](https://gcc.gnu.org/onlinedocs/gcc-5.1.0/cpp/Common-Predefined-Macros.html#Common-Predefined-Macros)

## Learning Objectives
details>
<summary>What are macros and how to use them</summary>
Macros are a powerful feature provided by the preprocessor that allows for the definition of code snippets that can be reused throughout a program. They can be used to simplify code, define constants, and perform conditional compilation. Macros are defined using the ``#define`` directive and are processed before the actual compilation of the program.

### Types of Macros
#### 1. Object-like Macros: 
These are used to define constants or simple values. ``#define PI 3.14159``
This allows you to use ``PI`` in your code without having to write the actual value repeatedly.

#### 2. Function-like Macros: 
These allow you to define macros that take arguments, similar to functions. ``#define SQUARE(x) ((x) * (x))``
You can then use ``SQUARE(5)`` in your code, which will be replaced by ``((5) * (5))`` during preprocessing.

### How to Use Macros
#### 1. Defining a Macro: 
Use the #define directive to create a macro. ``#define MACRO_NAME value_or_expression``
#### 2. Using a Macro: 
Simply write the macro name in your code. The preprocessor will replace the macro with its definition before compilation.
```c
#include <stdio.h>

#define PI 3.14159
#define SQUARE(x) ((x) * (x))

int main() {
    printf("Value of PI: %f\n", PI);
    printf("Square of 5: %d\n", SQUARE(5));
    return 0;
}
```
### Important Considerations
- **Parentheses:** When defining function-like macros, it’s important to use parentheses around the parameters and the entire expression to ensure correct evaluation. ``#define ADD(a, b) ((a) + (b))``. Without parentheses, expressions like ``ADD(1, 2) * 3 ``would not behave as expected (it would evaluate to`` 1 + 2 * 3`` instead of ``3 * 3``).

- **Debugging:** Since macros are replaced by their definitions before compilation, they can sometimes make debugging difficult. Compiler error messages may not point to the actual location of the error in the source code.

- **Scope:** Macros do not have scope like variables; they are replaced globally throughout the file after their definition. To avoid naming conflicts, it’s common to use uppercase letters for macro names.

- **No Type Checking:** Unlike functions, macros do not perform type checking, which can lead to unexpected behavior if the wrong type is passed as an argument.

### Conditional Compilation
Macros can also be used for conditional compilation, allowing code to be included or excluded based on certain conditions (e.g., the operating system, compiler version).
```c
#if defined(WIN32)
#include <windows.h>
#else
#include <unistd.h>
#endif
```
</details>
<details>
<summary>Steps of Compilation in C</summary>

#### 1. Preprocessing:

- **Preprocessor Directives:** The C preprocessor handles directives that start with ``#``, such as ``#include``, ``#define``, and ``#ifdef``.
- **File Inclusion:** Header files specified with ``#include`` are included in the source code.
- **Macro Substitution:** All macros defined with ``#define`` are replaced with their corresponding values or expressions.
- **Conditional Compilation:** Code enclosed within ``#ifdef``, ``#ifndef``, ``#if``, ``#else``, and ``#endif`` is conditionally compiled based on whether the specified macros are defined.
- **Output:** The result of this stage is a modified source code file, often with a ``.i``:  ``extension. gcc -E my_program.c -o my_program.i``

#### 2. Compilation:

- **Syntax and Semantic Analysis:** The compiler checks the modified source code for syntax errors and performs semantic analysis to ensure that the code makes sense (e.g., type checking).
- **Intermediate Code Generation:** The compiler translates the code into an intermediate representation, which is platform-independent.
- **Optimization:** The compiler may optimize the intermediate code to improve performance, reduce size, or both.
- **Output:** The result is typically an object file with a ``.s`` extension.
`gcc -S my_program.i -o my_program.s`

#### 3. Assembly:

- **Assembly Language Translation:** The assembler converts the intermediate representation (assembly code) into machine code, which consists of binary instructions that the computer's processor can execute.
- **Output:** This results in another object file (e.g., ``.o`` or ``.obj``).
``gcc -c my_program.s -o my_program.o``

#### 4. Linking:

- **Combining Object Files:** The linker combines the object files generated in the previous step with any required libraries (standard libraries, third-party libraries, etc.).
- **Address Resolution:** It resolves references between different object files and assigns final memory addresses to all variables and functions.
- **Output:** The final output is typically an executable file, such as ``a.out`` (on Unix-like systems) or ``my_program.exe`` (on Windows).
``gcc my_program.o -o my_program``

### Summary of Compilation Steps
**1. Preprocessing:** Handle preprocessor directives, include headers, and expand macros.
**2. Compilation:** Analyze syntax and semantics, generate intermediate code, and perform optimizations.
**3. Assembly:** Convert intermediate code into machine code.
**4. Linking:** Combine object files and libraries to create the final executable.

### Steps of Compilation with Static and Dynamic Libraries
| **Step**              | **Static Library**                                                       | **Dynamic Library**                                                      |
|-----------------------|-------------------------------------------------------------------------|-------------------------------------------------------------------------|
| **1. Preprocessing**   | - Preprocessor directives processed.<br>- Header files included.<br>- Macros expanded. | - Same as static library.                                               |
| **2. Compilation**     | - Source code is compiled into intermediate code.<br>- Syntax and semantic checks performed.<br>- Intermediate representation generated. | - Same as static library.                                               |
| **3. Assembly**        | - Intermediate code is translated into machine code.<br>- Object file created. | - Same as static library.                                               |
| **4. Linking**         | - **Linking with Static Libraries**:<br>  - Object files combined with static libraries (e.g., `.a` files).<br>  - The linker includes the necessary object code from the static libraries into the final executable.<br>  - The final executable contains all the necessary code, leading to a larger file size. | - **Linking with Dynamic Libraries**:<br>  - Object files combined with dynamic libraries (e.g., `.so` on Linux, `.dll` on Windows).<br>  - The linker only includes references to the dynamic libraries, not their code.<br>  - The final executable is smaller and requires the dynamic libraries to be present at runtime. |
| **5. Execution**       | - The executable runs independently without requiring the static library files. | - The executable relies on the presence of the dynamic library files at runtime to function. |

</details>
<details>
<summary>What are the most common predefined macros</summary>

| **Macro**             | **Description**                                                 |
|-----------------------|---------------------------------------------------------------|
| `__DATE__`            | A string representing the date when the source file was compiled (in the format "Mmm dd yyyy"). |
| `__TIME__`            | A string representing the time when the source file was compiled (in the format "hh:mm:ss"). |
| `__FILE__`           | A string representing the name of the current input file (source file). |
| `__LINE__`           | An integer representing the current line number in the source file. |
| `__STDC__`           | Defined as 1 when the compiler conforms to the ANSI C standard. |
| `__cplusplus`        | Defined if the compiler is in C++ mode; it gives the version of the C++ standard being used (e.g., `201103L` for C++11). |
| `__GNUC__`           | The GNU C compiler version (major version number).            |
| `__GNUC_MINOR__`     | The minor version number of the GNU C compiler.               |
| `__VERSION__`        | A string representing the version of the compiler.            |
| `__cplusplus`        | A defined value that represents the C++ standard version.     |

</details>
details>
<summary>How to include guard your header files</summary>

### Steps to Include Guards in Your Header Files
**1. Use ``#ifndef`` (if not defined):** This checks if a specific macro (usually named after the header file) has not been defined.

**2. Define the Macro:** If the macro is not defined, define it.

**3. Include Your Header File Contents:** Place your header file's contents between the ``#ifndef`` and ``#endif`` directives.

- Use ``#endif``: This closes the conditional inclusion.

#### Example of Including Guards
```c
#ifndef MY_HEADER_H   // Check if MY_HEADER_H is not defined
#define MY_HEADER_H   // Define MY_HEADER_H

// Your header file contents go here
void my_function();

#endif // End of the include guard
```
</details>

## Tasks
### 0. Object-like Macro
Create a header file that defines a macro named ``SIZE`` as an abbreviation for the token ``1024``.
```bash
$ cat 0-main.c
#include "0-object_like_macro.h"
#include "0-object_like_macro.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int s;

    s = 98 + SIZE;
    printf("%d\n", s);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c -o a
$ ./a 
1122
```
### 1. Pi
Create a header file that defines a macro named ``PI`` as an abbreviation for the token ``3.14159265359``.
```bash
$ cat 1-main.c
#include "1-pi.h"
#include "1-pi.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    float a;
    float r;

    r = 98;
    a = PI * r * r;
    printf("%.3f\n", a);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c -o b
$ ./b
30171.855
```
  
### 2. File name
Write a program that prints the name of the file it was compiled from, followed by a new line.
```bash
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c -o c
$ ./c 
2-main.c
$ cp 2-main.c 02-main.c
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 02-main.c -o cc
$ ./cc
02-main.c
```  
### 3. Function-like macro
Write a function-like macro ``ABS(x)`` that computes the absolute value of a number ``x``.
```bash
$ cat 3-main.c
#include <stdio.h>
#include "3-function_like_macro.h"
#include "3-function_like_macro.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int i;
    int j;

    i = ABS(-98) * 10;
    j = ABS(98) * 10;
    printf("%d, %d\n", i, j);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c -o d
$ ./d 
980, 980
```
### 4. SUM
Write a function-like macro ``SUM(x, y)`` that computes the sum of the numbers ``x`` and ``y``.
```bash
$ cat 4-main.c
#include <stdio.h>
#include "4-sum.h"
#include "4-sum.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int s;

    s = SUM(98, 1024);
    printf("%d\n", s);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c -o e
$ ./e 
1122
```