/**
pianinho 
 @author nick/ana

*/






void setup() {

  pinMode(8, INPUT_PULLUP);
}



void loop() {
  int sw1 = digitalRead(8);
  Serial.println("sw1:");

  int sw2 = digitalRead(9);
  Serial.println("sw2:");

  int sw3 = digitalRead(10);
  Serial.println("sw3:");

  int sw4 = digitalRead(11);
  Serial.println("sw4:");

  if (sw1 == 0) {
    digitalWrite(2, HIGH);  //verde
    digitalWrite(3, LOW);   //vermelho
    digitalWrite(4, LOW);   //azul
    digitalWrite(5, LOW);   //amarelo

  } else {
    digitalWrite(2, LOW);  //verde
    digitalWrite(3, LOW);   //vermelho
    digitalWrite(4, LOW);   //azul
    digitalWrite(5, LOW);   //amarelo
  }


  if (sw2 == 0) {
    digitalWrite(2, LOW);  //verde
    digitalWrite(3, LOW);   //vermelho
    digitalWrite(4, LOW);   //azul
    digitalWrite(5, LOW);   //amarelo

  } else {
    digitalWrite(2, LOW);  //verde
    digitalWrite(3, HIGH);   //vermelho
    digitalWrite(4, LOW);   //azul
    digitalWrite(5, LOW);   //amarelo
  }

}
