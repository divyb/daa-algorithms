#/bin/bash/python3
#Problem 01: Given n Boolean variables x1, x2, x3, .... xn  we wish to print all possible combinations of truth values they can assume. For instance, if n=2, there are 4 possibilities: true, true; true, false; false, true and false, false. Write a program in python to accomplish this.
from itertools import product

n =int(input("Enter value of n:\t"))
lst = list(product([True, False],repeat=3))[0:2**n-1]

for i in lst:
    print(i)