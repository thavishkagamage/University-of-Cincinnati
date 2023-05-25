# Homework 11.1 Task 2
# File: HW11p1_Task2_gamagetd.py 
# Date:    11/11/2021
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
# The program asks the user to input the temperature outside, the humidity
# and the weather condition to give a recommendation of what to do to ensure
# the safety of the workers on a construction site.

import math

# Ask for inputs
T = float(input('Please input the outside temperature (in Fahrenheit): '))
H = float(input('Relative humidity: '))
Wc = str(input('Enter the weather conditions (sunny, cloudy, or raining): '))

# Determine if inputs are valid
if ((T < -10) or (T > 125)):
    print('Invalid temperature')
    quit()
if ((H < 0) or (H > 1)):
    print('Invalid humidity')
    quit()
if ((Wc != 'Sunny') and (Wc != 'sunny') and (Wc != 'Cloudy')
    and (Wc != 'cloudy') and (Wc != 'Raining') and (Wc != 'raining')):
    print('Invalid weather condition.')
    quit()

# Consider all the possibilities.

if ((Wc == 'Raining') or (Wc == 'raining')):
    print('Work inside')
else:
    if (T >= 90):
        if ((H > 0.8) and ((Wc == 'Sunny') or (Wc == 'sunny'))):
            print('Please give two 15 minute breaks')
        elif ((H > 0.9) and ((Wc == 'Cloudy') or (Wc == 'cloudy'))):
            print('Please give one 15 minute break')
        else:
            print('Please give one 10 minute break')
    elif ((T > 80) and (H > 0.9) and ((Wc == 'Sunny') or (Wc == 'sunny'))):
        print('Please give two 10 minute break')
    elif ((T > 80) and ((H > 0.9) or ((Wc == 'Sunny') or (Wc == 'sunny')))):
        print('Please give one 10 minute break')
    else:
        print('No extra breaks')
