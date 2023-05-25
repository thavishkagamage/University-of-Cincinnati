# Lab14

author = "Thavishka Gamage"
credits = "Worked independently"
email = "gamagetd@mail.uc.edu" # Your email address

# imports 
import numpy as np
from random import random
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt


balls = np.arange(1,1000,1)
emptyBin = []
numBins = 0

for N in balls:
    numBins = 0
    bins = np.zeros(N)

    for b in range(N):
        bins[int(N*random())] += 1

    for i in bins:
        if i == 0:
            numBins += 1

    emptyBin.append(numBins)


plt.plot(balls, emptyBin)
plt.show()

x = balls.reshape(-1,1)
y = emptyBin

model = LinearRegression().fit(x,y)
intercept = model.intercept_
rvalue = model.score(x,y)
slope = model.coef_

print("SciPy Linear Regression Solution")
print(' slope: ', (float(slope)))
print(' intercept ', (float(intercept)))
print(' rvalue: ', (rvalue))