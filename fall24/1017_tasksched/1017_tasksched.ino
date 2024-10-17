#include <ArduinoJson.h>
#include <TaskScheduler.h>
#include <RH_RF95.h>

/* radio setup
pins!*/
#define RFM95_CS 16
#define RFM95_INT 21
#define RFM95_RST 4

#define RFM95_FREQ 915.0

RH_RF95 rf95(RFM95_CS, RFM95_INT);

#define SECOND 1000

JsonDocument message;
void sendMessage();
Task radioTask (10*SECOND, TASK_FOREVER, &sendMessage);
Scheduler taskManager;

char packet[RH_RF95_MAX_MESSAGE_LEN];

void setup(){
  // put your setup code here, to run once:
  message["id"] = 128;
  message["rs"] = JsonDocument();

  Serial.begin(9600);
  while(!Serial) delay(1);

  pinMode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, LOW);
  delay(10);
  digitalWrite(RFM95_RST, HIGH);
  delay(10);

  if (!rf95.init())
  {
    Serial.println("Error initing radio.  Bad?");
    while(1);
  }
  if (!rf95.setFrequency(RFM95_FREQ))
  {
    Serial.println("Set frequency failed");
    while(1);
  }
  Serial.print("Frequency set to:"); Serial.println(RFM95_FREQ);

  rf95.setCodingRate4(6);
  rf95.setSignalBandwidth(62500);
  rf95.setSpreadingFactor(8);
  rf95.setTxPower(20, false);

  taskManager.init();
  taskManager.addTask(radioTask);

  radioTask.enable();
}

void loop() {
  // put your main code here, to run repeatedly:
  taskManager.execute();
}

void sendMessage()
{
  message["rs"]["wt"] = 15 + rand() % 10;
  message["rs"]["pH"] = 5 + (rand() % 30)/10.0;
  message["rs"]["ec"] = (rand() % 1000 )/ 1000.0;
  serializeJson(message, Serial);
  Serial.println();
  int bytes = serializeJson(message, packet);
  rf95.send((uint8_t*)packet, bytes);
}
