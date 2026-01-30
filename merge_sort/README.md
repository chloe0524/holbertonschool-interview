# Merge Sort

Top-down merge sort implementation in C.

## Description

Sorts an array of integers in ascending order using the merge sort algorithm with visual output of the merging process.

## Files

- `sort.h` - Header file
- `print_array.c` - Array printing utility
- `0-merge_sort.c` - Merge sort implementation
- `0-O` - Time complexity (best, average, worst)

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge
```

## Usage

```bash
./merge
```

## Time Complexity

- Best: O(nlog(n))
- Average: O(nlog(n))
- Worst: O(nlog(n))

## Features

- Recursive top-down approach
- Left array size always <= right array size
- Single malloc/free call
- Sorts left before right
