import numpy as np
from sklearn.metrics import mean_squared_error
from sklearn.linear_model import LinearRegression
import pandas as pd


def fn(arr, X, Y):
	if len(arr) == f:
		XN = X
		for i, a in enumerate(arr):
			XN[:, i] = X[:, i] ** a
			model = LinearRegression().fit(XN, Y)
			p = model.predict(XN)
			err = mean_squared_error(Y, p)
			return err, model
	else:
		j = len(arr)
		arr.append(0)
		minerr = -1.0
		for k in range(4):
			arr[j] = k
			err, model = fn(arr, X, Y)
			if minerr == -1.0 or minerr > err:
				bestmodel = model
		del arr[-1]
		return minerr, bestmodel


f, n = input().split(" ")
f, n = int(f), int(n)
x = []
y = []
for i in range(n):
	s = [float(v) for v in input().split()]
	x.append(s[:-1])
	y.append([s[-1]])
X = np.array(x)
Y = np.array(y)
minerr, bestmodel = fn([], X, Y)

t = int(input())
xt = []
for i in range(t):
	s = [float(v) for v in input().split()]
	xt.append(s)
XT = np.array(xt)
p = bestmodel.predict(XT)
for v in np.nditer(p):
	print(v)