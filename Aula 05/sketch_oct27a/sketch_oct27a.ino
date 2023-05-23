int potenciometro1 = A0;
int potenciometro2 = A1;
int leitura1 = 0;
int leitura2 = 0;
int brilho1 = 0;
int brilho2 = 0;
int led1 = 11;
int led2 = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(potenciometro1, INPUT);
  pinMode(potenciometro2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  leitura1 = analogRead(potenciometro1);
  leitura2 = analogRead(potenciometro2);
  Serial.println(leitura1);
  Serial.println(leitura2);
  Serial.println("...");
  brilho1 = map(leitura1, 0, 1023, 0, 255);
  brilho2 = map(leitura2, 0, 1023, 0, 255);
  analogWrite(led1, brilho1);
  analogWrite(led2, brilho2);  
}
