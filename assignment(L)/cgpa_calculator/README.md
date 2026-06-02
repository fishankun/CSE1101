# CGPA Calculator (C Programming)

A simple C program that calculates the CGPA of a student based on marks in multiple subjects using a standard grading scale and credit-weighted system.

---

## 📌 Features

- Takes marks input for 7 university courses.
- Converts marks into GPA using a fixed grading scale
- Uses credit weighting for each subject
- Calculates final CGPA automatically
- Validates input (0–100 range check)

---

## 📚 Subjects Included

- CSE 1101  
- CSE 1102  
- STAT 1103  
- MATH 1107  
- GE 1105  
- SE 1106  
- CSE 1101L  

---

## 🧠 Grading System

| Marks Range | GPA |
|------------|-----|
| 80 – 100   | 4.00 |
| 75 – 79    | 3.75 |
| 70 – 74    | 3.50 |
| 65 – 69    | 3.25 |
| 60 – 64    | 3.00 |
| 55 – 59    | 2.75 |
| 50 – 54    | 2.50 |
| 45 – 49    | 2.25 |
| 40 – 44    | 2.00 |
| Below 40   | 0.00 |

---

## 🎯 Credit System

- Most subjects carry **3.0 credits**
- Lab subject (CSE 1101L) carries **1.5 credits**

---

## 🧮 CGPA Formula

CGPA = (Σ GPA × Credit) / (Σ Credits)

---

## 🚀 How to Run

### 1. Compile the program
```bash
gcc cgpa_calculator.c -o cgpa
]
