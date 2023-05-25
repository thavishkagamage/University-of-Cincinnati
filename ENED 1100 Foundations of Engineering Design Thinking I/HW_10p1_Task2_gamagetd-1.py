# Activity Python 1: HW_10p1_Task1
# File: HW_10p1_Task1_gamagetd.py
# Date:    04 12 1997
# By:      Thavishka Gamage
# Section: 003
# Team:    24
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
# This script is a header template that will be used for
# all your python files the rest of the semester.

# The program will ask the user to input the values for
# the intrinsic impedance and phase constant of 2 materials
# and the amplitude of the incident wave to calculate Brewster angle
# and the angles of the transmitted and reflected waves. It will also calculate the
# amplitude of the reflected and transmitted waves.

import math

# Tells user to input intrinsic impedences and phase constants of the two media
# (II is intrinsic impedence, and PC will stand for phase constant)
II1 = float(input('Please enter the intrinsic impedance of material 1: '))
PC1 = float(input('Please enter the phase constant of material 1:  '))
II2 = float(input('Please enter the intrinsic impedance of material 2: '))
PC2 = float(input('Please enter the phase constant of material 2:  '))

# Tell user to enter the amplitude of incident wave (IW)
IW = float(input('Please enter the amplitude of the incident wave (V/m): '))

# Calculate Brewster angle (in radians):
Brewster_rad = (math.asin(math.sqrt(((PC2 ** 2) * (II2 ** 2 - II1 ** 2)) / (((II2 ** 2) * (PC1 ** 2)) - ((II1 ** 2) * (PC2 ** 2))))))

# convert to degrees:
Brewster_deg = Brewster_rad * (180 / math.pi)

# Since the angle of the reflected wave (let this be RWA) is equal
# to Brewster angle (angle of the incident wave)
RWAngle = Brewster_deg

# Calculate transmitted wave angle (TWA) in radians:
TWAngle_rad = math.acos((II1 * math.cos(Brewster_rad)) / II2)

# convert TWA_rad to degrees:
TWAngle_deg = TWAngle_rad * (180 / math.pi)

#calculate the amplitude of the transmitted and reflected waves:
TWAmp = (((2 * II2 * math.cos(Brewster_rad)) / ((II2 * math.cos(TWAngle_rad)) + (II1 * math.cos(Brewster_rad)))) * IW)
RWAmp = ((((II2 * math.cos(Brewster_rad)) - (II1 * math.cos(TWAngle_rad))) / ((II2 * math.cos(Brewster_rad)) + (II1 * math.cos(TWAngle_rad)))) * IW)

# Output answers
print('Incident Angle: {0:0.2f} degrees'.format(Brewster_deg))
print('Reflected Angle: {0:0.2f} degrees'.format(RWAngle))
print('Transmitted Angle: {0:0.2f} degrees'.format(TWAngle_deg))
print('Reflected Amplitude: {0:0.2f} V/m'.format(RWAmp))
print('Transmitted Amplitude: {0:0.2f} V/m'.format(TWAmp))
