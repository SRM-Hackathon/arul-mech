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

Const int sensorMin =0;
Const int sensorMax =1024;
int range;

#include<Servo.h>
int servopin =9;
Servo Servo1;

#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_12C lcd(0 3F,16,2);

int inputPin =2;
Int pinStatus =LOW;
int val=0;

int a;

#include <SoftwareSerial.h>
char msg;
char call;

void setup()
{
  Serial.begin(9600);
  Pin Mode(9,OUTPUT);
  Pin Mode(10,OUTPUT);
  Pin Mode(inputPin,INPUT);
  Pin Mode(trigPin1,OUTPUT);
  Pin Mode(echoPin1,INPUT);
  Pin Mode(trigPin2,OUTPUT);
  Pin Mode(echoPin2,INPUT);
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
      
    }
  }
}
