# Pascal's Triangle Pattern in C

A simple C program that prints Pascal's Triangle using numbers. The number of rows in the triangle is determined by user input.

## Features

* User-defined number of rows
* Left-aligned numerical triangle pattern
* Efficient calculation of binomial coefficients without using factorials
* Uses nested loops and sequential multipliers

## Example Output

For `row = 5`:

```text
Enter the value of row: 5
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
```

## How It Works

The program:

1. Takes the total number of rows as input.
2. Loops through each row `n` from `0` up to `row - 1`.
3. Initializes the first value of the row (`C`) to `1`.
4. Prints the current value of `C`, then computes the next value in the row using the binomial coefficient formula: `C = C * (n - col) / (col + 1)`.
5. Repeats for all columns in the current row before moving to the next line.

## Code Concepts Used

* Nested loops (`for` loops)
* Mathematical series generation (Binomial Theorem)
* Inline arithmetic updates
* User input/output

## Compilation

Using GCC:

```bash
gcc main.c -o pascals_triangle
```

## Running

```bash
./pascals_triangle
```

## File Structure

```text
.
├── main.c
└── README.md
```

## Algorithm

```text
Input row

For each row n from 0 to row - 1:
    Set C = 1

    For each column col from 0 to n:
        Print C
        Calculate next C = C * (n - col) / (col + 1)

    Move to next line
```

## Complexity

* Time Complexity: O(n²)
* Space Complexity: O(1)

## Author

A beginner-friendly C programming project demonstrating pattern printing and mathematical computations using loops.