#include <LiquidCrystal.h>/*Include the library required to run LCD Display.*/

const int buzzer=2;//Set pin D2 for the buzzer.
const int threshold=300;//Set the threshold value for the detection of the alcohol vapours by the mq3 sensor
const int sensor=A0;//Set the analog pin to read the data from mq3 alcohol sensor

LiquidCrystal lcd(12,11,7,6,5,4);//Set the pins of arduino to which the LCD Display is connected.

void setup() {
  /* put your setup code here, to run once:*/
  Serial.begin(9600);     //Begin the Serial Monitor with a particular Baud Rate.
  pinMode(sensor,INPUT);  //Set the analog pin connected to mq3 sensor to Input mode.
  pinMode(buzzer,OUTPUT); //Set the digital pin connected to buzzer to Output mode.
  pinMode(9,OUTPUT);      //Set the PWM pin connected to LCD Display to control the contrast of the display to Output mode.
  analogWrite(9,100);//Set the contrast of the LCD Display.
  lcd.begin(16,2);//Begin the LCD Display specifying the size of the LCD Display.
  lcd.setCursor(0,0);//Set the cursor position to row(0), column(0).
  lcd.print("Threshold : ");//Print "Threshold" in the first line of the display
  lcd.print(300);
  lcd.setCursor(0,1);
  lcd.print("Measured : ");//Print "Measured" in the second line of the display.
}

void loop() {
  /* put your main code here, to run repeatedly:*/
  int a=analogRead(sensor);
  Serial.println(a);
  lcd.setCursor(11,1);
  lcd.print(a);//Print the measured value on the display.
  if(a>threshold) //If the measured value is greater than threshold, ring the buzzer.
  {
    digitalWrite(buzzer,1);
    delay(1000);
  }
 else//Else check the measured value again.
 {
    digitalWrite(buzzer,0);
    delay(1000);
 }
}
