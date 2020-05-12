#!/usr/bin/python3
"""
Minimum Operations
"""
# import time


def minOperations(n):
    """
    calculates the fewest number of operations
    needed to result in exactly n H characters
    :param n: Given a number n
    :return:
    """
    operations = 0
    value = 1
    last_value = 1

    # t0 = time.time()
    while n > value:
        if n % value != 0:
            value += last_value
            operations += 1
        else:
            last_value = value
            value += last_value
            operations += 2
    # t1 = time.time()
    # print(t1 - t0)
    return operations
