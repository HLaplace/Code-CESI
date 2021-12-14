######################### importation des librairies et recuperation du message a chiffrer #########################
import os
import numpy as np
import matplotlib.pyplot as plt
import wavio as wav

fichier = open("test.txt", 'r') 
main_value = fichier.readlines()

######################################## conversion du texte entree en ascci ########################################
main_ascii_values = []

for i in main_value[0]:
    main_ascii_values.append(ord(i))

#print("texte en ascci : ", main_ascii_values)

######################################## conversion du texte ascci en binaire ########################################
main_bin_values = []
for i in range(0,len(main_ascii_values)):
    if 63 >= main_ascii_values[i] >= 32 :
        main_bin_values.append(str("00" + bin(main_ascii_values[i])[2::]))
    else:
        main_bin_values.append(str("0" + bin(main_ascii_values[i])[2::]))

main_bin_values_2 = []
for i in range (0, len(main_bin_values)):
    for ii in range (0, len(main_bin_values[i])):
        main_bin_values_2.append(int(main_bin_values[i][ii]))

#print("texte en binaire : ", main_bin_values_2)

######################################## chiffrement du code binaire en manchester ########################################
main_manchester_values = []
for i in range (0, len(main_bin_values_2)):
    
    if main_bin_values_2[i] == 0:
        main_manchester_values.append(0)
        main_manchester_values.append(1)

    else:
        main_manchester_values.append(1)
        main_manchester_values.append(0)
        
#print("texte code en manchester : " ,main_manchester_values)

######################################## application de la porteuse ########################################

Fe = 44100                                    
baud = 300                     
Nbits = len(main_manchester_values)               
Ns = Fe/baud                   
N = Ns*Nbits      

######################################## modulation de la valeur ########################################
main_modulation_values = np.repeat(main_manchester_values,Ns)  

#print("valeur module : " ,main_modulation_values)     
                           
######################################## chiffrement de la valeur ########################################
t = np.linspace(0, N/Fe, int(N))                    
Ap = 1                                          
Fp= 2000                                             
Porteuse = Ap*np.sin(2*np.pi*Fp*t)                  

main_ASK_values = Porteuse*main_modulation_values             

plt.figure (figsize = (10,6))
plt.plot(t,main_ASK_values,'r')
plt.title('ASK')
plt.xlabel('temps (s)')
plt.ylabel('Amplitude')
plt.grid()
#plt.show()

#print("valeur chiffre en ask : ",main_ASK_values)

######################################## je joue le son ########################################

#wav.write("file_temp.wav", main_ASK_values,Fe,sampwidth=3) 
#winsound.PlaySound("file_temp.wav",winsound.SND_ALIAS) 
#os.remove("file_temp.wav")

######################################## decodage du message  ########################################

######################################## reconstruction du message original ########################################
main_value_decode = []                                                  

for i in range(0,int(N),int(Ns)):
        if (np.trapz(main_ASK_values[i:i+int(Ns)])) != 0 :
            main_value_decode.append(1)
        else :
            main_value_decode.append(0)
                                           
#print("valeur code en manchester",main_value_decode)     

######################################## decodage de manchester vers binaire ########################################
main_value_decode_binaire =  []  

for i in range (0, len(main_value_decode) - 1, 2):
    
    if main_value_decode[i] == 0 and main_value_decode[i + 1] == 1:
        main_value_decode_binaire.append(0)

    else:
        main_value_decode_binaire.append(1)
        

main_value_decode_binaire_string = ""
for i in range (0, len(main_value_decode_binaire)):

    main_value_decode_binaire_string = main_value_decode_binaire_string + str(main_value_decode_binaire[i])

#print("message en binaire pur : ", main_value_decode_binaire_string)

######################################## decodage de binaire vers ascii ########################################

def BinaryToDecimal(binary):  
    binary1 = binary 
    decimal, i, n = 0, 0, 0 #initialisation des variables
    while(binary != 0): 
        dec = binary % 10
        decimal = decimal + dec * pow(2, i) 
        binary = binary//10
        i += 1
    return (decimal)

data_reçu =' '

for i in range(0, len(main_value_decode_binaire_string), 8): 
    temp_data = int(main_value_decode_binaire_string[i+1:i+8])

    decimal_data = BinaryToDecimal(temp_data)
    data_reçu = data_reçu + chr(decimal_data) 

print("Le message reçu est :", data_reçu) 