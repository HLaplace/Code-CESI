///////////////////////////////////////////////////// Declaration des variables /////////////////////////////////////////////////////
int code[4] = {1,2,3,4}; // code ouvrant le coffre 
int tableau[8] = {2,3,4,5,8,9,10,11}; // tableau contenant les pins de tout les boutons puis de toute les leds
int i = 0; // variable de suivi principale
int a = 0; // variable de suivi temporaire dans la fonction erreur code
int chiffre_tenter = 0; // variable principale contenant le chiffre tenté par l'utilisateur
int test = 0; // variable qui prend la valeur du pin de la led associé au bouton activé
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() 
{ 
  Serial.begin(9600);
   
  pinMode(tableau[0], INPUT_PULLUP); // configuration de tout les boutons : broche disponible dans le tableau (4 première valeurs)
  pinMode(tableau[1], INPUT_PULLUP);
  pinMode(tableau[2], INPUT_PULLUP);
  pinMode(tableau[3], INPUT_PULLUP); 
  
  pinMode(tableau[4], OUTPUT);// configuration de toutes les leds : broche disponible dans le tableau (4 dernières valeurs)
  pinMode(tableau[5], OUTPUT);
  pinMode(tableau[6], OUTPUT);
  pinMode(tableau[7], OUTPUT);
  
  pinMode(12, OUTPUT); // led verte
  pinMode(13, OUTPUT);  // moteur
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop(){
  
  while (i != 4){ // quand i = 4, c'est que les 4 chiffres de la combinaisons sont validés
    Serial.println("début du WHILE");
    delay(300); // tempo pour eviter que un appui sois pris comme plusieur entrées
 
    activation_bouton(tableau[0]);
    activation_bouton(tableau[1]);
    activation_bouton(tableau[2]);
    activation_bouton(tableau[3]);

    Serial.println("chiffre_tenter : " + String(chiffre_tenter)); // chiffre ressorti par l'appui d'un bouton
    
    if (chiffre_tenter != 0){// si il est égal à 0 c'est qu'aucun chiffre n'a été tenté
      
      if (chiffre_tenter == code[i]){
        Serial.println("Chiffre n°" + String(i + 1) + " de la combinaison validé");
        test = i + 4; // car dans le tableau la broche de la led associé au bouton 
        // est 4 entrée plus loin que la broche du bouton
        Serial.println("allumage de la led sur le pin " + String(tableau[test]));
        digitalWrite(tableau[test], HIGH);
        
        i = i +1 ; // car un des chiffres de la combinaison est validé
        chiffre_tenter = 0;
        }
        
      else{ // si le chiffre entré par l'utilisateur n'est pas le bon
        Serial.println("Chiffre n°" + String(i + 1) + " de la combinaison est FAUX");
        erreur_code();
        }
     } 
} 
code_valide(); // code validé lancement de la fonction de fin
}
///////////////////////////////////////////////////// Definition des fonctions ///////////////////////////////////////////////////// 

// fonction qui renvoie le chiffre entré par l'utilisateur en fonction du bouton appuyé
void activation_bouton(int btn){
  if (digitalRead(btn) == LOW) {
    chiffre_tenter = btn - 1; 
    }
}

// fonction activant le clignotement des leds quand le chiffre entré est faux
void erreur_code(){ 
  Serial.println("ERREUR, remise a 0 des variabales");
  i = 0;
  chiffre_tenter = 0;
  while (a !=3){ // car les leds clignotents 3 fois
    digitalWrite(tableau[4], HIGH);
    digitalWrite(tableau[5], HIGH);
    digitalWrite(tableau[6], HIGH);
    digitalWrite(tableau[7], HIGH);
    delay(500);
    digitalWrite(tableau[4], LOW);
    digitalWrite(tableau[5], LOW);
    digitalWrite(tableau[6], LOW);
    digitalWrite(tableau[7], LOW);
    delay(500);
    a = a + 1;
    }
  }
  
// fonction activé lorsque le code est validé elle allume la led est fait tourner le moteur
 void code_valide(){
  digitalWrite(12, HIGH); // led verte allumé
  digitalWrite(13, HIGH);  // allumage du moteur 
  delay(1000);
  digitalWrite(13, LOW);
  Serial.println("coffre ouvert ");
  delay(100);
  exit(1);
  }
