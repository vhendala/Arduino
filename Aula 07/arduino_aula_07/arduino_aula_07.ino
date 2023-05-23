#include <Ultrasonic.h>
#include <LiquidCrystal.h>

Ultrasonic ultrassom(8,9);
//define o nome do sensor e os pinos trig=8 e echo=7
LiquidCrystal lcd(2,3,4,5,6,7);
//cria objeto lcd da classe LiquidCrystal, RS=2, Enable=3,DB4=4, DB5=5, DB6=6, DB7=7

int relay = 12;
int ledVerde = 13;
int ledVermelho = 11;

void setup() {

lcd.begin(16,2); //inicializa display de 2 linhas x 16 colunas
pinMode(relay, OUTPUT); //define o relay na porta 12 como saída
pinMode(ledVerde, OUTPUT); //define o led verde na porta 13 como saída
pinMode(ledVermelho, OUTPUT); //define o led vermelho na porta 11 como saída 
}

void loop() {
long distancia = ultrassom.Ranging(CM); //ler a distância em centímetros(cm) ou polegadas(inc)

if( distancia < 400){
  digitalWrite(relay, HIGH);
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledVermelho, LOW);
  lcd.print("LAMPADA LIGADA");
  delay(1000);
  lcd.clear();  
}
else{
  digitalWrite(relay, LOW);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, HIGH);
  lcd.print("LAMPADA DESLIGADA");
  delay(2000);
  lcd.clear();
}

}
