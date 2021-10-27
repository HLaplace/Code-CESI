int code[4] = {1,2,3,4};
int tableau[8] = {2,3,4,5,8,11,12,9};
int i = 0;
int a = 0;
int chiffre_tenter = 0;
int test = 0;

void setup() 
{ 
  Serial.begin(9600);
  pinMode(tableau[0], INPUT_PULLUP);
  pinMode(tableau[1], INPUT_PULLUP);
  pinMode(tableau[2], INPUT_PULLUP);
  pinMode(tableau[3], INPUT_PULLUP); 

}

void loop(){
  Serial.println("LOOP");
  while (i != 4){
    Serial.println("WHILE");
    delay(500);
    activation_bouton(tableau[0]);
    activation_bouton(tableau[1]);
    activation_bouton(tableau[2]);
    activation_bouton(tableau[3]);

    Serial.println("chiffre_tenter : " + String(chiffre_tenter));
    if (chiffre_tenter != 0){
      Serial.println("Dans le 1er if");
      if (chiffre_tenter == code[i]){
        Serial.println("Chiffre " + String(i) + " de la combinaison est validé");
        test = chiffre_tenter + 3;
        Serial.println("allumage de " + String(tableau[test]));
        digitalWrite(tableau[test], HIGH);
        i = i +1 ;
        chiffre_tenter = 0;
        }
        
      else{
        Serial.println("Chiffre " + String(i) + " de la combinaison est FAUX");
        erreur_code();
        }
     } 
} 

Serial.println("fini");
//code_valide();
}
///////////////////////////////////////////////////// Definition des fonctions ///////////////////////////////////////////////////// 

void activation_bouton(int btn){
  if (digitalRead(btn) == LOW) {
    chiffre_tenter = btn - 1; // temp = valeur a tester
    Serial.println("btn : " + String(chiffre_tenter));// chiffre saisi
    }
}
void erreur_code(){ 
  Serial.println("ERREUR, remise a 0 des variabales");
  i = 0;
  chiffre_tenter = 0;
  while (a !=3){
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
  
 void code_valide(){
  Serial.println("coffre ouvert ");
  Serial.println("led verte allume");
  Serial.println("moteur active");
  }
