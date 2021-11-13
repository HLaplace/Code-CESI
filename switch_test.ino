void setup() {
  Serial.begin(9600);
  int NivSecu = 0;
}

void loop() {
    if(error==false && ouverture==false){
    while (NivSecu == 0){
      if (Serial.available()>1){
         NivSecu = Serial.parseInt();//recupere une chaine de caractere
      }
    }
  }
  switch (NivSecu) {
    
    case 1:
      MA1();
      MA3();
      Serial.println("Ouverture du coffre");
      break;
      
    case 2:
      MA1();  
      MA4();  
      Serial.println("Ouverture du coffre");
      break;

    case 3:
      MA2();  
      MA5();  
      Serial.println("Ouverture du coffre");
      break;
      
    case 4:
      MA2();  
      MA3();  
      MA4();  
      Serial.println("Ouverture du coffre");
      break;
      
    case 5:
      MA1();  
      MA2();  
      MA3();  
      MA5();  
      Serial.println("Ouverture du coffre");
      break;
              
    default:
      Serial.println("Ce niveau n existe pas ");  
      break;
}
}
