import matplotlib.pylab as plt
from sklearn import datasets

import numpy as np


def split_data(x, y, k):
	y_temp = np.reshape(y, (-1, 1))
	x_bias = np.concatenate((x, np.ones((x.shape[0], 1))), 1)
	combined = np.concatenate((x_bias, y_temp), 1)
	np.random.shuffle(combined)
	n = int(x.shape[0] * k)
	train = combined[:n, :]
	test = combined[n:, :]
	train_split = np.split(train, [-1], 1);
	test_split = np.split(test, [-1], 1);
	return train_split[0], train_split[1], test_split[0], test_split[1]

def train(x, y, lr):
	w = np.random.rand(x.shape[1], 1)
	i = 0
	while True:
		d = np.subtract(y, np.matmul(x, w))
		j = np.matmul(np.transpose(d), d)[0, 0] / x.shape[0]
		if i > 500000:
			break;
		k = 2.0 * lr / x.shape[0]
		b = np.matmul(np.transpose(x), d)
		w_new = np.add(w, b * k)
		diff = np.subtract(w_new, w)
		# if i % 50000 == 0:
			# print(j)
			# print(np.reshape(diff, (diff.shape[0])))
		w = w_new
		i += 1
	return w


def main():
	d = datasets.load_diabetes()
	x = d.data
	y = d.target
	x_train, y_train, x_test, y_test = split_data(x, y, 0.8)
	w = train(x_train, y_train, 0.1)
	y_pred = np.matmul(x_test, w)
	# print(np.concatenate((y_test, y_pred), 1))
	

if __name__ == '__main__':
	main()
