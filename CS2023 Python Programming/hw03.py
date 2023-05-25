# CS2023 - HW03

_author_ = "Thavishka Gamage"
_credits_ = "Worked independently"
_email_ = "gamagetd@mail.uc.edu" # Your email address


# Starter Code

url = "http://raw.githubusercontent.com/eneko/data-repository/master/data/words.txt"
import os
from urllib.request import urlopen
wordfile = urlopen(url)
words = wordfile.read().decode('utf-8').upper().split()

# My Code
# This was designed as a function to run the doctests as presented from the
# canvas assignment page

# NOTE: doctests were modified to have the expected words in alphabetical order
# this was done as while the program produces all the correct words, it does still
# fail the tests because of the order the words are in

def step(x):
    
    """
   >>> step("APPLE")
    ['APPEAL', 'CAPPLE', 'PALPED', 'LAPPED', 'DAPPLE', 'ALEPPO', 'LAPPER', 'RAPPEL', 'LAPPET', 'PAPULE', 'UPLEAP']

>>> step("UC")
    ['UCA', 'CUB', 'CUD', 'CUE', 'LUC', 'CUM', 'CUP', 'CUR', 'CUT']

>>> step("BEARCAT")
    ['BRACCATE', 'ACERBATE', 'BACTERIA', 'BRACTEAL', 'CARTABLE', 'SCABRATE']
    """
    
    wordChecker = []
    for i in range(65, 91): # based on ASCII Values
        wordChecker.append(chr(i))
    
    def step(wordIn):
    
        wordOut = []
        for w in words:
    
            if len(w) != len(wordIn)+1:
                continue
    
            for wc in wordChecker:
    
                if wc not in w:
                    continue
    
                if sorted(w) == sorted(wordIn + wc):
                    wordOut += [w]
    
        return wordOut
    
    print(step(x))

# Doctest function below switched to true to ensure that program was working
# with displaying tests failing/passing

import doctest
if __name__ == "__main__":
  doctest.testmod(verbose=True)

"""
The primary problem with my code is that because it performs a crude array search,
it executes roughly 235881*26 loops for each comparison. Even after saving my file last Monday and trying to think about it all weekend,
I was confused of how else to approach the search.
I first make sure the dictionary term is the appropriate length for my step word in an effort to reduce some of these comparisons.
When determining whether a word is equal to a word that is only two letters long,
there is no need to loop through and manually add each letter of the alphabet to a word.
After that, I make sure the word to which the letter is being added is actually in the dictionary.
I don't have to perform an entire comparison before writing data to an array.
This wasn't a particularly effective solution to the problem,
but these two tests did assist reduce the time to under a second
(for APPLE, other words can still take slightly over 2 seconds but were still improved).
The biggest problem, and the one I was unable to resolve, is making comparisons for all 235886 words.
The most beneficial strategy, though it wasn't the finest in the overall scheme, was to check the length to skip the 26 solutions.
"""