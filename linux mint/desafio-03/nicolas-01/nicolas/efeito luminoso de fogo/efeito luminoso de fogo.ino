

void setup() {

  Serial.begin(9600);

  //referência ao gerador de números aleatórios

  randomSeed(analogRead(A0));
}



void loop() {

  analogWrite(9, random(255));
  delay(120);
  analogWrite(10, random(255));
  delay(100);
  analogWrite(11, random(255));
  delay(120);
  analogWrite(8, random(255));
  delay(100);

}