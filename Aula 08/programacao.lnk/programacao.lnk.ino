#include <Servo.h>

int enable1 = 9;
int in1 = 11;
int in2 = 10;

int enable2 = 2;
int in3 = 1;
int in4 = 0;

int botao1 = 5; 
int botao2 = 4; 
int botao3 = 3; 
int botao4 = 2; 
int botao5 = 1; 

int estado1;
int estado2;
int estado3;
int estado4;
int estado5;

Servo servo1; //variável servo motor
int angulo=1;; //ângulo do servo motor
int led_verde = 5; //declarando led verde no pino 5
int led_azul = 4; //declarando led azul no pino 4
int led_amarelo = 3; //declarando led amarelo no pino 3
int led_vermelho = 8; //declarando led vermelho no pino 8

void setup() {
pinMode(enable1, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
digitalWrite(enable1, HIGH);

pinMode(enable2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
digitalWrite(enable2, HIGH);

servo1.attach(6); //anexa o servo no pino 6
servo1.write(0); //inicia servo motor na posição zero
pinMode(led_verde, OUTPUT);
pinMode(led_azul, OUTPUT);
pinMode(led_amarelo, OUTPUT);
pinMode(led_vermelho, OUTPUT);

pinMode(botao1, INPUT);
pinMode(botao2, INPUT);
pinMode(botao3, INPUT);
pinMode(botao4, INPUT);
pinMode(botao5, INPUT);

}

void loop() {
estado1 = analogRead(botao1);
estado2 = analogRead(botao2);
estado3 = analogRead(botao3);
estado4 = analogRead(botao4);
estado5 = analogRead(botao5);

while(estado1 == HIGH){
      while(angulo<180){
       angulo++;
          servo1.write(angulo);
          digitalWrite(led_verde, HIGH);
          delay(20);
        }
        
        while( angulo>0){
           angulo--;
          servo1.write(angulo);
          digitalWrite(led_verde, HIGH);
          delay(20);
        }
        delay(20);  
}

while(estado1 == LOW){
  digitalWrite(led_verde, LOW);  
}



while(estado2 == HIGH){
  digitalWrite(led_azul, HIGH);
  digitalWrite(in1, HIGH); 
  delay(1000); 
}

while(estado2 == LOW){
  digitalWrite(led_azul, LOW);
  digitalWrite(in1, LOW);
}



while(estado3 == HIGH){
  digitalWrite(led_amarelo, HIGH);
  digitalWrite(in4, HIGH);
  delay(1000);
}

while(estado3 == LOW){
  digitalWrite(led_amarelo, LOW);
  digitalWrite(in4, LOW);
  delay(1000);
}



while(estado4 == HIGH){
   while(angulo<180){
       angulo++;
          servo1.write(angulo);
          digitalWrite(led_verde, HIGH);
          delay(20);
        }
        
        while( angulo>0){
           angulo--;
          servo1.write(angulo);
          digitalWrite(led_verde, HIGH);
          delay(20);
        }
        delay(20); 

  digitalWrite(led_azul, HIGH);
  digitalWrite(in1, HIGH); 
  digitalWrite(led_amarelo, HIGH);
  digitalWrite(in4, HIGH);
  delay(1000);  
  
}


while(estado5 == HIGH){
  digitalWrite(led_vermelho, HIGH); 
}

while(estado5 == LOW){
  digitalWrite(led_vermelho, LOW);
}

}
