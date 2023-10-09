#define LED 4

short tab[1024];


void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);

  for (int i = 0; i < 1024; i++) {
    tab[i] = 0;
  }
  delay(5000);
  //Serial.println("start messuring");
  for (long times = 0; times < 5000; times++) {

    long l0 = 0;
    digitalWrite(LED, 0);
    delayMicroseconds(1000);
    long l00 = analogRead(A0);
    digitalWrite(LED, 1);
    delayMicroseconds(1000);
    long l01 = analogRead(A0);

    if (l00 < 1024) {
      tab[l00] = l01 - l00;
      //Serial.print("VAL:");
      //Serial.println(l00);
    }
  }
  digitalWrite(LED, 0);
  long p = 0;
  for (int i = 0; i < 800; i++) {
    if (tab[i] == 0) {
      Serial.println(p);
    }
    else {
      p = tab[i];
      Serial.println(p);
    }
  }

 delay(60000);
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
    l = l0;
  }
  //l0 = l0 / 10;
  //l1 = l1 / 10;
  //l=l/10;

  Serial.println(l0);
  Serial.println(l1);
}
