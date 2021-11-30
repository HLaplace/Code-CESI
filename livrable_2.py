# -*- coding: utf-8 -*-

import numpy as np
import wavio as wav
from matplotlib import pyplot as plt
import winsound
import os, time

fe = 44100
t = np.linspace(0, 1, 1 * fe)
tab_frequence = [10,100,1000,10000,15000,17000,20000,22000,35000,40000] # tableau contenant tout les frequences choisis

for i in range(0, len(tab_frequence)): # je parcours pour tout les frequences du tableau

	son = np.cos(np.pi*2*tab_frequence[i]*t)

	plt.plot(t[0:100],son[0:100])  # legende du graphe
	plt.grid(True) # affichage de la grille sur le graphe
	plt.xlabel('temps (s)') # legende du graphe
	plt.ylabel('amplitude (u.a.)') # legende du graphe
	#plt.show() # je n affiche pas le graphe pour que tout le programme s execute plus vite

	# tout les variables pour l enregistrement
	file_name = "son_"+ str(i) # nom du dossier
	file_name_wav = file_name + ".wav" # nom du fichier sonore
	file_name_png = file_name + ".png" # nom du fichier contenant le graphe
	os.system("mkdir " + file_name) # creation du dossier

	loc = os.getcwd() # recupperatio de l emplacement du fichier main
	plt.savefig(str(loc) + "\\"  + str(file_name) + "\\" + str(file_name_png)) # enregistrement du graphe
	wav.write(str(loc) + "\\" + str(file_name) + "\\" + str(file_name_wav), son, 44100,sampwidth=3) # enregistremeznt du fichier sonore
	print(file_name)

	winsound.PlaySound(str(loc) + "\\" + str(file_name) + "\\" + str(file_name_wav),winsound.SND_ALIAS) # lecture du son

