"""The Game of Hog."""

_author_ = "Thavishka Gamage"
_credits_ = "Worked Independently"
_email_ = "gamagetd@mail.uc.edu" # Your email address

from dice import four_sided, six_sided, make_test_dice

GOAL_SCORE = 100 # The goal of Hog is to score 100 points.

######################
# Phase 1: Simulator #
######################

def roll_dice(num_rolls, dice=six_sided):
    """
    $ python3 -i hog.py
>>> dice = make_test_dice(1, 2, 3)
>>> dice()
1
>>> dice()
2
>>> dice()
3
>>> dice()
1
>>> dice()
2
    >>> roll_dice(1,make_test_dice(4, 2, 1, 3))
    4
    >>> roll_dice(2,make_test_dice(4, 2, 1, 3))
    6
    >>> roll_dice(3,make_test_dice(4, 2, 1, 3))
    1
    >>> roll_dice(4,make_test_dice(4, 2, 1, 3))
    1
    """
    # These assert statements ensure that num_rolls is a positive integer.
    assert type(num_rolls) == int, 'num_rolls must be an integer.'
    assert num_rolls > 0, 'Must roll at least once.'
    # BEGIN Question 1
    Sum = 0
    pig_out_total = 1
    while num_rolls > 0:
        dice_value = dice()
        Sum = Sum + dice_value
        if dice_value == 1:
            return 1
        num_rolls = num_rolls - 1
    else:
        return Sum
    # END Question 1


def take_turn(num_rolls, opponent_score, dice=six_sided):
    """
    $ python3 -i hog.py
    >>> take_turn(2, 0, make_test_dice(4, 6, 1))
    10
    >>> take_turn(3, 0, make_test_dice(4, 6, 1))
    1
    >>> take_turn(0, 35)
    6
    >>> take_turn(0, 71)
    8
    >>> take_turn(0, 7)
    8
    >>> take_turn(0, 0)
    1
    >>> take_turn(0, 9)
    10
    >>> take_turn(2, 0, make_test_dice(6))
    12
    >>> take_turn(0, 50)
    6
    """
    """Simulate a turn rolling NUM_ROLLS dice, which may be 0 (Free bacon).

    num_rolls:       The number of dice rolls that will be made.
    opponent_score:  The total score of the opponent.
    dice:            A function of no args that returns an integer outcome.
    """
    assert type(num_rolls) == int, 'num_rolls must be an integer.'
    assert num_rolls >= 0, 'Cannot roll a negative number of dice.'
    assert num_rolls <= 10, 'Cannot roll more than 10 dice.'
    assert opponent_score < 100, 'The game should be over.'
    # BEGIN Question 2
    from math import sqrt
    def is_prime(n):
        k = 2
        if n > 1:
            while k <= (sqrt(n)):
                if n % k == 0:
                    return False
                else:
                    k += 1
            return True
    
    def next_prime(n):
        new_prime = n + 1
        while not is_prime(new_prime):
            new_prime += 1
        return new_prime
    
    if num_rolls == 0:
        score = max(opponent_score // 10, opponent_score % 10) + 1
    else:
        score = roll_dice(num_rolls, dice)
    
    if is_prime(score):
        return next_prime(score)
    else:
        return score 
    # END Question 2

def select_dice(score, opponent_score):
    """
    $ python3 -i hog.py
    >>> select_dice(4, 24) == four_sided
    True
    >>> select_dice(16, 64) == four_sided
    False
    >>> select_dice(0, 0) == four_sided
    True
    >>> select_dice(50, 80) == four_sided
    False   
    """
    """Select six-sided dice unless the sum of SCORE and OPPONENT_SCORE is a
    multiple of 7, in which case select four-sided dice (Hog wild).
    """
    # BEGIN Question 3
    if (score + opponent_score) % 7 == 0:
        return four_sided
    return six_sided
    # END Question 3

def is_swap(score0, score1):
    """
    $ python3 -i hog.py
    >>> is_swap(19, 91)
    True
    >>> is_swap(20, 40)
    False
    >>> is_swap(41, 14)
    True
    >>> is_swap(23, 42)
    False
    >>> is_swap(55, 55)
    True
    >>> is_swap(114, 41) # We check the last two digits
    True
    """
    """Return True if ending a turn with SCORE0 and SCORE1 will result in a
    swap.

    Swaps occur when the last two digits of the first score are the reverse
    of the last two digits of the second score.
    """
    # BEGIN Question 4
    if score0 > 99:
        if (score0 - 100) // 10 == score1 % 10 and (score0 - 100) % 10 == score1 // 10:
            return True
        else:
            return False
    elif score1 > 99:
        if (score1 - 100) // 10 == score0 % 10 and (score1 - 100) % 10 == score0 // 10:
            return True
        else:
            return False
    elif score0 // 10 == score1 % 10 and score0 % 10 == score1 // 10:
        return True
    else:
        return False
    # END Question 4


def other(who):
    """Return the other player, for a player WHO numbered 0 or 1.

    >>> other(0)
    1
    >>> other(1)
    0
    """
    return 1 - who

def play(strategy0, strategy1, score0=0, score1=0, goal=GOAL_SCORE):
    """
    $ python3 -i hog.py
    >>> four_sided = make_test_dice(1)
    >>> six_sided = make_test_dice(3)
    >>> always = always_roll
    >>> s0,s1 = play(always(5), always(3), score0=91, score1=10)
    >>> s0, s1
    (106, 10)

    >>> s0,s1 = play(always(5), always(5), goal=10)
    >>> s0, s1
    (1, 15)

    >>> s0,s1 = play(always(5), always(3), score0=36, score1=15, goal=50)
    >>> s0, s1
    (15, 51)

    >>> # Swine swap applies to 3 digit scores
    >>> s0,s1 = play(always(5), always(3), score0=98, score1=31)
    >>> s0,s1
    (31, 113)

    >>> # Goal edge case
    >>> s0,s1 = play(always(4), always(3), score0=88, score1=20)
    >>> s0, s1
    (100, 20)
    >>> import random
>>> four_sided = lambda: random.randrange(1, 5)
>>> six_sided = lambda: random.randrange(1, 7)
>>> random_strat = lambda a, b: (random.randrange(11) + b) % 10
>>> random.seed(4321)
>>> for _ in range(100):
       s0, s1 = play(random_strat,random_strat)
>>> def printed(fn):
...     def print_and_return(*args):
...         result = fn(*args)
...         print('Result:', result)
...         return result
...     return print_and_return
>>> printed_pow = printed(pow)
>>> printed_pow(2, 8)
>>> printed_abs = printed(abs)
>>> printed_abs(-10)            
    """
    """Simulate a game and return the final scores of both players, with
    Player 0's score first, and Player 1's score second.

    A strategy is a function that takes two total scores as arguments
    (the current player's score, and the opponent's score), and returns a
    number of dice that the current player will roll this turn.

    strategy0:  The strategy function for Player 0, who plays first
    strategy1:  The strategy function for Player 1, who plays second
    score0   :  The starting score for Player 0
    score1   :  The starting score for Player 1
    """
    who = 0  # Which player is about to take a turn, 0 (first) or 1 (second)
    # BEGIN Question 5
    score, op_score, strategy, op_strategy = score0, score1, strategy0, strategy1

    dice = six_sided
    while score0 < goal and score1 < goal:
        if score0 + score1 % 7 == 0:
            dice = four_sided
        else: 
            dice = six_sided
        if who == 0:
            score0 += take_turn(strategy0(score0, score1), score1, dice)
        else:
            score1 += take_turn(strategy1(score1, score0), score0, dice)
        if is_swap(score0, score1):
            score0, score1 = score1, score0
        who = other(who)
    # END Question 5
    return score0, score1


def always_roll(n):
    """Return a strategy that always rolls N dice.
    

    A strategy is a function that takes two total scores as arguments
    (the current player's score, and the opponent's score), and returns a
    number of dice that the current player will roll this turn.

    >>> strategy = always_roll(5)
    >>> strategy(0, 0)
    5
    >>> strategy(99, 99)
    5
    """
    def strategy(score, opponent_score):
        return n
    return strategy

import doctest
if __name__ == "__main__":
  doctest.testmod(verbose=True)