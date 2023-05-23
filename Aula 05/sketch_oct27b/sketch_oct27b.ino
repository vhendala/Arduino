int led = 11;

void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(led, 100);
delay(500);
analogWrite(led, 200);
delay(500);
}
