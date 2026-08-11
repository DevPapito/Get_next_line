*This project has been created as part of the 42 curriculum by pezio*

## Description

This project is a function that allows reading a file line by line via its file descriptor (fd), ensuring there are no memory leaks.

## Instructions

Use this example to get the first line of a file:


```c
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char    *line;
int     fd;

fd = open("your file to read", O_RDONLY);
line = get_next_line(fd);
printf("%s", line);
free(line);
```

You can read all lines of a file using this example:

```c
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char    *line;
int     fd;

fd = open("your file to read", O_RDONLY);
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
```

# Project Algorithm

In this project, I used a static variable (buffer):

```c
static char *buffer;
```

This allowed me to use the buffer across multiple function calls without losing memory state.

# Resources

* unistd.h
* stdlib.h
* Valgrind for detecting memory leaks and undefined behavior
* GNU GDB (GNU Debugger)
* Linux Kernel/GNU/POSIX