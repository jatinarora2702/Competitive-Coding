def predict(W, X):
	T = 0.5

	y = sigmoid(W * X)
	Y = floor(y - T) + 1
	
	return Y


# X -> B x d (float)
# Y -> B x 1 (int: 0 or 1)
def train(X, Y):
	W = random_init(X.shape[1], Y.shape[1])
	lr = 0.001
	T = 1e-4

	while True:
		y = sigmoid(W * X)
		loss = - sum(Y * log(y) + (1 - Y) * log(1 - y))
		if loss < T:
			break
		g = sum((Y - y) * X)
		W -= lr * g


def ml_system(X, Y, X_test):
	M = train(X, Y)
	Y_test = predict(M, X_test)

	return Y_test
