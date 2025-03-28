# UTF-8 Validation

![Python](https://img.shields.io/badge/Python-3.4.3-blue)
![Ubuntu](https://img.shields.io/badge/OS-Ubuntu%2014.04%20LTS-orange)
![PEP 8](https://img.shields.io/badge/Style-PEP%208%20v1.7.x-green)
![Executable](https://img.shields.io/badge/Executable-Yes-brightgreen)

Write a Python method that determines if a given dataset represents a valid UTF-8 encoding.

#### Prototype
```python
def validUTF8(data):
```
#### Features
- Returns `True` if the dataset is valid UTF-8, otherwise `False`.
- A character in UTF-8 can be 1 to 4 bytes long.
- Handles multiple characters in the dataset.
- Each integer in the dataset represents 1 byte of data (only the 8 least significant bits are relevant).
