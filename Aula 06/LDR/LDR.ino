int ledPin = 4; //Led no pino 4
int ldrPin = 0; //LDR no pino analógico 0
int ldrValor = 0; //Valor lido do LDR


void setup() {
  pinMode(ledPin,OUTPUT); //define a porta 7 como saída
  Serial.begin(9600); //inicia a comunicação serial
}

void loop() {
  //ler o valor do LDR
  ldrValor = analogRead(ldrPin);
  //se o valor lido for maior ou igual à 800, liga o led
  if (ldrValor>= 800) digitalWrite(ledPin,HIGH);
  //senão, apaga o led
  else digitalWrite(ledPin,LOW);
  //imprime o valor lido do LDR no monitor serial
  Serial.println(ldrValor);
  delay(100);
}
