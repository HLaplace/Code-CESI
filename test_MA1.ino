int MA1(int multi){   
  
 int var_temp = 0;
 
 if (Serial.available() != 0){   // Il faut actualiser le Serial.available à chauqe fois pour que ça fonctionne sinon la condition est reprise à chaque fois comme vrai
     var_temp = Serial.parseInt();
     var_temp = var_temp * multi;
     Serial.println("If ");
     Serial.println(var_temp);
     return var_temp;
 }
 else{
  Serial.println("else ");
  MA1(multi);

  }
}

void setup() {
  Serial.begin(9600);
  principale();
}

void loop() {}

void principale(){
  int prenom ;
  int nom;
  int dai;
  int mat;
  int temp = 0;
  bool test;
  int TabAgent[16] = {248, 1411, 3563, 4065, 4597, 6395, 7340, 7880, 9233, 10014, 10250, 12439, 12716, 13704, 14023, 15442};
  String TabPrenom[16]={"Alexandre/0","Jean-Marie/1","Henri/2","Louis/3","Tony/4","Gael/5","Jack/6","Theo/7","Adam/8","Leo/9","Simon /10","William/11","Loic/12","Paul/13", "Charle/14", "Tom/15"};
  String TabNom[16]={"Bond/0","Colby/1","Blake/2","Philby/3","Smith/4","James/5","Morton/6","Jackson/7","Scott/8","Evans/9","Lewis/10","May/11","Walker/12","Adams/13","Oliver/14","Baker/15"};
  String TabNai[16] = {"16/06/82 :0","30/05/86 :1","15/04/83 :2","21/08/85 :3","17/03/84 :4","02/01/88 :5","17/09/81 :6","20/12/82 :7","26/11/90 :8","18/08/80 :9","05/04/83 :10","03/10/85 :11","22/07/84 :12","07/12/86 :13","21/11/89 :14","31/03/90 :15"};
  String TabMat[16] = {"007 : 0", "004 : 1", "009 : 2", "002 : 3", "001 : 4", "012 : 5", "035 : 6", "008 : 7", "079 : 8", "003 : 9", "028 : 10", "046 : 11", "005 : 12", "092 : 13", "083 : 14", "006 : 15"};
  
  for(int i=0; i<16; i++){
     Serial.println(TabPrenom[i]);
  }
  Serial.println("Prénom ?");
  prenom = MA1(1000);
  delay(1000);

  for(int i=0; i<16; i++){
     Serial.println(TabNom[i]);
  }
  Serial.println("nom ?");
  nom = MA1(100);
  delay(1000);
 
 for(int i=0; i<16; i++){
    Serial.println(TabNai[i]);
  }
  Serial.println("Date de naissance ?");
  dai = MA1(10);
  delay(1000);

  for(int i=0; i<16; i++){
    Serial.println(TabMat[i]);
  }
  Serial.println("matricule ?");
  mat = MA1(1);
  delay(1000);

  temp = prenom + nom+ dai + mat;
  Serial.println(temp);
  // comparaison avec le tableau
  for(int i=0; i<16; i++){
    if (temp == TabAgent[i]){
      Serial.println("correspondance");
      test = True;
      }  
    }
   if (test == True){
    Serial.println("MA1 valider");
    }
   else{
    Serial.println("MA1 non valider");
    }
   
  }
  
  
