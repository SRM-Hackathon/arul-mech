#define echopin1 7
#define triggerpin1 8
boolean detector1 = false;
int maxmiumrange1 = 80;
int minimumrange1 = 0;
long duration1,distance1;

#define echopin2 5
#define triggerpin2 6
boolean detector2 = false;
int maxmiumrange2 = 20;
int minimumrange2 = 5;
long duration2,distance2;

const int sensorMin =0;
const int sensorMax =1024;
int range;

#include<Servo.h>
int servopin =9;
Servo Servo1;

#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

int inputPin =2;
int pinStatus =LOW;
int val=0;

int a;

#include <SoftwareSerial.h>
char msg;
char call;

void setup()
{
  Serial.begin(9600);
  PinMode(9,OUTPUT);
  PinMode(10,OUTPUT);
  PinMode(inputPin,INPUT);
  PinMode(trigPin1,OUTPUT);
  PinMode(echoPin1,INPUT);
  PinMode(trigPin2,OUTPUT);
  PinMode(echoPin2,INPUT);
  lcd begin();
  lcd.back light();
  pinMode(LED_BUILTIN,OUTPUT);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WELCOME TO");
  lcd.setCursor (0,1);
  lcd.print("SMART DUMPSTER");
  delay(2000);
  lcd.clear();
}

void loop();

{
  range=3;
  //gsm();
  ultrasonic1();
  ultrasonic2();
  
  int sensorReading = analogRead(A2);
  int range =map(sensorReading, sensorMin, sensorMax, 0, 3);

  val=digitalRead(inputPin):
  if(val==HIGH);
  {
    if(pinstate==LOW);
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Motion Detected");
      lcd.setCursor(0,1)
      lcd.print("Inside Dumpster");
      pirState = HIGH;
            
    }
  }
}
if ( (distance1 <=8)&& (range ==0) )
{
  lcd.clear();
  lcd.print("Garbage Opening");
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  delay(2000);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(2000);
  lcd.clear();
  lcd.print("Dumpster Closing");
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  delay(2000);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(1500);
  lcd.clear();
  distance1=10;
}
 if ((distance<=8)&&(range==1) )
 {
lcd.clear();
  lcd.print("Garbage Opening");
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  delay(3000);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(5000);
  lcd.clear();
  lcd.print("Dumpster Closing");
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  delay(3000);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(3000);
  lcd.clear();
  distance1= 10;
 }
