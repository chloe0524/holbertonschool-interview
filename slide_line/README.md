# 2048

![C](https://img.shields.io/badge/C-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![VSCode](https://img.shields.io/badge/Visual_Studio_Code-%23007ACC.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white)
![Holberton](https://img.shields.io/badge/Holberton-%23F57F17?style=for-the-badge&logo=hippocamp&logoColor=white)
![Project Badge](https://img.shields.io/badge/Project%20Score-100%25-brightgreen?style=for-the-badge)
![Curriculum Badge](https://img.shields.io/badge/C%23%2022-Interview%20Preparation%20-%23FF6F00?style=for-the-badge)

## Overview

The **Slide Line** project is a C implementation of the 2048 game mechanics on a single horizontal line.


### General
- Allowed editors: `vi`, `vim`, `emacs`
- All files compiled on **Ubuntu 14.04 LTS**
- Programs and functions compiled with `gcc 4.8.4` using the flags: 
-Wall -Werror -Wextra -pedantic
- Code style follows **Betty** and will be checked with `betty-style.pl` and `betty-doc.pl`
- No global variables allowed
- Maximum of 5 functions per file
- Function prototypes must be included in the header file called `slide_line.h`

## Task

### 0. Slide Line (Mandatory)
The goal of this task is to slide and merge an array of integers to the left or right. Identical numbers that are contiguous or separated by zeros should be merged.

#### Function Prototype
```c
int slide_line(int *line, size_t size, int direction);
