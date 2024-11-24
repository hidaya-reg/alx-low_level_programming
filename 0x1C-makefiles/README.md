# 0x1C. C - Makefiles
## Resources
- [What is a makefile and how does it work](https://opensource.com/article/18/8/what-how-makefile)
- [Installing the make utility](https://www.geeksforgeeks.org/how-to-install-make-on-ubuntu/)
- [make-official documentation](https://www.gnu.org/software/make/manual/html_node/)

## Learning Objectives
<details>
<summary>What are `make`, Makefiles</summary>

### `make` and Makefiles
`make` is a build automation tool commonly used in software development to compile code, manage dependencies, and automate repetitive tasks. The tool uses files called **Makefiles**, which contain a set of instructions that define how to build and manage a project.

#### 1. What is `make`?
- `make` is a command-line utility that reads instructions from a Makefile and executes the specified tasks.
- It is often used to compile and build projects, particularly for C/C++ programs, but can be used for any type of automation.
- The main advantage of `make` is its ability to manage dependencies. For example, it can check if certain files have changed since the last run and only rebuild parts of the project that need updating.

#### 2. What is a Makefile?
- A Makefile is a file where the instructions for `make` are written.
- It contains **rules** which specify:
    + **Targets**: The desired output files or tasks (e.g., a compiled program, or a group of files).
    + **Dependencies**: The files or conditions needed to create or update the target.
    + **Commands**: The commands executed to build the target if its dependencies are out of date.

#### 3. Basic Structure of a Makefile
Here’s a simple example to illustrate:
```makefile
target: dependencies
	commands
```
- **Target**: The output or task that `make` should produce.
- **Dependencies**: Files that the target depends on. If any dependencies change, `make` will rebuild the target.
- **Commands**: The commands used to build or update the target. Each command must be indented with a tab (spaces won’t work).

#### 4. Example Makefile
Let’s look at a basic Makefile example for compiling a C program:

```makefile
# Set the default target that `make` will build if no target is specified
.DEFAULT_GOAL := all

# Variables
CC = gcc
CFLAGS = -Wall -g
TARGET = main

# Default rule
all: $(TARGET)

# Rule to build the main target
$(TARGET): main.o utils.o
	$(CC) -o $(TARGET) main.o utils.o

# Rules to build each object file
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

utils.o: utils.c
	$(CC) $(CFLAGS) -c utils.c

# Clean up object files and the executable
clean:
	rm -f $(TARGET) *.o
```
- This Makefile defines how to compile `main.c` and `utils.c` into object files, link them to create the `main` executable, and has a `clean` rule to remove generated files.
- You can run `make` to compile the project, or `make clean` to delete the compiled files.

#### 5. Why Use Make and Makefiles?
- **Efficiency**: `make` can detect changes in source files and only recompile the necessary parts, saving time.
- **Automation**: It automates building, testing, cleaning, and other repetitive tasks.
- **Consistency**: Using a Makefile provides a standard way for team members to build and manage the project.

#### 6. Running Make Commands
- **Default target**: Simply running `make` will build the default target.
- **Specifying a target**: You can run `make clean` to clean up files or `make all` to build everything, depending on the rules defined in the Makefile.

</details>
<details>
<summary>When, why and how to use Makefiles</summary>

### When, why and how to use Makefiles
Makefiles are useful for managing and automating complex workflows in development. Here’s a deeper look at when, why, and how to use Makefiles effectively:

#### When to Use Makefiles
You should consider using Makefiles when:
- **Your project has multiple dependencies or files:** For projects with many source files (e.g., C or C++ programs), manually compiling each file and linking can be tedious and error-prone.
- **You want to automate repetitive tasks**: This includes tasks such as building, testing, cleaning up files, generating documentation, or deploying code.
- **Your workflow benefits from modularity:** Makefiles help you organize tasks and specify dependencies, making your build process more modular and easier to manage.
- **You want a standardized way for team members to build and run the project:** A Makefile provides a consistent and easy way for others to run tasks in the project without needing to understand all the underlying steps.
#### Why Use Makefiles
The benefits of Makefiles include:
- **Automating Complex Processes:** Makefiles can handle the entire build process, testing, and deployment in one place.
- **Dependency Management:** Makefiles help you only recompile files that have changed, saving time and computing resources.
- **Modularity and Reusability:** You can organize different tasks into separate targets in the Makefile (e.g., make build, make test, make clean).
- **Cross-Platform Consistency:** Makefiles provide a standardized build system that works across different operating systems (though sometimes with some OS-specific configurations).

#### How to Use Makefiles
To use Makefiles effectively, here are key steps and tips:
##### 1. Basic Structure
A Makefile is organized into rules with the following structure:

```makefile
target: dependencies
	command
```
##### 2. Define Variables
Using variables in a Makefile allows you to change file names or flags easily in one place.

```makefile
CC = gcc
CFLAGS = -Wall -g
TARGET = my_program
```
##### 3. Common Targets
- `all`: Often used as the default target to build the main project.
- `clean`: Removes generated files, allowing a fresh start.
- `test`: Runs tests for the project.
- `install`: Installs the compiled program or dependencies.

- ##### 4. Running `make` Commands
- `make`: Runs the default or `all` target in the Makefile.
- `make clean`: Runs the `clean` target, removing object files or executables.
- `make <target>`: Runs any specified target.
##### 5. Using .PHONY for Non-File Targets
`.PHONY` tells `make` that certain targets aren’t actual files, which helps avoid conflicts if files with the same name exist.

```makefile
.PHONY: clean all
```
#### Best Practices
- **Organize Your Targets:** Keep your Makefile organized by grouping related tasks.
- **Use Variables:** Define variables for commonly used options, file names, or directories.
- **Document Your Makefile:** Comment on complex parts, especially if the Makefile has several rules or custom functions.
- **Use `.PHONY`**: Add `.PHONY` for targets like `clean`, `all`, or `test` to avoid issues with files named after these targets.

#### When to Avoid Makefiles
In some cases, Makefiles might not be the best tool:
In languages with dedicated build tools: Many modern languages have their own build systems, like `npm` for JavaScript, `pip` for Python, `cargo` for Rust, or `maven` for Java.
In simple, single-file scripts: If your project is a single script without dependencies, a Makefile may be unnecessary.

</details>
<details>
<summary>Pattern rules and wildcards</summary>

### Pattern rules and wildcards
Pattern rules and wildcards are powerful features in Makefiles that allow you to write more concise and flexible rules, especially useful in large projects where multiple files follow similar naming conventions.

#### 1. Pattern Rules (`%`)
Pattern rules in Makefiles let you define a single rule that can be applied to multiple targets, rather than having to write individual rules for each target. Pattern rules use `%` as a wildcard symbol that matches any non-empty substring, making it versatile for creating targets and dependencies.
- It can be used in both targets and dependencies
**Pattern Rule Syntax**
The syntax for a pattern rule is:
```makefile
%.o: %.c
	<command>
```
- `%.o`: Represents the target, where `%` can match any substring.
- `%.c`: Represents the dependency, where `%` in the dependency matches the same substring as in the target.

The `%` acts as a placeholder for matching file names and allows us to generalize rules.

**Example of a Pattern Rule**
Suppose you have multiple C source files (`file1.c`, `file2.c`, `file3.c`) and want to compile each into an object file (`file1.o`, `file2.o`, `file3.o`). Instead of writing separate rules for each file, you can use a pattern rule:

```makefile
CC = gcc
CFLAGS = -Wall -g

# Pattern rule to compile any .c file to a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the executable from all .o files
my_program: file1.o file2.o file3.o
	$(CC) $(CFLAGS) -o my_program file1.o file2.o file3.o
```
- `%.o: %.c` tells `make` to compile any `.c` file into a `.o` file using the specified command.
- `$<` is an automatic variable that refers to the first dependency (in this case, the `.c` file).
- `$@` is an automatic variable that refers to the target (in this case, the `.o` file).

When you run `make my_program`, make will look for `file1.o`, `file2.o`, and `file3.o`. It will apply the pattern rule to each `.c` file, creating the `.o` files if they do not already exist or are out-of-date.

#### 2. Wildcards ($(wildcard ))
- `$(wildcard pattern)` searches for files that match a specific pattern and returns them as a space-separated list.
- It's often used to automatically collect files into variables.

**Wildcard Syntax**
```makefile
$(wildcard pattern)
```
`pattern` can include `*`, `?`, and `[...]`, which are common wildcard symbols in shell scripting.
- `*` matches any sequence of characters.
- `?` matches any single character.
- `[abc]` matches any one of the specified characters.

**Example of Using `$(wildcard)`**

```makefile
CC = gcc
CFLAGS = -Wall -g

# Automatically find all .c files in the directory
SRC_FILES = $(wildcard *.c)

# Convert the list of .c files to .o files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Pattern rule to compile each .c file to a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build the executable
my_program: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o my_program $(OBJ_FILES)

# Clean up
clean:
	rm -f my_program $(OBJ_FILES)
```
**Convert the list of `.c` files to `.o` files** `OBJ_FILES = $(SRC_FILES:.c=.o)`
- `$(wildcard *.c)` finds all `.c`files in the directory.
- `SRC_FILES` is a variable that holds the list of all `.c` source files (e.g.,` main.c`, `utils.c`).
- The expression `$(SRC_FILES:.c=.o)` takes each `.c` file in `SRC_FILES` and replaces the `.c` extension with `.o`. This conversion creates a list of object files (e.g., `main.o`, `utils.o`).
- `OBJ_FILES` now holds the list of all `.o` files needed for the final program.
- This setup is more flexible and scales easily if additional `.c` files are added to the directory.
**Pattern rule to compile each `.c` file to a `.o` file**
```makefile
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
```
- The `%.o: %.c` syntax tells `make` to match any `.c` file and its corresponding `.o` file (where `%` is the matched part of the filename). For example, if `main.o` is needed, it looks for `main.c`.
- The command on the next line uses variables:
    + `$(CC)`: The compiler, usually `gcc`.
    + `$(CFLAGS)`: Compiler flags, like `-Wall` (show all warnings) and `-g` (include debugging information).
    + `-c`: Tells `gcc` to compile the `.c` file into an object file (`.o`).
    + `$<`: Refers to the first dependency, the `.c` file being compiled.
    + `$@`: Refers to the target, the `.o` file being created.

**Rule to Build the Executable**
```makefile
my_program: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o my_program $(OBJ_FILES)
```
- This rule defines `my_program` as the final executable target.
- `my_program` depends on all object files in `$(OBJ_FILES)`. This means `make` will first check if each `.o` file is up-to-date (using the pattern rule above) before building the executable.
- The command to build `my_program`:
    + `$(CC) $(CFLAGS)`: Calls the compiler with flags.
    + `-o my_program`: Specifies the output file (`my_program`) for the compiled code.
    + `$(OBJ_FILES)`: Includes all `.o` files required to link and create the executable.
Example:
If OBJ_FILES = main.o utils.o, this command will run:

```bash
gcc -Wall -g -o my_program main.o utils.o
```
#### 3. Combining Pattern Rules with Automatic Variables
Automatic variables are placeholders that `make` replaces with information related to the target and dependencies:

- `$@` – The name of the target.
- `$<` – The name of the first dependency.
- `$^` – All dependencies, space-separated.
- `$?` – All dependencies newer than the target.

By combining pattern rules and automatic variables, you can create efficient Makefiles.

**Example with Automatic Variables**
```makefile
CC = gcc
CFLAGS = -Wall -g

# Pattern rule with automatic variables
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

my_program: main.o utils.o
	$(CC) $(CFLAGS) -o $@ $^

# Clean target
clean:
	rm -f my_program *.o
```
Here:

- `$<` is used in `%.o: %.c` to represent the `.c` file being compiled.
- `$@` and `$^` are used in the `my_program` rule to represent the target and all dependencies, respectively.
#### 4. Advanced Example: Recursive Compilation with Subdirectories
For more complex projects with source files in subdirectories, you can use pattern rules with recursive wildcards to find and compile files in multiple folders.

**Example**
Suppose your project has this structure:

```css
project/
├── src/
│   ├── main.c
│   ├── utils.c
│   └── helpers/
│       └── helper.c
├── include/
│   └── myheader.h
└── Makefile
```
You want to compile all `.c` files in `src/` and its subdirectories. Here’s how:

```makefile
CC = gcc
CFLAGS = -Wall -g -Iinclude

# Use wildcard to find all .c files recursively
SRC_FILES = $(shell find src -name '*.c')
OBJ_FILES = $(SRC_FILES:.c=.o)

# Pattern rule to compile each .c file to a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build the executable
my_program: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $(OBJ_FILES)

# Clean up
clean:
	rm -f my_program $(OBJ_FILES)
```
- `$(shell find src -name '*.c')` recursively finds all `.c` files in `src/`.
- `$(SRC_FILES:.c=.o)` converts all `.c` files to `.o` files, creating `OBJ_FILES`.
- This approach scales easily and compiles all source files in the directory tree.
#### Summary
Pattern rules and wildcards are essential for writing flexible, maintainable Makefiles, especially in larger projects:

- **Pattern Rules (`%.o: %.c`):** Allow generalized rules for files with similar naming patterns.
- **Wildcards (`$(wildcard *.c)`):** Automatically expand file lists without hardcoding each file.
- **Automatic Variables (`$@, $<, $^`):** Provide information about the target and dependencies, allowing for concise, reusable commands.

</details>
<details>
<summary>`$(...)` syntax</summary>

### `$(...)` syntax
The `$(...)` syntax in Makefiles is used in two distinct ways: for shell command substitution and for Make functions (like `wildcard`).

#### 1. Shell Command Substitution: `$(...)`
In a Makefile, `$(...)` can be used to execute a shell command and capture its output.

**How it works:**
- When you use `$(...)`, `make` treats it as a shell command and will execute it, replacing `$(...)` with the output of that command.
- This is similar to how `$()` is used in a shell script for command substitution (e.g., `$(ls)`).

**Example:**
```makefile
FILE_LIST = $(shell ls *.c)
```
- `$(shell ls *.c)` runs the shell command `ls *.c` (which lists all `.c` files in the directory).
- The result is captured and assigned to `FILE_LIST`.

If there are files like `main.c` and `utils.c` in the directory, `FILE_LIST` will become `main.c utils.c`.

#### 2. Make Functions: `$(...)`
In addition to running shell commands, `$(...)` is also used to call Make functions. These functions are built-in commands provided by make to perform various operations, such as pattern matching or variable manipulation.
##### Table of Make Functions

| **Function**                          | **Description**                                                                           | **Example**                                           | **Explanation**                                                                              |
|---------------------------------------|-------------------------------------------------------------------------------------------|-------------------------------------------------------|----------------------------------------------------------------------------------------------|
| `$(wildcard pattern)`                 | Expands to a list of files that match a specified pattern.                                | `SRC_FILES = $(wildcard *.c)`                         | Lists all `.c` files in the current directory and assigns them to `SRC_FILES`.               |
| `$(patsubst pattern,replacement,text)`| Replaces matching patterns in `text` with `replacement`.                                  | `OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))`        | Converts each `.c` file in `SRC_FILES` to an `.o` equivalent and stores it in `OBJ_FILES`.   |
| `$(subst from,to,text)`               | Substitutes all occurrences of `from` with `to` in `text`.                                | `SRC_FILES_NO_MAIN = $(subst main.c,,$(SRC_FILES))`   | Removes `main.c` from `SRC_FILES`.                                                           |
| `$(sort list)`                        | Sorts and removes duplicate elements from `list`.                                         | `UNIQUE_FILES = $(sort $(SRC_FILES))`                 | Sorts and removes duplicates from `SRC_FILES`.                                               |
| `$(notdir names...)`                  | Strips directory paths from file names.                                                   | `FILENAMES = $(notdir $(SRC_FILES))`                  | Removes directory paths from each file in `SRC_FILES`, leaving only the filenames.           |
| `$(dir names...)`                     | Extracts the directory path from each file name.                                          | `DIRS = $(dir $(SRC_FILES))`                          | Extracts and lists directories of each file in `SRC_FILES`.                                  |
| `$(addprefix prefix,names...)`        | Adds a prefix to each word in `names`.                                                    | `OBJ_FILES = $(addprefix build/,$(OBJ_FILES))`        | Adds `build/` as a prefix to each file in `OBJ_FILES`, so `file.o` becomes `build/file.o`.   |
| `$(addsuffix suffix,names...)`        | Adds a suffix to each word in `names`.                                                    | `OBJ_FILES = $(addsuffix .o,$(BASENAMES))`            | Adds `.o` as a suffix to each base name in `BASENAMES`.                                      |
| `$(basename names...)`                | Strips the suffix from each word in `names`, leaving only the base name.                  | `BASENAMES = $(basename $(SRC_FILES))`                | Removes extensions from `SRC_FILES`, so `main.c` becomes `main`.                             |
| `$(shell command)`                    | Executes a shell command and returns its output.                                          | `DATE = $(shell date +%Y-%m-%d)`                      | Stores the current date in `DATE`.                                                           |
| `$(filter pattern...,text)`           | Filters `text` to include only words that match `pattern`.                                | `C_FILES = $(filter %.c,$(SRC_FILES))`                | Filters `SRC_FILES` to include only `.c` files.                                              |
| `$(filter-out pattern...,text)`       | Filters `text` to exclude words that match `pattern`.                                     | `NON_MAIN_FILES = $(filter-out main.c,$(SRC_FILES))`  | Removes `main.c` from `SRC_FILES`, storing the result in `NON_MAIN_FILES`.                   |
| `$(if condition,then,else)`           | Evaluates `condition`; if true, returns `then`, otherwise `else`.                         | `$(if $(SRC_FILES), Files found, No files found)`     | Checks if `SRC_FILES` is non-empty and returns "Files found" if true, otherwise "No files found". |
| `$(foreach var, list, text)`          | Iterates over `list`, setting `var` to each item, and evaluates `text` for each.          | `$(foreach file,$(SRC_FILES),$(file): $(file).o)`     | Creates a list of targets, such as `file1.c: file1.o`, for each item in `SRC_FILES`.         |
| `$(error text)`                       | Stops execution and displays `text` as an error message.                                  | `$(error SRC_FILES is empty)`                         | Halts execution and prints an error if `SRC_FILES` is empty.                                 |
| `$(warning text)`                     | Displays `text` as a warning but continues execution.                                     | `$(warning Some files are missing)`                   | Displays a warning message if some files are missing but does not stop the build.            |
| `$(info text)`                        | Displays `text` as informational output but continues execution.                          | `$(info Compiling $(SRC_FILES))`                      | Prints "Compiling <files>" to give status information during build.                          |
| `$(join list1,list2)`                 | Joins corresponding items from `list1` and `list2`, producing pairs.                      | `PATHS = $(join $(DIRS), $(FILENAMES))`               | Combines directories and filenames, e.g., `dir1/file1`.                                      |


</details>
<details>
<summary>What are rules and how to set and use them</summary>

### Rules and how to set and use them
In a Makefile, rules define how files are created from other files. They are essentially instructions that tell `make` how to build each component of a project. Each rule specifies a **target** (usually a file you want to create or update), its **dependencies** (the files it relies on), and the **commands** needed to build or update it.

#### Structure of a Rule
```makefile
target: dependencies
    command
```

**Example of a Simple Rule**

```makefile
hello.o: hello.c
    gcc -c hello.c -o hello.o
```
In this example:
- `hello.o` is the target.
- `hello.c` is the dependency.
- `gcc -c hello.c -o hello.o` is the command to create `hello.o`.

If `hello.c` is modified after `hello.o` was last created, `make` will re-run the command to update `hello.o`.

#### Types of Rules
1. **File Rules:** These rules create or update files. The example above is a file rule.
2. **Phony Rules:** These are symbolic names for commands, not associated with files. They’re often used for commands like `clean` or `all`. Phony targets should be marked with `.PHONY`.

```makefile
.PHONY: clean
clean:
    rm -f *.o my_program
```
3. **Pattern Rules:** Define a rule template for targets with a similar structure, using `%` as a **wildcard**.

```makefile
%.o: %.c
    gcc -c $< -o $@
```
This rule compiles any `.c` file to a corresponding `.o` file. `$<` and `$@` are automatic variables.

#### Automatic Variables in Rules
Automatic variables make rules more flexible. Common ones include:

-`$@`: The target name.
-`$<`: The first dependency.
-`$^`: All dependencies, space-separated.

#### Setting and Using Rules
To set up rules in a Makefile, follow these steps:

1. **Identify the targets and dependencies:** For example, an executable that depends on object files.
2. **Define the necessary commands:** Specify how each file should be compiled or linked.
3. **Set a default rule:** Specify the default target to build when `make` is run without arguments.

**Example Makefile with Multiple Rules**
```makefile
# Define the compiler and flags
CC = gcc
CFLAGS = -Wall

# Specify the target executable
TARGET = my_program

# List of object files
OBJ_FILES = main.o utils.o

# Default target to build the program
all: $(TARGET)

# Rule to link object files and create the executable
$(TARGET): $(OBJ_FILES)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES)

# Pattern rule to compile each .c file to a .o file
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# Phony rule to clean up build files
.PHONY: clean
clean:
    rm -f $(TARGET) $(OBJ_FILES)
```
**Explanation of the Example**
- `all`: Default target. It depends on `$(TARGET)`, which is `my_program`.
- `$(TARGET)`: This rule links all object files to create the `my_program` executable.
- `%.o: %.c`: Pattern rule that compiles any `.c` file to `.o` format.
- `clean`: Phony rule to delete generated files.

#### Using Rules
1. **Run `make`:** The `all` target is executed by default, which compiles each `.c` file and then links them to form the executable.

```bash
make
```
2. **Run specific targets:** Run `make <target>` to build a specific target.

```bash
make clean
```
**Summary**
Rules in Makefiles define how files are created or updated. You specify targets, dependencies, and commands, and make uses timestamps and dependencies to decide when to run each rule. By combining different types of rules, automatic variables, and phony targets, you can build complex workflows for your projects.

</details>
<details>
<summary>What are explicit and implicit rules</summary>

### Explicit rules vs. Implicit rules
In Makefiles, rules are used to specify how to create or update targets based on their dependencies. These rules can be categorized into **explicit rules** and **implicit rules**.

#### Explicit Rules
Explicit rules are the specific instructions you define for a target. They directly specify how a target should be built from its dependencies.

An explicit rule consists of:
- **Target:** The file you want to create or update.
- **Dependencies**: The files that the target depends on.
- **Command(s):** The commands used to create the target from the dependencies.

**Syntax for Explicit Rules**
```makefile
target: dependencies
    command
```
**Example of an Explicit Rule:**
```makefile
hello.o: hello.c
    gcc -c hello.c -o hello.o
```
- `hello.o` is the target.
- `hello.c` is the dependency.
- `gcc -c hello.c -o hello.o` is the command that make will run if hello.o is out of date compared to hello.c.

#### Implicit Rules
Implicit rules are built-in rules that `make` already knows about. They are provided by `make` to handle common cases (like compiling `.c` files into `.o` files) without needing to define explicit rules for each target.

These rules are defined by `make` and are based on general patterns. You don’t need to write these rules yourself, but you can override them if necessary.

**Common Implicit Rules:**
- `.c` to `.o` conversion: By default, `make` knows how to compile `.c` files into `.o` files using a compiler like gcc.
- `.cpp` to `.o` conversion: For C++ files, `make` can convert `.cpp` to `.o` using a C++ compiler.
For example, `make` already knows how to turn a `.c` file into a `.o` file with a rule like this:

```makefile
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@
```
This pattern rule is built into `make`, so you don’t need to explicitly define it unless you want to override or customize it.

Example of Implicit Rule:
If you have a file `hello.c` and want to create `hello.o`, you can simply write:

```makefile
hello.o: hello.c
```
But `make` already knows how to convert `hello.c` to `hello.o` using the default rule, so this explicit rule is actually not needed. Instead, you can rely on the implicit rule, and `make` will automatically know how to compile `hello.c` into `hello.o` using the appropriate command.

#### Differences Between Explicit and Implicit Rules

| Aspect               | Explicit Rules                                    | Implicit Rules                                          |
|----------------------|---------------------------------------------------|---------------------------------------------------------|
| **Definition**        | You define these rules manually in your Makefile.  | These rules are built into `make` or system-specific.   |
| **Control**           | Full control over the target and command.         | Limited control; you can override or customize them.    |
| **Usage**             | Used for specific instructions or non-standard rules. | Used for common tasks like compiling `.c` to `.o` files. |
| **Examples**          | `hello.o: hello.c`, `my_program: $(OBJ_FILES)`     | `%.o: %.c`, `%.o: %.cpp`                                |
| **Overriding**        | You define everything explicitly.                 | You can override or modify default behavior.            |


#### Key Difference:
- Explicit Rule: You define the full rule directly for each target. For example, `hello.o: hello.c` is an explicit rule where `hello.o` is the target, `hello.c` is the dependency, and the command to build `hello.o` is explicitly specified.

- Implicit Rule: A pattern rule (like `%.o: %.c`) is an implicit rule because it doesn't refer to a specific target or dependency. Instead, it's a generalized rule that tells `make` how to handle any `.c` file by converting it to a `.o` file. It’s a template rule, where `make` automatically applies it to any `.c` file in your project when needed.

In other words:
- An **explicit rule** is specific and tells `make` how to build a particular target from a specific set of dependencies.
- An **implicit rule** is a pattern (like `%.o: %.c`) that tells `make` how to handle a class of files, and it gets applied to all files that match the pattern.

**Example Clarification**
```makefile
%.o: %.c
    gcc -c $< -o $@
```
- This is a **pattern rule**, which `make` automatically applies to any `.c` file. For example, if `make` encounters `file.c`, it will use this rule to compile `file.c` into `file.o`.
- The `$<` and `$@` are **automatic variables** used within pattern rules. `$<` represents the first dependency (in this case, `%.c`), and `$@` represents the target (in this case, `%.o`).
</details>
<details>
<summary>What are the most common / useful rules</summary>

### Most common / Useful Rules
In Makefiles, there are several common and useful rules that are widely used for building and managing projects, especially when dealing with source code compilation, linking, and cleaning. 
#### 1. Pattern Rules
Pattern rules are used to define a general recipe that applies to multiple targets matching a given pattern (such as `.c` files being compiled to `.o` files).

- **Compiling `.c` files to `.o` files:**
```makefile
%.o: %.c
    $(CC) -c $< -o $@
```
This rule tells make to compile any `.c` file into a `.o` file.

- **Compiling `.cpp` files to `.o` files (for C++ projects):**

```makefile
%.o: %.cpp
    $(CXX) -c $< -o $@
```
- **Linking object files to create an executable:**

```makefile
my_program: $(OBJ_FILES)
    $(CC) -o $@ $^
```
This rule links the object files (`$(OBJ_FILES)`) to create the executable `my_program`.

#### 2. Phony Targets
Phony targets are targets that do not correspond to actual files. They are used for tasks such as cleaning, testing, or running scripts, and they help avoid conflicts with filenames.

- **Clean:** Used to remove generated files (e.g., object files and executables).
```makefile
.PHONY: clean
clean:
    rm -f *.o my_program
```
- **All:** A target to build everything in your project.

```makefile
.PHONY: all
all: my_program
```
- **Install:** Used for installing binaries, libraries, or files to system directories.

```makefile
.PHONY: install
install:
    cp my_program /usr/local/bin/
```
#### 3. Dependency Management
Dependencies are key to telling `make` how and when to rebuild files. Common rules include setting up dependencies between source files and header files.

- **Auto-Generating Dependencies for C/C++ Projects:** This rule automatically generates dependencies for header files.
    ```makefile
    .PHONY: depend
    depend:
        gcc -MM *.c > .dependencies
    ```
- **Include Generated Dependencies:**
    ```makefile
    -include .dependencies
    ```
This includes the `.dependencies` file generated by the `depend` rule, ensuring that header files are properly tracked.

#### 4. Variable Substitution
Makefiles use variables for flexibility, making the build process more maintainable. Common variables include compilers, flags, and lists of files.

- **CC**: The compiler to use (e.g., gcc or g++).
```makefile
CC = gcc
CFLAGS = -Wall -g
```
- **OBJ_FILES**: A list of object files.
```makefile
OBJ_FILES = file1.o file2.o file3.o
```
- **Wildcard**: Used to select files matching a pattern, often used to get a list of .c files or .o files in a directory.
```makefile
SRC_FILES = $(wildcard *.c)
```
#### 5. Linking and Building Executables
After compiling object files, the next step is often to link them together into an executable.

- **Linking Object Files:**
```makefile
my_program: file1.o file2.o
    $(CC) -o $@ $^
```
This will link `file1.o` and `file2.o` into the executable `my_program`.

- **Using Libraries:** If you're using external libraries, you can link them as well:
```makefile
my_program: file1.o file2.o
    $(CC) -o $@ $^ -lm  # -lm links the math library
```
#### 6. Compiling and Installing Libraries
For larger projects, especially when dealing with libraries, you may want to define rules for compiling and installing them.

- **Compiling Static Libraries:**
```makefile
libmylib.a: file1.o file2.o
    ar rcs $@ $^
```
- **Installing a Library:**
```makefile
.PHONY: install
install: libmylib.a
    cp libmylib.a /usr/local/lib
```
#### 7. Run Tests
You may want to run tests as part of your build process, and a `make` rule can automate this.
- **Running Unit Tests:**
```makefile
.PHONY: test
test:
    ./run_tests.sh
```
#### 8. Help (Custom Rule)
You can define a custom rule to display a help message when `make` is run with no arguments.
- **Help Target:**
```makefile
.PHONY: help
help:
    @echo "Usage: make [target]"
    @echo "Available targets:"
    @echo "  all    - Build the program"
    @echo "  clean  - Remove object files and executables"
    @echo "  test   - Run unit tests"
```
</details>
<details>
<summary>What are variables and how to set and use them</summary>

### Variables in Makefiles
In Makefiles, variables are used to store values (such as file names, flags, paths, or other information) that can be used throughout the Makefile. 
#### Setting Variables in Makefiles
There are two primary ways to set variables in a `Makefile`:
1. **Simple Assignment (`=`):** This is the most common method. It assigns a value to a variable.

Example:
```makefile
CC = gcc
CFLAGS = -Wall -g
```
Here, `CC` is a variable that holds the value `gcc`, and `CFLAGS` holds the flags `-Wall -g` for the compiler.

2. **Immediate Assignment (`:=`):** This method evaluates the right-hand side immediately when the variable is set. This can be useful in cases where the value of the variable depends on the result of a command or other variables.

Example:
```makefile
SRC_FILES := $(wildcard *.c)
```
Here, `SRC_FILES` is immediately assigned the value of all `.c` files in the current directory by using the `wildcard` function.

#### Using Variables in Makefiles
Once you've set a variable, you can use it by referencing the variable name inside `$(...)` (or `${...}` in some cases):

```makefile
$(CC) $(CFLAGS) -o my_program my_program.c
```
In this example, `$(CC)` would be replaced by `gcc`, and `$(CFLAGS)` would be replaced by `-Wall -g`.

#### Types of Variables in Makefiles
- **Simple Variables:** These are the most basic variables, where the value is directly assigned.

```makefile
CC = gcc
```
- **Environment Variables:** Make also allows you to pass in environment variables from the shell that can be used within the `Makefile`.

Example:

```bash
export CC=gcc
make
```
- **Automatic Variables:** These are special predefined variables in `Make`. Some common ones include:

- `$@`: The name of the target file.
- `$<`: The first dependency (usually used in rules).
- `$^`: The list of all dependencies.
- `$?`: The list of dependencies that are newer than the target.
Example:

```makefile
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@
```
In this example:
- `$<` refers to the first dependency (the `.c` file).
- `$@` refers to the target (the `.o` file).
#### Example of Using Variables in a Makefile

```makefile
# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Source and object files
SRC_FILES = main.c utils.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# Target: build executable
my_program: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o my_program $(OBJ_FILES)

# Rule: compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object and executable files
clean:
	rm -f $(OBJ_FILES) my_program
```

</details>


## More Info
In the following tasks, we are going to use [these files](https://github.com/alx-tools/0x1B.c). We want to compile these only.

## Tasks
### 0. make -f 0-Makefile
Create your first Makefile.

Requirements:
- name of the executable: `school`
- rules: `all`
    + The `all` rule builds your executable
- variables: none
```bash
$ make -f 0-Makefile 
gcc main.c school.c -o school
$ ./school 
j#0000000000000000000000000000000000000
j#000000000000000000@Q**g00000000000000
j#0000000000000000*]++]4000000000000000
j#000000000000000k]++]++*N#000000000000
j#0000000000000*C+++]++]++]J*0000000000
j#00000000000@+]++qwwwp=]++++]*00000000
j#0000000000*+++]q#0000k+]+]++]4#000000
j#00000000*C+]+]w#0000*]+++]+]++0000000
j#0000we+]wW000***C++]++]+]++++40000000
j#000000000*C+]+]]+]++]++]++]+q#0000000
j#0000000*]+]+++++++]++]+++]+++J0000000
j#000000C++]=]+]+]+]++]++]+]+]+]=000000
j#00000k+]++]+++]+]++qwW0000000AgW00000
j#00000k++]++]+]+++qW#00000000000000000
j#00000A]++]++]++]++J**0000000000000000
j#000000e]++]+++]++]++]J000000000000000
j#0000000A]++]+]++]++]++000000000000000
j#000000000w]++]+]++]+qW#00000000000000
j#00000000000w]++++]*0##000000000000000
j#0000000000000Ag]+]++*0000000000000000
j#00000000000000000we]+]Q00000000000000
j#0000000000000@@+wgdA]+J00000000000000
j#0000000000000k?qwgdC=]4#0000000000000
j#00000000000000w]+]++qw#00000000000000
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
```
### 1. make -f 1-Makefile
Requirements:
- name of the executable: `school`
- rules: `all`
    + The `all` rule builds your executable
- variables: `CC`, `SRC`
    + `CC`: the compiler to be used
    + `SRC`: the `.c` files
```bash
$ make -f 1-Makefile
gcc main.c school.c -o school
$ make -f 1-Makefile
gcc main.c school.c -o school
```
### 2. make -f 2-Makefile
Create your first useful Makefile.

Requirements:
- name of the executable: `school`
- rules: `all`
    + The `all` rule builds your executable
- variables: `CC`, `SRC`, `OBJ`, `NAME`
    + `CC`: the compiler to be used
    + `SRC`: the `.c` files
    + `OBJ`: the `.o` files
    + `NAME`: the name of the executable
- The `all` rule should recompile only the updated source files
- You are not allowed to have a list of all the `.o` files
```bash
$ make -f 2-Makefile
gcc    -c -o main.o main.c
gcc    -c -o school.o school.c
gcc main.o school.o -o school
$ make -f 2-Makefile
gcc main.o school.o -o school
$ echo "/* School */" >> main.c
$ make -f 2-Makefile
gcc    -c -o main.o main.c
gcc main.o school.o -o school
```
### 3. make -f 3-Makefile
Requirements:
- name of the executable: `school`
- rules: `all`, `clean`, `oclean`, `fclean`, `re`
    + `all`: builds your executable
    + `clean`: deletes all Emacs and Vim temporary files along with the executable
    + `oclean`: deletes the object files
    + `fclean`: deletes all Emacs and Vim temporary files, the executable, and the object files
    + `re`: forces recompilation of all source files
- variables: `CC`, `SRC`, `OBJ`, `NAME`, `RM`
    + `CC`: the compiler to be used
    + `SRC`: the `.c` files
    + `OBJ`: the `.o` files
    + `NAME`: the name of the executable
    + `RM`: the program to delete files
- The `all` rule should recompile only the updated source files
- The `clean`, `oclean`, `fclean`, `re` rules should never fail
- You are not allowed to have a list of all the `.o` files
```bash
$ ls -1
0-Makefile
1-Makefile
2-Makefile
3-Makefile
school.c
main.c
main.c~
m.h
$ make -f 3-Makefile
gcc    -c -o main.o main.c
gcc    -c -o school.o school.c
gcc main.o school.o -o school
$ make all -f 3-Makefile
gcc main.o school.o -o school
$ ls -1
0-Makefile
1-Makefile
2-Makefile
3-Makefile
school
school.c
school.o
main.c
main.c~
main.o
m.h
$ make clean -f 3-Makefile 
rm -f *~ school
$ make oclean -f 3-Makefile 
rm -f main.o school.o
$ make fclean -f 3-Makefile 
rm -f *~ school
rm -f main.o school.o
$ make all -f 3-Makefile
gcc    -c -o main.o main.c
gcc    -c -o school.o school.c
gcc main.o school.o -o school
$ make all -f 3-Makefile
gcc main.o school.o -o school
$ make re -f 3-Makefile
rm -f main.o school.o
gcc    -c -o main.o main.c
gcc    -c -o school.o school.c
gcc main.o school.o -o school
```
### 4. A complete Makefile
Requirements:
- name of the executable: `school`
- rules: `all`, `clean`, `fclean`, `oclean`, `re`
    + `all`: builds your executable
    + `clean`: deletes all Emacs and Vim temporary files along with the executable
    + `oclean`: deletes the object files
    + `fclean`: deletes all Emacs and Vim temporary files, the executable, and the object files
    + `re`: forces recompilation of all source files
- variables: `CC`, `SRC`, `OBJ`, `NAME`, `RM`, `CFLAGS`
    + `CC`: the compiler to be used
    + `SRC`: the `.c` files
    + `OBJ`: the `.o` files
    + `NAME`: the name of the executable
    + `RM`: the program to delete files
    + `CFLAGS`: your favorite compiler flags: `-Wall -Werror -Wextra -pedantic`
- The `all` rule should recompile only the updated source files
- The `clean`, `oclean`, `fclean`, `re` rules should never fail

- You are not allowed to have a list of all the `.o` files
```bash
$ make all -f 4-Makefile
gcc -Wall -Werror -Wextra -pedantic   -c -o main.o main.c
gcc -Wall -Werror -Wextra -pedantic   -c -o school.o school.c
gcc main.o school.o -o school
```
### 5. Island Perimeter
**Technical interview preparation:**
Create a function `def island_perimeter(grid):` that returns the perimeter of the island described in `grid`:
- `grid` is a list of list of integers:
    + 0 represents a water zone
    + 1 represents a land zone
    + One cell is a square with side length 1
    + Grid cells are connected horizontally/vertically (not diagonally).
    + Grid is rectangular, width and height don’t exceed 100
- Grid is completely surrounded by water, and there is one island (or nothing).
- The island doesn’t have “lakes” (water inside that isn’t connected to the water around the island).

Requirements:
- First line contains `#!/usr/bin/python3`
- You are not allowed to import any module
- Module and function must be documented
```bash
$ cat 5-main.py
#!/usr/bin/python3
"""
5-main
"""
island_perimeter = __import__('5-island_perimeter').island_perimeter

if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    print(island_perimeter(grid))

$ 
$ ./5-main.py
12
```
### 6. make -f 100-Makefile
#advanced
Requirements:
- name of the executable: `school`
- rules: `all`, `clean`, `fclean`, `oclean`, `re`
    + `all`: builds your executable
    + `clean`: deletes all Emacs and Vim temporary files along with the executable
    + `oclean`: deletes the object files
    + `fclean`: deletes all Emacs and Vim temporary files, the executable, and the object files
    + `re`: forces recompilation of all source files
- variables: `CC`, `SRC`, `OBJ`, `NAME`, `RM`, `CFLAGS`
    + `CC`: the compiler to be used
    + `SRC`: the `.c` files
    + `OBJ`: the `.o` files
    + `NAME`: the name of the executable
    + `RM`: the program to delete files
    + CFLAGS: your favorite compiler flags: `-Wall -Werror -Wextra -pedantic`
- The `all` rule should recompile only the updated source files
- The `clean`, `oclean`, `fclean`, `re` rules should never fail
- You are not allowed to have a list of all the `.o` files
- You have to use `$(RM)` for the cleaning up rules, but you are not allowed to set the `RM` variable
- You are not allowed to use the string `$(CC)` more than once in your Makefile
- You are only allowed to use the string `$(RM)` twice in your Makefile
- You are not allowed to use the string `$(CFLAGS)` (but the compiler should still use the flags you set in this variable)
- You are not allowed to have an `$(OBJ)` rule
- You are not allowed to use the `%.o: %.c` rule
- Your Makefile should work even if there is a file in the folder that has the same name as one of your rule
- Your Makefile should not compile if the header file `m.h` is missing