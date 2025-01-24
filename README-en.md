<div align="center">
  <img src="https://raw.githubusercontent.com/15Galan/42_project-readmes/refs/heads/master/banners/cursus/projects/get_next_line-light.png" />
  <img src="https://img.shields.io/badge/status-finished-darkgreen" />
  <img src="https://img.shields.io/badge/score-125-darkblue" /><br/> 
   <b>English</b> · <a href="/README.md">Español<a>
</div> 

---

# Introduction

The **get_next_line** project consists of implementing a C function capable of reading and returning a complete line from a file, handling the reading efficiently. This project is part of the 42 School program and is essential to develop skills in file manipulation and dynamic memory management.

This is the [subject](es.subject.pdf) of the project.

---

## 📋Table of Contents

- 📖 [Description](#description)
- ⚙️ [Requirements](#requirements)
- 🛠️ [Installation](#installation)
- 🚀 [Usage](#usage)
- 📚 [Project Specifications](#project-specifications)
- ✅ [Tests](#tests)
- 🌐 [Resources](#resources)
- 📜 [License](#license)

---

## 📖 Description

The `get_next_line` function allows you to read a file line by line, regardless of the size of the lines or the file. To achieve this, the project uses a buffer that can be adjusted according to the user's needs.

The main challenge of the project is to efficiently handle file reading, dynamic memory, and special scenarios such as empty files, long lines, or multiple function calls.

---

## ⚙️Requirements

- **Language:** C
- **Standards:** The function must comply with Norminette (code style 42).
- **Compiler:** `gcc` with the flags `-Wall -Wextra -Werror`.
- **Headers:** Only the C standard library (`unistd.h`, `stdlib.h`, `fcntl.h`) must be used.

---

## 🛠️Installation

1. Clone this repository to your local machine:
```tap
git clone https://github.com/your_user/get_next_line.git
cd get_next_line
```

2. Compile the function files:
```tap
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

3. Change the value of `BUFFER_SIZE` according to your needs:
- This defines the size of the buffer used to read the file.

---

## 🚀 Usage

You can include the function in any project or test it with a text file:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main (empty)
{
int fd = open("file.txt", O_RDONLY);
character *line;

while ((line = get_next_line(fd)))
{
printf("%s", line);
free(line);
}
close(fd);
return 0;
}
```

Compile and run your program:
```tap
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
./gnl
```

---

## 📚 Project Specifications

- The function must return a complete line, including the newline (`\n`), except if the end of the file is reached.
- **Function prototype:**
```c
char *get_next_line(int fd);
```
- **Parameters:**
- `fd`: Descriptor of the file to read.
- **Expected behavior:**
- Returns a line from the file specified by `fd`.
- If the end of the file is reached, returns `NULL`.

### Project Files:
1. `get_next_line.c` - Main implementation of the function.
2. `get_next_line_utils.c` - Helper functions needed for the implementation.
3. `get_next_line.h` - Header file with the prototypes and macros.

---

## ✅ Testing

To test your implementation, you can use community testers or create your own test cases.

### Recommended Testers:
- [42Testers-GNL](https://github.com/Mazoise/42TESTERS-GNL)
- [gnl-war-machine](https://github.com/Tripouille/gnl-war-machine)
-[gnlkiller](https://github.com/DontBreakAlex/gnlkiller)

### Basic Test Cases:
1. File with multiple lines.
2. Empty file.
3. File with a single very long line.
4. Consecutive calls to `get_next_line` with the same descriptor.

---

## 🌐 Resources

- [read() man page](https://man7.org/linux/man-pages/man2/read.2.html)
- [C file handling guide](https://www.gnu.org/software/libc/manual/html_node/I_002fO-on-Streams.html)
- [Dynamic memory allocation in C explained](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)
