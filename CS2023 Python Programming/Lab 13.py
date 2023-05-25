author = "Thavishka Gamage"
credits = "Worked independently"
email = "gamagetd@mail.uc.edu" # Your email address

import pandas as pd
from IPython.display import display
from sklearn.datasets import fetch_california_housing
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn import metrics

cali = fetch_california_housing()
caliDf = pd.DataFrame(cali.data, columns=cali.feature_names)
caliDf["MedHouseValue"] = pd.Series(cali.target)

xTrain, xTest, yTrain, yTest = train_test_split( cali.data, cali.target,random_state=11)
muRegress = LinearRegression()
muRegress.fit(X=xTrain, y=yTrain)
predicted = muRegress.predict(xTest)
expected = yTest
print(f"Multiple Linear Progression using ALL features\nR2 score :{metrics.r2_score(expected, predicted)}\nhas MSE score:{metrics.mean_squared_error(expected, predicted)}\n")

for i in range(8):
    xTrain, xTest, yTrain, yTest = train_test_split(caliDf.iloc[:,i].values.reshape(-1,1), cali.target, random_state=11)
    regress = LinearRegression()
    regress.fit(X=xTrain, y=yTrain)
    predicted = regress.predict(xTest)
    expected = yTest
    print(f"Feature {i} has R2 score : {metrics.r2_score(expected, predicted)}\n has MSE score:  {metrics.mean_squared_error(expected, predicted)}")