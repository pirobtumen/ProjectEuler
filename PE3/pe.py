"""
	Project Euler - 3
	======================

    'The prime factors of 13195 are 5, 7, 13 and 29.

    What is the largest prime factor of the number 600851475143 ?'

	Alberto Sola - 2016
"""

from math import sqrt

def largest_prime_factor(n):
	larguest_prime = 1
	factor = 3
	max_factor = sqrt(n)

	if n % 2 == 0:
		n = n / 2
		largest_prime = 2

		while n % 2 == 0:
			n = n / 2

		max_factor = sqrt(n)

	while n > 1 and factor <= max_factor:

		if n % factor == 0:
			n = n / factor
			larguest_prime = factor

			while( n % factor == 0 ):
				n = n / factor

			max_factor = sqrt(n)

		factor += 2

	if n > 1:
		larguest_prime = n

	return int(larguest_prime)


if __name__ == '__main__':

    N = 600851475143

    larguest_prime = largest_prime_factor( N )

    print("Solution: " + str(larguest_prime))
