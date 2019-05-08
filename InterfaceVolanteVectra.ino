#define between(x, a, b)  (((a) <= (x)) && ((x) <= (b)))

const int analogInPin = A6;

#define VolMais 2 // 646
#define VolMenos 3  // 475
#define Mute 4 // 962
#define Source 5 // 767
#define Prev 6  //914
#define Next 7 // 852



int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  digitalWrite(VolMais, OUTPUT);
  digitalWrite(VolMenos, OUTPUT);
  digitalWrite(Mute, OUTPUT);
  digitalWrite(Source, OUTPUT);
  digitalWrite(Prev, OUTPUT);
  digitalWrite(Next, OUTPUT);

  digitalWrite(VolMais, LOW);
  digitalWrite(VolMenos, LOW);
  digitalWrite(Mute, LOW);
  digitalWrite(Source, LOW);
  digitalWrite(Prev, LOW);
  digitalWrite(Next, LOW);
  
}

void loop() {
  sensorValue = analogRead(analogInPin);

  // VOLUME MAIS
  if( between(sensorValue, 637, 653) ){
    digitalWrite(VolMenos, HIGH);
    delay(30);
    digitalWrite(VolMais, HIGH);
    delay(30);
    digitalWrite(VolMenos, LOW);
    delay(30);
    digitalWrite(VolMais, LOW);
    delay(30);
    delay(200);
  }

  // VOLUME MENOS
  if( between(sensorValue, 467, 483) ){
    digitalWrite(VolMais, HIGH);
    delay(30);
    digitalWrite(VolMenos, HIGH);
    delay(30);
    digitalWrite(VolMais, LOW);
    delay(30);
    digitalWrite(VolMenos, LOW);
    delay(30);
    delay(200);
  }

  // SOURCE
  if( between(sensorValue, 760, 777) ){
    digitalWrite(Source, HIGH);
    delay(100);
    digitalWrite(Source, LOW);
    delay(50);
  }

  // MUTE
  if( between(sensorValue, 957, 974) ){
    digitalWrite(Mute, HIGH);
    delay(100);
    digitalWrite(Mute, LOW);
    delay(50);
  }

  // NEXT
  if( between(sensorValue, 846, 858) ){
    digitalWrite(Next, HIGH);
    delay(100);
    digitalWrite(Next, LOW);
    delay(50);
  }

  // PREV
  if( between(sensorValue, 907, 922) ){
    digitalWrite(Prev, HIGH);
    delay(100);
    digitalWrite(Prev, LOW);
    delay(50);
  }

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.println(sensorValue);

  delay(2);
}
