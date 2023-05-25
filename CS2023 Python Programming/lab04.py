## Lab 4: Module 4 - Lab 4 Required Questions

_author_ = "Thavishka Gamage"
_credits_ = "Worked Independently"
_email_ = "gamagetd@mail.uc.edu" # Your email address

# RQ1
def cascade(lst):
    """Returns the cascade of the given list.

cascade([1, 2, 3, 4])
    [1, 2, 3, 4, 4, 3, 2, 1]
    """
    list = []
    for j in range(len(lst)):
        list.append(lst[j])
    for k in reversed(range(len(lst))):
        list.append(lst[k])
    return list

# RQ2
def maptwice(fn, seq):
    """Applies fn twice onto each element in seq and returns the resulting list.

    >>> maptwice(lambda x: x*x, [1, 2, 3])
    [1, 16, 81]
    """
    list = seq
    for i in range (len(seq)):
        list[i] = fn(fn(list[i]))
    return list

#RQ3
def filterout(pred, seq):
    """Keeps elements in seq only if they do not satisfy pred.

    >>> filterout(lambda x: x % 2 == 0, [1, 2, 3, 4])
    [1, 3]
    """
    list = []
    for x in range (len(seq)):
        if pred(seq[x]) == False:
            list.append(seq[x])
    return list

#RQ4
def comp(n, pred):
    """ Uses a one line list comprehension to return list of the first n integers (0...n-1) which satisfy the predicate pred.
    >>> comp(7, lambda x: x%2 ==0)
    [0, 2, 4, 6]
    """
    list = []
    for i in range(n):
        if (pred(i)):
            list.append(i)
    return list

#RQ5
def flatten(lst):
    """ Takes a nested list and "flattens" it.

    >>> flatten([1, 2, 3]) 
    [1, 2, 3]
    >>> x = [1, [2, 3], 4]
    >>> flatten(x)
    [1, 2, 3, 4]
    >>> x = [[1, [1, 1]], 1, [1, 1]] 
    >>> flatten(x)
    [1, 1, 1, 1, 1, 1]
    >>> lst = [1, [[2], 3], 4, [5, 6]]
    >>> flatten(lst)
    [1, 2, 3, 4, 5, 6]
    """
    list_1 = lst

    if (len(list_1) == 0):
        return list_1
    elif isinstance(list_1[0], list):
        return flatten(list_1[0]) + flatten(list_1[1:])
    return list_1[:1] + flatten(list_1[1:])

    
import doctest
if __name__ == "__main__":
  doctest.testmod(verbose=True)