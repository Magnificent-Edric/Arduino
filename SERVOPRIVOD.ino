#include <Servo.h>
int angl = 0;
int joyX = 0;
Servo s;
void setup() {
  s.attach(12);
  pinMode(joyX, INPUT);
  Serial.begin(9600);
}

void loop() {
  int val = (analogRead(joyX)/64) - 8;
  angl = angl + val + 1;
  if (angl < 0){angl = 0;}
  if (angl > 180){angl = 180;}
  s.write(angl);
  Serial.print("angl:");
  Serial.println(angl);
  int spd = 500;
  if (val != 0){spd = (600/abs(val));}
  delay(spd);
}
