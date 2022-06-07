/*Aguinaldo Alves de Souza Técnico em mecatrônica ,sexta-feira 12/10/18 ás 17:20min programação para
Semáforo*/
int carroVermelho = 7; 
int carroAmarelo = 5; 
int carroVerde = 4; 
int pessoaVerde = 3;
int pessoaVermelho = 6; 
int estado;
int tempoAtravessando = 5000;
unsigned long mudaTempo;
 
void setup() {
  
  // Inicializamos o temporizador aqui
  // Observe que o "contador" foi atrelado
  // a váriavel que setamos acima "tempoAtravessando".
  
  mudaTempo = millis();
    
  pinMode(carroVermelho, OUTPUT);
  pinMode(carroAmarelo, OUTPUT);
  pinMode(carroVerde, OUTPUT);
  pinMode(pessoaVermelho, OUTPUT);
  pinMode(pessoaVerde, OUTPUT);
   
  digitalWrite(carroVerde, HIGH);
  digitalWrite(pessoaVermelho, HIGH);
  digitalWrite(carroVermelho, LOW);
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(pessoaVerde, LOW);
  Serial.begin(9600);
  Serial.println(estado);  // mostre o estado dos Leds
}
 
void loop() {
  
       // Se a variavel 'estado' estiver apagado "LOW" comece a contar o tempo de 5 segundos
  if (estado == LOW && (millis() - mudaTempo) > 5000) {
    
    //Então SE SIM, executa a função de mudar o estado das luzes abaixo:
    mudaLuzes();
  }
}
 
void mudaLuzes() {
  digitalWrite(carroVerde, LOW);    // A luz do led verde é desligada
  digitalWrite(carroAmarelo, HIGH); // A luz do led amarela vai ligar por 5 segundos
  delay(5000); 
  
  digitalWrite(carroAmarelo, LOW); // A luz do led amarela vai desligar
  digitalWrite(carroVermelho, HIGH); // A luz do led vermelha vai ligar por 5 segundos
 
  digitalWrite(pessoaVermelho, LOW);  //A luz do led vermelha vai desligar por 5 segundos
  digitalWrite(pessoaVerde, HIGH);
  delay(tempoAtravessando);
  
  // Pisca a luz verde dos PEDESTRES
  for (int x=0; x<10; x++) {
    digitalWrite(pessoaVerde, LOW);
    delay(260);
    digitalWrite(pessoaVerde, HIGH);
    delay(260);
  }
  digitalWrite(pessoaVerde, LOW);
  digitalWrite(carroVermelho, LOW);
  digitalWrite(pessoaVermelho, HIGH);
  digitalWrite(carroVerde, HIGH);
 
  mudaTempo = millis();
 }




