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

# The program will take in the relative permittivity and permeability of two material
# and the amplitude of an incident wave and calculate the intrinsic impedences of the two
# media and the values of the transmitted and reflected waves.

import math

# Pt is permittivity, Pm is permeability
Pt1 = float(input('Please enter the relative permittivity of material 1: '))
Pm1 = float(input('Please enter the relative permeability of material 1: '))
Pt2 = float(input('Please enter the relative permittivity of material 2: '))
Pm2 = float(input('Please enter the relative permeability of material 2: '))

# IW is the amplitude of the incident wave
IW = float(input('Please enter the amplitude of the incident wave (V/m): '))

# calculate intrinsic impedence (II)
II1 = 377.14 * (( Pm1 / Pt1 ) ** (1/2))
II2 = 377.14 * (( Pm2 / Pt2 ) ** (1/2))

# calculate the amplitude of the reflected and transmitted wave (RW is reflected, and TW is
# transmitted)
TW = ((2 * II2) / (II2 + II1)) * IW
RW = ((II2 - II1) / (II2 + II1)) * IW

#Output answers
print('Intrinsic Impedence 1: {0:0.2f} Ohms'.format(II1))
print('Intrinsic Impedence 2: {0:0.2f} Ohms'.format(II2))
print('Reflected Amplitude: {0:0.2f} V/m'.format(RW))
print('Transmitted Amplitude: {0:0.2f} V/m'.format(TW))

