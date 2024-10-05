
---

# Push Swap Project

## Overview

The **Push Swap** project is a simple but challenging algorithm task that requires sorting a stack of integers using a restricted set of operations. With two stacks (`a` and `b`) and a series of specific instructions, the goal is to create the shortest possible sequence of operations that sorts the integers in ascending order in stack `a`. This program is written in C and aims to minimize the number of moves needed to achieve a sorted stack.

## Features

- **Two Stack Setup**: The program begins with stack `a` containing a random set of integers (no duplicates allowed) and stack `b` empty.
- **Sorting Operations**: A limited set of stack operations are available to manipulate and sort the data.
- **Optimization**: The program calculates the minimal sequence of instructions required to achieve a sorted stack `a`.
- **Error Handling**: The program checks for valid integer input, unique values, and handles errors gracefully.

## Operations

Here is the list of available operations to manipulate the stacks:

- **sa**: Swap the first two elements at the top of stack `a`.
- **sb**: Swap the first two elements at the top of stack `b`.
- **ss**: Execute `sa` and `sb` simultaneously.
- **pa**: Push the top element of stack `b` to stack `a`.
- **pb**: Push the top element of stack `a` to stack `b`.
- **ra**: Rotate stack `a` upward, moving the top element to the bottom.
- **rb**: Rotate stack `b` upward, moving the top element to the bottom.
- **rr**: Execute `ra` and `rb` simultaneously.
- **rra**: Reverse rotate stack `a`, moving the bottom element to the top.
- **rrb**: Reverse rotate stack `b`, moving the bottom element to the top.
- **rrr**: Execute `rra` and `rrb` simultaneously.

## Example

Consider a random list of integers in stack `a`. The program `push_swap` will output the optimal sequence of instructions to sort this list in ascending order.

For example:

```bash
$ ./push_swap 4 2 3 1
ra
pb
sa
```

## Project Files

- **Makefile**: The project includes a `Makefile` with the following commands:
  - `make`: Compile the project.
  - `make clean`: Remove object files.
  - `make fclean`: Remove all generated files.
  - `make re`: Rebuild the project.
- **Source Files (`*.c` and `*.h`)**: Implementation of the algorithm and stack manipulation logic.

## Usage

1. Clone this repository.
2. Run `make` to compile the `push_swap` program.
3. Execute `./push_swap` with a list of integers as arguments. Example:
   ```bash
   ./push_swap 3 2 5 8 1
   ```

   The output will be a sequence of instructions to sort the provided integers.

### Requirements

- **External Functions**: The program can use `read`, `write`, `malloc`, `free`, `exit`, `ft_printf`, or an equivalent.
- **Libft Library**: The project is authorized to use functions from the `libft` library.

## Constraints and Rules

- **No Global Variables**: All variables should be managed within the function scope.
- **Minimum Moves**: The program should strive for the lowest number of operations to sort the list. Results will be compared to a defined operation limit during evaluation.
- **Error Messages**: If an input is invalid (e.g., not an integer, duplicates, out of integer range), the program will display `"Error\n"` to the standard error output.
- **No Output for Empty Input**: When no parameters are provided, the program will exit without output.

## Error Handling

- Duplicate values are not allowed in the input.
- Only valid integer values are accepted. Non-integer inputs or values beyond the integer range will produce an error message.

## License

This project is intended for educational and evaluative purposes, as part of a programming curriculum. Feel free to use the code as a reference or starting point for similar projects.
