#/bin/bash/python3

#Devise and implement an algorithm that searches an unsorted array a[1:n] for the element x. If x occurs, then return a position in the array; else return zero.

arr = [2, 8, 1, 3, 6, 7, 5, 4]
ele = int(input('Enter element to be searched:\t'))



try:
    print("element found at ",arr.index(ele,1))
except:
    print('0')
