///////////////////////////////////////////////////// Declaration des variables /////////////////////////////////////////////////////
String fleur = "Muguet";
int code[4] = {4,2,1,2}; // code ouvrant le coffre 
int tableau[8] = {2,3,4,5,8,9,10,11}; // tableau contenant les pins de tout les boutons puis de toute les leds
int i = 0; // variable de suivi principale
int chiffre_tenter = 0; // variable principale contenant le chiffre tenté par l'utilisateur

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
  pinMode(13, OUTPUT); // moteur
  pinMode(6, INPUT_PULLUP); // Scan Rétinien
  pinMode(7, INPUT_PULLUP); // Scan Digital
  
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop(){

verification_code_debut();

Serial.println("Bonjour, veuillez suivre les indications en repondant aux questions, afin d'excuter une verification");
int Niveausecurite=0;
Serial.println("Quel est votre niveau de securite?");
 while(Niveausecurite==0){
    Niveausecurite=Serial.parseInt();
  } 
  Serial.println(Niveausecurite);
int(Niveausecurite<5||Niveausecurite>1);
switch (Niveausecurite){
   case 1:
        //Questions();
        ScanRetinien();
        digitalWrite(12, HIGH); // led verte allumé
        digitalWrite(13, HIGH);  // allumage du moteur 
        delay(1000);
        digitalWrite(13, LOW);
        Serial.println("coffre ouvert ");
        delay(300);
        exit(1);
        //break;
  
    case 2:
        Questions();
        ScanDigital();
        digitalWrite(12, HIGH); // led verte allumé
        digitalWrite(13, HIGH);  // allumage du moteur 
        delay(1000);
        digitalWrite(13, LOW);
        Serial.println("coffre ouvert ");
        delay(300);
        exit(1);
        //break;
  
    case 3:
        Code();
        MA5();
        digitalWrite(12, HIGH); // led verte allumé
        digitalWrite(13, HIGH);  // allumage du moteur 
        delay(1000);
        digitalWrite(13, LOW);
        Serial.println("coffre ouvert ");
        delay(300);
        exit(1);
        //break;
  
    case 4:
        Code();
        ScanRetinien();
        ScanDigital();
        digitalWrite(12, HIGH); // led verte allumé
        digitalWrite(13, HIGH);  // allumage du moteur 
        delay(1000);
        digitalWrite(13, LOW);
        Serial.println("coffre ouvert ");
        delay(300);
        exit(1);
        //break;
  
    case 5:
        Questions();
        Code();
        ScanRetinien();
        MA5();
        digitalWrite(12, HIGH); // led verte allumé
        digitalWrite(13, HIGH);  // allumage du moteur 
        delay(1000);
        digitalWrite(13, LOW);
        Serial.println("coffre ouvert ");
        delay(300);
        exit(1);
        //break;
   
  default:
  Serial.println("Niveau de securite non valide");
    break;
  }
   
}
//////////verification du code///////////////////////////////////////////////////////////////
void verification_code_debut(){  
  while (i != 4){ // quand i = 4, c'est que les 4 chiffres de la combinaisons sont validés
    //Serial.println("début du WHILE");
    delay(300); // tempo pour eviter que un appui sois pris comme plusieur entrées
 
    activation_bouton(tableau[0]);
    activation_bouton(tableau[1]);
    activation_bouton(tableau[2]);
    activation_bouton(tableau[3]);

    Serial.println("chiffre_tenter : " + String(chiffre_tenter)); // chiffre ressorti par l'appui d'un bouton
    
    if (chiffre_tenter != 0){// si il est égal à 0 c'est qu'aucun chiffre n'a été tenté
      
      if (chiffre_tenter == code[i]){
        Serial.println("Chiffre n°" + String(i + 1) + " de la combinaison validé");
        Serial.println("allumage de la led sur le pin " + String(tableau[i+4]));
        digitalWrite(tableau[i+4], HIGH);
        
        i = i +1 ; // car un des chiffres de la combinaison est validé
        chiffre_tenter = 0;
        }
        
      else{ // si le chiffre entré par l'utilisateur n'est pas le bon
        Serial.println("Chiffre n°" + String(i + 1) + " de la combinaison est FAUX");
        erreur_code();
        }
     } 
} 
}

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
  int a=0;//pour que la fonction  puisse fonctionner plusieurs fois
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
////////////MA1//////////////////////////////////////////////////    
bool Questions(){
  bool reponse;
  reponse=false;
  int tabNom[16]={9242, 4603, 16356, 11924, 6125, 3520, 12291, 935, 15138, 3551, 8223, 1743, 8070, 10307, 7582, 13709};
  int Agent;
  int x;
  boolean etat1=0, etat2=0, etat3=0, etat4=0;
                  
  Serial.println("Nom? ROSS:0 WESTERN:1 ADAMS:2 LOGAN:3 TANNER:4 BOURNE:5 PEARCE:6 KING:7 BOSS:8 VOLKOFF:9 TANAKA:10 SACKEVILLE:11 FOX:12 KIM:13 WHITE:14 ROMANOVA:15");
  while(Serial.available()!= 0 and etat1==0){
    Serial.parseInt();
  }
  while(Serial.available()<=0){}
  x=Serial.parseInt();
  etat1 = 1;
  Serial.println(x);
  Agent=x*1000;
  x=0;
    
  Serial.println("Prenom? Big:0 Alexei:1 Gray:2 Tigre:3 Gabe:4 Bill:5 William:6 Michael:7 Betty:8 Victor:9 Jason:10 Ames:11 Tara:12 Tatiana:13 Lauren:14 Harry:15");
  while(Serial.available() and etat1==1 and etat2 ==0){
    Serial.parseInt();
  }
  while(Serial.available()<=0){}
  x=Serial.parseInt();
  etat2 = 1;
  Serial.println(x);
  Agent=Agent+x*100;
  x=0;
    
  Serial.println("Ville de naissance? Pekin:0 Agen:1 Toulouse:2 Sydney:3 Bruges:4 Stocholm:5 Bordeaux:6 New-York:7 Moscou:8 Miami:9 Londres:10 Paris:11 Lyon:12 Villeneuve-d'ascq:13 LasVegas:14 Rio:15");
  while(Serial.available() and etat1==1 and etat2==1 and etat3==0){
    Serial.parseInt();
  }
  while(Serial.available()<=0){}
  x=Serial.parseInt();
  etat3 = 1;
  Serial.println(x);
  Agent=Agent+x*10;
  x=0;
                  
  Serial.println("Taille? 1m70:0 1m90:1 2m02:2 1m66:3 1m60:4 1m67:5 1m75:6 1m62:7 1m85:8 1m73:9 1m78:10 1m72:11 1m99:12 1m80:13 1m50:14 2m:15");
  while(Serial.available() and etat1==1 and etat2==1 and etat3==1 and etat4==0){
    Serial.parseInt();
  }
  while(Serial.available()<=0){}
  x=Serial.parseInt();
  etat4 = 1;
  Serial.println(x);
  Agent=Agent+x;
  int compteur;   
                  
  compteur=0;
  for (compteur=0; compteur<=15; compteur++){
    if (Agent==tabNom[compteur]){
      reponse=true;
    }
  }
  Serial.println (reponse);
                  
  return reponse;                
}  
/////////////MA2//////////////////////////////////////////////////    

int Code() {
  
  int e, M, C;
  int Mp= 0;
  boolean etat1=0;
  boolean etat2=0;
  
  Serial.println("Identifiez-vous");
  randomSeed(analogRead(0));//permet de changer de variable aléatoire
  String x="";
  while(x==""){
    x=Serial.readString();//recupere une chaine de caractere
  }
  M=random(2881);//nombre aléatoire
  e=CleAgent(x);
  C= Modexp(M, e, 2881);
  Serial.println("Message a dechiffrer:");
  Serial.println(C);
  Serial.println("Entrer le code dechiffrer");
  while(Mp==0){
    Mp= Serial.parseInt();//recupere un entier dans la console
  }
  if(M==Mp){
    Serial.println("true");
    Serial.println("cryptage code valide");
  }
  else{
    Serial.println("false");
    exit(1);
  }
}

int Modexp(int a, int e, int n) {
  long r;
  if (e < 0) {
    Serial.println("Cas non traite");
    exit(1);
  }
  if (a == 0 || n == 1) {
    r = 0;
  }
  else {
    r = 1;
    while (e > 0) {
      r = r * (a % n) % n;
      e = e - 1;
    }
  }
  return r;
}

int CleAgent(String x){//recupere la cle publique de l'agent
  
  int ClePublicAgent[16] = {601,619,631,641,647,653,661,673,691,701,733,739,751,797,809,811};
  String NomAgent = "ABCDEFHIJKLMNOPQ";
  int i = 0;
  int cle = 0;
  
  for(i=0; i<(NomAgent.length());i++)
  {
    if(String(NomAgent[i])== x)//lorsque ma lettre coincide, je recupere la position
    {
      cle= ClePublicAgent[i];//on l'enregistre en utilisant la position pour recuperer la cle
    }
  }
  return cle;
}
/////////////////MA3/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ScanRetinien(){
  Serial.println("le scan retinien va commencer, veuillez appuyez sur le bouton 2 en partant du haut");
   while (digitalRead(6) == HIGH ){
    delay(500);
    }
  Serial.println("doight reconnu");
  delay(300);
}
///////////////MA4///////////////////////////////////////////////////////////////////////////////////////  
bool ScanDigital(){
   Serial.println("le scan digital va commencer, veuillez appuyez sur le bouton 1 en partant du haut");
   while (digitalRead(7) == HIGH ){
    delay(500);
    }
  Serial.println("doight reconnu");
  delay(300);
}
/////////////////////////////////MA5////////////////////////////////////////////////////////////////  
int MA5(){
  String a[16] = {"Jonquille","Rose","Paquerette","Maguerite","Pissenlit","Muguet","Tulipe","Lavande","Orchidee","Tournesol","Coquelicot","Bouton dor","Oeillet","Iris","Viollette","Hortensia"};
  boolean id = false;
  boolean entree = false;
  Serial.println("Inserez votre CARTE_ID");
  while(entree == false){
    if (Serial.available()>1){
    entree= true;
    int x = Serial.parseInt();
    delay(1000);
    if (fleur == a[x-1]){
      Serial.println("true");
    }
    else{
      Serial.println("False");
      delay(500);
      exit(1);
    }
   }
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
