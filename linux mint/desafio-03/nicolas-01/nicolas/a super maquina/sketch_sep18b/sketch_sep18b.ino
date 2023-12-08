 /**
  A super maquina (sequencial de leds)
  */



//variável global para ajustar a velocidade do efeito
int velocidade = 500;
void setup() {
  for (int x = 1; x <= 6; x++) {
    pinMode(x, OUTPUT);
  }
}

void loop() {
  for (int x = 1; x <= 6; x++) {
    digitalWrite(x, HIGH);
    delay(velocidade);
    digitalWrite(x, LOW);
  }
  for (int x = 5; x >=2; x--){
   digitalWrite(x, HIGH);
    delay(velocidade);
    digitalWrite(x, LOW);
  } 
  
}
