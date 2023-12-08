/**
 fundamentos da  programação do com arduino 
 @author nick/ana 
*/

// variáveis (declarações)
int valorSensor;//numeros inteiros 
float temperatura, umidade;// números inteiros e não inteiros 
char tecla; //1 caractere 
String placa; //sequencia de caracteres
bool gameOver; //verdadeiro ou falso (true false) 

void setup() {
  valorSensor = 100.5;
  temperatura = 31.6;
  tecla = 'w';
  placa = "arduino UNO R3";
  gameOver =

  Serial.begin(9600); //inializar a comunicação serial (9600 bits per second)
  Serial.print("hello world");
  Serial.println("estudo das variáveis");
  Serial.println("valor do sensor:" );
  Serial.println(valorSensor);
  Serial.print("temperatura");
  Serial.println(temperatura);
  Serial.print("tecla pressionada");
  Serial.println(tecla);
  Serial.print("placa:");
  Serial.println(placa);
  Serial.print("game Over (0: false 1: true) ");
  Serial.println(gameOver);
}


void loop() {
  

}
