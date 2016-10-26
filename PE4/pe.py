"""
	Project Euler - 4
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

def get_max(max, min, N):
    """
    Binary search.

    Return the maximun number, X, between MAX and MIN that multiplied by MAX
    is greater than N.
    """
    precision = 10

    while precision > 0:
        mid = (max+min)//2

        if mid*min > N:
            max = mid
        else:
            min = mid

        precision -= 1

    return max

def get_palindrome2(N, min = 100, max = 999):
    """
    Find the largest palindrome made from the product of two 3-digit numbers
    which is less than N.
    """
    a_max = get_max(max,min,N)
    a = max
    b = max
    c = 0
    big_pal = 0

    stop = False
    exit = False

    while b >= min and not exit:
        if a > b:
            a = b
        else:
            a = a_max

        c = a*b

        if c <= big_pal:
            exit = True
            stop = True

        while a >= min and not stop:

            greater = c > big_pal
            str_c = str(c)

            if str_c == str_c[::-1] and greater and c < N:
                big_pal = c

            if not greater:
                stop = True

            a -= 1
            c -= b

        stop = False
        b -= 1

    return big_pal


if __name__ == '__main__':

    # PROJECT EULER

    start = time.time()
    N = get_palindrome()
    end = time.time()

    print(str(N) + " found in " + str(end-start))

"""
    time_list = []

    for i in range(110000,1010001,10000):
        start = time.time()
        N = get_palindrome2(i)
        end = time.time()

        time_list.append( end - start )
        print("N: " + str(i) + " - P: " + str(N) + " - T: " + str(end-start))

    average = 0
    for x in time_list:
        average += x

    average = average / len(time_list)

    print("\nFound in (average) " + str(average) + '\n')
"""
