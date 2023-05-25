# CS2023 - Lab11

author = "Thavishka Gamage"
credits = "Worked independently"
email = "gamagetd@mail.uc.edu" # Your email address

# Starter code from textbook

import matplotlib.pyplot as plt 
import pandas as pd 
import numpy as np 
from pandas import DataFrame, Series 

sh_raw = pd.read_csv(r'C:\Users\thavi\Downloads\movies.csv',  header=None, names= 
['Year','Title','Comic','IMDB','RT', 'CompositeRating','OpeningWeekendBoxOffice','AvgTicketPriceThatYear','EstdOpeningAttendance','USPopThatYear']) 
print(sh_raw.head(5))

sh = sh_raw[np.isfinite(sh_raw.OpeningWeekendBoxOffice)] 
print(sh.head(5))


imdb_normalized = sh.IMDB / 10

sh.insert(10,'IMDBNormalized',imdb_normalized) 
rt_normalized = sh.RT/100

sh.insert(11, 'RTNormalized', rt_normalized)

sh.plot.scatter(x ='RTNormalized', y ='IMDBNormalized') 
plt.show()

print(sh[['RTNormalized','IMDBNormalized']].
corr())


print(sh[['RTNormalized','IMDBNormalized']].
describe())

# REQUIRED QUESTIONS BELOW

"""
1. Define a command to show only 
'DC' comic movies fromthe sh DataFrame. 
"""


print(sh.loc[sh['Comic'].str.contains(r'\DC\b', case=False)])
print(" ")
print(" ") # spacers added to space out data in console

"""
2.  Define a command to show the Year, 
Title and OpeningWeekendBoxOffice 
columns from the sh DataFrame.

"""
print(sh[['Year','Title','OpeningWeekendBoxOffice']])
print(" ")
print(" ") # spacers added to space out data in console

"""
3. Define a command to show the Year 
and Title of only 'Marvel' movies from 
the sh DataFrame. 

"""
print(sh[['Year','Title']].loc[sh['Comic'].str.contains('Marvel', case=False)])
print(" ")
print(" ") # spacers added to space out data in console


"""
4. Define a command to plot a  line()  for 
the AvgTicketPriceThatYear with Year on 
the x axis. Make the line Black. 
"""

sh.plot.line(x = 'Year', y = 'AvgTicketPriceThatYear', color = 'Black')
plt.show()