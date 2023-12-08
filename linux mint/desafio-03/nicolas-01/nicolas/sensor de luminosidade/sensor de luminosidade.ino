/**
 leitura de um sensor de luminosidade(fotoresistor-LDR)
   @author nickMiraFofa
*/






void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  int sensorLDR = analogRead(A0);
  Serial.print("valor do sensor: ");
  Serial.println(sensorLDR);
  if(sensorLDR > 900){
    digitalWrite(13, LOW);
  }else{
    digitalWrite(13, HIGH);
  }
}
