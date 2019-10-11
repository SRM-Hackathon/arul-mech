#define echopin1
#define triggerpin1
boolean detector1= false;
int maxmium range1= 80;
int minimum range1= 5;
long duration1,distance1;

#define echopin2
#define triggerpin2
boolean detector2= false;
int maxmium range2= 20;
int minimum range2= 5;
long duration2,distance2;

Const int sensorMin=0;
Const int sensorMax=1024;
int range;

#include<Servo.h>
int servopin=9;
Servo Servo1;

#include<Wire.h>
#include<LiquidCrystal_12C.h>
LiquidCrystal_12C lcd(0x3F,16,2);

int inputPin=2;
Int pinStatus=LOW;
int val=0;

int a;

#include <SoftwareSerial.h>
char msg;
char call;

void setup()
{
  Serial.begin(9600);
  Pin Mode(9,OUTPUT);
  Pin Mode(9,OUTPUT);
  Pin Mode(9,OUTPUT);
  Pin Mode(9,OUTPUT);
  
}
