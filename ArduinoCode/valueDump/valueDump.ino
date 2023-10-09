#define LED 4
#define POT A3
bool running = true;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(LED, OUTPUT);
  analogReference(EXTERNAL);
  Serial.begin(9600);
  delay(200);
  Serial.println("l00, l01, l10, l11, l20, l21, p0, p1");

}
void loop() {

  if (running) {
    for (int i = 0; i < 10000; i++) {
      digitalWrite(LED, 0);
      delayMicroseconds(1000);
      long l00 = analogRead(A0);
      long l10 = analogRead(A1);
      long l20 = analogRead(A2);

      long p0 = analogRead(POT);

      digitalWrite(LED, 1);
      delayMicroseconds(1000);
      long l01 = analogRead(A0);
      long l11 = analogRead(A1);
      long l21 = analogRead(A2);
      long p1 = analogRead(POT);

      Serial.print(l00);
      Serial.print(',');
      Serial.print(l01);
      Serial.print(',');
      Serial.print(l10);
      Serial.print(',');
      Serial.print(l11);
      Serial.print(',');
      Serial.print(l20);
      Serial.print(',');
      Serial.print(l21);
      Serial.print(',');
      Serial.print(p0);
      Serial.print(',');
      Serial.println(p1);
    }
    running = false;
  }

}
