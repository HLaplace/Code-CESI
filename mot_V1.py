import math, numpy as np, wave
import time,os
import pyaudio, wave, sys
##############################################################################
def sound_creator(freq):
    freqech = 44100
    duree = 1.
    omega = 2 * math.pi * freq
    son = np.arange(0., duree, 1./freqech, np.float64)
    son = np.sin(omega * son)
    son *= 32768.
    son = son.astype(np.int16)
    wavfile = wave.open('temp.wav','w')
    wavfile.setparams((1, 2, freqech , len(son), 'NONE', 'not compressed'))
    wavfile.writeframes(son.tostring())
    wavfile.close()
    print("son creer avec une frequence de " + str(freq) + " hz.")
##############################################################################
def sound_play(frequence):
    
   print ("Lecture en cours..")
   chunk = 1024
   sound_creator(frequence)
   wf = wave.open("temp.wav",'r')
   p = pyaudio.PyAudio()
   data = wf.readframes(chunk)
   stream = p.open(format =
        p.get_format_from_width(wf.getsampwidth()),
        channels = wf.getnchannels(),
        rate = wf.getframerate(),
        output = True)
   stream.write(data)
   data = wf.readframes(chunk)
   time.sleep(1)
   stream.close()
   p.terminate()
   print ("Terminé")

##############################################################################
mot_user = input("mot : ")
mot_user = mot_user.lower()

tab_lettre = [' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
tab_freq = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26]

for i in range (0, len(mot_user)):
    var_temp = mot_user[i]
    for j in range(0, len(tab_lettre)):
        if var_temp == tab_lettre[j]:
            sound_play(tab_freq[j] * 20000)
        
        