


  Serial.println(" cm");
  delay(1000);
  if (distancia < 100) {
    servo1.write(90);

    digitalWrite(2, HIGH);


    digitalWrite(9, LOW);





  } else if (distancia > 6) {
    servo1.write(0);

    digitalWrite(9, HIGH);


    digitalWrite(2, LOW);
  }
}

long ping() {
  digitalWrite(A5, LOW);
  delayMicroseconds(2);
  digitalWrite(A5, HIGH);
  delayMicroseconds(10);
  sensor = pulseIn(A4, HIGH);
  return (sensor / 29) / 2;
}