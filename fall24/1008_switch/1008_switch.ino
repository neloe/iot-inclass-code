#define SWITCH 2

void IRAM_ATTR interrupt1();
bool pushed = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SWITCH, INPUT_PULLDOWN);
  attachInterrupt(SWITCH, interrupt1, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*if (digitalRead(SWITCH) == 1)
  {
    //do stuff
  }
  Serial.println(digitalRead(SWITCH));*/
  if (pushed)
  {
    Serial.println("moo");
    pushed = false;
  }
}

void IRAM_ATTR interrupt1()
{
  pushed = true;
}