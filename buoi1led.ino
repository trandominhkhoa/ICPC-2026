int btn1 = 2;
int btn2 = 3;
int btn3 = 4;
int led1 = 8;
int led2 = 9;
int led3 = 10;
void setup() {
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  int btn1Status = digitalRead(btn1);
  Serial.print(btn1Status);
  int btn2Status = digitalRead(btn2);
  Serial.print(btn2Status);
  int btn3Status = digitalRead(btn3);
  Serial.println(btn3Status);
  delay(50);
  if (btn1Status == 1) {

    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
  if (btn2Status == 1) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }
  if (btn3Status == 1) {
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led3, LOW);
  }
}