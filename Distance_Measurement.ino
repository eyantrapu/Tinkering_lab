#include<LiquidCrystal.h>
const int trigPin = 2;
const int echoPin = 4;
const int potential=A0;
int distance_req;
long cm;
LiquidCrystal lcd(5,6,7,8,9,10);   
void setup() 
  {
    Serial.begin(9600);
    lcd.begin(16,2);
  }
void loop()
  {
    long duration,cm;
    pinMode(potential,INPUT);
    pinMode(11,OUTPUT);
    pinMode(trigPin, OUTPUT);
    distance_req=analogRead(potential);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    cm = microsecondsToCentimeters(duration);
    map(distance_req,0,2230,0,1023);
    Serial.print(distance_req);
    Serial.println("cm");
    Serial.println(cm); 
    lcd.setCursor(0,0);
    lcd.print("DistanceSet:");
    lcd.print(distance_req);
    lcd.print("cm");
    lcd.setCursor(0,1);
    lcd.print("MeasuredVal:");
    lcd.print(cm);
    lcd.print("cm");
    if(cm==distance_req)
      {
        lcd.clear();
        lcd.setCursor(2, 0);
        digitalWrite(11,HIGH);
        lcd.print("It is the required distance.");
        for (int positionCounter = 0; positionCounter < 13; positionCounter++)
          {
            // scroll one position left:
            lcd.scrollDisplayLeft();
            // wait a bit:
            delay(250);
          }
          delay(3000);
          digitalWrite(11,LOW);
          lcd.clear();
      }
      Serial.println();
      delay(1000);
  }
long microsecondsToCentimeters(long microseconds)
  {return microseconds / 29 / 2;}
