# version adapte a l utilisation sur jupyter
import os
import numpy as np
import wavio as wav
from matplotlib import pyplot as plt
import winsound

fe = 44100
t = np.linspace(0, 1, 1 * fe)
tab_frequence = [10,100,1000,10000,15000,17000,20000,22000,35000,40000] # tableau contenant tout les frequences choisies

for i in range(0, len(tab_frequence)): # je parcours tout les frequences du tableau

	son = np.cos(np.pi*2*tab_frequence[i]*t)

	plt.plot(t[0:100],son[0:100])  # legende du graphe
	plt.grid(True) # affichage de la grille sur le graphe
	plt.xlabel('temps (s)') # legende du graphe
	plt.ylabel('amplitude (u.a.)') # legende du graphe
	plt.show() # je n affiche pas le graphe pour que tout le programme s execute plus vite

	# tout les variables pour l enregistrement
	file_name = "son_"+ str(i) # nom du dossier
	file_name_wav = file_name + ".wav" # nom du fichier sonore
	file_name_png = file_name + ".png" # nom du fichier contenant le graphe
    
	plt.savefig(file_name_png) # enregistrement du graphe
	wav.write(file_name_wav, son, fe, sampwidth=3) # enregistremeznt du fichier sonore
	winsound.PlaySound(file_name_wav,winsound.SND_ALIAS) # lecture du son   
	plt.clf() # je clean la courbe
  
	print(file_name)
