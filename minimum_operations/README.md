# **Minimum Operations**  
![Ubuntu](https://img.shields.io/badge/Platform-Ubuntu_14.04_LTS-orange)  
![Python](https://img.shields.io/badge/Language-Python_3.4.3-blue)  
![PEP 8](https://img.shields.io/badge/Style-PEP_8-green)  
![Executable](https://img.shields.io/badge/Executable-Yes-lightgrey)  

## **Tasks**  

### **0. Minimum Operations**  
Write a Python function `minOperations(n)` that calculates the fewest number of operations needed to result in exactly `n` characters in the file.  

#### **Prototype**  
```python
def minOperations(n):
    """
    Calculates the minimum number of operations to get n H characters.
    Returns an integer.
    """
```

#### **Requirements**  
- If `n` cannot be achieved, return `0`.  
- Example for `n = 9`:  
  ```
  H => Copy All => Paste => HH => Paste => HHH => Copy All => Paste => HHHHHH => Paste => HHHHHHHHH
  ```
  Operations: 6  

#### **Example Usage**  
```bash
carrie@ubuntu:~/minoperations$ cat 0-main.py
#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

n = 4
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 12
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

carrie@ubuntu:~/minoperations$
carrie@ubuntu:~/minoperations$ ./0-main.py
Min number of operations to reach 4 characters: 4
Min number of operations to reach 12 characters: 7
carrie@ubuntu:~/minoperations$
```

