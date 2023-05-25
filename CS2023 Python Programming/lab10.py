## Module 10 - Lab 10 - ML - Required Questions ##

_author_ = "Thavishka Gamage"
_credits_ = "Worked independently"
_email_ = "gamagetd@mail.uc.edu" # Your email address

"""
Trying model with 10 estimators...
Model accuracy on test set: 77.05%

Trying model with 20 estimators...
Model accuracy on test set: 80.33%

Trying model with 30 estimators...
Model accuracy on test set: 75.41%

Trying model with 40 estimators...
Model accuracy on test set: 81.97%

Trying model with 50 estimators...
Model accuracy on test set: 75.41%

Trying model with 60 estimators...
Model accuracy on test set: 78.69%

Trying model with 70 estimators...
Model accuracy on test set: 78.69%

Trying model with 80 estimators...
Model accuracy on test set: 77.05%

Trying model with 90 estimators...
Model accuracy on test set: 80.33%
"""

import numpy as np

# 1. Get the data ready
import pandas as pd
heart_disease = pd.read_csv("downloads/heart.csv")
heart_disease


# Create x (features matrix)
X = heart_disease.drop("target", axis = 1)

# Create y (labels)
y = heart_disease["target"]


# 2. Choose the right model and hyperparameters
from sklearn.ensemble import RandomForestClassifier
clf = RandomForestClassifier(n_estimators=100)

# Keep the default hyperparameters
clf.get_params()



# 3. Fit the model to the training data
from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2)

clf.fit(X_train, y_train);

X_train

# make a prediction
y_lable = clf.predict(np.array([0, 2, 3, 4]))

y_preds = clf.predict(X_test)
y_preds


y_test



# 4. Evaluate the model
clf.score(X_train, y_train)


clf.score(X_test, y_test)

from sklearn.metrics import classification_report, confusion_matrix, accuracy_score

print(classification_report(y_test, y_preds))


confusion_matrix(y_test, y_preds)


accuracy_score(y_test, y_preds)


#5. Improve a model
# Try different amount of n_estimators
np.random.seed(42)
for i in range(10, 100, 10):
    print(f"Trying model with {i} estimators...")
    clif = RandomForestClassifier(n_estimators=i).fit(X_train, y_train)
    print(f"Model accuracy on test set: {clif.score(X_test, y_test) * 100:.2f}%")
    print("")
