*This project has been created as part of the 42 curriculum by dtaylor-*

# 42 cursus - get_next_line

---

# Summary
- [42 cursus - get\_next\_line](#42-cursus---get_next_line)
- [Summary](#summary)
- [Description](#description)
- [Instructions](#instructions)
	- [Compilation](#compilation)
		- [Mandatory](#mandatory)
		- [Bonus](#bonus)
	- [Execution](#execution)
- [Resources](#resources)
- [Algorithm](#algorithm)
	- [Selected Approach: Static Buffer](#selected-approach-static-buffer)
	- [Choice Explanation](#choice-explanation)

---

# Description

The goal of the get_next_line project is to write a function that returns next line read from a file descriptor. With subsequent calls of get_next_line, subsequent lines from the file will be returned.

This project introduces the concept of static variables in C programming.

- **Bonus Part:** The program must be able to manage multiple file descriptors at the same time

---

# Instructions

## Compilation

The function is designed to be compiled with the flag -D BUFFER_SIZE=n, where n is the buffer size used for the `read()` calls.

### Mandatory
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=n get_next_line.c get_next_line_utils.c main.c
```
### Bonus
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=n get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```

## Execution

```bash
#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

# Resources

- [GeeksforGeeks: Static Variables in C](https://www.geeksforgeeks.org/c/static-variables-in-c/)
  - Explaining Static Variables
- [GeeksforGeeks: Input-output System Calls](https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/)
  - Explaining of file descriptors
  - Explaining the usage and syntax of `read()`
- [claude.ai](https://claude.ai/)
  - Help with .md syntax
  - Help formatting README.md
  - Help understanding valgrind errors

# Algorithm

## Selected Approach: Static Buffer
1. **Read and Append until Newline:** Using a static variable to act as a stash. The file is read into a temporary buffer, which is then appended to the static stash until a newline character (`\n`) is found or End of File (EOF) is reached.
2. **Extract line:** Once a newline is found, the index is located and everything up to (and including) the newline's index is copied into a new string a returned to the user.
3. **Clean Stash:** Update the static variable by removing the part just returned, ensuring that the leftover characters are stored in order to be used in the next call.

## Choice Explanation
Using a static variable was chosen as it is the most efficient. It allows the function to 'remember' the remaining text between successive calls without requiring the user to manage the buffer manually