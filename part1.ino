#include <LiquidCrystal.h>

#include <Ultrasonic.h>


const int trig = 12;
const int echo = 13;
const int inter_time = 1000;
int time = 0;
LiquidCrystal lcd(11, 10, 5, 4, 3, 2);
void setup() {
  Serial.begin(9600);
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
}

void loop() {
  
   
  float duration, distance;
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);
  duration = pulseIn (echo, HIGH);
  distance = (duration/2)/29;
  lcd.write("Data:");
    lcd.print(distance);
    lcd.write(" cm");
  time = time + inter_time;
  delay(inter_time);\
   lcd.clear();
  delay(100); 
}

