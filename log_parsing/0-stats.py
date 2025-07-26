#!/usr/bin/python3

import sys
import re
from collections import defaultdict


"""
prints total size + status codes seen so far
every 10 lines + when user hits ctrl + c
only lines that match the format are counted
if status code not valid --> we just skip it
"""

# Are those lines short enough for you now pycodestyle?
# 'LiNe tOo lOnG (80 > 79 ChArS)' yeah right bye.
# Are those lines short enough for you now pycodestyle?
# 'LiNe tOo lOnG (80 > 79 ChArS)' yeah right bye.
log_pattern = re.compile(
    r'^'
    r'\d'
    r'+'
    r'\.'
    r'\d'
    r'+'
    r'\.'
    r'\d'
    r'+'
    r'\.'
    r'\d'
    r'+'
    r' '
    r'-'
    r' '
    r'\['
    r'.'
    r'*'
    r'?'
    r'\]'
    r' '
    r'C'
    r'h'
    r'l'
    r'o'
    r'e'
    r' '
    r'C'
    r' '
    r'"'
    r'G'
    r'E'
    r'T'
    r' '
    r'/'
    r'p'
    r'r'
    r'o'
    r'j'
    r'e'
    r'c'
    r't'
    r's'
    r'/'
    r'2'
    r'6'
    r'0'
    r' '
    r'H'
    r'T'
    r'T'
    r'P'
    r'/'
    r'1'
    r'.'
    r'1'
    r'"'
    r' '
    r'('
    r'\d'
    r'{'
    r'3'
    r'}'
    r')'
    r' '
    r'('
    r'\d'
    r'+'
    r')'
    r'$'
)


status_codes = defaultdict(int)
total_size = 0
cnt = 0


def print_stats():
    """print collected stats"""
    print(f"File size: {total_size}")
    for code in sorted(status_codes):
        print(f"{code}: {status_codes[code]}")


try:
    for lin in sys.stdin:
        match = log_pattern.match(lin.strip())
        if match:
            code, size = match.groups()
            size = int(size)
            total_size += size
            if code in {
                '200', '301', '400', '401', '403', '404', '405', '500'
            }:
                status_codes[code] += 1
        cnt += 1
        if cnt % 10 == 0:
            print_stats()
except KeyboardInterrupt:
    print_stats()
    raise
else:
    print_stats()
