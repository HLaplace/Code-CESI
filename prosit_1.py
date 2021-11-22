# definition d une classe mer 
class mer:

    def __init__(self,profondeur,temperature,salinite):

    # intialisation des valeurs donnees
        self.temperature = temperature
        self.salinite = salinite
        self.profondeur = profondeur

    # calcul des celerites dans l eau et dans l air 
       	self.celerite_eau = 1449.2 + 4.6 * self.temperature - 0.55 * self.temperature ** 2 + 0.00029 * self.temperature ** 3 + (1.34 - 0.01 * self.temperature) * (self.salinite - 35) + 0.016 * self.profondeur
        self.celerite_air = 330 + (0.6 * self.temperature)

    # calcul du resultat final
    def resultat(self):
        return (600 / self.celerite_air)  - (600 / self.celerite_eau)

# donnees recuperes dans le tableau du prosit 
# initialisation des classes
baltique = mer(55, 9, 10)
mediterranee = mer(1429, 20, 38.5)
mer_du_nord = mer(94, 12, 33.5)
mer_de_ross = mer(500, 0, 33) # profondeur internet car flou dans le tableau
mer_rouge = mer(491, 30, 40)
atlantique = mer(3926, 14, 36.5)
marianes = mer(11000, 30, 34.5)

# print du resultat pour la mer baltique
print(baltique.resultat())