#define LED 4

//char tab[500];
//char tabAv[500];
//bool r;
void setup() {
  // put your setup code here, to run once:
  //pinMode(A0, INPUT);
  //pinMode(A1, INPUT);
  //pinMode(A2, INPUT);
  //pinMode(LED, OUTPUT);
  Serial.begin(9600);
  delay(1000);
  Serial.println(10);
  //for (int i = 0; i < 500; i++) {
//    tab[i] = 0;
//    tabAv[i] = 0;
  //}
 // r = true;

}





void loop() {
  
 /* if (r) {
    Serial.println("start messuring");
    for (long times = 0; times < 500; times++) {

      long l0 = 0;
      digitalWrite(LED, 0);
      delayMicroseconds(1000);
      long l00 = analogRead(A0);
      digitalWrite(LED, 1);
      delayMicroseconds(1000);
      long l01 = analogRead(A0);

      if (l00 < 500) {
       // tab[l00] += l01 - l00;
        //tabAv[l00]++;
        Serial.println(l00);
      }
    }
    digitalWrite(LED, 0);
    long p = 0;
    for (int i = 0; i < 500; i++) {
     // if (tabAv[i] == 0) {
        //Serial.println(p);
      //}
      //else {
       // p = tab[i] / tabAv[i];
        //Serial.println(p);
      //}
    }
    r = false;

  }*/
}
