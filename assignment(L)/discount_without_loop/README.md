# Shopping Cart Discount System in C

A simple C program that calculates discounts, payable amount, and updated customer points (CP) based on cart value and loyalty points.

## Features

- Calculates discount based on cart value
- Supports special discount conditions
- Converts customer points (CP) into currency value
- Calculates final payable amount
- Updates customer points after purchase

## Discount Rules

- No discount for purchases below 500 Tk
- Purchases above 500 Tk receive a flat 50 Tk discount
- Purchases from 2000 Tk to 4000 Tk receive a 5% discount
- Special discount of 270 Tk for cart value 2027 Tk
- Purchases above 5000 Tk receive a 10% discount
- Maximum discount limit for 10% discount is 2000 Tk

## Customer Point (CP) System

- 40 CP = 1 Tk
- Customers can use CP to reduce the payable amount
- New CP is earned after every purchase

### CP Earning Formula

- 1 Tk purchase = 0.4 CP

## Technologies Used

- C Programming Language
- Standard Input/Output Library (`stdio.h`)

## How to Run

1. Compile the program

```bash
gcc main.c -o main
