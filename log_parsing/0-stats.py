#!/usr/bin/python3
"""
prints total size + status codes seen so far
if status code not valid --> we just skip it
"""

import sys

if __name__ == "__main__":
    valid_status_codes = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0,
    }
    line_count = 0
    total_file_size = 0

    def parse_log_line(line):
        """Read, parse and extract status code and file size"""
        try:
            parts = line.split()
            status_code = parts[-2]
            if status_code in valid_status_codes:
                valid_status_codes[status_code] += 1
            return int(parts[-1])
        except Exception:
            return 0

    def print_stats():
        """Print file size and status code counts in ascending order"""
        print("File size: {}".format(total_file_size))
        for code in sorted(valid_status_codes.keys()):
            if valid_status_codes[code]:
                print(f"{code}: {valid_status_codes[code]}")

    try:
        for line in sys.stdin:
            total_file_size += parse_log_line(line)
            line_count += 1
            if line_count % 10 == 0:
                print_stats()
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()
