# 0x14. C - Bit manipulation
## Resources

[Operators in C - Part 6](https://www.youtube.com/watch?v=egUyaWtsQc0&ab_channel=Jenny%27sLecturesCSIT)
[Operators in C - Part 7 (Bitwise Operators-II)](https://www.youtube.com/watch?v=LP0acaj3ZLE&ab_channel=Jenny%27sLecturesCSIT)
[Bitwise Operators 1: The AND Operation](https://www.youtube.com/watch?v=bizj3dle8Qc&ab_channel=ComputerScience%28KevinDrumm%29)
[Bitwise Operators 2: The OR Operation](https://www.youtube.com/watch?v=TMFnWGJEJuI&ab_channel=ComputerScience%28KevinDrumm%29)
[Bitwise Operators 3: The XOR Operation](https://www.youtube.com/watch?v=O9VELMn3jIY&ab_channel=ComputerScience%28KevinDrumm%29)
[Bitwise Operators 4: The Logical Shift Operation](https://www.youtube.com/watch?v=mjqswwqE1RQ&ab_channel=ComputerScience%28KevinDrumm%29)
[Bit Manipulation](https://pebble.gitbooks.io/learning-c-with-pebble/content/chapter12.html)
[Bitwise Operators](https://www.programiz.com/c-programming/bitwise-operators)

## Learning Objectives
details>
<summary>How to manipulate bits and use bitwise operators</summary>

### Bitwise operators
Bitwise operators allow you to manipulate individual bits of integers directly, which is useful for low-level programming, such as working with hardware, optimizing performance, or implementing certain algorithms.

#### 1. AND (``&``)
Compares two bits and returns ``1`` if both bits are ``1``, otherwise returns ``0``.
```c
int result = 5 & 3;  // 5 = 0101, 3 = 0011
// result = 0001 (1 in decimal)
```
#### 2. OR (``|``)
Compares two bits and returns 1 if at least one bit is 1, otherwise returns 0.
```c
int result = 5 | 3;  // 5 = 0101, 3 = 0011
// result = 0111 (7 in decimal)
```
**bitwise OR assignment operator**
The ``|=`` operator in C is a bitwise OR assignment operator. It combines two operations:

1. **Bitwise OR (``|``)**: This operator compares the bits of two operands and returns `1` for each bit position where at least one of the corresponding bits is `1`.
2. **Assignment (``=``)**: It assigns the result of the bitwise OR operation to the left-hand variable.
In short, ``|=`` performs a bitwise OR between the current value of a variable and another value, then assigns the result back to the variable.

```c
int a = 5;  // 5 in binary: 0101
a |= 3;     // 3 in binary: 0011, So after a |= 3, the value of a becomes 
```

#### 3. XOR (``^``)
Compares two bits and returns 1 if the bits are different, otherwise returns 0.
```c
int result = 5 ^ 3;  // 5 = 0101, 3 = 0011
// result = 0110 (6 in decimal)
```
#### 4. NOT (``~``)
Inverts all the bits of a number (flips 1 to 0 and 0 to 1).
```c
int result = ~5;  // 5 = 0101 (in 4 bits)
// result = 1010 (binary) which is -6 in two's complement
```
#### 5. Left Shift (``<<``)
Shifts all the bits of a number to the left by a specified number of positions. Each shift left multiplies the number by 2.
```c
int result = 5 << 1;  // 5 = 0101
// result = 1010 (10 in decimal)
```
#### 6. Right Shift (``>>``)
Shifts all the bits of a number to the right by a specified number of positions. Each shift right divides the number by 2, discarding the remainder.
```c
Copy code
int result = 5 >> 1;  // 5 = 0101
// result = 0010 (2 in decimal)
```
### How Bitmasks Work
Bitmasks are typically used with bitwise operators to manipulate specific bits. Let's break down some key uses of bitmasks:

#### 1. Setting Bits (Turning Specific Bits On)
To set (turn on) a specific bit, you can use a bitmask with a bitwise OR (``|``) operation. The bitmask will have a ``1`` in the position of the bit you want to set, and ``0`` in all other positions.

```c
int num = 0b1010;        // Binary 1010 (decimal 10)
int bitmask = 0b0100;    // Bitmask to set bit 2 (from the right)
num |= bitmask;          // Result: 1110 (decimal 14)
```
#### 2. Clearing Bits (Turning Specific Bits Off)
To clear (turn off) a specific bit, you can use a bitwise AND (``&``) operation with a bitmask that has ``0`` in the position of the bit to be cleared, and ``1`` everywhere else. You typically invert the bitmask with ``~``.

```c
int num = 0b1011;        // Binary 1011 (decimal 11)
int bitmask = 0b1101;    // Bitmask to clear bit 1 (from the right)
num &= bitmask;          // Result: 1001 (decimal 9)
```
#### 3. Toggling Bits (Flipping Specific Bits)
To toggle (flip) specific bits, use the bitwise XOR (``^``) operation with a bitmask that has ``1`` in the position of the bit to toggle, and 0 elsewhere. A ``1`` in the bitmask will flip the corresponding bit in the number.

```c
int num = 0b1010;        // Binary 1010 (decimal 10)
int bitmask = 0b0101;    // Bitmask to toggle bits 0 and 2
num ^= bitmask;          // Result: 1111 (decimal 15)
```
#### 4. Checking/Testing Bits
You can test whether specific bits are set (or cleared) by using a bitwise AND (&) with a bitmask. If the result is non-zero, the corresponding bit(s) in the number were set.

```c
int num = 0b1010;        // Binary 1010 (decimal 10)
int bitmask = 0b0010;    // Bitmask to check bit 1
if (num & bitmask) {
    // Bit 1 is set
} else {
    // Bit 1 is not set
}
```
### Bit manipulation use cases
#### 1. Set, Clear, and Toggle Specific Bits
- **Set a bit:** Turn on a specific bit in a number. `num |= (1 << pos);  // Set bit at position pos`
Example: Set the 3rd bit of ``num = 4`` (0100 in binary):
```c
num |= (1 << 2);    // num = 1100 (12 in decimal)
```
- **Clear a bit:** Turn off a specific bit in a number. `num &= ~(1 << pos);  // Clear bit at position pos`
Example: Clear the 3rd bit of num = 12 (1100 in binary):
```c
num &= ~(1 << 2);    // num = 0100 (4 in decimal)
```
- **Toggle a bit:** Flip a specific bit in a number. `num ^= (1 << pos);  // Toggle bit at position pos`

#### 2. Checking Even or Odd Numbers
The least significant bit (LSB) of an integer tells whether it is even or odd:
```c
if (num & 1) {
    // Number is odd
} else {
    // Number is even
}
```
#### 3. Counting the Number of Set Bits (Hamming Weight)
Counting the number of ``1``s in the binary representation of a number is useful for optimization problems, cryptography, and error detection.

*Brian Kernighan's algorithm:*
```c
int countSetBits(int num) {
    int count = 0;
    while (num) {
        num &= (num - 1);  // Removes the lowest set bit
        count++;
    }
    return count;
}
```
#### 4. Checking if a Number is a Power of Two
A number is a power of two if it has only one ``1`` bit set in its binary representation.
```c
if (num > 0 && (num & (num - 1)) == 0) {
    // num is a power of two
}
```
#### 5. Swapping Two Numbers Without a Temporary Variable
Using XOR to swap two variables:
```c
a = a ^ b;
b = a ^ b;
a = a ^ b;
```
#### 6. Extracting or Modifying Specific Bits
- **Extracting bits:** Use bitmasks to extract a subset of bits from a number. `int bits = (num >> pos) & mask;  // Shift and apply mask`
Example: Extract 3 bits starting from the 2nd bit (position 1):
```c
int num = 0b110101;  // Binary: 110101
int mask = 0b111;    // Mask: 111
int extracted = (num >> 1) & mask;  // Result: 101 (5 in decimal)
```
- **Modifying bits:** Clear the bits and then set new bits in their place.
```c
num &= ~(mask << pos);    // Clear bits
num |= (value << pos);    // Set new bits
```
#### 7. Fast Multiplication and Division by Powers of 2
You can use bit shifts to multiply or divide by powers of two:
- **Multiplication** by ``2^k``: Shift left by ``k``. `num = num << k;  // Equivalent to num * 2^k`
- **Division** by ``2^k``: Shift right by ``k``. `num = num >> k;  // Equivalent to num / 2^k`
#### 8. Generating All Subsets of a Set
Each subset of a set can be represented by a binary number, where a ``1`` in the i-th position means the i-th element is included in the subset. You can generate all subsets by iterating over all possible bitmasks.

Example for a set of size ``n``:
```c
for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            // Element i is in the subset
        }
    }
}
```
#### 9. Finding the Lowest or Highest Set Bit
- Finding the lowest set bit (i.e., the rightmost ``1``): `int lowestBit = num & (-num);`
- Clearing the lowest set bit: `num &= (num - 1);`
- Finding the highest set bit (most significant bit): `int pos = 31 - __builtin_clz(num);  // GCC compiler's built-in function`
#### 10. Bitwise Rotation
- **Circular left or right shifts:** Used in cryptography and hashing algorithms. In circular shifts, the bits that are shifted out are wrapped around to the other end.
    + Left circular shift:
    ```c
    int leftRotate(int num, int k) {
    return (num << k) | (num >> (32 - k));
    }
    ```
    + Right circular shift:
    ```c
    int rightRotate(int num, int k) {
    return (num >> k) | (num << (32 - k));
    }
    ```
#### 11. Gray Code Conversion
Gray code is a binary numeral system where two successive numbers differ by only one bit. It’s used in digital communication and analog-to-digital conversions to minimize errors.
*Convert binary to Gray code:*
```c
int gray = num ^ (num >> 1);
```
#### 12. Bitmasking for Efficient Memory Usage
When working with flags or boolean values, you can store multiple boolean states in a single integer using different bits. Each bit represents a separate boolean value, reducing memory usage.

Example: Storing multiple states in one variable:
```c
int flags = 0;
flags |= (1 << 0);  // Set bit 0 (Flag 1 ON)
flags |= (1 << 2);  // Set bit 2 (Flag 3 ON)

// Check if Flag 3 is ON
if (flags & (1 << 2)) {
    // Flag 3 is ON
}
```
#### 13. Reversing Bits
Reversing the bits of a number is commonly used in cryptography, graphics, and communication protocols.

Example for reversing an 8-bit number:
```c
int reverseBits(int num) {
    int rev = 0;
    for (int i = 0; i < 8; i++) {
        rev <<= 1;
        rev |= (num & 1);
        num >>= 1;
    }
    return rev;
}
```
### Summary
Bit manipulation allows for highly efficient operations that are often faster than traditional methods. It is frequently used in areas like:

- **System programming** (working with hardware, memory control).
- **Cryptography** (efficient data manipulation, encryption).
- **Graphics** (working with colors, images).
- **Game development** (state tracking, flag management).
- **Data compression** (encoding/decoding binary data).
</details>

## Tasks
### 0. 0
Write a function that converts a binary number to an ``unsigned int``.
**Prototype:** ``unsigned int binary_to_uint(const char *b);``
- where ``b`` is pointing to a string of ``0`` and ``1`` chars
- Return: the converted number, or 0 if
    + there is one or more chars in the string ``b`` that is not ``0`` or ``1``
    + ``b`` is ``NULL``

```bash
$ cat 0-main.c
#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    unsigned int n;

    n = binary_to_uint("1");
    printf("%u\n", n);
    n = binary_to_uint("101");
    printf("%u\n", n);
    n = binary_to_uint("1e01");
    printf("%u\n", n);
    n = binary_to_uint("1100010");
    printf("%u\n", n);
    n = binary_to_uint("0000000000000000000110010010");
    printf("%u\n", n);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-binary_to_uint.c -o a
$ ./a 
1
5
0
98
402
```
### 1. 1
Write a function that prints the binary representation of a number.

**Prototype:** ``void print_binary(unsigned long int n);``
- Format: see example
- You are not allowed to use arrays
- You are not allowed to use ``malloc``
- You are not allowed to use the ``%`` or ``/`` operators

```bash
$ cat 1-main.c 
#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_binary(0);
    printf("\n");
    print_binary(1);
    printf("\n");
    print_binary(98);
    printf("\n");
    print_binary(1024);
    printf("\n");
    print_binary((1 << 10) + 1);
    printf("\n");
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-print_binary.c _putchar.c -o b
$ ./b 
0
1
1100010
10000000000
10000000001
```
### 2. 10
Write a function that returns the value of a bit at a given index.

**Prototype:** ``int get_bit(unsigned long int n, unsigned int index);``
- where ``index`` is the index, starting from ``0`` of the bit you want to get
- Returns: the value of the bit at index ``index`` or ``-1`` if an error occured

```bash
$ cat 2-main.c
#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int n;

    n = get_bit(1024, 10);
    printf("%d\n", n);
    n = get_bit(98, 1);
    printf("%d\n", n);
    n = get_bit(1024, 0);
    printf("%d\n", n);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-get_bit.c -o c  
$ ./c
1
1
0
```
### 3. 11
Write a function that sets the value of a bit to ``1`` at a given index.

**Prototype:** ``int set_bit(unsigned long int *n, unsigned int index);``
- where ``index`` is the index, starting from ``0`` of the bit you want to set
- Returns: ``1`` if it worked, or ``-1`` if an error occurred

```bash
$ cat 3-main.c
#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    unsigned long int n;

    n = 1024;
    set_bit(&n, 5);
    printf("%lu\n", n);
    n = 0;
    set_bit(&n, 10);
    printf("%lu\n", n);
    n = 98;
    set_bit(&n, 0);
    printf("%lu\n", n);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-set_bit.c -o d
$ ./d
1056
1024
99
```
### 4. 100
Write a function that sets the value of a bit to ``0`` at a given index.

**Prototype:** ``int clear_bit(unsigned long int *n, unsigned int index);``
- where ``index`` is the index, starting from ``0`` of the bit you want to set
- Returns: ``1`` if it worked, or ``-1`` if an error occurred

```bash
$ cat 4-main.c
#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    unsigned long int n;

    n = 1024;
    clear_bit(&n, 10);
    printf("%lu\n", n);
    n = 0;
    clear_bit(&n, 10);
    printf("%lu\n", n);
    n = 98;
    clear_bit(&n, 1);
    printf("%lu\n", n);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 4-clear_bit.c -o e
$ ./e
0
0
96
```
### 5. 101
Write a function that returns the number of bits you would need to flip to get from one number to another.
**Prototype:** ``unsigned int flip_bits(unsigned long int n, unsigned long int m);``
- You are not allowed to use the ``%`` or ``/`` operators

```bash
$ cat 5-main.c
#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    unsigned int n;

    n = flip_bits(1024, 1);
    printf("%u\n", n);
    n = flip_bits(402, 98);
    printf("%u\n", n);
    n = flip_bits(1024, 3);
    printf("%u\n", n);
    n = flip_bits(1024, 1025);
    printf("%u\n", n);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-main.c 5-flip_bits.c -o f
$ ./f
2
5
3
1
``` 
### 6. Endianness
Write a function that checks the endianness.

**Prototype:** ``int get_endianness(void);``
- Returns: ``0`` if big endian, ``1`` if little endian

```bash
$ cat 100-main.c
#include <stdio.h>
#include "main.h"

int main(void)
{
    int n;

    n = get_endianness();
    if (n != 0)
    {
        printf("Little Endian\n");
    }
    else
    {
        printf("Big Endian\n");
    }
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 100-main.c 100-get_endianness.c -o h
$ ./h 
Little Endian
$ lscpu | head
Architecture:          x86_64
CPU op-mode(s):        32-bit, 64-bit
Byte Order:            Little Endian
CPU(s):                1
On-line CPU(s) list:   0
Thread(s) per core:    1
Core(s) per socket:    1
Socket(s):             1
NUMA node(s):          1
Vendor ID:             GenuineIntel
```  
### 7. Crackme3
Find the password for this [program](https://github.com/alx-tools/0x13.c).

- Save the password in the file ``101-password``
- Your file should contain the exact password, no new line, no extra space

```bash
$ ./crackme3 `cat 101-password`
Congratulations!
```