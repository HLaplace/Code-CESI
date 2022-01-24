var_effectif = 500
var_nbr_premier_infecte = 1
var_temps_contamination = 2 # heures

# on fait l'hypothese que chaque zombie contamine une personne toutes les 2  heures
# et que chaque heure 10% des zombies sont tués

def fonc_nbre_infecte (var_population, var_debut, temps):

	var_nbre_infecte = var_debut
	tab_nombres_cas = []
	tab_temps_epidemie = []

	while var_nbre_infecte < var_population : 

		var_nbre_infecte = 2 * var_nbre_infecte - (var_nbre_infecte / 10) 
		temps = temps + var_temps_contamination 
		tab_temps_epidemie.append(temps)
		tab_nombres_cas.append(var_nbre_infecte)

	return tab_temps_epidemie, tab_nombres_cas

tab_temps = fonc_nbre_infecte(var_effectif, var_nbr_premier_infecte, var_temps_contamination)[0]
tab_contamine = fonc_nbre_infecte(var_effectif, var_nbr_premier_infecte, var_temps_contamination)[1]

####################################################################

import matplotlib.pyplot as plt

plt.title("evolution de l'epidemie en fonction du temps")
plt.plot(tab_temps, tab_contamine)
plt.grid(True)
#plt.show()
file_name = "courbe_evolution_epidemie.png"
plt.savefig(file_name)  

####################################################################
import smtplib, ssl
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email import encoders

def send_mail(file_name, mail_recever):

	# partie a modifier
	smtp_server = 'smtp.gmail.com'
	port = 465
	expediteur = "hugolapla332@gmail.com"
	password = "Secondairegmail33"

	message = MIMEMultipart('alternative')
	message['Subject'] = 'evolution tab_temps_epidemie'
	message['From'] = 'noreply@virusZ.fr'
	message['To'] = mail_recever	

	message.attach(MIMEText("Bonjour voici le suivi du virus Z sur une population de 500 personnes", 'plain'))
	
	with open(file_name, 'rb') as attachment:
		file_part = MIMEBase('application', 'octet-stream')
		file_part.set_payload(attachment.read())
		encoders.encode_base64(file_part)
		file_part.add_header(
		'Content-Disposition',
		'attachment; filename='+ str(file_name)
		)
		message.attach(file_part)

	context = ssl.create_default_context()
	with smtplib.SMTP_SSL(smtp_server, port, context=context) as server:
		server.login(expediteur, password)
		server.sendmail(message['From'], message['To'], message.as_string())
		print("send mail : ok")

####################################################################

mail = ["hugo.laplace@viacesi.fr","martin.grolhier@viacesi.fr"]
for i in (mail):
	send_mail(file_name, i)