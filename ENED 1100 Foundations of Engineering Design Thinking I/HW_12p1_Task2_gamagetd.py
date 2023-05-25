# Homework Homework 12.1 Task 1
# File: HW_12p1_Task2_gamagetd.py
# Date:    11/18/2021
# By:      Thavishka Gamage
# Section: 003
# Team:    024
# 
# ELECTRONIC SIGNATURE
# Thavishka Gamage
#
# The electronic signature above indicates the script
# submitted for evaluation is my individual work, and I
# have a general understanding of all aspects of its
# development and execution.
#
# A BRIEF DESCRIPTION OF WHAT THE SCRIPT OR FUNCTION DOES
# After entering the winning score, the program will simulate a two-player game of Sevens Out.
# If no positive number is submitted, keep prompting until the winning score is positive,
# then ask for each player's name.
# And the program will determine who is first by having each player roll a single die and displaying the results.
import math
import random

#input goal and the names of players
Goal = int(input('Please decide on a winning score: '))
while Goal < 0:
    Goal = int(input('Please decide on a POSITIVE winning score: '))
Player_1 = str(input('Enter player 1 name: '))
Player_2 = str(input('Enter player 2 name: '))

#both roll a die to decide who goes first
input('Now {0} press enter to roll a die: '.format(Player_1))
Player_1_Start = random.randint(1,6)
print('{0} got a {1}'.format(Player_1, Player_1_Start))
input('Now {0} press enter to roll a die: '.format(Player_2))
Player_2_Start = random.randint(1,6)
print('{0} got a {1}'.format(Player_2, Player_2_Start))

#check if they tied, and tell them to roll again if so.
while Player_1_Start == Player_2_Start:
    input('Now {0} press enter to roll a die again: '.format(Player_1))
    Player_1_Start = random.randint(1,6)
    print('{0} got a {1}'.format(Player_1, Player_1_Start))
    input('Now {0} press enter to roll a die again: '.format(Player_2))
    Player_2_Start = random.randint(1,6)
    print('{0} got a {1}'.format(Player_2, Player_2_Start))
if Player_1_Start > Player_2_Start:
    print('{0} goes first!'.format(Player_1))
    First_Player = Player_1
    Second_Player = Player_2
elif Player_2_Start > Player_1_Start:
    print('{0} goes first!'.format(Player_2))
    First_Player = Player_2
    Second_Player = Player_1


#call in some variables to keep track of the scores and rolls 
First_Player_Score = 0
Second_Player_Score = 0
roll1 = 0
roll2 = 0

#loop around, and stops if one of the players gets more than the target point.
while (First_Player_Score <= Goal) and (Second_Player_Score <= Goal):
    #
    while First_Player_Score <= Goal and Second_Player_Score <= Goal:
        roll1 = random.randint(1,6)
        roll2 = random.randint(1,6)
        print('\n{0} rolled a {1} and a {2}'.format(First_Player, roll1, roll2))
        roll_Total = roll1 + roll2
        if roll1 == roll2:
            roll_Total = roll_Total * 2
        First_Player_Score += roll_Total
        if First_Player_Score >= Goal:
            print('\n{0} is the winner!'.format(First_Player))
            print('{0} got {1} points.'.format(First_Player, First_Player_Score))
            print('{0} got {1} points.'.format(Second_Player, Second_Player_Score))
        if roll_Total == 7:
            First_Player_Score -= roll_Total
            print('{0} rolled a total of 7'.format(First_Player))
            print('\nCurrent scores are:\n{0} got {1} points.\n{2} got {3} points.'.format
                  (First_Player, First_Player_Score, Second_Player, Second_Player_Score))
            input('{0}, Press enter to roll.'.format(Second_Player))
            break
    while First_Player_Score <= Goal and Second_Player_Score <= Goal:
        roll1 = random.randint(1,6)
        roll2 = random.randint(1,6)
        print('\n{0} rolled a {1} and a {2}'.format(Second_Player, roll1, roll2))
        roll_Total = roll1 + roll2
        if roll1 == roll2:
            roll_Total = roll_Total * 2
        Second_Player_Score += roll_Total
        if Second_Player_Score >= Goal:
            print('\n{0} is the winner!'.format(Second_Player))
            print('{0} got {1} points.'.format(First_Player, First_Player_Score))
            print('{0} got {1} points.'.format(Second_Player, Second_Player_Score))
        if roll_Total == 7:
            Second_Player_Score -= roll_Total
            print('{0} rolled a total of 7'.format(Second_Player))
            print('Current scores are:\n{0} got {1} points.\n{2} got {3} points.'.format
                  (First_Player, First_Player_Score, Second_Player, Second_Player_Score))
            input('{0}, Press enter to roll.'.format(First_Player))
            break