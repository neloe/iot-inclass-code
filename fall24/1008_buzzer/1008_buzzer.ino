#define BUZZER 2
void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
  while(!Serial)delay(1);
  analogWriteFrequency(BUZZER, 220);
  analogWrite(BUZZER, 128);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*digitalWrite(BUZZER, HIGH);
  delay(1);
  digitalWrite(BUZZER, LOW);
  delay(1);*/
  //analogWrite(BUZZER, 128);
}
