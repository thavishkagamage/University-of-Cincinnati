""" Four Required questions for Lab 1."""
## Modify this file by adding your salutation and code. 
## Once you pass all the doctests, then 
# you can then submit you program for credit.

_author_ = "Thavishka Gamage"
_credits_ = "By myself"
_email_ = "gamagetd@mail.uc.edu"

# RQ1
def both_negative(x, y):
            
            """Returns True if both x and y are negative.

             >>> both_negative(-1, 1)
             False
             >>> both_negative(1, 2)
             False
             >>> both_negative(-1, -2)
             True
             """

            if x < 0 and y < 0:
                 result = True
            else:
                 result = False
            return result
             
     
 ## while Loops ##
 # RQ2
def not_factor (n):
             """Prints out all of the numbers that do not divide `n` evenly.
 
             >>> not_factor(10)
             9
             8
             7
             6
             4
             3
             """
            
             x = n
 
             while x > 1:
                 if n % x != 0:
 
                     print(x)
 
                 x = x - 1
                 
 # RQ3
def lucas(n):
             """Returns the nth Lucas number.
               Lucas numbers form a series similar to Fibonacci:
               2, 1, 3, 4, 7, 11, 18, 29, 47, 76, 123, 199, 322, 521, 843,...
 
             >>> lucas(0)
             2
             >>> lucas(1)
             1
             >>> lucas(2)
             3
             >>> lucas(3)
             4
             >>> lucas(11)
             199
             >>> lucas(100)
             792070839848372253127
             """
             
             lucas_number = 2
             lucas_number1 = 1
             x = 0    
 
             if n == 0:
                 print(lucas_number)
 
             elif n == 1:
                 print(lucas_number1)
 
             else:
                 while n > 1:
 
                     x = lucas_number1
                     lucas_number1 = lucas_number + lucas_number1
                     lucas_number = x
                     n = n - 1
 
                 print(lucas_number1)
                   
                     
 
 #RQ4
def gets_discount(p1, p2, p3):
     
             """ Returns True if p1 is an adult (age at least 18) and p2 and p3 are both children (age 12 or below),
             False otherwise. Do not use if statement.
             >>> gets_discount(15, 12, 11)
             False
             >>> gets_discount(90, 7, 12)
             True
             >>> gets_discount(18, 18, 18)
             False
             >>> gets_discount(40, 7, 15)
             False
             """
             
             return (p1 >= 18) and (p2 <= 12) and (p3 <= 12)
             
             
if __name__ == "__main__":
     import doctest
     doctest.testmod(verbose=(True))
 
