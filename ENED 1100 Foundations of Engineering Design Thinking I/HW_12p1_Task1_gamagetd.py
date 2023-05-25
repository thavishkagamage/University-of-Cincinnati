# Homework Homework 12.1 Task 1
# File: HW_12p1_Task1_gamagetd.py 
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
# After entering the beginning velocity, Vo, (m/s), and angle increment, Incr,
# the program will determine the maximum height, impact time, and matching angle (degrees).
# In addition, the application will check for invalid inputs and prompt until they are valid.

import math

Vo = float(input('Please enter a positive initial velocity: '))
while Vo < 0:
    Vo = float(input('Please enter a positive initial velocity: '))
Incr = int(input('Please enter an angle increment: '))
while ((Incr < 0) or (Incr > 90)):
    Incr = int(input('Please enter an angle increment between 0 and 90 degrees: '))

Angle = 0
i = 1
while Angle < 90:
    if ((Incr * i) > 90):
        break
    else:
        Angle = Incr * i
        Angle_rad = Angle * (math.pi / 180)
        Impact_Time = (2 * Vo * math.sin(Angle_rad)) / 9.81
        Max_Height = ((Vo ** 2) * (math.sin(Angle_rad)**2)) / (2 * 9.81)
        print('For Angle = {0} deg, Impact Time = {1:0.2f} s and Max Height = {2:0.2f} m'
              .format(Angle, Impact_Time, Max_Height))
        i += 1
