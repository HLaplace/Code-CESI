int code = 1234;
String codeR = String(code);
boolean erreur = false;

const int btn1 = 2;
const int btn2 = 3;
const int btn3 = 4;
const int btn4 = 5;
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;
const int ledv = 13;
boolean imple = false;
String var1;
String var2;
String var3;
String var4;
String vare1;
String vare2;
String vare3;
String vare4;
String codeT;

 
void setup(){
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(btn4, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(ledv, OUTPUT);
  Serial.begin(9600);
  var1 = codeR[0];
  var2 = codeR[1];
  var3 = codeR[2];
  var4 = codeR[3];
  Serial.println(codeR);
 

}

void loop(){
  while (codeT.length()<1){//test 1er chiffre
  btnApp();
  }// fin imple du 1er chiffre
  if (codeT.length() == 1 && erreur == false){
    vare1 = codeT[0];
    if (var1 == vare1){
      digitalWrite(led1, HIGH);
    }
    else {
      error();
    }
  }
  while (codeT.length()==1){//test 2eme chiffre
  btnApp();
  }// fin imple du 2eme chiffre
  if (codeT.length() == 2 && erreur == false){
    vare2 = codeT[1];
    if (var2 == vare2){
      digitalWrite(led2, HIGH);
    }
    else {
      error();
    }
  }  
  while (codeT.length()==2){//test 3eme chiffre
  btnApp();
  }// fin imple du 3eme chiffre
  if (codeT.length() == 3 && erreur == false){
    vare3 = codeT[2];
    Serial.println(var3);
    if (var3 == vare3){
      digitalWrite(led3, HIGH);
    }
    else {
      error();
    }
  }  
  while (codeT.length()==3){//test 4eme chiffre
  btnApp();
  }// fin imple du 4eme chiffre
  if (codeT.length() == 4 && erreur == false){
    vare4 = codeT[3];
    if (var4 == vare4){
      digitalWrite(led4, HIGH);
    }
    else {
      error();
    }
  }
}

void error(){
  erreur = true;
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(300);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(300);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(300);

}

void btnApp(){
  if (digitalRead(btn1)==LOW){
  delay(200);
  codeT+="1";
  }
  else if (digitalRead(btn2)==LOW){
  delay(200);
  codeT+="2";
  }
  else if (digitalRead(btn3)==LOW){
  delay(200);
  codeT+="3";
  }
  else if (digitalRead(btn4)==LOW){
  delay(200);
  codeT+="4";
  }
}
