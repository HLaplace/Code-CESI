const int bouton = 2; 
const int led = 13;
boolean running = false; // variable qui enregistre l'état du bouton


void setup()
{
    pinMode(led, OUTPUT); // la led est une sortie
    pinMode(bouton, INPUT_PULLUP); // le bouton est une entrée
    digitalWrite(bouton, HIGH); // Pullup interne sur le bouton
    digitalWrite(led, running); // mise de la led a l etat running
}

void loop()
{
  //quand on appuie le bouton est LOW
    if(digitalRead(bouton) == LOW) // test si le bouton a un niveau logique HAUT
    {
      while (digitalRead(bouton) == LOW);
      {
      digitalWrite(led, running); //le bouton est relâché, la LED est allumée

      }
    }
  running = !running; // inversion de running               

}
