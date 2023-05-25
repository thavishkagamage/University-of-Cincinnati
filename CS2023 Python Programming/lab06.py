_author_ = "Thavishka Gamage"
_credits_ = "Worked independently"
_email_ = "gamagetd@mail.uc.edu" # Your email address

## Required Questions: Linked Lists ##
## Use the Linked List ADT defined below

#RQ1
def has_prefix(s, prefix):
    """Returns whether prefix appears at the beginning of linked list s.

    >>> x = link(3, link(4, link(6, link(6))))
    >>> print_link(x)
    3 4 6 6
    >>> has_prefix(x, empty)
    True
    >>> has_prefix(x, link(3))
    True
    >>> has_prefix(x, link(4))
    False
    >>> has_prefix(x, link(3, link(4)))
    True
    >>> has_prefix(x, link(3, link(3)))
    False
    >>> has_prefix(x, x)
    True
    >>> has_prefix(link(2), link(2, link(3)))
    False
    """
    if (prefix == empty):
        return True
    elif s[0] == prefix[0]:
        if prefix[1] == empty:
            return True
        else:
            return has_prefix(s[1],prefix[1])
    else:
        return False

#RQ2
def has_sublist(s, sublist):
    """Returns whether sublist appears somewhere within linked list s.

    >>> has_sublist(empty, empty)
    True
    >>> aca = link('A', link('C', link('A')))
    >>> x = link('G', link('A', link('T', link('T', aca))))
    >>> print_link(x)
    G A T T A C A
    >>> has_sublist(x, empty)
    True
    >>> has_sublist(x, link(2, link(3)))
    False
    >>> has_sublist(x, link('G', link('T')))
    False
    >>> has_sublist(x, link('A', link('T', link('T'))))
    True
    >>> has_sublist(link(1, link(2, link(3))), link(2))
    True
    >>> has_sublist(x, link('A', x))
    False
    """
    listm = list(sublist)

    if (sublist == empty):
        return True
    elif (s == empty):
        return False
    else:
        if (first(s) != first(listm)):
            return (has_prefix(rest(s),listm))
        else:
            while listm != empty:
                if is_link(s):
                    return False
                elif first(s) == first(listm):
                    s = rest(s)
                    listm = rest(listm)
                else:
                    listm = list(sublist)
                    s = rest(s)
            else:
                return True

    return False
        


#RQ3
def has_kitty_gene(dna):
    """Returns whether linked list dna contains the CATCAT gene.

    >>> dna = link('C', link('A', link('T')))
    >>> dna = link('C', link('A', link('T', link('G', dna))))
    >>> print_link(dna)
    C A T G C A T
    >>> has_kitty_gene(dna)
    False
    >>> end = link('T', link('C', link('A', link('T', link('G')))))
    >>> dna = link('G', link('T', link('A', link('C', link('A', end)))))
    >>> print_link(dna)
    G T A C A T C A T G
    >>> has_kitty_gene(dna)
    True
    >>> has_kitty_gene(end)
    False
    """
    testcase = link('C', link('A', link('T', link('C', link('A', link('T'))))))
    while dna != empty:
        if (testcase == empty):
            return True
        elif (first(dna) == first(testcase)):
            testcase = rest(testcase)

        dna = rest(dna)
            
    return False


#RQ4

def count_change(amount, denominations):
    """Returns the number of ways to make change for amount.

    >>> denominations = link(50, link(25, link(10, link(5, link(1)))))
    >>> print_link(denominations)
    50 25 10 5 1
    >>> count_change(7, denominations)
    2
    >>> count_change(100, denominations)
    292
    >>> denominations = link(16, link(8, link(4, link(2, link(1)))))
    >>> print_link(denominations)
    16 8 4 2 1
    >>> count_change(7, denominations)
    6
    >>> count_change(10, denominations)
    14
    >>> count_change(20, denominations)
    60
    """
    if (amount == 0):
       return 1
    elif (denominations == empty):
       return 0


    totalamount = count_change(amount,rest(denominations))

    amountofcoin = 1
    while first(denominations)*amountofcoin <= amount:
       totalamount += count_change((amount-first(denominations)*amountofcoin),rest(denominations))
       amountofcoin += 1
   
    return totalamount
    
        






# Linked list ADT
# Interface Definitions and Implementations
empty = 'empty'

def is_link(s): # used
    """s is a linked list if it is empty or a (first, rest) pair."""
    return s == empty or (type(s) == list and len(s) == 2 and is_link(s[1]))

def link(first, rest=empty): # used
    """Construct a linked list from its first element and the rest."""
    assert is_link(rest), 'rest must be a linked list.'
    return [first, rest]

def first(s): # used
    """Return the first element of a linked list s."""
    assert is_link(s), 'first only applies to linked lists.'
    assert s != empty, 'empty linked list has no first element.'
    return s[0]

def rest(s): # used
    """Return the rest of the elements of a linked list s."""
    assert is_link(s), 'rest only applies to linked lists.'
    assert s != empty, 'empty linked list has no rest.'
    return s[1]

def print_link(s): # implemented in doctests
    """Print elements of a linked list s.

    >>> s = link(1, link(2, link(3, empty)))
    >>> print_link(s)
    1 2 3
    """
    line = ''
    while s != empty:
        if line:
            line += ' '
        line += str(first(s))
        s = rest(s)
    print(line)

import doctest
if __name__ == "__main__":
  doctest.testmod(verbose=True)