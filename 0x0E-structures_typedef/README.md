# 0x0E. C - Structures, typedef
## Resources

[0x0d. Structures.pdf](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/misc/2021/1/6eb80c79c99f6125450a0dc11b300d46238d1a5a.pdf?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20241004%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20241004T101329Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=d432585af23a2321ba1da3c3908391337183134eba4bc300f890d3a81e7d14b2)
[struct (C programming language)](https://en.wikipedia.org/wiki/Struct_(C_programming_language))
[Documentation: structures](https://github.com/alx-tools/Betty/wiki/Documentation:-Data-structures)
[0x0d. Typedef and structures.pdf](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/misc/2021/1/c8ff3e6f7202be7fa489a584e41d005504a07c23.pdf?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20241004%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20241004T102053Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=0633fabfe2cf10be79fb86531ed2a50b7c55c3487acf5b8ce1acd10baf362aa8)
[typedef](https://publications.gbdirect.co.uk//c_book/chapter8/typedef.html)

## Learning Objectives
<details>
<summary>What are structures, when, why and how to use them</summary>

### What are Structures?
A structure is a user-defined data type in C that allows you to combine different types of data. Each element within a structure is called a member. 

### Syntax of a Structure
The basic syntax for defining a structure is as follows:
```c
struct structure_name {
    data_type member1;
    data_type member2;
    // ... more members ...
};
```
### When to Use Structures
- **Grouping Related Data:** When you need to represent a single entity that has multiple attributes (e.g., a student with a name, ID, and age).
- **Complex Data Types:** When managing more complex data structures like linked lists, trees, or other data structures.
- **Clarity and Organization:** When you want to enhance code readability and maintainability by logically grouping data.

### Why Use Structures
- **Improved Organization:** Structures help keep related data together, making it easier to manage and understand.
- **Ease of Use:** Accessing members of a structure can be more intuitive than managing multiple variables separately.
- **Encapsulation:** Structures allow you to encapsulate data and related operations, which can help with data integrity and modularity.

**Example**
```c
#include <stdio.h>

// Define a structure for a student
struct Student {
    char name[50];
    int id;
    float grade;
};

int main() {
    // Declare a variable of type Student
    struct Student student1;

    // Assign values to the members
    strcpy(student1.name, "Alice"); // Use <string.h> for strcpy
    student1.id = 101;
    student1.grade = 89.5;

    // Access and print the members
    printf("Name: %s\n", student1.name);
    printf("ID: %d\n", student1.id);
    printf("Grade: %.2f\n", student1.grade);

    return 0;
}
```

### What is a Structure Pointer?
A structure pointer is a pointer that points to a structure type. It allows you to access the members of the structure using the pointer.

**Syntax for Declaring Structure Pointers**
``struct structure_name *ptr;``
### Steps to Use Structure Pointers
**1. Define a Structure:** Create a structure as you normally would.
**2. Declare a Structure Pointer:** Declare a pointer that will point to the structure.
**3. Allocate Memory:** Use dynamic memory allocation (e.g., with ``malloc``) if you need to allocate memory for the structure dynamically.
**4. Access Members:** Use the arrow operator (``->``) to access members of the structure through the pointer.

**Example** 
```c
#include <stdio.h>
#include <stdlib.h> // For malloc and free

// Define a structure for a student
struct Student {
    char name[50];
    int id;
    float grade;
};

int main() {
    // Declare a pointer to a Student structure
    struct Student *studentPtr;

    // Allocate memory for one Student structure
    studentPtr = (struct Student *)malloc(sizeof(struct Student));
    if (studentPtr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    // Assign values to the members using the pointer
    strcpy(studentPtr->name, "Alice"); // Use <string.h> for strcpy
    studentPtr->id = 101;
    studentPtr->grade = 89.5;

    // Access and print the members using the pointer
    printf("Name: %s\n", studentPtr->name);
    printf("ID: %d\n", studentPtr->id);
    printf("Grade: %.2f\n", studentPtr->grade);

    // Free the allocated memory
    free(studentPtr);

    return 0;
}
```
</details>
<details>
<summary>How to use typedef</summary>

The ``typedef`` keyword in C is used to create a new name (alias) for an existing type. This can improve code readability, simplify complex type definitions, and make it easier to manage data types.
**Syntax of typedef** : `typedef existing_type new_type_name;`
### Examples of Using typedef
#### 1. Using typedef with Basic Data Types
```c
typedef unsigned long ulong;
typedef int* IntPtr;

int main() {
    ulong number = 1234567890; // Now you can use 'ulong' instead of 'unsigned long'
    IntPtr ptr; // Now you can use 'IntPtr' as a pointer to int
    return 0;
}
```
#### 2. Using typedef with Structures
```c
#include <stdio.h>

// Define a structure for a point
struct Point {
    int x;
    int y;
};

// Create an alias for struct Point
typedef struct Point Point;

int main() {
    Point p1; // Now you can use 'Point' instead of 'struct Point'
    p1.x = 10;
    p1.y = 20;

    printf("Point: (%d, %d)\n", p1.x, p1.y);
    return 0;
}
```
#### 3. Using typedef with Function Pointers
```c
#include <stdio.h>

// Define a function pointer type
typedef void (*FuncPtr)(int);

// A sample function
void printNumber(int num) {
    printf("Number: %d\n", num);
}

int main() {
    FuncPtr fPtr = printNumber; // Using the typedef for a function pointer
    fPtr(5); // Call the function using the function pointer
    return 0;
}
```
</details>

## Tasks
### 0. Poppy
Define a new type ``struct dog`` with the following elements:

- ``name``, type = ``char *``
- ``age``, type = ``float``
- ``owner``, type = ``char *``
``` bash
$ cat 0-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    struct dog my_dog;

    my_dog.name = "Poppy";
    my_dog.age = 3.5;
    my_dog.owner = "Bob";
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c -o a
$ ./a 
My name is Poppy, and I am 3.5 :) - Woof!
```
### 1. A dog is the only thing on earth that loves you more than you love yourself
Write a function that initialize a variable of type ``struct dog``

**Prototype:** ``void init_dog(struct dog *d, char *name, float age, char *owner);``
```bash
$ cat 1-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    struct dog my_dog;

    init_dog(&my_dog, "Poppy", 3.5, "Bob");
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-init_dog.c -o b
$ ./b 
My name is Poppy, and I am 3.5 :) - Woof!
```  
### 2. A dog will teach you unconditional love. If you can have that in your life, things won't be too bad
Write a function that prints a ``struct dog``
**Prototype:** ``void print_dog(struct dog *d);``
- You are allowed to use the standard library
- If an element of ``d`` is ``NULL``, print ``(nil)`` instead of this element. (if ``name`` is ``NULL``, print ``Name: (nil)``)
- If ``d`` is ``NULL`` print nothing.
```bash
$ cat 2-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    struct dog my_dog;

    my_dog.name = "Poppy";
    my_dog.age = 3.5;
    my_dog.owner = "Bob";
    print_dog(&my_dog);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-print_dog.c -o c
$ ./c 
Name: Poppy
Age: 3.500000
Owner: Bob
```
### 3. Outside of a dog, a book is a man's best friend. Inside of a dog it's too dark to read
Define a new type ``dog_t`` as a new name for the type ``struct dog``.
```bash
$ cat 3-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    dog_t my_dog;

    my_dog.name = "Poppy";
    my_dog.age = 3.5;
    my_dog.owner = "Bob";
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c -o d
$ ./d 
My name is Poppy, and I am 3.5 :) - Woof!
```  
### 4. A door is what a dog is perpetually on the wrong side of
Write a function that creates a new dog.

**Prototype:** ``dog_t *new_dog(char *name, float age, char *owner);``
- You have to store a copy of ``name`` and ``owner``
- Return ``NULL`` if the function fails
```bash
$ cat 4-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    dog_t *my_dog;

    my_dog = new_dog("Poppy", 3.5, "Bob");
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog->name, my_dog->age);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 4-new_dog.c -o e
$ ./e
My name is Poppy, and I am 3.5 :) - Woof!
```  
### 5. How many legs does a dog have if you call his tail a leg? Four. Saying that a tail is a leg doesn't make it a leg
Write a function that frees dogs.

**Prototype:** ``void free_dog(dog_t *d);``
```bash
$ cat 5-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    dog_t *my_dog;

    my_dog = new_dog("Poppy", 3.5, "Bob");
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog->name, my_dog->age);
    free_dog(my_dog);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-main.c 5-free_dog.c 4-new_dog.c -o f
$ valgrind ./f
==22840== Memcheck, a memory error detector
==22840== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==22840== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==22840== Command: ./f
==22840== 
My name is Poppy, and I am 3.5 :) - Woof!
==22840== 
==22840== HEAP SUMMARY:
==22840==     in use at exit: 0 bytes in 0 blocks
==22840==   total heap usage: 4 allocs, 4 frees, 1,059 bytes allocated
==22840== 
==22840== All heap blocks were freed -- no leaks are possible
==22840== 
==22840== For counts of detected and suppressed errors, rerun with: -v
==22840== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```