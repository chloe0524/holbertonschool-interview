### **Linked List Palindrome**  
![Ubuntu](https://img.shields.io/badge/Platform-Ubuntu_14.04_LTS-orange)  
![C](https://img.shields.io/badge/Language-C-blue)  
![Betty Style](https://img.shields.io/badge/Style-Betty-green)  
![Compiler](https://img.shields.io/badge/Compiler-gcc_4.8.4-lightgrey)  

---

### **Task**  

#### **0. Linked List Palindrome**  
Write a function in C that checks if a singly linked list is a palindrome.  

**Prototype:**  
```c
int is_palindrome(listint_t **head);
```  

**Return Value:**  
- `1` if the list is a palindrome.  
- `0` if it is not a palindrome.  

**Additional Details:**  
- An empty list is considered a palindrome.  
- The following example files can be used to test your solution:  
  - `lists.h` (header file)  
  - `linked_lists.c` (helper functions)  
  - `0-main.c` (example main file for testing)  

**Compilation Command:**  
```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
```  
