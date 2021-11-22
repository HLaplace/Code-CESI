# Que se passe-t-il pour les variables x et y ?

# elle s'aditione, se multiplie et se divise

# A quoi correspondent ils ? Que remarquez-vous sur les calculs de la figure ci-dessous ?

# in : entier
# str : chaine de caractere 
# float : nombre decimal

# x = flaot(x)
# x = int(x)

# Qu’est-ce qu’une liste ? Comment ajouter des éléments à une liste existante ? Est-il possible de 
# créer une liste avec des éléments de types différents ?

# Une liste eest u tableau pouvant contenir des variables dez tout types différents.

# Réalisez un programme contenant 3 variables x, y et z valant respectivement 10, 20 et x/y. Après 
# exécution, ce programme devra afficher le type de chacune des variables, la valeur de z ainsi qu’un 
# message écrit de votre choix.

x = 10
y = 20
z = x / y

print(x,y,z)
print(type(x))
print(type(y))
print(type(z))
print("hello word")

# Créer un nouveau programme contenant une liste de 10 éléments (de votre choix) et permettant 
# l’affichage de chaque élément en un minimum d’instructions. Quel type d’instruction avez-vous 
# utilisé ?

liste = ["a", "b", 3 , 4.5, "hugo", 8, "c", 5 , 5.7, "prout"]
for i in range(0 , len(liste)):
	print(liste[i])

# A partir de la liste x=[1,2,3,4,5,6,7,8,9,10], créer un programme permettant d’afficher un texte 
# lorsque x[i] est inférieur à 5, i égal à 5 et i supérieur à 5

x = [1,2,3,4,5,6,7,8,9,10]

for i in range(0 , len(x)):
	if x[i] == 5:
		print("i = 5")

	elif x[i] > 5:
		print("i > 5")

	else :
		print("i < 5")

# En partant de 0, créer un programme affichant « faux » tant que x est inférieur à 10.

i = 0
while i < 10:
	print("faux") 
	i = i + 1

# Nous utiliserons dans ce projet, notamment les modules numpy et matplotlib. 
# Que permettent ils ? Comment faire pour les utiliser ? Ecrire un programme utilisant les modules.

import numpy , matplotlib

# cela permet d'utiliser des fonctions non présente initialement dans python comme des calculs complexes ou des nuages de point

