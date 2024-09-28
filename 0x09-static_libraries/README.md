# 0x09. C - Static libraries

## Resources
[What Is A “C” Library? What Is It Good For?](https://docencia.ac.upc.edu/FIB/USO/Bibliografia/unix-c-libraries.html)
[Creating A Static “C” Library Using “ar” and “ranlib”](https://docencia.ac.upc.edu/FIB/USO/Bibliografia/unix-c-libraries.html)
[Using A “C” Library In A Program](https://docencia.ac.upc.edu/FIB/USO/Bibliografia/unix-c-libraries.html)
[What is difference between Dynamic and Static library(Static and Dynamic linking)](https://www.youtube.com/watch?v=eW5he5uFBNM&ab_channel=HowTo)(stop at 4:44)
**man or help:**
ar
ranlib
nm
## General
<details>
<summary>What is a static library, how does it work, how to create one, and how to use it</summary>

| **Topic**                      | **Details**                                                                                                                                      |
|--------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------|
| **Definition**                 | A static library is a collection of object files that are linked into a program during the *compilation process*, becoming part of the executable. |
| **Purpose**                    | To manage large projects efficiently, reduce compilation time, and organize code into manageable units.                                         |
| **Creation Tools**             | The primary tools for creating static libraries are `ar` (archiver) and `ranlib` (for indexing).                                               |
| **Creating a Library**         | Use the command: `ar rc libutil.a util_file.o util_net.o util_math.o` to create a static library named `libutil.a`.                          |
| **Indexing**                   | Run `ranlib libutil.a` to index the library for faster symbol lookup during compilation.                                                        |
| **Using a Library**            | Link the library in a program with: `cc main.o -L. -lutil -o prog`, where `-lutil` refers to `libutil.a` and `-L.` specifies the library path. |
| **Benefits of Static Libraries**| Faster linking times, reduced file clutter, and better project organization.                                                                    |
| **Drawbacks**                  | Larger executable size compared to shared libraries, as all object files are included in the executable.                                         |

</details>
<details>
<summary>Basic usage of `ar`, `ranlib` , `nm`</summary>

### `ar` (Archiver)
- **Create a Library**: `ar rc libname.a file1.o file2.o`
- **Update Library**: `ar rcs libname.a newfile.o` (adds new files and creates an index)
- **List Contents**: `ar t libname.a`

### `ranlib` (Generate Index)
- **Index a Library**: `ranlib libname.a` (creates or updates the index for faster symbol lookup)

### `nm` (List Symbols)
- **View Symbols**: `nm libname.a` (lists symbols in the library, showing their types and addresses)
- **Filter by Type**: `nm -g libname.a` (shows only global symbols)


| **Command** | **Overview**                                         | **Flags**                  | **Description**                                               | **Example**                            |
|-------------|------------------------------------------------------|----------------------------|---------------------------------------------------------------|----------------------------------------|
| `ar`        | Creates, modifies, and manages static libraries.     | `r`                        | Replace or add files to the archive.                         | `ar rcs libutil.a file1.o file2.o`   |
|             |                                                      | `c`                        | Create the archive if it doesn't exist.                     | `ar c libutil.a file1.o`              |
|             |                                                      | `t`                        | List the contents of the archive.                            | `ar t libutil.a`                       |
|             |                                                      | `s`                        | Create an index for the archive (often combined with `r`).  | `ar rcs libutil.a file1.o`            |
| `ranlib`    | Generates or updates the index of a static library.  | None                       | Used to index the library for faster symbol lookup.          | `ranlib libutil.a`                     |
| `nm`        | Lists symbols from object files or libraries.        | `-g`                       | Display only global symbols.                                 | `nm -g libutil.a`                      |
|             |                                                      | `-n`                       | Sort symbols by address.                                     | `nm -n libutil.a`                      |
|             |                                                      | `-p`                       | Display symbols in a plain format (no additional info).      | `nm -p libutil.a`                      |
| **Linking** | Links against libraries.                             | `-l`                       | Specify a library to link against (omit `lib` prefix and `.a`). | `gcc main.o -L. -lutil -o prog`       |


</details>

## Tasks
### 0. A library is not a luxury but one of the necessities of life
Create the static library ``libmy.a`` containing all the functions listed below:

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
If you haven’t coded all of the above functions create empty ones with the right prototype.
Don’t forget to push your ``main.h`` file to your repository. It should at least contain all the prototypes of the above functions.
```bash
$ ar -t libmy.a 
0-isupper.o
0-memset.o
0-strcat.o
1-isdigit.o
1-memcpy.o
1-strncat.o
100-atoi.o
2-strchr.o
2-strlen.o
2-strncpy.o
3-islower.o
3-puts.o
3-strcmp.o
3-strspn.o
4-isalpha.o
4-strpbrk.o
5-strstr.o
6-abs.o
9-strcpy.o
_putchar.o
$ nm libmy.a 

0-isupper.o:
0000000000000000 T _isupper

0-memset.o:
0000000000000000 T _memset

0-strcat.o:
0000000000000000 T _strcat

1-isdigit.o:
0000000000000000 T _isdigit

1-memcpy.o:
0000000000000000 T _memcpy

1-strncat.o:
0000000000000000 T _strncat

100-atoi.o:
0000000000000000 T _atoi

2-strchr.o:
0000000000000000 T _strchr

2-strlen.o:
0000000000000000 T _strlen

2-strncpy.o:
0000000000000000 T _strncpy

3-islower.o:
0000000000000000 T _islower

3-puts.o:
                 U _putchar
0000000000000000 T _puts

3-strcmp.o:
0000000000000000 T _strcmp

3-strspn.o:
0000000000000000 T _strspn

4-isalpha.o:
0000000000000000 T _isalpha

4-strpbrk.o:
0000000000000000 T _strpbrk

5-strstr.o:
0000000000000000 T _strstr

6-abs.o:
0000000000000000 T _abs

9-strcpy.o:
0000000000000000 T _strcpy

_putchar.o:
0000000000000000 T _putchar
                 U write
$ cat main.c 
#include "main.h"

int main(void)
{
    _puts("\"At the end of the day, my goal was to be the best hacker\"\n\t- Kevin Mitnick");
    return (0);
}
$ gcc -std=gnu89 main.c -L. -lmy -o quote
$ ./quote 
"At the end of the day, my goal was to be the best hacker"
    - Kevin Mitnick
```
### 1. Without libraries what have we? We have no past and no future
Create a script called ``create_static_lib.sh`` that creates a static library called ``liball.a`` from all the ``.c`` files that are in the current directory.

```bash
$ ls *.c
0-isupper.c  0-strcat.c  1-isdigit.c  1-strncat.c  2-strlen.c   3-islower.c  3-strcmp.c  4-isalpha.c  5-strstr.c  9-strcpy.c  _putchar.c
0-memset.c   100-atoi.c  1-memcpy.c   2-strchr.c   2-strncpy.c  3-puts.c     3-strspn.c  4-strpbrk.c  6-abs.c
$ ./create_static_lib.sh 
$ ls *.a
liball.a
$ ar -t liball.a
0-isupper.o
0-memset.o
0-strcat.o
100-atoi.o
1-isdigit.o
1-memcpy.o
1-strncat.o
2-strchr.o
2-strlen.o
2-strncpy.o
3-islower.o
3-puts.o
3-strcmp.o
3-strspn.o
4-isalpha.o
4-strpbrk.o
5-strstr.o
6-abs.o
9-strcpy.o
_putchar.o
```