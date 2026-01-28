*This project has been created as part of the 42 curriculum by dtaylor-*

# 42cursus - ft_printf

---

# Summary
- [42cursus - ft\_printf](#42cursus---ft_printf)
- [Summary](#summary)
- [Description](#description)
- [Makefile](#makefile)
- [Prototype](#prototype)
- [Implemented Conversions](#implemented-conversions)
- [Resources](#resources)
- [Algorithm](#algorithm)
	- [Algorithm Design](#algorithm-design)
	- [Data Structure \& Memory Management](#data-structure--memory-management)

---

# Description

Using variadic functions to recreate the printf() function.

---

# Makefile

| Command     | Action                                      |
| ----------- | ------------------------------------------- |
| make        | Compile .c files and create libft.a         |
| make clean  | Delete .o files                             |
| make fclean | Delete .o files and libft.a                 |
| make re     | Deletes .o files and libft.a and recompiles |

---

# Prototype

`int	ft_printf(const char *, ...);`

---

# Implemented Conversions

| Formatter | Conversion                                                            |
| --------- | --------------------------------------------------------------------- |
| `%c`      | Prints a single character                                             |
| `%s`      | Prints a string (as defined by the common C convention)               |
| `%p`      | The `void *` pointer argument has to be printed in hexadecimal format |
| `%d`      | Prints a decimal (base 10) number                                     |
| `%i`      | Prints an integer in base 10                                          |
| `%u`      | Prints an unsigned decimal (base 10) number                           |
| `%x`      | Prints a number in hexadecimal (base 16) lowercase format             |
| `%X`      | Prints a number in hexadecimal (base 16) uppercase format             |
| `%%`      | Prints a percent sign                                                 |

---

# Resources

 - [(GeekforGeeks Vardiadic Functions)](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)

---

# Algorithm

## Algorithm Design

The `ft_printf` implementation uses a single-pass transition algorithm. The engine iterates through the format string character by character.
 - **Literal Handling:** Until a format specifier (`%`) is found characters are written directly to the standard output
 - **Dispatch Logic:** Upon detecting a `%`, the algorithm moves to a dispatcher module. This module views the next index to identify the conversion type (e.g. `d`, `s`, `x`)
 - **Modular Delegation:** Each conversion type is handled by a dedicated sub-function. If an invalid specifier is found, the engine resumes literal handling

## Data Structure & Memory Management

To ensure memory safety and high performance, this implementation adopts a buffer-less approach as appose to using intermediate arrays or dynamic memory allocation.
 - **Zero-Allocation Strategy:** Through writing each character directly instead of storing them to a temporary buffer, the risk of memory leaks is eliminated (0 bytes of heap allocation)
 - **State Tracking:** A cuumulative counter tracks the return value of each write operaiton, ensuring that the final function returns the total bytes processed, consistent with printf()