######################### importation des librairies et recuperation du message a chiffrer #########################
import os
import numpy as np
import matplotlib.pyplot as plt
import wavio as wav
import winsound
import random

fichier = open("test.txt", 'r') 
main_value = fichier.readlines()

def creation_fanion():
    tab = [1]
    for i in range (0,7):
        tab.append(random.randint(0,1))
    return tab

######################################## conversion du texte entree en ascci ########################################
main_ascii_values = []

for i in main_value[0]:
    main_ascii_values.append(ord(i))

print("texte en ascci : ", main_ascii_values)

######################################## conversion du texte ascci en binaire ########################################
main_bin_values = []
fanion = creation_fanion()

# je rajoute deux zero au donnees code sur 6 bits et un zero au donnees code sur 7 bits
for i in range(0,len(main_ascii_values)):
    if 63 >= main_ascii_values[i] >= 32 :
        main_bin_values.append(str("00" + bin(main_ascii_values[i])[2::])) # gestion des espaces
    else:
        main_bin_values.append(str("0" + bin(main_ascii_values[i])[2::])) # gestion des autres caracteres

# je regroupe toute les donnees dans une variable sous frome d'un nombre entier
main_bin_values_2 = []
for i in range (0, len(main_bin_values)):
    for ii in range (0, len(main_bin_values[i])):
        main_bin_values_2.append(int(main_bin_values[i][ii])) # je retransforme le tableau en nombre entier
print("texte en binaire : ", main_bin_values_2)

######################################## chiffrement du code binaire en manchester ########################################
main_manchester_values = []
for i in range (0, len(main_bin_values_2)):
    
    if main_bin_values_2[i] == 0:
        main_manchester_values.append(0)
        main_manchester_values.append(1)

    else:
        main_manchester_values.append(1)
        main_manchester_values.append(0)
        
print("texte code en manchester : " ,main_manchester_values)
######################################## calcul de la trame CRC ########################################
def xor(a, b): 
   
    result = [] 
    
    for i in range(1, len(b)): 
        if a[i] == b[i]: 
            result.append('0') 
        else: 
            result.append('1') 
   
    return ''.join(result) 
   
def mod2div(divident, divisor): 

    pick = len(divisor) 
    tmp = divident[0 : pick] 
    while pick < len(divident): 
        if tmp[0] == '1':    
            tmp = xor(divisor, tmp) + divident[pick] 
        else:          
            tmp = xor('0'*pick, tmp) + divident[pick] 
        pick = pick+1

    if tmp[0] == '1': 
        tmp = xor(divisor, tmp) 
    else: 
        tmp = xor('0'*pick, tmp) 

    return tmp 
   
def encodeData(data, key): 
   
    l_key = len(key) 
    appended_data = data + '0'*(l_key-1) 
    remainder = mod2div(appended_data, key) 
    codeword = data + remainder 
    return codeword     

STR_value = ""
for i in range(0, len(main_manchester_values)):  
    temp = str(main_manchester_values[i])  
    STR_value = STR_value + temp

trame_CRC = encodeData(STR_value,"1001") 
#print("message en CRC : " ,trame_CRC) 

# je creer ici mon message en ajoutant les deux fanion et la trame CRC
main = []
for i in range (0, len(fanion)):
    main.append(fanion[i])

for i in range (0, len(trame_CRC)):
    main.append(int(trame_CRC[i]))

for i in range (0, len(fanion)):
    main.append(fanion[i])

print("message principal : ", main)
######################################## application de la porteuse ########################################

Fe = 44100                                    
baud = 300                     
Nbits = len(main)               
Ns = Fe/baud                   
N = Ns*Nbits      

# modulation de la valeur 
main_modulation_values = np.repeat(main,Ns)  

#print("valeur module : " ,main_modulation_values)     
                           
#chiffrement de la valeur 
t = np.linspace(0, N/Fe, int(N))                    
Ap = 1                                          
Fp= 22000 # mettre a 2000 pour que le son soit audible                                            
Porteuse = Ap*np.sin(2*np.pi*Fp*t)                  

main_ASK_values = Porteuse * main_modulation_values             

plt.figure (figsize = (10,6))
plt.plot(t,main_ASK_values,'r')
plt.title('ASK')
plt.xlabel('temps (s)')
plt.ylabel('Amplitude')
plt.grid()
#plt.show()

print("valeur chiffre a envoyer: ",main_ASK_values)

# je joue le son 
wav.write("file_temp.wav", main_ASK_values,Fe,sampwidth=3) 
winsound.PlaySound("file_temp.wav",winsound.SND_ALIAS) 
os.remove("file_temp.wav")

########################################################################################################################
######################################## decodage du message  ##########################################################
########################################################################################################################
########################################## reconstruction du message original ##########################################
print("##########################################")
print("decodage du message recu")
print("##########################################")
main_value_decode = []                                                  

for i in range(0,int(N),int(Ns)):
        if (np.trapz(main_ASK_values[i:i+int(Ns)])) != 0 :
            main_value_decode.append(1)
        else :
            main_value_decode.append(0)
                                           
print("valeur code en manchester", main_value_decode)   

# je retrouve mes deux fanions et le compare
fanion_debut = []
for i in range(0,8):
    fanion_debut.append(int(main_value_decode[i]))
#print("fanion_debut: ", fanion_debut)

fanion_fin = []
for i in range(len(main_value_decode)-8,len(main_value_decode)):
    fanion_fin.append(int(main_value_decode[i]))
 #print("fanion_fin : ", fanion_fin)

if fanion_debut ==  fanion_fin:
    print("Le message est complet")

else:
    print("erreur message incomplet")
    quit() # si le message est incomplet (trame differente) je force l'arret du programme

######################################## decodage de manchester vers binaire ########################################

# je creer un message sans les fanions
main_encode_value = []
for i in range(8,len(main_value_decode)-8):
    main_encode_value.append(main_value_decode[i])

def decodeData(value, key):                
    
    l_cle = len(key)
    data_recu = ''
    for i in range (0,len(value)):
        if value[i] == 1 :
            data_recu = data_recu + str("1")
        if value[i] == 0 :
            data_recu = data_recu + str("0")

    append_data = data_recu + '0'*(l_cle-1)
    remainder = mod2div(append_data, key)
 
    return remainder

key = "1001"
#print("valeur sans fanion : ",main_encode_value)
data_decode = decodeData(main_encode_value, key) 

data_reçu = ""

if data_decode == "000" : 

    print("donnees recues sans erreur") 

else: 

    print("Error in data") 
    quit()
  
main_value_decode_binaire =  []  
for i in range (0, len(main_encode_value) - 1, 2):
    
    if main_encode_value[i] == 0 and main_encode_value[i + 1] == 1:
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

for i in range(0, len(main_value_decode_binaire_string)-1, 8):
        temp_data = int(main_value_decode_binaire_string[i+1:i+8])
        decimal_data = BinaryToDecimal(temp_data)
        data_reçu = data_reçu + chr(decimal_data)

print("Le message reçu est :", data_reçu) 
