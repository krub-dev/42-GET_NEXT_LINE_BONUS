<h1 align="center">
  <img src="https://iili.io/2odPQgn.png" alt="gnl header krub" width="1200" height="auto" style="align: bottom;"> 
</h1>

## Description

This project consists of developing a custom function, `get_next_line(fd)`, which is responsible for reading a line of text from a file descriptor in an efficient manner. Like `ft_printf()`, it is also an integral part of the library we are building at 42, designed to provide a series of utility functions that simplify C program development. Like `ft_printf()` and the others, it is designed to be modular and easily integrable into C projects, using it as a tool (function) according to the specific needs of the project.

🇪🇸 [Leer en español](README.md)

## Key Features

Programming `get_next_line(fd)` involves handling a file descriptor provided by us, in which we read line by line through repeated calls to the function in a loop. The function must return the newly read line (newline character `\n` included) with each call. If there is nothing more to read or an error occurs, it should return NULL. It must also read from `stdin` (standard input). All of this needs to be handled correctly, ultimately allowing the reading of large files without reading the entire file into memory at once.

## Project Files

- **get_next_line.c**: Contains the main function of the program, as well as its auxiliary functions.
- **get_next_line_utils.c**: Contains the functions that help achieve the reading of the new line.
- **get_next_line.h**: The header file. Contains all the functions, libraries, and macros required for the program.
- **get_next_line_bonus.c**: Nearly the same code as the non-bonus version, only a part has been modified to fulfill the bonus requirements.
- **get_next_line_utils_bonus.c**: Same as the previous one. Nearly identical code to the non-bonus version, with a modification to fulfill the bonus. In this case, it is the same.
- **get_next_line_bonus.h**: This is also the header for the bonus. Same code, but with an added macro (MAX_FD).

## Bonus

The bonus involves making our program capable of handling multiple file descriptors at once without losing track of the reading process in each of the sent file descriptors. This is achieved by implementing a double-pointer static.

