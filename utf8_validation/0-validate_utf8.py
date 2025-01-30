#!/usr/bin/python3
"""Determines if a data set represents a valid UTF-8 encoding."""


def validUTF8(data):
    """Determines if a data set represents a valid UTF-8 encoding."""
    if not isinstance(data, list):
        raise TypeError("Input must be a list of integers")
    if not all(isinstance(num, int) for num in data):
        raise ValueError("All input elements in the list must be integers")

    rem = 0
    for idx, num in enumerate(data):
        byte = num & 0xFF
        if rem:
            if byte >> 6 != 2:
                return False
            rem -= 1
            continue
        while (1 << abs(7 - rem)) & byte:
            rem += 1
        if rem == 1 or rem > 4:
            return False
        rem = max(rem - 1, 0)
    return True if rem == 0 else False
