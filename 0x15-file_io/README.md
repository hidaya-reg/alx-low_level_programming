# 0x15. C - File I/O
## Resources
[File descriptors](https://en.wikipedia.org/wiki/File_descriptor)
[C Programming in Linux Tutorial #024 - open() read() write() Functions](https://www.youtube.com/watch?v=e-srF6c3TJ8&ab_channel=ProgrammingKnowledge)

## Learning Objectives

<details>
<summary>How to create, open, close, read and write files</summary>

### File Operations
In C, file operations (creating, opening, closing, reading, and writing) are handled using standard I/O functions from the ``<stdio.h>`` library.

#### 1. Opening a File
To open a file, use the ``fopen()`` function. It returns a pointer to the ``FILE`` structure, which is used for further operations on the file.
```c
#include <stdio.h>

FILE *file = fopen("example.txt", "w");  // Opens the file for writing
if (file == NULL) {
    // Error handling if file couldn't be opened
    printf("Error opening file!\n");
}
```
**File modes:**
``"r"`` – Open for reading (file must exist).
``"w"`` – Open for writing (creates an empty file or truncates it if it exists).
``"a"`` – Open for appending (writes data at the end of the file).
``"r+"`` – Open for reading and writing.
``"w+"`` – Open for reading and writing (creates/truncates the file).
``"a+"`` – Open for reading and appending.

#### 2. Closing a File
After finishing with a file, it should be closed using the ``fclose()`` function to release any resources.
`fclose(file);`

#### 3. Writing to a File
To write data to a file, you can use fprintf() or fputs() for text files or fwrite() for binary files.
##### 3.1 `fprintf()`
- Used for formatted output, similar to ``printf()``.
- Supports format specifiers like ``%d``, ``%f``, ``%s``, etc., for writing different data types.
- Can be used to write both strings and other data types (integers, floats, etc.) into a file.
**Example with fprintf():**
```c
int age = 25;
float salary = 3000.50;

FILE *file = fopen("example.txt", "w");
if (file != NULL) {
    fprintf(file, "Age: %d, Salary: %.2f\n", age, salary);
    fclose(file);
}
```
This will write: `Age: 25, Salary: 3000.50`
##### 3.2 `fputs()`
- Simpler function to write strings (character arrays) to a file.
- It only writes raw strings, without any format specifiers.
- Cannot handle variables or different data types directly.
- Useful for writing a string as-is into a file.
```c
FILE *file = fopen("example.txt", "w");
if (file != NULL) {
    fputs("Hello, World!\n", file);
    fclose(file);
}
```
##### 3.3 `fwrite()`
- Used for writing binary data or blocks of data to a file.
- Writes raw bytes from memory (arrays, structs, etc.), rather than formatted or string data.
- Typically used when working with binary files or large chunks of data.
- You specify the number of items and the size of each item to write
**Syntax:** `size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);`
- ``ptr``: Pointer to the data you want to write.
- ``size``: Size of each element in bytes.
- ``nmemb``: Number of elements to write.
- ``stream``: The file pointer.
**Example with fwrite() (for binary files):**
```c
FILE *file = fopen("example.bin", "wb");
int data = 100;
if (file != NULL) {
    fwrite(&data, sizeof(int), 1, file);
    fclose(file);
}
```
##### Key differences
| Function  | Purpose                          | Data Type              | Formatting Support | Usage                            |
|-----------|----------------------------------|------------------------|--------------------|----------------------------------|
| `fprintf` | Formatted text output             | Text                   | Yes                | Writing formatted text with variables, numbers, etc. |
| `fputs`   | Writes a raw string to a file     | String (character array)| No                 | Writing plain text (no formatting or variables)      |
| `fwrite`  | Writes binary data to a file      | Binary (memory blocks)  | No                 | Writing raw data (arrays, structs, binary files)     |

#### 4. Reading from a File
To read data from a file, you can use ``fscanf()`` or ``fgets()`` for text files and ``fread()`` for binary files.
##### 4.1 `fscanf()`
- Used for formatted input from a file, similar to ``scanf()``, but reads from a file instead of standard input.
- It reads text from a file and parses the input according to the specified format specifiers (``%d``, ``%s``, ``%f``, etc.).
- Suitable for reading formatted data (e.g., structured records or known formats)

**Example with ``fscanf()``:**
```c
int age;
float salary;
FILE *file = fopen("example.txt", "r");
if (file != NULL) {
    fscanf(file, "%d %f", &age, &salary);
    fclose(file);
}
```
##### 4.2 `fgets()`
- Used to read a whole line of text from a file, including spaces, until a newline or the specified number of characters is reached.
- It reads a string into a buffer (character array) and adds a null terminator (\0) at the end of the string.
- Ideal for reading entire lines or blocks of text.
**Example with ``fgets()`` (reads a whole line):**
```c
FILE *file = fopen("example.txt", "r");
if (file != NULL) {
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}
```
##### 4.3 ``fread()``:
- Used to read binary data from a file, typically used with raw memory (arrays, structs).
- Reads a specified number of elements of a given size from the file and stores them in memory.
- Useful for reading binary files, serialized data, or chunks of raw data (not human-readable).
**Syntax:** ``size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);``
``ptr``: Pointer to the memory location where data will be stored.
``size``: Size of each element to read.
``nmemb``: Number of elements to read.
``stream``: The file pointer
**Example:**
```c
int data[5];
FILE *file = fopen("example.bin", "rb");
if (file != NULL) {
    fread(data, sizeof(int), 5, file);  // Read 5 integers from the file
    fclose(file);
}
```
##### Key differences
| Function  | Purpose                          | Data Type              | Formatting Support | Usage                            |
|-----------|----------------------------------|------------------------|--------------------|----------------------------------|
| `fscanf`  | Formatted input from a file       | Text (formatted)       | Yes                | Reading structured or formatted data (e.g., numbers, strings, etc.) |
| `fgets`   | Reads a line of text              | Text (strings)         | No                 | Reading lines or blocks of text from a file                         |
| `fread`   | Reads binary data from a file     | Binary (memory blocks) | No                 | Reading raw binary data (arrays, structs, etc.)                     |

</details>
<details>
<summary>What are file descriptors</summary>

### File descriptors
File descriptors (FDs) are integral to how Unix-like operating systems, including Linux, manage input/output (I/O) resources. Here’s a breakdown of what file descriptors are and their significance:

#### Definition:
- A **file descriptor** is a non-negative integer that uniquely identifies an open file or other input/output resource within a process.
- In Unix/Linux, file descriptors are used to manage files, sockets, pipes, and other I/O streams.

#### Key Points:
##### 1. Standard File Descriptors:
- By default, when a process starts, it has three standard file descriptors:
    + 0: Standard Input (stdin) – used for input, usually the keyboard.
    + 1: Standard Output (stdout) – used for output, usually the terminal or console.
    + 2: Standard Error (stderr) – used for error messages, also usually the terminal or console.

##### 2. Usage:
- When a file is opened, the operating system assigns a file descriptor to it. This descriptor is then used in system calls (like ``read()``, ``write()``, ``close()``) to perform operations on the file.
- For example, after opening a file, you might use the returned file descriptor to read from or write to that file.

##### 3. File Descriptor Table:
- Each process has a file descriptor table that keeps track of the file descriptors and the corresponding file objects.
- The File Descriptor Table contains:
    + The **file descriptor** (FD),
    + The **file offset** (position in the file),
    + The **access mode** (read/write), and
    + A **pointer to the Open File Table** which contains the actual metadata (like the file's name and its inode).

##### 4. Each process has its own File Descriptor Table:

- The **File Descriptor Table** is a data structure maintained by the operating system for each process. It maps file descriptors (small integers) to entries in the system-wide **Open File Table (OFT)**.
- When a process opens a file (using open() or similar functions), the operating system creates a new entry in the process's FDT that points to the corresponding entry in the OFT.
- The file descriptors (like ``0`` for stdin, ``1`` for stdout, ``2`` for stderr, and others) are specific to each process. For example, file descriptor ``3`` in one process might refer to a different file than file descriptor ``3`` in another process.
File descriptor numbers are reused:
- The file descriptor numbers (like ``3``, ``4``, ``5``) are unique within a process but can be reused by other processes. They are simply indexes in that process's File Descriptor Table.
Shared Open File Table (OFT):
- While the FDT is per process, the Open File Table is shared across the entire system. This table contains details like the file's current position, access mode, and the reference count.
- If multiple processes open the same file, their file descriptors may point to the same entry in the Open File Table, but they will each have their own entry in their respective File Descriptor Tables.
##### 5. Operations:

- **Creating a file descriptor:** When you open a file using system calls like ``open()``, a file descriptor is created.
- **Reading and writing:** You can use functions like ``read()`` and ``write()`` with file descriptors to handle I/O.
- **Closing a file descriptor:** When you're done with a file, you should close the file descriptor using close(), which releases the resource.

##### 6. Limitations:

There is a limit to the number of file descriptors a process can have open at any time. This limit can usually be adjusted through system settings.

#### Example in C:
```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    // Open a file
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read from the file
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        return EXIT_FAILURE;
    }

    // Null-terminate the buffer and print it
    buffer[bytesRead] = '\0';
    printf("Read %ld bytes: %s\n", bytesRead, buffer);

    // Close the file descriptor
    close(fd);
    return EXIT_SUCCESS;
}
```      
### Summary of Usage

- **File Operations**: `open()`, `read()`, `write()`, and `close()` are fundamental for file I/O.
- **File Descriptor Management**: `lseek()`, `fcntl()`, `dup()`, and `dup2()` are commonly used to manage and manipulate file descriptors.
- **I/O Monitoring**: `poll()` and `select()` are essential for handling asynchronous I/O, particularly in network programming or applications requiring multiple input sources.
- **Device Control**: `ioctl()` is used for controlling device-specific operations, while `mmap()` allows memory-mapped file access for performance optimization.

### `open()` vs `fopen()`
``open`` and ``fopen`` are both functions used to open files in C, but they belong to different libraries and have different usage patterns and features.

| Feature                   | `open`                                      | `fopen`                                      |
|---------------------------|---------------------------------------------|----------------------------------------------|
| **Library**               | `<fcntl.h>` (POSIX)                        | `<stdio.h>` (C Standard Library)            |
| **Function Signature**    | `int open(const char *pathname, int flags, mode_t mode);` | `FILE *fopen(const char *filename, const char *mode);` |
| **Return Type**           | Returns a file descriptor (int)            | Returns a pointer to `FILE`                  |
| **Error Indication**      | Returns -1 on error; use `errno` for details | Returns `NULL` on error; use `perror` or `strerror(errno)` |
| **I/O Model**             | Unbuffered I/O                             | Buffered I/O                                 |
| **Mode Specification**    | Uses flags (e.g., `O_RDONLY`, `O_WRONLY`) | Uses a string (e.g., `"r"`, `"w"`)          |
| **File Permissions**      | Takes a mode argument for new files        | No file permission specification              |
| **Error Handling**        | Check return value and `errno`             | Check for `NULL`                             |
| **Use Cases**             | Low-level file manipulation (e.g., sockets, pipes) | General file operations (formatted I/O)     |
| **Closing Files**         | `close(fd)`                                | `fclose(file)`                               |
| **File Positioning**      | Manual positioning using `lseek`           | Automatic handling via `FILE` stream         |

#### Use cases of `open()`:
common use cases where you might prefer ``open()`` over ``fopen()`` in C:
**1. Low-Level File Operations:** When you need to perform low-level operations, such as manipulating file descriptors, using ``open()`` is more appropriate. For instance, if you're working with sockets or pipes, ``open()`` provides the necessary functionality.
**2. File Permissions:** If you need to create a new file with specific permissions (e.g., when using ``O_CREAT``), ``open()`` allows you to specify a mode (permissions) for the file. ``fopen()`` does not provide this feature when opening existing files.
**3. Atomic Operations:** ``open()`` can be used with flags like ``O_CREAT | O_EXCL``, which ensures that a new file is created only if it does not already exist. This atomicity can be critical in concurrent environments to avoid race conditions.
**4. Non-Buffered I/O:** If you require non-buffered I/O for specific performance reasons, ``open()`` is the right choice. It gives you direct control over the I/O operations without the overhead of buffering.
**5. File Descriptor Manipulation:** ``open()`` allows you to directly work with file descriptors, which can be useful for advanced file operations, such as duplicating file descriptors with ``dup()`` or redirecting standard input/output.
**6. Working with Device Files:** When dealing with special files (like device files in ``/dev``), `open()` is necessary, as it directly interacts with the kernel and the underlying hardware.
**7. Access Control:** The ``open()`` function can be used with the ``O_RDONLY``, ``O_WRONLY``, and ``O_RDWR`` flags to explicitly control the access mode when opening a file. This level of control may be essential in some applications.
**8. Handling More File Types:** Since `open()` is part of the POSIX standard, it can be used to work with a broader range of file types beyond regular files, such as FIFOs and sockets.
Using fopen() might be more convenient for general-purpose file handling, especially when you don't need low-level control or specific features like file permissions. However, open() is more powerful for specialized use cases where you need that extra level of control.
</details>
<details>
<summary>File Descriptor Table vs Open File Table</summary>

### File Descriptor Table (FDT)
File Descriptor Table (FDT) is specific to each process, it holds:
1. File Descriptor (FD): An index (integer) used to identify an open file.
2. File Offset (Position): The current position in the file for reading or writing. This is updated as you read from or write to the file.
3. Access Mode: Information about how the file was opened (e.g., read-only, write-only, read-write).
4. Pointer to an Open File Table Entry: Instead of the file name, it holds a pointer to another table (called the Open File Table) that contains information about the file, including its inode (metadata) and the file's name if necessary.

### Open File Table
The Open File Table (OFT) contains detailed information about open files in a system, shared by all processes that have the file open. Here’s a breakdown of what the Open File Table contains:

#### Key Components of the Open File Table:
**1. File Offset (Current Position in File):**
This tracks the current position within the file for reading or writing. When a process reads from or writes to a file, the file offset is updated.
**2. Pointer to Inode (File Metadata):**
The Open File Table contains a pointer to the **inode** (Index Node) structure for the file, which is where most of the file's metadata is stored. The inode contains:
- File size
- File type
- Permissions
- Timestamps (creation, modification, etc.)
- Pointers to the actual data blocks on disk

**3. Access Mode (Permissions):**
This stores how the file was opened (e.g., read-only, write-only, read/write). The access mode determines what operations can be performed on the file.
**4. Reference Count:**
The Open File Table keeps a reference count of how many file descriptors are currently pointing to this open file. If multiple processes or threads open the same file, they may share the same Open File Table entry, and the reference count is incremented for each additional process that opens the file.
**5. File Flags:**
This includes special flags or options that were set when the file was opened (such as append mode, non-blocking mode, etc.).

#### Visual Breakdown:
```mathematica
+-------------------------+    +-----------------------------+    +-------------------------------+
|  File Descriptor Table   |    |      Open File Table         |    |            Inode               |
|     (per process)        |    |     (system-wide)            |    |       (file metadata)          |
+-------------------------+    +-----------------------------+    +-------------------------------+
| FD 3 (file1)  -------->  |    |  File Offset: 1024           |    |   File Size: 2048 bytes        |
| FD 4 (file2)  -------->  |--> |  Access Mode: Read-Only      |    |   Permissions: 0644            |
|                          |    |  Reference Count: 2          |    |   Data Block Pointers          |
+-------------------------+    |  Pointer to Inode -------->  |--> |   Timestamp: Last modified ... |
                               |  File Flags: O_APPEND         |    +-------------------------------+
                               +-----------------------------+ 
```


</details>
<details>
<summary>What are the 3 standard file descriptors, what are their purpose and what are their POSIX names</summary>

### the 3 standard file descriptors

| File Descriptor | Purpose                      | POSIX Name     | Example Code (C)                                           | Example Description                                       |
|-----------------|------------------------------|----------------|------------------------------------------------------------|-----------------------------------------------------------|
| `0`             | Standard Input (stdin)        | `STDIN_FILENO` | ```read(STDIN_FILENO, buffer, 100);```                      | Reads up to 100 characters from stdin (e.g., user input).  |
| `1`             | Standard Output (stdout)      | `STDOUT_FILENO`| ```write(STDOUT_FILENO, message, sizeof(message));```        | Writes a message to stdout (e.g., displays on the terminal).|
| `2`             | Standard Error (stderr)       | `STDERR_FILENO`| ```write(STDERR_FILENO, error_message, sizeof(error_message));``` | Writes an error message to stderr (e.g., error display).    |

### File structure vs file descriptor
- **File Structures** are higher-level constructs that provide buffered I/O and more complex functionality, making them user-friendly for file operations.
- **File Descriptors** are low-level handles that represent open files in the operating system, providing direct access to file operations without buffering.

| Feature                        | File Structure              | File Descriptor            |
|--------------------------------|-----------------------------|----------------------------|
| **Definition**                 | An abstract representation of a file (e.g., `FILE *` in C) that provides buffered I/O functions. | A low-level integer handle used by the operating system to access an open file. |
| **Data Type**                  | Typically defined as a structure (e.g., `struct FILE` in C) that contains metadata about the file. | An integer value (usually starting from 0) that acts as an index to a resource in a process-specific table. |
| **Buffering**                  | Supports buffered I/O, which improves performance by reducing the number of system calls. | Generally unbuffered I/O; operations go directly to the kernel without buffering. |
| **Abstraction Level**          | Higher-level abstraction, providing user-friendly functions like `fopen`, `fclose`, `fprintf`, etc. | Lower-level abstraction, providing basic operations like `open`, `read`, `write`, and `close`. |
| **Functionality**              | Provides additional features like formatted I/O, error handling, and easier manipulation of file data. | Provides direct access to the file without additional functionality; lower-level control. |
| **Standard Functions**         | `fopen`, `fclose`, `fread`, `fwrite`, `fprintf`, `fscanf`, etc. | `open`, `read`, `write`, `close`, `dup`, `dup2`, etc. |
| **Usage Example**              | `FILE *file = fopen("example.txt", "r");` | `int fd = open("example.txt", O_RDONLY);` |
| **Error Handling**             | Errors are typically managed with functions like `ferror()` or `feof()`. | Errors are typically managed by checking return values and using `errno`. |

### Comparison of Standard I/O Streams and File Descriptors in C

The table below summarizes the three standard I/O streams in C, along with their file structures, file descriptors, and examples of usage.

| Feature                | Standard File Structure | Standard File Descriptor | Example Use Case                                    |
|------------------------|-------------------------|--------------------------|-----------------------------------------------------|
| **Standard Input**     | `FILE *stdin`          | `STDIN_FILENO`          | Reading input from the user. <br> Example: `fscanf(stdin, "%d", &number);` <br> Low-level example: `read(STDIN_FILENO, buffer, size);` |
| **Standard Output**    | `FILE *stdout`         | `STDOUT_FILENO`         | Writing output to the console. <br> Example: `fprintf(stdout, "Hello, World!\n");` <br> Low-level example: `write(STDOUT_FILENO, "Hello, World!\n", 13);` |
| **Standard Error**     | `FILE *stderr`         | `STDERR_FILENO`         | Writing error messages to the console. <br> Example: `fprintf(stderr, "Error occurred!\n");` <br> Low-level example: `write(STDERR_FILENO, "Error occurred!\n", 17);` |

</details>
<details>
<summary>How to use the I/O system calls open, close, read and write</summary>

### I/O system calls open, close, read, and write
#### 1. open
The ``open`` function is used to open a file and obtain a file descriptor. The syntax is as follows:
```c
#include <fcntl.h>
#include <unistd.h>

int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
```
**Parameters:**
- ``pathname``: The path to the file to be opened.
- ``flags``: File access modes (e.g., ``O_RDONLY``, ``O_WRONLY``, ``O_RDWR``, ``O_CREAT``).
- ``mode``: The permissions to use if creating a new file (used with ``O_CREAT``).

Example:
```c
int fd = open("example.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
if (fd == -1) {
    perror("Error opening file");
}
```
#### 2. close
The ``close`` function is used to close an open file descriptor. The syntax is as follows: `int close(int fd);`
**Parameters:**
- ``fd``: The file descriptor to close.
**Return Value:**
- On Success: It returns 0, indicating that the file descriptor was successfully closed.
- On Failure: It returns -1, and the global variable ``errno`` is set to indicate the error.
```c
if (close(fd) == -1) {
    perror("Error closing file");
}
```
#### 3. read
The ``read`` function reads data from a file descriptor. The syntax is as follows: `ssize_t read(int fd, void *buf, size_t count);`
**Parameters:**
- ``fd``: The file descriptor from which to read.
- ``buf``: A pointer to the buffer where the read data will be stored.
- ``count``: The maximum number of bytes to read.
```c
char buffer[100];
ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
if (bytesRead == -1) {
    perror("Error reading file");
} else {
    buffer[bytesRead] = '\0'; // Null-terminate the string
    printf("Read %zd bytes: %s\n", bytesRead, buffer);
}
```
#### 4. write
The ``write`` function writes data to a file descriptor. The syntax is: `ssize_t write(int fd, const void *buf, size_t count);`
**Parameters:**
- ``fd``: The file descriptor to write to.
- ``buf``: A pointer to the data to write.
- ``count``: The number of bytes to write.
```c
const char *text = "Hello, World!\n";
ssize_t bytesWritten = write(fd, text, strlen(text));
if (bytesWritten == -1) {
    perror("Error writing to file");
}
```
**Full Example**
Here’s a complete example that demonstrates opening a file, writing to it, closing it, reopening it, reading from it, and then closing it again:
```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    const char *filename = "example.txt";
    int fd;

    // Open file for writing
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Write to file
    const char *text = "Hello, World!\n";
    if (write(fd, text, strlen(text)) == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    // Close the file
    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    // Reopen file for reading
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Read from file
    char buffer[100];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1) {
        perror("Error reading file");
    } else {
        buffer[bytesRead] = '\0'; // Null-terminate the string
        printf("Read %zd bytes: %s\n", bytesRead, buffer);
    }

    // Close the file
    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}
```
#### Summary
``open``: Used to open a file and returns a file descriptor.
``close``: Closes an open file descriptor.
``read``: Reads data from a file descriptor into a buffer.
``write``: Writes data from a buffer to a file descriptor.
</details>
<details>
<summary>What are and how to use the flags O_RDONLY, O_WRONLY, O_RDWR</summary>

### flags O_RDONLY, O_WRONLY, O_RDWR
The flags ``O_RDONLY``, ``O_WRONLY``, and ``O_RDWR`` are used with the open system call in C to specify the access mode when opening a file.

| Flag        | Description                                 |
|-------------|---------------------------------------------|
| `O_RDONLY`  | Open the file for read-only access.        |
| `O_WRONLY`  | Open the file for write-only access.       |
| `O_RDWR`    | Open the file for both reading and writing. |

#### How to Use the Flags
**1. Including the Required Header** You need to include the ``<fcntl.h>`` header to use these flags.
**2. Using open()**
```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file for reading");
        return 1;
    }
    // Perform reading operations...
    
    close(fd); // Always close the file descriptor
    return 0;
}
```
</details>
<details>
<summary>What are file permissions, and how to set them when creating a file with the open system call</summary>

### File Permission
File permissions determine who can read, write, or execute a file in a Unix-like operating system. Each file has an associated permission set that defines the actions allowed for different users: the owner of the file, the group associated with the file, and others.

#### File Permission Types
File permissions are typically represented by three categories:
- Read (r): Allows a user to read the contents of the file.
- Write (w): Allows a user to modify the contents of the file.
- Execute (x): Allows a user to execute the file as a program (for executable files).

#### Permission Representation
Permissions can be represented in two ways:
- **Symbolic**: Using letters (e.g., ``rwxr-xr--``), where each set of three characters represents the permissions for the owner, group, and others, respectively.
- **Octal**: Using numeric values (e.g., ``755``), where each digit corresponds to a set of permissions for the owner, group, and others.

| Permission           | Symbol | Octal Value |
|---------------------|--------|-------------|
| No permission        | -      | 0           |
| Execute              | x      | 1           |
| Write                | w      | 2           |
| Write + Execute      | wx     | 3           |
| Read                 | r      | 4           |
| Read + Execute       | rx     | 5           |
| Read + Write         | rw     | 6           |
| Read + Write + Execute| rwx   | 7           |

#### Setting File Permissions with open
When creating a file using the ``open`` system call, you can specify the file permissions using the mode parameter. The mode is usually specified in octal format.

Here’s how to set file permissions when creating a file:
```c
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    const char *filename = "example.txt";
    
    // Create a file with read and write permissions for the owner,
    // and read permissions for the group and others.
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // 0644 in octal

    int fd = open(filename, O_CREAT | O_RDWR, mode);
    
    if (fd == -1) {
        perror("Error creating file");
        return 1;
    }

    // Write to the file (example)
    write(fd, "Hello, World!\n", 14);
    
    // Close the file descriptor
    close(fd);
    
    return 0;
}
```
Explanation of the Example
- ``O_CREAT``: This flag indicates that the file should be created if it does not exist.
- ``O_RDWR``: This flag opens the file for both reading and writing.
- ``mode``: The permissions for the new file are set using symbolic constants defined in sys/stat.h:
    + S_IRUSR: Read permission for the owner.
    + S_IWUSR: Write permission for the owner.
    + S_IRGRP: Read permission for the group.
    + S_IROTH: Read permission for others.

#### Notes
- If the file already exists, the specified mode will be ignored, and the file’s existing permissions will remain unchanged.
- Always check the return value of ``open`` to ensure that the file was created successfully. If the function fails, it returns ``-1``, and errno will be set to indicate the error.
</details>
<details>
<summary>What is a system call</summary>

### System call
A system call is a way for programs to request services from the operating system's kernel. It provides an interface between a user-level program and the operating system, allowing applications to perform operations that are outside their direct control, such as:

- **File Management:** Opening, reading, writing, and closing files (e.g., ``open()``, ``read()``, ``write()``, ``close()``).
- **Process Control:** Creating, managing, and terminating processes (e.g., ``fork()``, ``exec()``, ``exit()``).
- **Memory Management:** Allocating and freeing memory (e.g., ``mmap()``, ``brk()``).
- **Communication:** Facilitating communication between processes (e.g., ``pipe()``, ``socket()``).
- **Device Management:** Interacting with hardware devices (e.g., ``ioctl()``).
#### Characteristics of System Calls:
- Privileged Mode: System calls typically run in kernel mode, which allows the operating system to perform low-level operations securely.
- Access Control: They help enforce access control mechanisms, ensuring that only authorized processes can perform certain operations.
- Error Handling: System calls provide mechanisms to handle errors, often returning specific error codes when operations fail.
</details>
<details>
<summary>What is the difference between a function and a system call</summary>

### function vs system call
- **Functions** are user-defined or library-defined routines that execute code within the application.
- **System calls** are predefined interfaces provided by the operating system, allowing applications to request services that require elevated privileges.

| Feature                  | Function                                       | System Call                                  |
|--------------------------|------------------------------------------------|----------------------------------------------|
| **Definition**           | A block of code designed to perform a specific task, defined by the user or a library. | A request made by a program to the operating system kernel for a service. |
| **Execution Context**    | Runs in user mode, allowing direct access to memory and CPU instructions within the application. | Runs in kernel mode, with privileged access to system resources and hardware. |
| **Scope**                | Limited to the application or library it is part of, usually not interacting with hardware or OS-level features. | Interacts with the operating system, managing resources like files, processes, and memory. |
| **Performance**          | Generally faster due to no context switch, as they run directly in user space. | Slower because they require a context switch from user mode to kernel mode. |
| **Error Handling**       | Errors are managed within the application, often using return values or exceptions. | Errors are indicated by return values and can be further explained using `errno` and functions like `perror()`. |
| **Usage**                | Used for implementing application logic and algorithms. | Used for performing operations that require OS-level permissions, such as file operations and process management. |
| **Example**              | `int add(int a, int b) { return a + b; }` | `open("file.txt", O_RDONLY);` |

</details>

## Tasks
### 0. Tread lightly, she is near
Write a function that reads a text file and prints it to the POSIX standard output.
**Prototype:** ``ssize_t read_textfile(const char *filename, size_t letters);``
- where letters is the number of letters it should read and print
- returns the actual number of letters it could read and print
- if the file can not be opened or read, return ``0``
- if ``filename`` is ``NULL`` return `0`
- if ``write`` fails or does not write the expected amount of bytes, return ``0``

```bash
$ cat Requiescat 
Requiescat
by Oscar Wilde

Tread lightly, she is near
Under the snow,
Speak gently, she can hear
The daisies grow.

All her bright golden hair
Tarnished with rust,
She that was young and fair
Fallen to dust.

Lily-like, white as snow,
She hardly knew
She was a woman, so
Sweetly she grew.

Coffin-board, heavy stone,
Lie on her breast,
I vex my heart alone,
She is at rest.

Peace, Peace, she cannot hear
Lyre or sonnet,
All my life's buried here,
Heap earth upon it.
$ cat 0-main.c
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    ssize_t n;

    if (ac != 2)
    {
        dprintf(2, "Usage: %s filename\n", av[0]);
        exit(1);
    }
    n = read_textfile(av[1], 114);
    printf("\n(printed chars: %li)\n", n);
    n = read_textfile(av[1], 1024);
    printf("\n(printed chars: %li)\n", n);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-read_textfile.c -o a
$ ./a Requiescat 
Requiescat
by Oscar Wilde

Tread lightly, she is near
Under the snow,
Speak gently, she can hear
The daisies grow.
(printed chars: 114)
Requiescat
by Oscar Wilde

Tread lightly, she is near
Under the snow,
Speak gently, she can hear
The daisies grow.

All her bright golden hair
Tarnished with rust,
She that was young and fair
Fallen to dust.

Lily-like, white as snow,
She hardly knew
She was a woman, so
Sweetly she grew.

Coffin-board, heavy stone,
Lie on her breast,
I vex my heart alone,
She is at rest.

Peace, Peace, she cannot hear
Lyre or sonnet,
All my life's buried here,
Heap earth upon it.

(printed chars: 468)
```
  
### 1. Under the snow
Create a function that creates a file.
**Prototype:** ``int create_file(const char *filename, char *text_content);``
- where ``filename`` is the name of the file to create and ``text_content`` is a ``NULL`` terminated string to write to the file
- Returns: ``1`` on success, ``-1`` on failure (file can not be created, file can not be written, ``write`` “fails”, etc…)
- The created file must have those permissions: ``rw-------``. If the file already exists, do not change the permissions.
- if the file already exists, truncate it
- if ``filename`` is NULL return ``-1``
- if ``text_content`` is ``NULL`` create an empty file
```bash
$ cat 1-main.c
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    int res;

    if (ac != 3)
    {
        dprintf(2, "Usage: %s filename text\n", av[0]);
        exit(1);
    }
    res = create_file(av[1], av[2]);
    printf("-> %i)\n", res);
    return (0);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-create_file.c -o b
$ ./b hello world
-> 1)
$ ls -l hello
-rw------- 1 julien julien 5 Dec  3 14:28 hello
$ cat hello 
world$ 
```
  
### 2. Speak gently, she can hear
Write a function that appends text at the end of a file.
**Prototype:** ``int append_text_to_file(const char *filename, char *text_content);``
- where ``filename`` is the name of the file and ``text_content`` is the ``NULL`` terminated string to add at the end of the file
- Return: ``1`` on success and ``-1`` on failure
- Do not create the file if it does not exist
- If ``filename`` is ``NULL`` return ``-1``
- If ``text_content`` is ``NULL``, do not add anything to the file. Return 1 if the file exists and -1 if the file does not exist or if you do not have the required permissions to write the file
```bash
$ cat 2-main.c
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    int res;

    if (ac != 3)
    {
        dprintf(2, "Usage: %s filename text\n", av[0]);
        exit(1);
    }
    res = append_text_to_file(av[1], av[2]);
    printf("-> %i)\n", res);
    return (0);
}
$ echo -n Hello > hello
$ ls -l hello
-rw-rw-r-- 1 julien julien 5 Dec  3 14:48 hello
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-append_text_to_file.c -o c
$ ./c hello " World!
> "
-> 1)
$ cat hello 
Hello World!
```
  
### 3. cp
Write a program that copies the content of a file to another file.
- Usage: ``cp file_from file_to``
- if the number of argument is not the correct one, exit with code ``97`` and print ``Usage: cp file_from file_to``, followed by a new line, on the ``POSIX`` standard error
- if ``file_to`` already exists, truncate it
- if ``file_from`` does not exist, or if you can not read it, exit with code ``98`` and print ``Error: Can't read from file NAME_OF_THE_FILE``, followed by a new line, on the ``POSIX`` standard error
    + where ``NAME_OF_THE_FILE`` is the first argument passed to your program
- if you can not create or if ``write`` to ``file_to`` fails, exit with code ``99`` and print ``Error: Can't write to NAME_OF_THE_FILE``, followed by a new line, on the ``POSIX`` standard error
    + where ``NAME_OF_THE_FILE`` is the second argument passed to your program
- if you can not close a file descriptor , exit with code ``100`` and print ``Error: Can't close fd FD_VALUE``, followed by a new line, on the ``POSIX`` standard error
    + where ``FD_VALUE`` is the value of the file descriptor
- Permissions of the created file: ``rw-rw-r--``. If the file already exists, do not change the permissions
- You must read ``1,024`` bytes at a time from the ``file_from`` to make less system calls. Use a buffer
- You are allowed to use ``dprintf``
```bash
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-cp.c -o cp
$ cat incitatous 
Why you should think twice before putting pictures on social media.
(What you always wanted to know about @Incitatous)
#PrivacyAware
http://imgur.com/a/Mq1tc
$ ./cp incitatous Incitatous
$ ls -l Incitatous 
-rw-rw-r-- 1 julien julien 158 Dec  3 15:39 Incitatous
$ cat Incitatous 
Why you should think twice before putting pictures on social media.
(What you always wanted to know about @Incitatous)
#PrivacyAware
http://imgur.com/a/Mq1tc
```
  
### 4. elf
Write a program that displays the information contained in the ``ELF`` header at the start of an ``ELF`` file.
- Usage: ``elf_header elf_filename``
- Displayed information: (no less, no more, do not include trailing whitespace)
    + Magic
    + Class
    + Data
    + Version
    + OS/ABI
    + ABI Version
    + Type
    + Entry point address
- Format: the same as ``readelf -h`` (version ``2.26.1``)
- If the file is not an ``ELF`` file, or on error, exit with status code ``98`` and display a comprehensive error message to ``stderr``
- You are allowed to use ``lseek`` once
- You are allowed to use ``read`` a maximum of 2 times at runtime
- You are allowed to have as many functions as you want in your source file
- You are allowed to use ``printf``
```bash
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 100-elf_header.c -o elf_header
$ ./elf_header ubuntu64 
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Entry point address:               0x400600
$ readelf --version
GNU readelf (GNU Binutils for Ubuntu) 2.26.1
Copyright (C) 2015 Free Software Foundation, Inc.
This program is free software; you may redistribute it under the terms of
the GNU General Public License version 3 or (at your option) any later version.
This program has absolutely no warranty.
$ readelf -h ubuntu64 
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x1
  Entry point address:               0x400600
  Start of program headers:          64 (bytes into file)
  Start of section headers:          6936 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           56 (bytes)
  Number of program headers:         9
  Size of section headers:           64 (bytes)
  Number of section headers:         31
  Section header string table index: 28
$ ./elf_header /lib/ld-linux.so.2
ELF Header:
  Magic:   7f 45 4c 46 01 01 01 00 00 00 00 00 00 00 00 00
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              DYN (Shared object file)
  Entry point address:               0xac0
$ readelf -h /lib/ld-linux.so.2
ELF Header:
  Magic:   7f 45 4c 46 01 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              DYN (Shared object file)
  Machine:                           Intel 80386
  Version:                           0x1
  Entry point address:               0xac0
  Start of program headers:          52 (bytes into file)
  Start of section headers:          145756 (bytes into file)
  Flags:                             0x0
  Size of this header:               52 (bytes)
  Size of program headers:           32 (bytes)
  Number of program headers:         7
  Size of section headers:           40 (bytes)
  Number of section headers:         24
  Section header string table index: 23
$ ./elf_header netbsd32 
ELF Header:
  Magic:   7f 45 4c 46 01 01 01 02 00 00 00 00 00 00 00 00
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - NetBSD
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Entry point address:               0x80484c0
$ ./elf_header sortix32 
ELF Header:
  Magic:   7f 45 4c 46 01 01 01 53 00 00 00 00 00 00 00 00
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            <unknown: 53>
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Entry point address:               0x80484c0
$ ./elf_header solaris32 
ELF Header:
  Magic:   7f 45 4c 46 01 01 01 06 01 00 00 00 00 00 00 00
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - Solaris
  ABI Version:                       1
  Type:                              EXEC (Executable file)
  Entry point address:               0x8052400
$ ./elf_header sparc32 
ELF Header:
  Magic:   7f 45 4c 46 01 02 01 00 00 00 00 00 00 00 00 00
  Class:                             ELF32
  Data:                              2's complement, big endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Entry point address:               0x10d20
```