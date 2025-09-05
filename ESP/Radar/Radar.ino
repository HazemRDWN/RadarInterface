#include <cmath>
#include <Servo.h>

const int trigPin = D1;
const int echoPin = D2; 

Servo myServo;

void setup() {

  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(D5);

}

float measureDistance(){

  // Trigger the ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);//It was 10 just in case
  digitalWrite(trigPin, LOW);

  // Measure how long the echo pin stays HIGH
  long duration = pulseIn(echoPin, HIGH);

  // Convert duration to distance in cm
  float distance = duration * 0.034 / 2;

  return distance;

} 

void loop() {

  delay(500);
  
  for (int i = 0; i <= 180; i = i + 2){ //Servo motion from 0 to 180 degrees

    delay(60);

    myServo.write(i);

    Serial.print("RDR");
    Serial.print(":");
    Serial.print(measureDistance());
    Serial.print(",");
    Serial.print(i);
    Serial.print("\n");

  }

  delay(500);

  for (int j = 180; j >= 0; j = j - 2){ //Servo motion from 180 back to 0 degrees

    delay(60);

    myServo.write(j);

    Serial.print("RDR");
    Serial.print(":");
    Serial.print(measureDistance());
    Serial.print(",");
    Serial.print(j);
    Serial.print("\n");

  }

}






