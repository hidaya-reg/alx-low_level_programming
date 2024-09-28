# 0x0A. C - argc, argv
## Resources
[Arguments to main](https://publications.gbdirect.co.uk//c_book/chapter10/arguments_to_main.html)
[argc and argv](http://crasseux.com/books/ctutorial/argc-and-argv.html)
[What does argc and argv mean?](https://www.youtube.com/watch?v=aP1ijjeZc24&ab_channel=PaulProgramming)
[how to compile with unused variables]()

## General
<details>
<summary>What are two prototypes of main that you know of, and in which case do you use one or the other</summary>

**Standard Prototype:** ``int main(void)`` when no arguments are needed.
**Argument Prototype:** ``int main(int argc, char *argv[])`` when you want to process command-line arguments.
</details>
<details>
<summary> How to use ``__attribute__((unused))`` or ``(void)`` to compile functions with unused variables or parameters</summary>

When you have variables or parameters in your functions that are not used, the compiler may issue warnings. You can use the following methods to suppress these warnings.

#### 1. Using `__attribute__((unused))`

You can annotate variables or function parameters with `__attribute__((unused))` to inform the compiler that the variable may not be used.

##### Example:
```c
#include <stdio.h>

void myFunction(int unusedParam __attribute__((unused))) {
    // Function body, unusedParam is intentionally unused
}

int main() {
    myFunction(42);
    return 0;
}
```
#### 2. Using (void)
Another approach is to explicitly cast the unused variable or parameter to (void), which tells the compiler that the variable is intentionally unused.

##### Example:
```c
#include <stdio.h>

void myFunction(int unusedParam) {
    (void)unusedParam;  // Suppresses unused variable warning
}

int main() {
    myFunction(42);
    return 0;
}
```
</details>

## Tasks
### 0. It ain't what they call you, it's what you answer to
Write a program that prints its ``name``, followed by a new line.

- If you rename the program, it will print the new name, without having to compile it again
- You should not remove the path before the name of the program
```bash
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-whatsmyname.c -o mynameis
$ ./mynameis 
./mynameis
$ mv mynameis mynewnameis
$ ./mynewnameis 
./mynewnameis
```
  
### 1. Silence is argument carried out by other means
Write a program that prints the number of arguments passed into it, followed by a new line.
```bash
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-args.c -o nargs
$ ./nargs 
0
$ ./nargs hello
1
$ ./nargs "hello, world"
1
$ ./nargs hello, world
2
```  
### 2. The best argument against democracy is a five-minute conversation with the average voter
Write a program that prints all arguments it receives.

- All arguments should be printed, including the first one
- Only print one argument per line, ending with a new line
```bash
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-args.c -o args
$ ./args 
./args
$ ./args You can do anything, but not everything.
./args
You
can
do
anything,
but
not
everything.
```
### 3. Neither irony nor sarcasm is argument
Write a program that multiplies two numbers.

- Your program should print the result of the multiplication, followed by a new line
- You can assume that the two numbers and result of the multiplication can be stored in an integer
- If the program does not receive two arguments, your program should print ``Error``, followed by a new line, and return ``1``.
```bash
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-mul.c -o mul
$ ./mul 2 3
6
$ ./mul 2 -3
-6
$ ./mul 2 0
0
$ ./mul 245 3245342
795108790
$ ./mul
Error
```
  
### 4. To infinity and beyond
Write a program that adds positive numbers.

- Print the result, followed by a new line
- If no number is passed to the program, print ``0``, followed by a new line
- If one of the number contains symbols that are not digits, print ``Error``, followed by a new line, and return ``1``
- You can assume that numbers and the addition of all the numbers can be stored in an ``int``
```bash
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-add.c -o add
$ ./add 1 1
2
$ ./add 1 10 100 1000
1111
$ ./add 1 2 3 e 4 5
Error
$ ./add
0
```
  
### 5. Minimal Number of Coins for Change
Write a program that prints the minimum number of coins to make change for an amount of money.

- Usage: ``./change cents``
- where ``cents`` is the amount of cents you need to give back
- if the number of arguments passed to your program is not exactly ``1``, print ``Error``, followed by a new line, and return ``1``
- you should use ``atoi`` to parse the parameter passed to your program
- If the number passed as the argument is negative, print ``0``, followed by a new line
- You can use an unlimited number of coins of values 25, 10, 5, 2, and 1 cent
```bash
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 100-change.c -o change
$ ./change 
Error
$ ./change 10
1
$ ./change 100
4
$ ./change 101
5
$ ./change 13
3
```