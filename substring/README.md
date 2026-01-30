# Substring Concatenation Finder

Implementation of the classic interview problem that locates every starting index where a list of equal-length words appears concatenated within a string.

## Building

```
gcc -Wall -Wextra -Werror -pedantic main.c substring.c -o substring
```

## Running

```
./substring <haystack> <word1> [word2 ...]
```

The executable prints the list of indices where the concatenation of all provided words is detected. The repository includes only the library files; use your own `main.c` when testing.
