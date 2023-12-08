/**
leitura de um sensor ultrasonico-hc-SR04
 @author nick/ana

  ------------------------
  |  Sensor  | arduino   |
  |   vcc    |    5v     |
  |   trig   |    a5     |
  |   echo   |    a4     |
  |    GND   |    GND    |
  ------------------------


*/


//variaveis globais de apoio a formula para calcular a distancia em cm
int distancia;
long sensor;

void setup() {
  Serial.begin(9600);
  pinMode(A4, INPUT);   //echo
  pinMode(A5, OUTPUT);  //saida
}


void loop() {
  //executa a função e armazena na variavel distância
  distancia = ping();
  Serial.print(distancia);
  Serial.println(" cm ");

}
//para retornar um valor,não podemos usar a palavra void na criação 
//função para disparar o sinal,calcular e retornar a distância(cm)
//da função. Neste caso usamos a variável atribuida
long ping() {
  digitalWrite(A5, LOW);  //iniciar sem disparar trig
  delayMicroseconds(2);
  digitalWrite(A5, HIGH);  //disparar o sinal (ping)
    delayMicroseconds(10);
  sensor = pulseIn(A4, HIGH);  //recebimento do sinal
  return (sensor / 29) / 2;   //formula para converter em cm
}
