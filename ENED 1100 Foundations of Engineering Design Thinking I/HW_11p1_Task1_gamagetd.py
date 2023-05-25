# Homework 11.1 Task 1
# File: HW_11p1_Task1_gamagetd.py 
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
# A BRIEF DESCRIPTION OF WHAT THE SCRIPT OR FUNCTION DOES
# The program will ask the user to input temperature, weather conditions,
# humidity, number of ladders on the construction site, the height of the
# structure, and the dryness of the surface to determine the safeness of a
# construction site, and give a recommendation of what to do to ensure safety.


import math

# Ask user for inputs, and define HRI, FRI, and H_Cat
T = float(input('Please input the outside temperature (in Fahrenheit): '))
print('\n3: Sunny \n2: Partly cloudy. \n0: Cloudy.')
Wc = int(input('Weather conditions (pick from above):'))
H = float(input('Relative humidity: '))
L = int(input('Number of ladders on construction site: '))
H_Struc = int(input('Height of the structure: '))
print('\n3: All surfaces wet \n2: Puddles with some dry area. \n0: Completely dry.')
S_Dry = int(input(' Surface Dryness (pick from above): '))
HRI = float
FRI = float
H_Cat = float


# Determine if inputs are valid
if ((T < -10) or (T > 125)):
    print('Invalid temperature')
    exit()
if ((Wc < 0) or (Wc > 3) or (Wc == 1)):
    print('Invalid weather condition.')
    exit()
if ((H < 0) or (H > 1)):
    print('Invalid humidity.')
    exit()
if ((H_Struc < 20) or (H_Struc > 2800)):
    print('Invalid structure height.')
    exit()
if ((S_Dry > 3) or (S_Dry < 0) or (S_Dry == 1)):
    print('Invalid surface dryness.')
    exit()

# Calculate HRI:
HRI = (0.75 * T) + (5.0 * Wc) + (H ** 2)
print('HRI: {0:0.1f}'.format(HRI))

# Determine H_Cat based on HRI
if (HRI > 75):
    H_Cat = 1
else:
    H_Cat = 0

# Calculate FRI:
FRI = (0.2 * L) + (0.03 * H_Struc) + (30 * H_Cat) + (10 * S_Dry)
print('FRI: {0:0.1f}\n'.format(FRI))


# Goes through the calculated HRI and FRI to determing recommendations.
if (HRI > 75) and (FRI > 100):
    print('Please hold a safety session and allow an extra break.')
elif (HRI > 75):
    print('Allow Extra Break.')
elif (FRI > 100):
    print('Hold a Safety Session.')
if (HRI <= 75) and (FRI <= 100):
    print('Safety is Job #1')