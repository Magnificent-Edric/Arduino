#define led 11

int shelf = 0;
int a = 0;

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  digitalWrite(led, LOW);
  pinMode(led, INPUT);
  a = readData();
  Serial.begin(9600);
  Serial.print("a:");
  Serial.print(a);
  Serial.print("\n");
  pinMode(led, OUTPUT);
  if (a > 3650)
    digitalWrite(led, LOW);
  else
    digitalWrite(led, HIGH);
  delay(10000);
  digitalWrite(led, LOW);
}

int readData()
{
  int sum = 0;

  for (int i = 0; i < 5; i++) analogRead(led);
  for (int i = 0; i < 10; i++){
    sum += analogRead(led);
    delay(10);
  }
  return (sum);
}
