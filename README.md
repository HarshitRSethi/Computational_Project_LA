# 📘 Computational Linear Algebra Project

This repository contains two C++ programs written as part of a computational mathematics project. Both programs implement fundamental matrix operations **from scratch** without relying on external linear algebra libraries.

---

## 📂 Contents

1. **RREF**
2. **Determinant**

---

# 1️⃣ Row-Reduced Echelon Form (RREF)

### 📌 Description

This program computes the **Row-Reduced Echelon Form** of any matrix of size \( m x n \).  
It performs:

- Finding the next pivot column
- Row swapping
- Normalizing the pivot row
- Eliminating all other rows

The final matrix is displayed with **3-decimal precision**.

---

### ▶️ How to Compile & Run

```bash
./RREF
```

### Sample Input

```bash
3 3
1 2 3
2 4 7
1 1 0
```

### Sample Output

```bash
Row-Reduced Echelon Form:
1.000 0.000 0.000
0.000 1.000 0.000
0.000 0.000 1.000
```

---

## 2. Determinant using Laplace Expansion

### Description

This program computes the determinant of an n × n matrix using recursive cofactor (Laplace) expansion along the first row. It includes:

- Minor matrix generation
- Base cases for 1×1 and 2×2 matrices
- A recursive determinant function for larger matrices

### How to Compile and Run

```bash
./Determinant
```

### Sample Input

```bash
3
1 2 3
0 4 5
1 0 6
```

### Sample Output

```bash
Determinant of given matrix is 22
```

---

## Project Structure

```
├── RREF.cpp # Code 1: Computes RREF of a matrix
├── RREF # Program 1: Executable file, precompiled for RREF
├── Determinant.cpp # Code 2: Computes determinant using Laplace expansion
├── Determinant # Program 2: Executable file, precompiled for determinant
└── README.md # Project documentation
```

---

## Features

- Implemented in standard C++
- Uses only STL vector for matrix representation
- Clear, modular functions for each operation
- Suitable for educational and demonstration purposes

---

## Author

Harshit Sethi  
B.Tech IT, IIIT Allahabad

---
