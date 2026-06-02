# Password Validator in C

A simple C program that checks the strength and validity of a user-provided password based on standard security criteria. The program continuously prompts the user until a valid password is provided.

## Features

* Verifies minimum password length (at least 8 characters)
* Checks for at least one uppercase letter (`A-Z`)
* Checks for at least one lowercase letter (`a-z`)
* Checks for at least one numerical digit (`0-9`)
* Checks for at least one special character
* Provides specific, detailed feedback on missing requirements
* Uses an interactive loop to retry upon failure

## Example Output

```text
Length of the password: 5
Password length is too short.

Length of the password: 8
Enter your password: password
Password is invalid.
Upper case needed
Digit needed
Special character needed

Length of the password: 9
Enter your password: Password1!
Password is valid.
```

## How It Works

The program:

1. Prompts the user for the intended password length (`n`).
2. Rejects the input immediately if the length is less than 8.
3. If the length is valid, prompts the user to enter the password.
4. Reads the input character by character and updates integer flags (`a`, `b`, `c`, `d`) based on ASCII values for:
   * Uppercase letters
   * Lowercase letters
   * Digits
   * Special characters
5. Uses a helper function `check()` to verify all four criteria are met.
6. Prints a success message and terminates if valid, or lists the missing character types and repeats the process.

## Code Concepts Used

* Infinite loops and `break` statements
* Custom helper functions
* ASCII character evaluation
* Logical operators and complex `if-else` structures
* Formatted input/output

## Compilation

Using GCC:

```bash
gcc main.c -o password_validator
```

## Running

```bash
./password_validator
```

## File Structure

```text
.
├── main.c
└── README.md
```

## Algorithm

```text
Loop forever:
    Input length n
    
    If n < 8:
        Set status to short
    Else:
        Input password
        For each character:
            If uppercase: flag A = 1
            If digit: flag B = 1
            If lowercase: flag C = 1
            If special: flag D = 1
            
        Calculate status = check(A, B, C, D)
        
    If status == valid:
        Print success
        Break loop
    Else if status == short:
        Print length error
    Else:
        Print invalid
        Print missing requirements based on flags A, B, C, D
```

## Complexity

* Time Complexity: O(n) per attempt, where n is the length of the password.
* Space Complexity: O(1), as it evaluates characters on the fly using a fixed number of integer flags.

## Author

A practical C programming project demonstrating character evaluation, conditional logic, and looping control flows.