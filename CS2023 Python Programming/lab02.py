# CS2021 Lab 02 - Required Questions
## Modify this file by adding your salutation and code. 
## Once you pass all the doctests, then 
## you can then submit you program for credit. 

_author_ = "Thavishka Gamage"
_credits_ = "Worked Independently"
_email_ = "gamagetd@mail.uc.edu" # Your email address

#  RQ1
"""
Write a function day_name that converts an integer number 0 to 6 into the name of a day. Assume day 0 is “Sunday”. Your function should return error message if the arguments to the function are not valid. 
"""
def day_name(n):
    """
    >>> day_name(3) 
    'Wednesday'
    >>> day_name(6) 
    'Saturday'
    >>> day_name(42)
    'Invalid argument'
    """
    "*** YOUR CODE HERE ***"
    
    def intcon(n):
        if n == 0:
            return "Sunday"
        elif n == 1:
            return "Monday"
        elif n == 2:
            return "Tuesday"
        elif n == 3:
            return "Wednesday"
        elif n == 4:
            return "Thursday"
        elif n == 5:
            return "Friday"
        elif n == 6:
            return "Saturday"
        else:
            return "Invalid argument"
            
    return intcon(n)

#  RQ2
def two_of_three(a, b, c):
    """Return value using only a one-line return statement.  The value should be the
    sum of two squares x*x + y*y, where x and y are the two largest members of the set of
    positive numbers a, b, and c.

    >>> two_of_three(1, 2, 3)
    13
    >>> two_of_three(5, 3, 1)
    34
    >>> two_of_three(10, 2, 8)
    164
    >>> two_of_three(5, 5, 5)
    50
    """
    return (a ** 2) + (b ** 2) + (c ** 2) - (min(a,b,c) ** 2)


#  RQ3
def largest_factor(n):
    """Return the largest factor of n that is smaller than n.

    >>> largest_factor(15) # factors are 1, 3, 5
    5
    >>> largest_factor(80) # factors are 1, 2, 4, 5, 8, 10, 16, 20, 40
    40
    """
    "*** YOUR CODE HERE ***"
    
    def print_factor(n):
        factors = []
        for i in range(1,n-1,1):
            if n%i == 0:
                factors.append(i)
        return (factors[-1])
    return print_factor(n)

         
#  RQ4
def keeper(pred, n):
    """Print the numbers between 1 and n which satisfy the predicate pred.

    >>> keeper(lambda x: x%2 == 0, 15)
    2 4 6 8 10 12 14 
    >>> keeper(lambda x: x%7 == 0, 40)
    7 14 21 28 35 
    """
    "*** YOUR CODE HERE ***"  
    
    
    def pre_result(n):
        for j in range(1,n):
            if pred(j) == True:
                print(j, end=" ")
    return pre_result(n)
    
       
    
import doctest
if __name__ == "__main__":
  doctest.testmod(verbose=True)