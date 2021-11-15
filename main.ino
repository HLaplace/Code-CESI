//////////////////////////////////////////////////////////////////////////////////////////////Variables globales///////////////////////////////////////////////////////////////////////////////////////////////
String Animal = "Lion";
int code[4] = {1,2,3,4}; // code ouvrant le coffre 
int tableau_connexion[8] = {2,3,4,5,8,9,10,11}; // tableau contenant les pins de tout les boutons puis de toute les leds

int i = 0; // variable de suivi principale
int chiffre_tenter = 0; // variable principale contenant le chiffre tenté par l'utilisateur

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup()
{
  Serial.begin(9600);
  pinMode(tableau_connexion[0], INPUT_PULLUP); // configuration de tout les boutons : broche disponible dans le tableau (4 première valeurs)
  pinMode(tableau_connexion[1], INPUT_PULLUP);
  pinMode(tableau_connexion[2], INPUT_PULLUP);
  pinMode(tableau_connexion[3], INPUT_PULLUP); 
  
  pinMode(tableau_connexion[4], OUTPUT);// configuration de toutes les leds : broche disponible dans le tableau (4 dernières valeurs)
  pinMode(tableau_connexion[5], OUTPUT);
  pinMode(tableau_connexion[6], OUTPUT);
  pinMode(tableau_connexion[7], OUTPUT);
  
  pinMode(12, OUTPUT); // led verte
  pinMode(6, INPUT_PULLUP); // lecteur empreinte digitale
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop(){
  
  
  //verification_code_debut();
  int NivSecu = 0;
  Serial.println("Niveau de sécurité ?");
  while (NivSecu == 0){
    if (Serial.available()>1){
       NivSecu = Serial.parseInt();//recupere un entier
      }
    }
  
  switch (NivSecu) {
    case 1:
      MA1();
      MA3();
      Serial.println("Ouverture du coffre");
      delay(300);
      exit(1);
      //break;
      
    case 2:
      MA1();  
      MA4();  
      Serial.println("Ouverture du coffre");
      delay(300);
      exit(1);
      //break;

    case 3:
      MA2();  
      MA5();  
      Serial.println("Ouverture du coffre");
      delay(300);
      exit(1);
      //break;
      
    case 4:
      MA2();  
      MA3();  
      MA4();  
      Serial.println("Ouverture du coffre");
      delay(300);
      exit(1);
      //break;
      
    case 5:
      MA1();  
      MA2();  
      MA3();  
      MA5();  
      Serial.println("Ouverture du coffre");
      delay(300);
      exit(1);
      //break;
              
    default:
      Serial.println("Ce niveau n existe pas ");  
      break;
  }
}
////////////////////////////////////////////////////////////////////////////////////////////Verifiaction du code au debut////////////////////////////////////////////////////////////////////////////////////////////
void verification_code_debut(){
 Serial.println("Entrez le code sur les boutons :");
 while (i != 4){ // quand i = 4, c'est que les 4 chiffres de la combinaisons sont validés
    delay(300); // tempo pour eviter que un appui sois pris comme plusieur entrées
 
    activation_bouton(tableau_connexion[0]);
    activation_bouton(tableau_connexion[1]);
    activation_bouton(tableau_connexion[2]);
    activation_bouton(tableau_connexion[3]);
    
    if (chiffre_tenter != 0){// si il est égal à 0 c'est qu'aucun chiffre n'a été tenté
      
      if (chiffre_tenter == code[i]){ // si le chiffre tenter est le chiffre attendu par le code
        Serial.println("Chiffre n°" + String(i + 1) + " de la combinaison validé");
        digitalWrite(tableau_connexion[i + 4], HIGH);
        
        i = i +1 ; // car un des chiffres de la combinaison est validé
        chiffre_tenter = 0;
        }
        
      else{ // si le chiffre entré par l'utilisateur n'est pas le bon
        erreur_code();
        }
     } 
 }
  digitalWrite(12, HIGH); // led verte allumé
  delay(1000);
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
  int a = 0; // pour que la fonction puisse fonctioner plusieurs fois
  while (a !=3){ // car les leds clignotents 3 fois
    digitalWrite(tableau_connexion[4], HIGH);
    digitalWrite(tableau_connexion[5], HIGH);
    digitalWrite(tableau_connexion[6], HIGH);
    digitalWrite(tableau_connexion[7], HIGH);
    delay(500);
    digitalWrite(tableau_connexion[4], LOW);
    digitalWrite(tableau_connexion[5], LOW);
    digitalWrite(tableau_connexion[6], LOW);
    digitalWrite(tableau_connexion[7], LOW);
    delay(500);
    a = a + 1;
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////MA1//////////////////////////////////////////////////////////////////////////////////////////////////
void MA1(){
  int prenom ;
  int nom;
  int dai;
  int mat;
  int temp = 0;
  bool test;
  int TabAgent[16] = {248, 1411, 3563, 4065, 4597, 6395, 7340, 7880, 9233, 10014, 10250, 12439, 12716, 13704, 14023, 15442};
  String TabPrenom[16]={"Alexandre 0", "Jean-Marie 1", "Henri 2", "Louis 3", "Tony 4", "Gael 5", "Jack 6", "Theo 7", "Adam 8", "Leo 9", "Simon 10", "William 11", "Loic 12", "Paul 13", "Charles 14", "Tom 15"};
  String TabNom[16]={"BOND 0", "COLBY 1", "BLAKE 2", "PHILBY 3", "SMITH 4", "JAMES 5", "MORTON 6", "JACKSON 7", "SCOTT 8", "EVANS 9", "LEWIS 10", "MAY 11", "WALKER 12", "ADAMS 13", "OLIVER 14", "BAKER 15"};
  String TabNai[16] = {"16/06/82 0", "30/05/86 1", "15/04/83 2", "21/08/85 3", "17/03/84 4", "02/01/88 5", "17/09/81 6", "20/12/82 7", "26/11/90 8", "18/08/80 9", "05/04/83 10", "03/10/85 11", "22/07/84 12", "07/12/86 13", "21/11/89 14", "31/03/90 15"};
  String TabMat[16] = {"007 0", "004 1", "009 2", "002 3", "001 4", "012 5", "035 6", "008 7", "079 8", "003 9", "028 10", "046 11", "005 12", "092 13", "083 14", "006 15"};

  for(int i=0; i<16; i++){
     Serial.println(TabNom[i]);
  }
  Serial.println("nom ?");
  nom = MA1_bis(1000);
  delay(1000);

  for(int i=0; i<16; i++){
     Serial.println(TabPrenom[i]);
  }
  Serial.println("Prénom ?");
  prenom = MA1_bis(100);
  delay(1000);
 
 for(int i=0; i<16; i++){
    Serial.println(TabNai[i]);
  }
  Serial.println("Date de naissance ?");
  dai = MA1_bis(10);
  delay(1000);

  for(int i=0; i<16; i++){
    Serial.println(TabMat[i]);
  }
  Serial.println("matricule ?");
  mat = MA1_bis(1);
  delay(1000);

  temp = prenom + nom+ dai + mat;
  Serial.println(temp);
  for(int i=0; i<16; i++){
    if (temp == TabAgent[i]){
      Serial.println("correspondance");
      test = true;
      }  
    }
   if (test == true){
    Serial.println("MA1 valider");
    }
   else{
    Serial.println("MA1 non valider");
    }
   
  }   

int MA1_bis(int multi){  
 
 int var_temp = 0;
 
 if (Serial.available() > 1){   // Il faut actualiser le Serial.available à chauqe fois pour que ça fonctionne sinon la condition est reprise à chaque fois comme vrai
     var_temp = Serial.parseInt();
     var_temp = var_temp * multi;
     return var_temp;
 }
 else{
  MA1_bis(multi);

  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////MA2//////////////////////////////////////////////////////////////////////////////////////////////////
int MA2(){
  int e, M, C;
  int Mp = 0;
  boolean first, second = false;
  Serial.println("Identifiez-vous :");
  randomSeed(analogRead(0));//permet de changer de variable aléatoire
  String x = "";
  while (x == ""){
    if (Serial.available()>1){
       x = Serial.readString();//recupere une chaine de caractere
    }
  }
  e = CleAgent(x);
  M = random(2881);//nombre aléatoire
  C = Modexp(M,e,2881);
  Serial.print("Message a dechiffrer :");
  Serial.println(C);
  Serial.println("Entrez le message :");
  while (Mp == 0){
      Mp = Serial.parseInt();//recupere un entier dans la console
  } 
  if (M==Mp){
    Serial.print("Vous êtes authentifié! Bienvenue agent ");
    Serial.println(x);
    return true;
  }
  else {
    Serial.println("Erreur d'authentification, le système de sécutité se déclenchera dans 5 secondes");
    return false;
  }
}
int Modexp(float a, int e, float n){
  float r;
  if (e<0){
    Serial.println("unhandled case");
    exit(1);
  }
  else if ((a==0)||(n==1)){
    r = 0;
  }
  else {  
    r = 1;
    while (e>0){
      r = fmod((r*fmod(a,n)),n); 
      e=e-1;
    }
  }
  return r;
}

int CleAgent(String x){//recupere la cle publique de l'agent
  
    int ClePublicAgent[16] = {601,619,631,641,647,653,661,673,691,701,733,739,751,797,809,811};
    String NomAgent = "ABCDEFHIJKLMNOPQ";
    int i = 0;
    int cle = 0;
    
    for(i=0; i<(NomAgent.length()); i++)
    {
        if(String(NomAgent[i]) == String(x))//dès que ma lettre coincide, je recupere la position
        {
            // alors on l'enregistre
            cle = ClePublicAgent[i];//j'utilise la position pour recupere la clé
        }
    }
    return cle;
}
//////////////////////////////////////////////////////////////////////////////////////////////////MA//////////////////////////////////////////////////////////////////////////////////////////////////
bool MA3(){ // scanner retinien simule par les boutons 1 et 6
  Serial.println("le scan retienien va commencer");
  while (digitalRead(2) == HIGH && digitalRead(6) == HIGH ) {
    delay(500);
    }
  Serial.println("oeil reconnu");
  delay(300);
}
//////////////////////////////////////////////////////////////////////////////////////////////////MA4//////////////////////////////////////////////////////////////////////////////////////////////////
bool MA4(){ // reconnaissance digital simulé par un bouton branché sur le pin 6
  Serial.println("le scan digital va commencer, veuillez appuyez sur le bouton rouge");
   while (digitalRead(6) == HIGH ){
    delay(500);
    }
  Serial.println("doight reconnu");
  delay(300);
}
//////////////////////////////////////////////////////////////////////////////////////////////////MA5//////////////////////////////////////////////////////////////////////////////////////////////////
int MA5(){
  String a[16] = {"Taureau", "Lion", "Verseau", "Belier", "Sagitaire", "Poisson", "Poisson", "Vierge", "Gémeaux", "Cancer", "Balance", "Scorpion", "Capricorne", "Papillon", "Lynx", "Ours" };
  boolean id=false;
  boolean entree = false;
  Serial.print("Votre Carte ID est:");
  while (entree == false){
    if (Serial.available()>1){
      entree = true;
      int x = Serial.parseInt();
      if (Animal == a[x-1]){
        Serial.print("exact");
      }
      else{
        Serial.print("erreur identification de la carte");
        delay(500);
        exit(1);
       }
    }
  } 
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
