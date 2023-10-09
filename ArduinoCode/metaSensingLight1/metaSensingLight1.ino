#define LED 4

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);

}




void loop() {

  long l0 = 0;
  long l1 = 0;
  long l2 = 0;
  for (int i = 0; i < 10; i++) {
    digitalWrite(LED, 0);
    delayMicroseconds(1000);
    long l00 = analogRead(A0);
    long l10 = analogRead(A1);
    long l20 = analogRead(A2);
    digitalWrite(LED, 1);
    delayMicroseconds(1000);
    long l01 = analogRead(A0);
    long l11 = analogRead(A1);
    long l21 = analogRead(A2);

    l01 = l01 - l00;
    l11 = l11 - l10;
    l21 = l21 - l20;

    // compansate for saturation
    double c0 = l00*(-0.00115)+1;
    double c1 = l10*(-0.00115)+1;
    double c2 = l20*(-0.00115)+1;

    //c0=c0*1000;
    c0=c0<0.05?0.05:c0;
    c1=c1<0.05?0.05:c1;
    c2=c2<0.05?0.05:c2;

    l0 +=((double)l01)/c0;
    l1 +=((double)l11)/c1;
    l2 +=((double)l21)/c2;

    
  }
  l0 = l0 / 10;
  l1 = l1 / 10;
  l2 = l2 / 10;

  double l=0;

  if(l0>l2){
    l=1+double((l0-l1))/double((l0+l1));
  }
  else{
    l=(-1)+double((l1-l2))/double((l1+l2));
  }

  
  
  Serial.println(l);

}
