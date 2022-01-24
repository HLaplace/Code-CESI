import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d 

f = lambda x, y : x * np.exp(-x**2 + y**2) + x * 4 * np.exp(-x**2 + y**2)
tab_X = []
tab_Y = []
tab_Z = []

i = -2
while -2 <= i <= 2:
	j = - 2
	while -2 <= j < 2.25:
		
		tab_X.append(i)
		tab_Y.append(j)
		tab_Z.append(f(i,j))
		print(i, j, f(i,j))

		j = j + 0.25
	i = i + 0.25

fig = plt.figure()
ax = fig.gca(projection='3d')  # Affichage en 3D
ax.scatter(tab_X, tab_Y, tab_Z)  # Tracé des points 3D
plt.title("Cartographie des donnees")
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('f(x,y)')
plt.tight_layout()
plt.show()


