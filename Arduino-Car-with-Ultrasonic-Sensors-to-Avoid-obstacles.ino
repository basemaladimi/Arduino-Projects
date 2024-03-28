int trigPins[] = {13, 11, 9};
int echoPins[] = {12, 10, 8};
int travleTimes[3];
float distances[3];

int EnA = 3;
int in1 = 2;
int in2 = 4;
int EnB = 5;
int in3 = 6;
int in4 = 7;
int speed = 130;

void setup() {
  for (int i = 0; i < 3; ++i) {
    pinMode(trigPins[i], OUTPUT);
    pinMode(echoPins[i], INPUT);
  }
  pinMode(EnA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ultarsonic(trigPins, echoPins, travleTimes, distances, 3);
  Serial.println("dis1 " + String(distances[0]) + " dis2 " + String(distances[1]) + " dis3 " + String(distances[2]));
  
  if (distances[0] < 25) {
  if (distances[1] > 15 && distances[2] > 15) {
    left();
    delay(680);
  }
  if (distances[2] < 15) {
    left();
    delay(680);
    }
  if(distances[1] < 15) {
    right();
    delay(680);
    }
  } else if (distances[1] < 8 && distances[2] < 8) {
  back();
  delay(680);
} 
else {
  front();
}

 
}


void ultarsonic(const int trig[], const int echo[], int travleTime[], float dis[], int numSensors) {
  for (int i = 0; i < numSensors; ++i) {
    digitalWrite(trig[i], LOW);
    delayMicroseconds(10);
    digitalWrite(trig[i], HIGH);
    delayMicroseconds(10); 
    digitalWrite(trig[i], LOW);
    travleTime[i] = pulseIn(echo[i], HIGH, 20000);
    dis[i] = (17.907 * travleTime[i]) / 1000;
  }
}
void left(){
  analogWrite(EnA, speed);
  analogWrite(EnB, speed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void right(){
  analogWrite(EnA, speed);
  analogWrite(EnB, speed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void back(){
  analogWrite(EnA, speed);
  analogWrite(EnB, speed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void front(){
  analogWrite(EnA, speed);
  analogWrite(EnB, speed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void stop(){
  analogWrite(EnA, speed);
  analogWrite(EnB, speed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}