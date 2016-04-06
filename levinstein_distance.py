import numpy as np

def levenstein_distance(x: str, y: str) -> int:
	n = len(x)
	m = len(y)
	E = np.ndarray((m + 1, n + 1))
	for i in range(0, m + 1):
		E[i, 0] = i
	for j in range(0, n + 1):
		E[0, j] = j
	for i in range(1, m + 1):
		for j in range(1, n + 1):
			E[i, j] = min(E[i-1, j] + 1, E[i, j-1] + 1, E[i-1, j-1] + (x[j-1] != y[i-1]))
	return E[m, n]

print(levenstein_distance("polynomial", "exponential"))
