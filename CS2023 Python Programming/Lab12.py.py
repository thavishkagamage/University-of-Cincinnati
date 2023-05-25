#Lab 12 - Python Programming

author = "Thavishka Gamage"
credits = "Worked independently"
email = "gamagetd@mail.uc.edu" # Your email address

#RQ1
class Cheer:
    """
    >>> UC = Cheer("Bearcats")
    >>> for c in UC:
    ...     print(c)
    ...
    Give me an B
    Give me an e
    Give me an a
    Give me an r
    Give me an c
    Give me an a
    Give me an t
    Give me an s
    """
    "*** YOUR CODE HERE ***"
    def __init__(self, text):
        self.text = text
        self.i = -1

    def __iter__(self):
        return Cheer(self.text)

    def __next__(self):
        self.i += 1
        if self.i == len(self.text):
            raise StopIteration
        return "Give me an " + self.text[self.i]

#RQ2
class Countdown:
    """
    An iterator that counts down from N to 0.
    >>> for number in Countdown(5):
    ...     print(number)
    ...
    5
    4
    3
    2
    1
    0
    >>> for number in Countdown(2):
    ...     print(number)
    ...
    2
    1
    0
    """
    
    "*** YOUR CODE HERE ***"

    def __init__(self,N):
        self.N=N
    def __iter__(self):
        while self.N>=0:
            yield self.N
            self.N=self.N-1

##############
# Generators #
##############

# RQ3
def evens():
    """A generator function that yields the infinite sequence of all even natural
    numbers, starting at 1.

    >>> m = evens()
    >>> type(m)
    <class 'generator'>
    >>> [next(m) for _ in range(10)]
    [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    """
    "*** YOUR CODE HERE ***"

    x = 1
    while True:
        yield x
        x+=1
#RQ4
def scale(s, k):
    """Yield elements of the iterable s scaled by a number k.

    >>> s = scale([1, 5, 2], 5)
    >>> type(s)
    <class 'generator'>
    >>> list(s)
    [5, 25, 10]

    >>> m = scale(evens(), 2)
    >>> [next(m) for _ in range(5)]
    [2, 4, 6, 8, 10]
    """
    "*** YOUR CODE HERE ***"

    for y in s:
        yield y*k

# RQ5
def countdown(n):
    """
    A generator that counts down from N to 0.
    >>> for number in countdown(5):
    ...     print(number)
    ...
    5
    4
    3
    2
    1
    0
    >>> for number in countdown(2):
    ...     print(number)
    ...
    2
    1
    0
    """
    "*** YOUR CODE HERE ***"
    while n>=0:
        yield n
        n=n-1

# RQ6
def hailstone(n):
    """
    >>> for num in hailstone(10):
    ...     print(num)
    ...
    10
    5
    16
    8
    4
    2
    1
    """
    "*** YOUR CODE HERE ***"
    yield n
    if n == 1:
        return
    elif n % 2 == 0:
        n = n // 2
        yield from hailstone(n)
    else:
        n = n * 3 + 1
        yield from hailstone(n)

import doctest
doctest.testmod(verbose=True)