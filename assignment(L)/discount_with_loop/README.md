# Customer Point & Discount System

A simple C program that simulates a customer loyalty system. The program calculates discounts based on cart value, allows customers to redeem loyalty points (CP), and updates their points after each purchase.

## Features

* Multiple discount tiers based on cart value
* Customer point (CP) redemption system
* Automatic CP earning after each purchase
* Continuous transaction loop until the user chooses to quit
* Special handling for specific cart values

## Discount Rules

| Cart Value                | Discount                       |
| ------------------------- | ------------------------------ |
| Less than 500             | No discount                    |
| 500 - 1999.99             | 50 Tk                          |
| 2000 - 4000 (except 2027) | 5% discount                    |
| Exactly 2027              | 270 Tk discount                |
| 5000 or more              | 10% discount (maximum 2000 Tk) |

## Customer Points (CP)

### Redeeming CP

* Every 40 CP = 1 Tk discount
* Customers can choose whether to spend their CP

### Earning CP

* After each purchase, customers earn:

  * 4 CP for every 10 Tk spent
  * Equivalent to 40% of the cart value in CP

## Example

```text
Enter customer point: 1000
Enter the cart value: 2500
Do you want to spend your customer point?
Press '0' if no, '1' if yes
1

Total discount: 150.00
Payable: 2350.00
Updated CP: 1000.00
```

## Compilation

Using GCC:

```bash
gcc main.c -o customer_system
```

## Running

```bash
./customer_system
```

## File Structure

```text
.
├── main.c
└── README.md
```

## Functions

### `discount(float x)`

Calculates the discount amount based on the cart value.

### `main()`

Handles:

* Customer point input
* Cart value input
* CP redemption
* Discount calculation
* CP updates
* Repeated transactions

## Author

Created as a C programming practice project demonstrating:

* Functions
* Conditional statements
* Loops
* User input/output
* Simple business logic
