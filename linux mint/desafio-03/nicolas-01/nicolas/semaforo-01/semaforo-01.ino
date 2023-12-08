
/**

  Pianinho

  @author Felipe

*/



void setup() {
  Serial.begin(9600);

  pinMode(8, INPUT_PULLUP);  // Dó

  pinMode(9, INPUT_PULLUP);  //Ré

  pinMode(10, INPUT_PULLUP);  // Mi

  pinMode(11, INPUT_PULLUP);  // Fá

  //buzzer

  pinMode(6, OUTPUT);

  //leds

  pinMode(2, OUTPUT);

  pinMode(3, OUTPUT);

  pinMode(4, OUTPUT);

  pinMode(5, OUTPUT);
}



void loop() {

  int sw1 = digitalRead(8);

  int sw2 = digitalRead(9);

  int sw3 = digitalRead(10);

  int sw4 = digitalRead(11);

  //encadeamento da estrutura if

  Serial.print(sw1);

  if (sw1 == 0) {

    tone(6, 262);

    digitalWrite(2, HIGH);

  } else if (sw2 == 0) {

    tone(6, 294);

    digitalWrite(3, HIGH);

  } else if (sw3 == 0) {

    tone(6, 330);

    digitalWrite(4, HIGH);

  } else if (sw4 == 0) {

    tone(6, 349);

    digitalWrite(5, HIGH);

  } else {

    noTone(6);

    digitalWrite(2, LOW);

    digitalWrite(3, LOW);

    digitalWrite(4, LOW);

    digitalWrite(5, LOW);
  }
}