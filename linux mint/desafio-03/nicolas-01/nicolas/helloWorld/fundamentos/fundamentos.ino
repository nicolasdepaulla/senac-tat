/**
 fundamentos da  programação do com arduino 
 @author nick/ana 
*/

// variáveis (declarações)
int valorSensor;
float temperatura, umidade;
int valorSensor = 100;

void setup() {
  serial.begin(9600); //inicializar a comunicação serial 
  serial.print("hello world");
  serial.println("estudo das variáveis");
  serial.println("valor do sensor:" + valorSensor);
}

void loop() {
  

}
