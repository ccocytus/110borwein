# 110BORWEIN

**110BORWEIN** is a program that computes Borwein integrals, a set of remarkable integrals studied by the Borwein brothers. The program uses numerical methods such as the midpoint rule, trapezoidal rule, and Simpson’s rule to evaluate these integrals. The project is implemented in both C and Rust, offering a comparison of performance and implementation between the two languages.

## Overview

In 2001, the Borwein brothers introduced a series of integrals that have unique properties, particularly that the first few integrals in the series equal \(\pi/2\). This program calculates these integrals for any given `n` using three different numerical methods:

- **Midpoint Rule**
- **Trapezoidal Rule**
- **Simpson's Rule**

The results include both the value of the integral and the absolute difference between the calculated value and \(\pi/2\).

## Features

- **Borwein Integrals**: Computes the integrals for a given `n`.
- **Numerical Methods**: Implements the midpoint rule, trapezoidal rule, and Simpson’s rule.
- **Comparison**: Compare the results between C and Rust implementations.
- **Error Handling**: Outputs error messages to stderr and exits with code 84 in case of issues.

## Usage

The program is designed to be run from the command line. Here’s how you can use it:

in C
```sh
./110borwein n
```
in Rust
```sh
./bonus/110borwein
```

# Parameters
`n`: The constant defining the integral to be computed. `n` must be a non-negative integer.
# Exemples
For `n = 0`

```sh
./110borwein 0
```
Output:
```sh
Midpoint:
I0 = 1.5707651076
diff = 0.0000312192

Trapezoidal:
I0 = 1.5707660806
diff = 0.0000302462

Simpson:
I0 = 1.5707654320
diff = 0.0000308948
```
## Compilation

To compile the program in C, use the provided Makefile. The Makefile includes several rules:
```sh
make
```
- `make clean`: Remove object files.
- `make fclean`: Remove object files and the binary.
- `make re`: Recompile the project from scratch.
