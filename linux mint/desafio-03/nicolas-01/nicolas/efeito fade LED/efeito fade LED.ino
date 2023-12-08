/** 
 efeito luminoso fade LED
 @author nickmirafofa
 */





void setup() {
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(11, i);  //usar PWM na saida digital (0 a 255)
    delay(1);
  }
  for (int i = 255; i >= 0; i--)
    analogWrite(11, i);  //usar PWM na saida digital (0 a 255)
  delay(1);
  for (int i = 0; i <= 255; i++) {
    analogWrite(10, i);  //usar PWM na saida digital (0 a 255)
    delay(1);
  }
  for (int i = 255; i >= 0; i--)
    analogWrite(10, i);  //usar PWM na saida digital (0 a 255)
  delay(1);
}
