# Push_Swap - Stack Sorting Algorithm

## Purpose
> The purpose of the Push_Swap project is to create a C program that calculates and displays the shortest sequence of instructions to sort a stack of integers using a limited set of operations. The program works with two stacks and must determine the minimal number of moves to sort the data in ascending order.

## Explanation of Behavior
Push_Swap implements a sorting algorithm with restricted operations. It takes a list of integers as command-line arguments, stores them in a stack named 'a', and outputs the sequence of operations needed to sort them. The program:

* Validates that all arguments are valid, unique integers
* Determines an efficient sequence of operations to sort the stack
* Outputs each operation with a newline character
* Sorts the stack using the minimum possible number of operations

If the input is invalid or an error occurs, the program exits cleanly with "Error" displayed to standard error.

## How It Works
**Initialization:** The program receives a list of integers as arguments (e.g., `./push_swap 2 1 3 6 5 8`).

**Input Validation:** It verifies all arguments are valid integers without duplicates.

**Stack Implementation:** The program uses two stacks (a and b) for sorting:
* Stack a initially contains all input integers
* Stack b is initially empty
* The goal is to sort stack a in ascending order

**Sorting Algorithm:** The program implements an optimized sorting strategy:
* For small datasets, it uses specialized algorithms
* For larger datasets, it employs more complex algorithms like quicksort variants

**Operation Output:** The program prints each operation required to sort the stack, with each operation followed by a newline character.

## Available Operations
The program works with the following operations:

* `sa` - Swap the first 2 elements of stack a
* `sb` - Swap the first 2 elements of stack b
* `ss` - Execute sa and sb simultaneously
* `pa` - Push the top element from stack b to stack a
* `pb` - Push the top element from stack a to stack b
* `ra` - Rotate stack a upward (first element becomes last)
* `rb` - Rotate stack b upward (first element becomes last)
* `rr` - Execute ra and rb simultaneously
* `rra` - Reverse rotate stack a (last element becomes first)
* `rrb` - Reverse rotate stack b (last element becomes first)
* `rrr` - Execute rra and rrb simultaneously

## Compilation and Usage
**Compile:** Run `make` to build the program.

**Execution:** `./push_swap [list of integers]`

**Example:** `./push_swap 2 1 3 6 5 8` outputs the operations needed to sort these numbers.

**Benchmark Requirements:**
* 100 random numbers: fewer than 700 operations
* 500 random numbers: fewer than 5500 operations

## Memory Management
The program efficiently manages memory:
* All allocated memory is properly freed
* No memory leaks occur during execution
* Stack operations are optimized for memory efficiency

**Usage:** `./checker [list of integers]`, then input operations line by line (finish with Ctrl+D).

**Output:**
* `OK` if the stack is correctly sorted after operations
* `KO` if the stack is not sorted or stack b is not empty
* `Error` for invalid inputs or operations

**Example:**
```
$> ./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
```

## Key Concepts
* **Stack Operations:** Implementation of fundamental stack operations
* **Algorithm Efficiency:** Optimizing the number of operations for different data sizes
* **Process Management:** Handling the sorting process efficiently
* **Error Handling:** Managing invalid inputs and edge cases gracefully

## Grade: 100/100

#### Used Tests
push_swap_tester: https://github.com/gemartin99/Push-Swap-Tester<br>
visualizer: https://github.com/o-reo/push_swap_visualizer
