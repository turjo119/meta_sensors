#define LED 4

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);

}




void loop() {

  long l0 = 0;
  long l1 = 0;
  long l = 0;
  for (int i = 0; i < 10; i++) {
    digitalWrite(LED, 0);
    delayMicroseconds(5000);
    long l00 = analogRead(A0);
    long l10 = analogRead(A1);
    digitalWrite(LED, 1);
    delayMicroseconds(5000);
    long l01 = analogRead(A0);
    long l11 = analogRead(A1);

    l0 = l00;
    l1 = l01;
    l=l0;
  }
  //l0 = l0 / 10;
  //l1 = l1 / 10;
  //l=l/10;

  Serial.println(l0);
  Serial.println(l1);
}
