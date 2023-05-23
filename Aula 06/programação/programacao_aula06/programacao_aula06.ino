#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);
//cria objeto lcd da classe LiquidCrystal, RS=2, Enable=3,DB4=4, DB5=5, DB6=6, DB7=7

#include "DHT.h" //inclui biblioteca DHT da adafruit
#define DHTPIN A2 //indica o pino que o DHT está conectado
#define DHTTYPE DHT11 //indica se é DHT 11, ou DHT12 etc..

DHT dht(DHTPIN, DHTTYPE); //cria um objeto de classe DHT chamado dht

int ledPin = 13; //Led no pino 13
int ldrPin = 0; //LDR no pino analógico 0
int ldrValor = 0; //valor lido do LDR

//sensor de temperatura usando o LM35
const int LM35 = A1; //define o pino que lerá a saída do LM35
float temperatura; //variável que armazenará a temperatura medida

//função que será executada uma vez quando ligar o resetar o arduino
void setup() {
  lcd.begin(16,2); //inicializa display de 2 linhas x 16 colunas
  
  lcd.print("3 "); //executa uma contagem regressiva
  delay(1000);
  lcd.print("2 ");
  delay(1000);
  lcd.print("1 ");
  delay(1000);

  lcd.clear(); //limpa a tela do LCD
  lcd.setCursor(1,1); //posiciona o cursor na posição (1,1):(coluna,linha)
  lcd.print("VHENDALA"); //escreve VHENDALA
  
  pinMode(ledPin,OUTPUT); //define a porta 13 como saída
  Serial.begin(9600); //inicia a comunicação serial
  dht.begin();
}

//função que será executada continuamente
void loop() {
  //ler o valor do LDR
  ldrValor = analogRead(ldrPin);
  //se o valor lido for maior ou igual à 800, liga o led
  if (ldrValor>= 800) digitalWrite(ledPin,HIGH);
  //senão, apaga o led
  else digitalWrite(ledPin,LOW);
  //imprime o valor lido do LDR no monitor serial
  Serial.print("Resistencia LDR: ");
  Serial.println(ldrValor);
  delay(100);

  temperatura = (float(analogRead(LM35))*5/(1023))/0.01;
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  delay(1000);

  float h = dht.readHumidity();
  Serial.print("Umidade: ");
  Serial.print(h);
  Serial.println(" %");
  delay(1000);

  lcd.clear();
  lcd.print("Res LDR");
  delay(2000);
  lcd.clear();
  lcd.print(ldrValor);
  delay(2000);
  
  lcd.clear();
  lcd.print("Temperatura");
  delay(2000);
  lcd.clear();
  lcd.print(temperatura);
  delay(2000);
  
  lcd.clear();
  lcd.print("Umidade");
  delay(2000);
  lcd.clear();
  lcd.print(h);
  delay(2000);
}
