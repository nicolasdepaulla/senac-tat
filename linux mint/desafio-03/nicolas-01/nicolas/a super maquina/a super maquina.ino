
void setup() {
  Serial.begin(9600);
  Serial.println("");
  // laço for - número determinado de repetições
  // int x=1 (valor do laço)
  // x <= 10 (condição para encerrar o laço da repetição)
  // x++(incremento)
  for (int x = 1; x <= 10; x++) {
    Serial.println(x);
    delay(1000);
  }
  Serial.println("fim do laco for");
  Serial.println("_____________");
  for (int x = 10; x >= 1; x--) {
    Serial.println(x);
    delay(1000);
  }
  Serial.println("decolar...");
}

void loop() {
}
