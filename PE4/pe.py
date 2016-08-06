"""
	Project Euler - 3
	======================

    'A palindromic number reads the same both ways. The largest palindrome made
    from the product of two 2-digit numbers is 9009 = 91 × 99.

    Find the largest palindrome made from the product of two 3-digit numbers.'

	Alberto Sola - 2016
"""

import time

def get_palindrome(min = 100, max = 999):
    a = max
    b = max
    c = 0

    big_pal = 0
    stop = False
    exit = False

    while b >= min and not exit:
        a = b
        c = a*b

        if c < big_pal:
            exit = True
            stop = True

        while a >= min and not stop:

            greater = c > big_pal
            str_c = str(c)

            if str_c == str_c[::-1] and greater:
                big_pal = c

            if not greater:
                stop = True

            a -= 1
            c -= b

        stop = False
        b -= 1

    return big_pal

if __name__ == '__main__':
    start = time.time()
    N = get_palindrome()
    end = time.time()

    print('\n' + str(N) + " found in " + str(end - start) + '\n')
