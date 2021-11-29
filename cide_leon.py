import math, numpy as np, wave
def sound_creator():
    freq = 1000.
    freqech = 44100
    duree = 5.
    omega = 2 * math.pi * freq
    son = np.arange(0., duree, 1./freqech, np.float64)
    son = np.sin(omega * son)
    son *= 32768.
    son = son.astype(np.int16)
 
    wavfile = wave.open('AutreAmplitude.wav','w')
    wavfile.setparams((1, 2, freqech , len(son), 'NONE', 'not compressed'))
    wavfile.writeframes(son.tostring())
    wavfile.close()
#   sound_creator()

import pyaudio, wave, sys
def sound_play():
    print ("Lecture en cours..")
    chunk = 1024
 
    wf = wave.open("AutreAmplitude.wav",'r')
 
    p = pyaudio.PyAudio()
 
    # open stream
    stream = p.open(format =
                    p.get_format_from_width(wf.getsampwidth()),
                    channels = wf.getnchannels(),
                    rate = wf.getframerate(),
                    output = True)
 
    # read data
    data = wf.readframes(chunk)
 
    # play stream
    while data != '':
        stream.write(data)
        data = wf.readframes(chunk)
 
    stream.close()
    p.terminate()
sound_play()

