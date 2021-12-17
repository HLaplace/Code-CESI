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
        pick += 1

    if tmp[0] == '1': 
        tmp = xor(divisor, tmp) 
    else: 
        tmp = xor('0'*pick, tmp) 
    checkword = tmp 
    return checkword 
   
def encodeData(data, key): 
   
    l_key = len(key) 
    appended_data = str(data) + '0'*(l_key-1) 
    remainder = mod2div(appended_data, key) 
    codeword = str(data) + remainder 
    return codeword     
     
def decodeData(data, key): 

    l_key = len(key) 
    appended_data = str(data) + '0'*(l_key-1) 
    remainder = mod2div(appended_data, key) 
    return remainder 
  
#####################################################################
data_to_converte = input("Enter data you want to convert ") 

main_ascii_values = []

for i in data_to_converte:
    main_ascii_values.append(ord(i))

print("texte en ascci : ", main_ascii_values)

main_bin_values = []

for i in range(0,len(main_ascii_values)):
    if 63 >= main_ascii_values[i] >= 32 :
        main_bin_values.append(str("00" + bin(main_ascii_values[i])[2::])) # gestion des espaces
    else:
        main_bin_values.append(str("0" + bin(main_ascii_values[i])[2::])) # gestion des autres caracteres
print(main_bin_values)

main_bin_values_2 = []
for i in range (0, len(main_bin_values[0])):
    for ii in range (0, len(main_bin_values[i])-1):
        main_bin_values_2.append(int(main_bin_values[i][ii])) # je retransforme le tableau en nombre entier
        print(main_bin_values_2)
print("texte en binaire : ", main_bin_values_2)

#####################################################################

key = "1001"
encode_value = encodeData(main_bin_values_2,key) 
print(encode_value) 

data_decode = decodeData(encode_value, key) 
print("Remainder after decoding is->"+data_decode) 

temp = "0" * (len(key) - 1)  
if data_decode == temp: 
    print("donne recues sans erreur : " ,encode_value) 
else: 
    print("Error in data") 

