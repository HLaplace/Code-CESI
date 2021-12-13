main_value = input("texte à envoyer : ") #coucou #99 111 117 99 111 117 

main_ascii_values = []
for i in main_value:
    main_ascii_values.append(ord(i))

print("texte en ascci : ", main_ascii_values)

main_bin_values = []
for i in range(0,len(main_ascii_values)):
    main_bin_values.append(bin(main_ascii_values[i])[2::])
main_bin_values_2 = []
for i in range (0, len(main_bin_values)):
    main_bin_values_2.append(0)
    for ii in range (0, len(main_bin_values[i])):
        main_bin_values_2.append(int(main_bin_values[i][ii]))

print("texte en binaire : ", main_bin_values_2)

main_manchester_values = []
for i in range (0, len(main_bin_values_2)):
    
    if main_bin_values_2[i] == 0:
        main_manchester_values.append(0)
        main_manchester_values.append(1)

    else:
        main_manchester_values.append(1)
        main_manchester_values.append(0)
        
print("texte code en manchester : " ,main_manchester_values)
