var_effectif = 500
var_nbr_premier_infecte = 1
var_temps_contamination = 2 # heures

# on fait l'hypothese que chaque zombie contamine une personne toutes les 2  heures

def fonc_nbre_infecte (var_population, var_debut, temps):

	var_nbre_infecte = var_debut
	tab_nombres_cas = []
	tab_temps_epidemie = []
	while var_nbre_infecte < var_population : 

		var_nbre_infecte = 2 * var_nbre_infecte - (var_nbre_infecte / 10) 
		temps = temps + var_temps_contamination
		#print("nombre infecte = ", var_nbre_infecte)
		#print("temps depuis le debut de l'épidimie = ", temps)
		tab_temps_epidemie.append(temps)
		tab_nombres_cas.append(var_nbre_infecte)

	return tab_temps_epidemie, tab_nombres_cas

tab_temps = fonc_nbre_infecte(var_effectif, var_nbr_premier_infecte, var_temps_contamination)[0]
tab_contamine = fonc_nbre_infecte(var_effectif, var_nbr_premier_infecte, var_temps_contamination)[1]

import matplotlib.pyplot as plt

plt.title("evolution de l'epidemie en fonction du temps")
plt.plot(tab_temps, tab_contamine)
plt.grid(True)
plt.show()
plt.savefig("courbe_evolution_epidemie")  
