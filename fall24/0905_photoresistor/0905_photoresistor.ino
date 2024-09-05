
#define PHOTOCELL_PIN 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(PHOTOCELL_PIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogReadMilliVolts(PHOTOCELL_PIN);
  Serial.println(val);
  delay(500);
}
