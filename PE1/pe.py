"""
	Project Euler - 1
	======================
	
	'If we list all the natural numbers below 10 that are multiples of 3 or 5,
	we get 3, 5, 6 and 9. The sum of these multiples is 23.

	Find the sum of all the multiples of 3 or 5 below 1000.'
	
	
	Alberto Sola Comino - 2016

"""

def multiples_sum(n):
	n = n-1
	num_three = n // 3
	num_five = n // 5
	num_fifteen = n // 15
	
	return (3*num_three*(num_three+1) + 5*num_five*(num_five+1) - 15*num_fifteen*(num_fifteen+1))/2
	
if __name__ == '__main__':

	N = 1000

	sum_ = multiples_sum(N)

	print("Sum: " + str(sum_))

