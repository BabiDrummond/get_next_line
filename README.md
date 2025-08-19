# get_next_line

`get_next_line` is a project from **42 school (École 42)** in C designed to read from a file descriptor, returning a single line each time it’s called.

---

## Project Overview

- **Goal**: Implement a utility that reads and returns the next line from a file descriptor.  
- **Key Skills**: Understand **file I/O**, **buffer handling**, and **memory management**, use of **static** variables to retain state across function calls.

---

## Specification

**Mandatory Part:**
- The function must have the following prototype:
```
char *get_next_line(int fd);
```
- Must work with any valid file descriptor.
- Must read and return one line per call.
- Must return NULL in case of error or end of file.

The project must be compilable with:
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=<n> get_next_line.c get_next_line_utils.c
```

**Bonus Part:**
- Support for multiple file descriptors simultaneously.
- Use of only one static variable per call.

---

## Usage

1. Clone the repo and build the library:

```bash
git clone https://github.com/BabiDrummond/get_next_line.git
cd get_next_line
```

2. Include the header in your source:

```c
#include "get_next_line.h"
```

## Usage Example

```c
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```


## Code Style & Norm

- Conforms to 42’s **Norminette** (coding style/structure).
- Use of **libft** is forbidden. No external functions are allowed (besides `read()`, `malloc()` and `free()`).
- No memory leaks. 
- Global variables are prohibited.
- Correct behavior on various file descriptors.

---

## Author

**BabiDrummond** – Student at École 42.