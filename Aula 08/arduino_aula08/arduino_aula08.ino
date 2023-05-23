#include <Servo.h>
int botao1 = 1; 

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
int angulo; //ângulo do servo motor
int led_verde = 5; //declarando led no pino 5

void setup() {
servo1.attach(6); //anexa o servo no pino 6

pinMode(led_verde, OUTPUT);
pinMode(botao1, INPUT);

}

void loop() {
estado1 = digitalRead(botao1);
estado2 = analogRead(botao2);
estado3 = analogRead(botao3);
estado4 = analogRead(botao4);
estado5 = analogRead(botao5);

if(estado1 == HIGH){
  
        pinMode(led_verde, HIGH);
        
       
}

else{
  pinMode(led_verde, LOW);
}



if(estado2 == HIGH){

}

while(estado3 == HIGH){

}

while(estado4 == HIGH){

}

while(estado5 == HIGH){

}

}
