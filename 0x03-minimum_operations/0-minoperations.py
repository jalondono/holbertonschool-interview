#!/usr/bin/python3
"""
Minimum Operations
"""


def copy(word):
    return word


def paste(word, last_word):
    return word + last_word


def minOperations(n):
    """
    calculates the fewest number of operations
    needed to result in exactly n H characters
    :param n: Given a number n
    :return: 
    """
    operations = 0
    len_list = 1
    word = 'H'
    last_word = 'H'

    if n <= 0:
        return 0

    while n > len_list:

        if n % len_list != 0:
            word = paste(word, last_word)
            operations += 1
        else:
            last_word = word
            word = paste(word, last_word)
            operations += 2

        len_list = len(word)
    if n == len_list:
        return operations
    return 0
