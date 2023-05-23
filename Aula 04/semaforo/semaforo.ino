int botao = 10;
int led_vermelho = 11;
int led_amarelo = 12;
int led_verde = 13; 
int estado;

void setup() {
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);  
  pinMode(botao, INPUT);
}

void loop() {
  estado = digitalRead(botao);
  if( estado == HIGH){
  digitalWrite(led_vermelho, HIGH);    
  }
  else{
  digitalWrite(led_verde, HIGH);
  delay(3000);
  digitalWrite(led_verde, LOW);
  digitalWrite(led_amarelo, HIGH);
  delay(1000);
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_vermelho, HIGH);
  delay(3000);
  digitalWrite(led_vermelho, LOW);  
  }
}
