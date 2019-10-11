#define echopin1 7
#define triggerpin1 8
boolean detector1 = false;
int maxmiumrange1 = 200;
int minimumrange1 = 0;
long duration1,distance1;

#define echopin2 5
#define trigpin2 6
boolean detector2 = false;
int maxmiumrange2 = 200;
int minimumrange2 = 5;
long duration2,distance2;

const int sensorMin=0;
const int sensorMax=2024;
int range;

#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

int inputPin =2;
int pinState =LOW;
int val = 0;

int a;

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
  lcd.backlight();
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
      delay(2000);
      SendMessage2();
      lcd.clear();      
    }
  }
else 
{
  pirStatus=LOW;
 
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
 if ((distance1 <=8) )
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
  }
  if ((distance2 >=100) )
 {
  lcd.clear();
  lcd.print("Garbage Full");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  SendMessage1();
  lcd.clear();
  }
  delay(800);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Trash Level");
  if(distance2 <=99)
  {
  lcd.setCursor(12,0);
  lcd.print(distance2);
  lcd.setCursor(14,0);
  lcd.print("%");
  }
  if(distance2 >=99)
  {
  lcd.setCursor(12,0);
  lcd.print("Full");
  }
  if(range==0)
  {
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Raining");
  delay(1000);
  lcd.clear();  
  }
  if(range==1)
  {
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Rain Warning");
  delay(1000);
  lcd.clear();
  }
  
  void ultrasonic1()
  {
  detect1=0;
  digitalWrite(trigpin1,LOW);
  delayMicroseconds(2);
   digitalWrite(trigpin1,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigpin1,LOW);
  duration1=pulseIn(echopin1,HIGH);
  distance1=duration1/58.2;
  }
  
  void ultrasonic2()
  {
  detect2=0;
  digitalWrite(trigpin2,LOW);
  delayMicroseconds(2);
   digitalWrite(trigpin2,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigpin2,LOW);
  duration2=pulseIn(echopin2,HIGH);
  distance2=duration2/58.2;
  if(distance2>=51)
  {
    distance2=50;
  }
  distance2=map(distance2,3,50,100,0);
  }

  void rainsensor()
  {
  int sensorReading=analogRead(A2);
  int range=map(sensorReading,sensorMin,sensorMax,0,3);
  switch(range)
  {
    
    case 0: Sensor getting wet
            Serial.println("Raining");
    break;
     
    case 1: sensor getting wet
            Serial.println("Rain Warning");

    case 2: sensor dry
            Serial.println("Not Raining");
  }
  delay(1);
  }
   void lcddisplay()
   {
    lcdprint("Hello");
   }
  void motionsensor()
  { 
    val=digitalRead(inputPin);
    if(val==HIGH)
   {
    if(pirState==LOW);
    {
      
    pirState=HIGH;
    }
   }
   
  
   

  
