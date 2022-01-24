import numpy as np

f = lambda x, y : x * np.exp(-(x**2 + y**2)) + x * 4 * np.exp(-(x**2 + y**2))
i = -2
while -2 <= i <= 2:
	j = - 2
	while -2 <= j < 2:
		j = j + 0.25
		print(f(i,j))

	i = i + 0.25