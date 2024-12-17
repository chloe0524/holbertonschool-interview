#!/usr/bin/python
'''method that calculates the fewest number of operations needed'''


def minOperations(n):
    ''' method '''
    if n <= 1:
        return 0
    operation = 0
    div = 2
    while n > 1:
        if n % div == 0:
            operation += div
            n = int(n / div)
        else:
            div += 1
    return operation
