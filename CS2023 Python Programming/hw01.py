
# CS2023 Python Programming Challenge #1

_author_ = "Thavishka Gamage"
_credits_ = "Worked independently"
_email_ = "gamagetd@mail.uc.edu" # Your email address


# defined function egypt

def egypt(p,q):
    
    """
    >>> egypt(3,4)
    '1/2 + 1/4 = 3/4'
    >>> egypt(11,12)
    '1/2 + 1/3 + 1/12 = 11/12'
    

## Partial credit will be given for code that passes the two given doctests. 
## For full credit on HW1 you should test your solutions to egypt(103,104) and  egypt(123,124)
## These are more difficult and may require you to develop faster, more efficient code.
## Hint: you may consider using code for gcd function for greatest common divisor:
## https://www.geeksforgeeks.org/gcd-in-python/

    >>> egypt(123,124)
    '1/2 + 1/3 + 1/7 + 1/64 + 1/8333 + 1/347186112 = 123/124'
    >>> egypt(103,104)
    '1/2 + 1/3 + 1/7 + 1/71 + 1/9122 + 1/141449381 + 1/100039636784966424 = 103/104'
    """


    
    numerator = p
    denominator = q

    # list for denominator
    denomlist = []

    # Computations for every fraction and lists them. crafted to accommodate huge fractions in order to prevent overflow errors.
    while numerator != 0:

        if denominator % numerator == 0:
            unit = denominator // numerator
        else:
            unit = (denominator // numerator) + 1

        denomlist.append(unit)

        numerator = (numerator*unit) - denominator
        denominator = denominator*unit


    # For formatting, use the print statement to display the first
    print('\'', sep='', end='')

    # Executing the for loop and outputting the fractions
    for i in range(len(denomlist)):
        print(f"1/{denomlist[i]}",end="")
        if i >= len(denomlist)-1:
                print(f" = {p}/{q}",end="'")
                break
        else:
            print(" + ",end="")
       

## Partial credit will be given for code that passes the two given doctests. 
## For full credit on HW1 you should test your solutions to egypt(103,104) and  egypt(123,124)
## These are more difficult and may require you to develop faster, more efficient code.

import doctest
if __name__ == "__main__":
  doctest.testmod(verbose=True)