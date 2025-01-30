#!/usr/bin/python3
"""Determines if a data set represents a valid UTF-8 encoding."""

def validUTF8(data):
    """Determines if a data set represents a valid UTF-8 encoding."""
    num_bs = 0
    for b in data:
        b = b & 0xFF
        
        if num_bs == 0:
            if (b >> 5) == 0b110:
                num_bs = 1
            elif (b >> 7):
                return False
            elif (b >> 4) == 0b1110:
                num_bs = 2
            elif (b >> 3) == 0b11110:
                num_bs = 3
        else:
            if (b >> 6) != 0b10:
                return False
            num_bs -= 1
    
    return num_bs == 0
