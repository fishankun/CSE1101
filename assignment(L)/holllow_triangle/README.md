# Hollow Triangle Pattern in C

A simple C program that prints a hollow triangle pattern using asterisks (`*`). The height of the triangle is determined by user input.

## Features

* User-defined triangle height
* Center-aligned triangle
* Hollow interior
* Solid base line
* Uses nested loops and conditional operators

## Example Output

For `n = 5`:

```text
    *
   * *
  *   *
 *     *
*********
```

## How It Works

The program:

1. Takes the height (`n`) as input.
2. Prints leading spaces to center the triangle.
3. Prints:

   * `*` on the left edge
   * `*` on the right edge
   * `*` across the entire last row
   * Spaces inside the triangle
4. Repeats until all rows are printed.

## Code Concepts Used

* Nested loops
* Conditional (ternary) operator
* Pattern printing
* User input/output
* Basic geometry with rows and columns

## Compilation

Using GCC:

```bash
gcc main.c -o hollow_triangle
```

## Running

```bash
./hollow_triangle
```

## File Structure

```text
.
├── main.c
└── README.md
```

## Algorithm

```text
Input n

For each row:
    Print leading spaces

    For each column:
        If first column OR last column OR last row:
            Print '*'
        Else:
            Print space

Move to next line
```

## Complexity

* Time Complexity: O(n²)
* Space Complexity: O(1)

## Author

A beginner-friendly C programming project demonstrating pattern printing using loops and conditions.
