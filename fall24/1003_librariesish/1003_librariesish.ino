#include "myfunctions.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial)delay(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(getNumber());
  int num1, num2;
  getTwoNumbers(num1, num2);
  Serial.printf("%d %d\n", num1, num2);
  delay(3000);
}

/*
void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}*/