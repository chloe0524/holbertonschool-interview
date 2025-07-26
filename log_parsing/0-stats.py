#!/usr/bin/python3
"""
prints total size + status codes seen so far
if status code not valid --> we just skip it
"""

import sys
import re
from collections import defaultdict

status_codes = defaultdict(int)
total_size = 0
cnt = 0


def print_stats():
    """print collected stats"""
    print(f"File size: {total_size}")
    for code in sorted(status_codes):
        print(f"{code}: {status_codes[code]}")


if __name__ == "__main__":
    try:
        log_pattern = re.compile(
            r'^'
            r'\d+'
            r'\.'
            r'\d+'
            r'\.'
            r'\d+'
            r' '
            r'-'
            r' '
            r'\[.*?\]'
            r' '
            r'Chloe C '
            r'"GET /projects/260 HTTP/1.1" '
            r'(\d{3}) '
            r'(\d+)$'
        )

        for lin in sys.stdin:
            match = log_pattern.match(lin.strip())
            if match:
                code, size = match.groups()
                size = int(size)
                total_size += size
                if code in {'200', '301', '400', '401', '403',
                            '404', '405', '500'}:
                    status_codes[code] += 1
            cnt += 1
            if cnt % 10 == 0:
                print_stats()
    except KeyboardInterrupt:
        print_stats()
        raise
    else:
        print_stats()
