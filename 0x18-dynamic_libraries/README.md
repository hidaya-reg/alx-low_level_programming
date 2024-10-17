# 0x18-dynamic_libraries
## Resources
[What is difference between Dynamic and Static library (Static and Dynamic linking)](https://www.youtube.com/watch?v=eW5he5uFBNM&ab_channel=HowTo)
[Creating a dynamic library in C](https://cylab.be/blog/234/creating-a-dynamic-library-in-c)
[Chapter 17. Creating libraries with GCC](https://docs.redhat.com/en/documentation/red_hat_enterprise_linux/7/html/developer_guide/creating-libraries-gcc)

## Learning Objectives
<details>
<summary>What is a dynamic library, how does it work, how to create one, and how to use it</summary>

### Dynamic Library
| **Aspect**             | **Shared (Dynamic) Library**                                                                 | **Static Library**                                                                        |
|------------------------|---------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------|
| **Definition**         | A library that is loaded at runtime and shared among multiple programs. It is not embedded in the executable. Usually has a ``.so`` (Linux) or ``.dll`` (Windows) extension. | A library that is fully included (statically linked) into the program’s executable at compile time. Usually has a ``.a`` (Linux) or ``.lib`` (Windows) extension. |
| **Purpose**            | Allows multiple programs to share the same library code in memory, reducing redundancy and improving resource efficiency. Can be updated independently of programs using it. | Used to include all necessary code into a single executable during compilation. The resulting executable becomes self-contained and doesn’t need external library files at runtime. |
| **Creation Tools**     | ``gcc``, ``g++``, ``ld`` with the ``-shared`` option, and ``-fPIC`` (Position Independent Code) flag.          | ``ar`` (Archiver), ``gcc``, ``g++``, or ``ld`` to compile and link the library into an archive using the ``.a`` format. |
| **Creating Libraries**  | 1. Compile source files into position-independent object files using ``-fPIC``.<br>2. Create a shared library using `gcc -shared -o libname.so file.o`. | 1. Compile source files into object files using `gcc -c`.<br>2. Create a static library using `ar rcs libname.a file.o`. |
| **Using Libraries**     | 1. During compilation, link the library using -L and -l options (e.g., `gcc -o main main.c -L. -lmylib`).<br>2. At runtime, ensure the dynamic linker finds the library by setting ``LD_LIBRARY_PATH``. | Link the library at compile time using the -L and -l options (e.g., `gcc -o main main.c -L. -lmylib`). Once linked, the entire library is embedded into the executable. No external files needed at runtime. |
| **Advantages**          | - Reduces executable size as the library is loaded dynamically.<br>- Allows multiple programs to share the same library in memory, saving resources.<br>- Library updates don’t require recompilation of dependent programs.<br>- Reduces overall disk space when the same library is used by many programs. | - The executable is self-contained, meaning it doesn’t rely on external files at runtime.<br>- Programs can work without needing library files at runtime, making distribution simpler.<br>- Faster execution time since no dynamic linking is required at runtime. |
| **Disadvantages**       | - Requires the library to be present at runtime, which can cause errors if the library is missing or not found.<br>- Slight overhead at program startup as the OS loads and links the library.<br>- Versioning issues: If the library changes in a backward-incompatible way, programs may break. | - Larger executable size, as the entire library is included in the program.<br>- Less efficient memory usage because each program has its own copy of the library, rather than sharing it.<br>- Updates require recompiling all programs that depend on the library. |
| **File Extension**      | ``.so`` (Shared Object) on Linux, ``.dll`` (Dynamic Link Library) on Windows.                      | ``.a`` (Archive) on Linux, ``.lib`` on Windows.                                                  |
| **Linking Time**        | Linked at **runtime**. The program has references to the shared library, which is resolved by the operating system when the program starts. | Linked at **compile time**. The entire library is included in the executable, so no linking is done at runtime. |
| **Memory Usage**        | Efficient: Multiple programs can share a single copy of the library in memory.             | Less efficient: Each program contains its own copy of the library, leading to higher memory usage. |
| **Updating Libraries**   | The library can be updated independently of the programs that use it. No need to recompile the program unless the API changes. | Updating the library requires the dependent programs to be recompiled to include the new version of the library. |
| **Versioning**          | Requires careful version management. Programs can break if the shared library changes in a backward-incompatible way. Version numbers can help manage compatibility (e.g., ``libmylib.so.1``, ``libmylib.so.2``). | No versioning issues because the library is statically included in the program. However, to update the library, you need to recompile the program with the new library. |
| **Execution Speed**     | Slightly slower due to runtime linking. However, this is negligible in most cases.         | Slightly faster since there is no runtime linking. All necessary code is included at compile time. |
| **Distribution**        | Easier distribution of multiple programs sharing the same library, but you need to ensure the library is distributed correctly alongside the executable. | Simpler distribution since everything is packed into the executable. No need to worry about distributing external libraries. |

#### Compile time vs Runtime
**1. Compile Time**
Compile time refers to the period when your source code is being converted into machine code (an executable file) by a **compiler**. This phase happens before your program can be executed.

- Key points:
    + Errors like syntax errors, type mismatches, and missing references are caught during compile time.
    + The code is analyzed and transformed into an executable binary that can be run later.
- With Static Libraries:
    + At compile time, when you use a static library, the compiler links the necessary functions from the library into the final executable.
    + The whole linking process is completed during compilation, so once the executable is created, it contains all the code it needs, including the static library code.
- Example (Static Linking):
```bash
gcc -o my_program my_program.c -L. -lmystaticlib
```
Here,`` mystaticlib.a`` is linked into ``my_program`` at compile time. After this, ``my_program`` will include the library functions directly, and there will be no need for the library anymore.
**2. Runtime**
Runtime refers to the period when the program is actually being **executed** (running) on the system. It’s when the code is actively doing what it's supposed to do—reading files, displaying output, or processing data.

- Key points:
    + Errors like logical errors, memory errors, and missing files typically happen during runtime.
    + When the program is running, it needs all necessary resources (like libraries) to be available.
- With Dynamic Libraries:
    + When you use a dynamic library, the linking happens **at runtime**. The compiled executable contains only **references** to the dynamic library, not the actual code.
    + When you run the program, the operating system looks for the required dynamic library (``.so`` or ``.dll`` file) and links it to the program **while it is running**.
- Example (Dynamic Linking):
```bash
gcc -o my_program my_program.c -L. -lmylib
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
./my_program
```
Here, ``libmylib.so`` is loaded and linked **when the program runs**. If ``libmylib.so`` is not available when the program runs, you’ll get an error.

#### Key Differences: Static vs Dynamic Libraries

| **Aspect**             | **Compile Time**                                         | **Runtime**                                        |
|------------------------|----------------------------------------------------------|----------------------------------------------------|
| **Definition**          | The phase during which the source code is translated into machine code (executable). | The phase when the compiled program is actually executed by the system. |
| **When It Occurs**      | Happens before the program is run, during the compilation of the code by the compiler. | Happens after the program has been compiled and is being executed. |
| **Errors**              | Errors detected at compile time are typically syntax errors, type-checking errors, and other static analysis errors. | Errors detected at runtime include logical errors, resource allocation errors, and exceptions like division by zero. |
| **Performance Impact**  | Optimization of the code is done at compile time, making it crucial for efficient execution. | Runtime performance is influenced by how the program is executed, including memory and processor management. |
| **Tools Involved**      | Compiler (e.g., GCC, Clang, etc.), linkers, and preprocessors. | Operating system, memory manager, and runtime environments (e.g., JVM for Java). |
| **Memory Usage**        | Memory allocation decisions (for static memory) can be made at compile time. | Dynamic memory allocation and resource management occur at runtime. |
| **Error Handling**      | Compilation will fail if errors are found, preventing program execution until resolved. | Runtime errors can cause the program to crash or throw exceptions that need to be handled by the code. |
| **Code Optimization**   | Most code optimization happens at compile time, such as inlining and dead code elimination. | Some optimizations can occur at runtime (just-in-time compilation), but most are predefined during compilation. |
| **Example Errors**      | Missing semicolon, undeclared variables, type mismatches. | Null pointer dereference, file not found, index out of bounds. |
| **Output**              | Produces an executable file that can be run.             | Produces the actual program behavior and output based on inputs. |
| **Program Visibility**  | The source code is visible to the compiler but not executed. | The compiled machine code is executed, and the results are visible to the user. |

#### Example of Compile-Time vs. Runtime Error:
**- Compile-Time Error:** Missing semicolon, undeclared variable, or a missing function reference.
This type of error will prevent the program from being compiled and must be fixed before you can run the program.
**- Runtime Error:** Dividing by zero, trying to access a missing file, or using a null pointer.
These errors occur while the program is running and can crash the program or cause unintended behavior.
</details>
<details>
<summary>What is the environment variable ``$LD_LIBRARY_PATH`` and how to use it</summary>

### Environment Variable ``$LD_LIBRARY_PATH``
The environment variable ``$LD_LIBRARY_PATH`` is used on Unix-like operating systems (e.g., Linux) to specify a list of directories where the system should search for dynamic (shared) libraries before using the default library paths. It helps the dynamic linker find and load the shared libraries required by your programs.

**Purpose:**
- When you run a program that uses shared libraries, the operating system needs to know where those libraries are located.
- By default, the dynamic linker looks in standard directories like ``/lib``, ``/usr/lib``, and ``/usr/local/lib``.
- ``$LD_LIBRARY_PATH`` allows you to override or extend these default search paths by specifying additional directories where the system should look for shared libraries.

**How It Works:**
When a program is executed, the dynamic linker (``ld.so`` or ``ld-linux.so``) checks:
1. The paths specified in the program's binary (using ``rpath``).
2. The directories listed in the ``$LD_LIBRARY_PATH`` environment variable.
3. The default system library directories (``/lib``, ``/usr/lib``, etc.).
If the linker finds the required shared libraries in any of these paths, it loads them for the program. If it can't find them, the program will fail with a "library not found" error.

**Example Usage:**
**1. Setting ``$LD_LIBRARY_PATH``:** You can temporarily set the ``$LD_LIBRARY_PATH`` for the current terminal session:
```bash
export LD_LIBRARY_PATH=/path/to/your/library:$LD_LIBRARY_PATH
```
This adds the directory ``/path/to/your/library`` to the list of directories to be searched for shared libraries.
**2. Running a Program with Custom Libraries:** After setting ``$LD_LIBRARY_PATH``, you can run a program that depends on shared libraries in your specified path:
```bash
./your_program
```
**3. Using Multiple Library Paths:** You can specify multiple directories by separating them with colons (``:``):
```bash
export LD_LIBRARY_PATH=/path/to/lib1:/path/to/lib2:$LD_LIBRARY_PATH
```
**4. Temporary Use for a Single Command:** Instead of setting ``$LD_LIBRARY_PATH`` for the entire session, you can set it only for a single command:
```bash
LD_LIBRARY_PATH=/path/to/your/library ./your_program
```
#### Important Notes:
**- Scope:** ``$LD_LIBRARY_PATH`` is typically set on a per-session basis. Once you close the terminal, it is reset unless set permanently.

**- Security:** Be cautious when using ``$LD_LIBRARY_PATH``, especially for system-wide programs. Incorrect or malicious paths can lead to unexpected behavior or security vulnerabilities.

Example of potential danger: Setting it globally in critical environments might cause system programs to load incorrect or compromised libraries.

#### Permanent Setting:
To make ``$LD_LIBRARY_PATH`` persist across terminal sessions, add it to your shell configuration file (``~/.bashrc``, ``~/.zshrc``, etc.):
```bash
export LD_LIBRARY_PATH=/path/to/your/library:$LD_LIBRARY_PATH
```
Then, run ``source ~/.bashrc`` to apply the changes.

</details>
<details>
<summary>Step-by-step on creating and using dynamic libraries in C on Linux systems</summary>

### Step-by-step on creating and using dynamic libraries
#### 1. Writing the Source Code
First, create a source file for the library.

**``mymath.c`` (Library Source Code)**
```c
// mymath.c
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

void greet() {
    printf("Hello from the dynamic library!\n");
}
```
**``subtraction.c`` (Another Library Source File)**
```c
// subtraction.c
int subtract(int a, int b) {
    return a - b;
}
```
#### 2. Compiling the Shared Library
- Compile each source file into position-independent object files into position-independent code (PIC) using the ``-fPIC`` option.
    ```bash
    gcc -c -fPIC mymath.c -o mymath.o
    gcc -c -fPIC subtraction.c -o subtraction.o
    ```
    This command compiles ``mymath.c`` into an object file (``mymath.o``) with position-independent code (``-fPIC``), which is necessary for creating shared libraries.
        + The -fPIC (Position Independent Code) flag is necessary when compiling object files that will be used to create shared (dynamic) libraries. This flag generates machine code that is position-independent, meaning the code can execute correctly regardless of where in memory it is loaded.
- Create a shared library that includes both object files
    ```bash
    gcc -shared -o libmymath.so mymath.o subtraction.o
    ```
    This command combines both object files into the shared library ``libmymath.so``.

#### 3. Using the Shared Library in Your Program
Now, you can create a program that uses the shared library.
**``main.c`` (Program Using the Library)**
```c
// main.c
#include <stdio.h>

// Function prototypes from the shared library
int add(int a, int b);
int subtract(int a, int b);
void greet();

int main() {
    int sum = add(10, 5);
    int difference = subtract(10, 5);

    printf("The result of 10 + 5 is: %d\n", sum);
    printf("The result of 10 - 5 is: %d\n", difference);

    greet(); // This is from mymath.c
    return 0;
}
```
#### 4. Compiling the Program with the Shared Library
When you compile the program, you need to:
- Specify the library path using -L.
- Specify the library name using -l.
Compile the program:
```bash
gcc -o main main.c -L. -lmymath
```
Here:

-``L.`` tells the compiler to look for libraries in the current directory (.).
-``lmymath`` tells the compiler to link with the ``libmymath.so`` library (you omit the lib prefix and .so extension when specifying the library name).
#### 5. Set ``LD_LIBRARY_PATH`` and Run the Program
Before running the program, you need to make sure the system can find the shared library. The operating system searches for shared libraries in several default directories (/lib, /usr/lib, etc.).

- Set ``LD_LIBRARY_PATH``:
    ```bash
    export LD_LIBRARY_PATH=.
    ```
    This command tells the system to look for shared libraries in the current directory (``.``).

- Run the program:
```bash
./main
```
#### 6. Installing the Shared Library (Optional)
If you want the shared library to be available globally (without setting ``LD_LIBRARY_PATH``), you can install it in one of the standard library directories, such as ``/usr/lib`` or /usr/local/lib.

- Copy the library to /usr/local/lib:
    ```bash
    sudo cp libmymath.so /usr/local/lib/
    ```
- Update the linker cache:
    ```bash
    sudo ldconfig
    ```
Now, the system will be able to find ``libmymath.so`` automatically when you run your program, and you won’t need to set ``LD_LIBRARY_PATH``.

##### Note
Once you've created the shared library ``libmymath.so``, if you want to add additional object files later, you cannot directly modify the existing ``libmymath.so`` file. Instead, you need to recreate the shared library by combining the new object file with the existing ones.
#### Summary
**1. Write the source code:** Create a ``.c`` file containing the functions for the shared library.
**2. Compile the shared library:** Use ``gcc -c -fPIC`` to create an object file, then ``gcc -shared`` to create the shared library (``.so`` file).
**3. Use the library in a program:** Write a program that includes the library’s functions and compile it with ``gcc -L`` and ``-l`` options to link the shared library.
**4. Set ``LD_LIBRARY_PATH`` or install:** Ensure the dynamic linker can find your shared library by either setting ``LD_LIBRARY_PATH`` or installing the library globally.
</details>
<details>
<summary>Effect on changing an object file on the library</summary>

### Effect on changing an object file on the library
If you change an object file, such as updating ``substraction.c``, the effect on the library depends on whether you're using static or dynamic linking.

#### 1. Static Library (``.a``):
+ When you modify ``substraction.c`` and recompile it into an object file (``substraction.o``), the change will not automatically affect any existing static library (``libmymath.a``).
+ To update the static library, you need to re-add the updated object file into the archive using ``ar``:
```bash
gcc -c substraction.c -o substraction.o
ar rcs libmymath.a substraction.o
```
+ Once the library is updated, any program using the static library must be recompiled to include the updated code, since the executable will embed a copy of the library at compile time.
```bash
gcc main.c -L. -lmymath -o program
```
#### 2. Dynamic Library (``.so``):
+ When you modify ``substraction.c``, recompile it into an object file (``substraction.o``), and update the shared library (``libmymath.so``), programs using the shared library will automatically pick up the change at runtime, as the linking happens dynamically.
+ To update the shared library:
```bash
gcc -fPIC -c substraction.c -o substraction.o
gcc -shared -o libmymath.so substraction.o other.o
```
+ You **don't** need to recompile programs that use this library, as long as the API (function signatures) hasn’t changed. The change in behavior will take effect the next time the program is run.
#### Summary:
- Static Library: Rebuild the library and recompile programs to see the changes.
- Dynamic Library: Rebuild the library, and changes will be applied the next time the program runs without recompilation.
</details>
<details>
<summary>Basic usage ``nm``, ``ldd``, ``ldconfig``</summary>

### Basic usage nm, ldd, ldconfig
``nm``, ``ldd``, and ``ldconfig`` are tools commonly used when working with libraries in Linux.

#### 1. ``nm`` — List Symbols in Object Files and Libraries
The ``nm`` command displays the symbols (variables, functions, etc.) from object files, static libraries (``.a``), or shared libraries (``.so``). This is useful to inspect what symbols are defined or used in a file.
**Basic Usage:** ``nm <file>``

**Symbols can be marked as:**
- T: Defined in the text (code) section.
- U: Undefined (used but not defined in this file).
- D: Defined in the data section.
**Usage Scenarios:**
- Checking what functions or variables a library or object file contains.
- Debugging symbol visibility issues.
#### 2. ldd — List Shared Library Dependencies
The ``ldd`` command shows the shared libraries that a program or a shared library depends on. It is useful for checking if the required dynamic libraries are correctly linked and available.
**Basic Usage:** ``ldd <file>``
Example : `ldd ./program`
**Key Output:**
- Lists the shared libraries the program uses along with their paths.
- Shows whether each library is found (``=> /path/to/lib.so``) or missing (``=> not found``).
**Usage Scenarios:**
- Ensuring all required shared libraries are available before running a program.
- Diagnosing missing library issues at runtime.
#### 3. ``ldconfig`` — Configure Dynamic Linker Run-Time Bindings
The ``ldconfig`` command is used to update and maintain the cache of shared libraries (``/etc/ld.so.cache``). It helps the dynamic linker find shared libraries at runtime. After installing new shared libraries, run ``ldconfig`` to make the system aware of them.
**Basic Usage:** `sudo ldconfig`
**Example:** `sudo ldconfig /usr/local/lib`
**Key Points:**
- ``ldconfig`` updates the cache that the linker uses to quickly locate shared libraries.
- You can add custom paths (e.g., ``/usr/local/lib``) to ``LD_LIBRARY_PATH`` or add them to ``/etc/ld.so.conf`` and run ``ldconfig`` to make sure they are recognized.
**Usage Scenarios:**
- After creating or installing shared libraries.
- Ensuring that new shared libraries are correctly registered and available system-wide.

</details>

## Tasks
### 0. A library is not a luxury but one of the necessities of life
Create the dynamic library libdynamic.so containing all the functions listed below:
```c
int _putchar(char c);
int _islower(int c);
int _isalpha(int c);
int _abs(int n);
int _isupper(int c);
int _isdigit(int c);
int _strlen(char *s);
void _puts(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);
```
If you haven’t coded all of the above functions create empty ones, with the right prototype.
Don’t forget to push your ``main.h`` file in your repository, containing at least all the prototypes of the above functions.
```bash
$ ls -la lib*
-rwxrwxr-x 1 julien julien 13632 Jan  7 06:25 libdynamic.so
$ nm -D libdynamic.so 
0000000000000a90 T _abs
0000000000000aa9 T _atoi
0000000000202048 B __bss_start
                 w __cxa_finalize
0000000000202048 D _edata
0000000000202050 B _end
00000000000011f8 T _fini
                 w __gmon_start__
0000000000000900 T _init
0000000000000bd7 T _isalpha
0000000000000c04 T _isdigit
0000000000000c25 T _islower
0000000000000c46 T _isupper
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
                 w _Jv_RegisterClasses
0000000000000c67 T _memcpy
0000000000000caa T _memset
0000000000000ce9 T _putchar
0000000000000d0e T _puts
0000000000000d4a T _strcat
0000000000000dcf T _strchr
0000000000000e21 T _strcmp
0000000000000e89 T _strcpy
0000000000000eeb T _strlen
0000000000000f15 T _strncat
0000000000000fa5 T _strncpy
0000000000001029 T _strpbrk
000000000000109d T _strspn
0000000000001176 T _strstr
                 U write
$ cat 0-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    printf("%d\n", _strlen("My Dyn Lib"));
    return (EXIT_SUCCESS);
}
$ gcc -Wall -pedantic -Werror -Wextra -L. 0-main.c -ldynamic -o len
$ ldd len 
    linux-vdso.so.1 =>  (0x00007fff5d1d2000)
    libdynamic.so => not found
    libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f74c6bb9000)
    /lib64/ld-linux-x86-64.so.2 (0x0000556be5b82000)
$ export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
$ ldd len
    linux-vdso.so.1 =>  (0x00007fff41ae9000)
    libdynamic.so => ./libdynamic.so (0x00007fd4bf2d9000)
    libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fd4beef6000)
    /lib64/ld-linux-x86-64.so.2 (0x0000557566402000)
$ ./len 
10
```
### 1. Without libraries what have we? We have no past and no future
Create a script that creates a dynamic library called ``liball.so`` from all the ``.c`` files that are in the current directory.
```bash
$ ls *.c
abs.c   isalpha.c  islower.c  memcpy.c  putchar.c  strcat.c  strcmp.c  strlen.c   strncpy.c  strspn.c
atoi.c  isdigit.c  isupper.c  memset.c  puts.c     strchr.c  strcpy.c  strncat.c  strpbrk.c  strstr.c
$ ./1-create_dynamic_lib.sh 
$ nm -D --defined-only liball.so 
0000000000000a90 T _abs
0000000000000aa9 T _atoi
0000000000202048 B __bss_start
0000000000202048 D _edata
0000000000202050 B _end
00000000000011f8 T _fini
0000000000000900 T _init
0000000000000bd7 T _isalpha
0000000000000c04 T _isdigit
0000000000000c25 T _islower
0000000000000c46 T _isupper
0000000000000c67 T _memcpy
0000000000000caa T _memset
0000000000000ce9 T _putchar
0000000000000d0e T _puts
0000000000000d4a T _strcat
0000000000000dcf T _strchr
0000000000000e21 T _strcmp
0000000000000e89 T _strcpy
0000000000000eeb T _strlen
0000000000000f15 T _strncat
0000000000000fa5 T _strncpy
0000000000001029 T _strpbrk
000000000000109d T _strspn
0000000000001176 T _strstr
``` 
### 2. Let's call C functions from Python
I know, you’re missing C when coding in Python. So let’s fix that!

Create a dynamic library that contains C functions that can be called from Python. See example for more detail.
```bash
$ cat 100-tests.py
import random
import ctypes

cops = ctypes.CDLL('./100-operations.so')
a = random.randint(-111, 111)
b = random.randint(-111, 111)
print("{} + {} = {}".format(a, b, cops.add(a, b)))
print("{} - {} = {}".format(a, b, cops.sub(a, b)))
print("{} x {} = {}".format(a, b, cops.mul(a, b)))
print("{} / {} = {}".format(a, b, cops.div(a, b)))
print("{} % {} = {}".format(a, b, cops.mod(a, b)))
julien@ubuntu:~/0x16. Doubly linked lists$ python3 100-tests.py 
66 + -76 = -10
66 - -76 = 142
66 x -76 = -5016
66 / -76 = 0
66 % -76 = 66
$ python3 100-tests.py 
-34 + -57 = -91
-34 - -57 = 23
-34 x -57 = 1938
-34 / -57 = 0
-34 % -57 = -34
$ python3 100-tests.py 
-5 + -72 = -77
-5 - -72 = 67
-5 x -72 = 360
-5 / -72 = 0
-5 % -72 = -5
$ python3 100-tests.py 
39 + -62 = -23
39 - -62 = 101
39 x -62 = -2418
39 / -62 = 0
39 % -62 = 39
```
### 3. Code injection: Win the Giga Millions!
I bought a ticket for the Giga Millions and chose these numbers: 9, 8, 10, 24, 75 + 9. If you could run two commands on the same server where the Giga Millions program runs, could you make me win the Jackpot?

Our mole got us a copy of the program, you can download it [here](https://github.com/alx-tools/0x18.c). Our mole also gave us a piece of documentation:
```
/* Giga Millions program                                                                                    
  * Players may pick six numbers from two separate pools of numbers:                                                
  * - five different numbers from 1 to 75 and                                                                       
  * - one number from 1 to 15                                                                                       
  * You win the jackpot by matching all six winning numbers in a drawing.                                           
  * Your chances to win the jackpot is 1 in 258,890,850                                                             
  *                                                                                                                 
  * usage: ./gm n1 n2 n3 n4 n5 bonus
```
- You can’t modify the program ``gm`` itself as Master Sysadmin Sylvain (MSS) always checks its [MD5](https://github.com/alx-tools/0x18.c/blob/master/101-md5_gm) before running it
- The system is an Linux Ubuntu ``16.04``
- The server has internet access
- Our mole will be only able to run two commands from a shell script, without being detected by MSS
- Your shell script should be maximum 3 lines long. You are not allowed to use ``;``, ``&&``, ``||``, ``|``, ` (it would be detected by MSS), and have a maximum of two commands
- Our mole has only the authorization to upload one file on the server. It will be your shell script
- Our mole will run your shell script this way: ``mss@gm_server$ . ./101-make_me_win.sh``
- Our mole will run your shell script from the same directory containing the program ``gm``, exactly 98 seconds before MSS runs ``gm`` with my numbers: ``./gm 9 8 10 24 75 9``
- MSS will use the same terminal and session than our mole
- Before running the ``gm`` program, MSS always check the content of the directory
- MSS always exit after running the program ``gm``
- TL;DR; This is what is going to happen
```bash
mss@gm_server$ . ./101-make_me_win.sh
mss@gm_server$ rm 101-make_me_win.sh
mss@gm_server$ ls -la
. .. gm
mss@gm_server$ history -c
mss@gm_server$ clear
mss@gm_server$ ls -la
. .. gm
mss@gm_server$ md5sum gm
d52e6c18e0723f5b025a75dea19ef365  gm
mss@gm_server$ ./gm 9 8 10 24 75 9
--> Please make me win!
mss@gm_server$ exit
```
Tip: ``LD_PRELOAD``