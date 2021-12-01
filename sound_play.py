import numpy as np
import wavio as wav
import winsound,os

def sound_play(frequence):
	fe = 44100
	t = np.linspace(0, 1, 1 * fe)
	son = np.cos(np.pi*2*frequence*t)	
	wav.write("file_temp.wav", son, fe,sampwidth=3) # enregistrement du fichier sonore
	winsound.PlaySound("file_temp.wav",winsound.SND_ALIAS) # lecture du son
	os.remove("file_temp.wav")

sound_play(int(input("frequence : ")))
