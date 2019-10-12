#define echopin1 7
#define trigpin1 8
boolean detector1 = false;
int maximumrange1 = 200;
int minimumrange1 = 0;
long duration1, distance1;

#define echopin2 5
#define trigpin2 6
boolean detector2 = false;
int maximumrange2 = 200;
int minimumrange2 = 0;
long duration2, distance2;

const int sensorMin = 0;     
const int sensorMax = 1024; 
int range;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

int inputPin = 2;               
int pirState = LOW;            
int val = 0;                   

int a;

#include <SoftwareSerial.h>
SoftwareSerial mySerial(11, 12);
char msg;
char call;

void setup()
{
  Serial.begin(9600);
  Serial.begin(9600);
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(inputPin, INPUT); 
  pinMode(trigpin1, OUTPUT);
  pinMode(echopin1, INPUT); 
  pinMode(trigpin2, OUTPUT);
  pinMode(echopin2, INPUT);
 
  
  lcd.begin();
  lcd.backlight();
  pinMode(LED_BUILTIN, OUTPUT); 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WELCOME TO");
  lcd.setCursor(0, 1);
  lcd.print("SMART DUMPSTER");
  delay(2000);
  lcd.clear();
}

void loop()
{
  range = 3;
  ultrasonic1();
  ultrasonic2();
 
  int sensorReading = analogRead(A2);
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  
  val = digitalRead(inputPin);  
  if (val == HIGH)
  {
    if (pirState == LOW)
    {
      //Serial.println("Motion detected!");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("MOTION DETECTED");
      lcd.setCursor(0, 1);
      lcd.print("INSIDE DUMBSTER");
      pirState = HIGH;
      delay(2000);
      SendMessage2();
      lcd.clear();
    }
  }
  else
  {
    if (pirState == HIGH)
    {
      pirState = LOW;
    }
  }
  
  if (  ( distance1 <= 8 ) &&  ( range == 0)   )
  {
    lcd.clear();
    lcd.print("DUMPSTER OPENING");
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(9, HIGH); 
    digitalWrite(10, LOW);
    delay(2000);
    digitalWrite(9, LOW); 
    digitalWrite(10, LOW);
    delay(2000);
    lcd.clear();
    lcd.print("DUMPSTER CLOSING");
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    delay(2000);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(1500);
    lcd.clear();
    distance1 = 10;
  }

  if (  ( distance1 <= 8 ) &&  ( range == 1)  )
  {
    lcd.clear();
    lcd.print("DUMPSTER OPENING");
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(9, HIGH); 
    digitalWrite(10, LOW);
    delay(3000);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(5000);
    lcd.clear();
    lcd.print("DUMPSTER CLOSING");
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(9, LOW); 
    digitalWrite(10, HIGH);
    delay(3000);
    digitalWrite(9, LOW); 
    digitalWrite(10, LOW);
    delay(3000);
    lcd.clear();
    distance1 = 10;
  }

  if (  ( distance1 <= 8 )  )
  {
    lcd.clear();
    lcd.print("DUMPSTER OPENING");
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(9, HIGH); 
    digitalWrite(10, LOW);
    delay(3000);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(5000);
    lcd.clear();
    lcd.print("DUMPSTER CLOSING");
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(9, LOW); 
    digitalWrite(10, HIGH);
    delay(3000);
    digitalWrite(9, LOW); 
    digitalWrite(10, LOW);
    delay(3000);
    lcd.clear();
  }

 
  if ( distance2 >= 100 )
  {
    lcd.clear();
    lcd.print("DUMPSTER FULL");
    delay(2000);
    SendMessage1();
    lcd.clear();
  }
  
  else
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    
    lcd.print("TRASH LEVEL-");
    if (distance2 <= 99)
    {
      lcd.setCursor(12, 0);
      lcd.print(distance2);
      lcd.setCursor(14, 0);
      lcd.print("%");
    }
    if (distance2 >= 99)
    {
      lcd.setCursor(12, 0);
      lcd.print("FULL");
    }
    
  }

  if ( range == 0)
  {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("RAINING");
    delay(1000);
    //range = 2;
    lcd.clear();
  }
  if ( range == 1)
  {
    //Serial.println("RAIN WARNING");
    //range = 3;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("RAIN WARNING");
    delay(1000);
    lcd.clear();
  }
}

void ultrasonic1()
{
  detector1 = 0;
  digitalWrite(trigpin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin1, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigpin1, LOW);
  duration1 = pulseIn(echopin1, HIGH); 
  distance1 = duration1 / 58.2; 
}

void ultrasonic2()
{
  detector2 = 0;
  digitalWrite(trigpin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin2, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigpin2, LOW);
  duration2 = pulseIn(echopin2, HIGH); 
  distance2 = duration2 / 58.2; 
  if ( distance2 >= 51)
  {
    distance2 = 50;
  }
  distance2 = map(distance2, 3, 50, 100, 0);
}
 void rainsensor()
{
  int sensorReading = analogRead(A2);
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  switch (range)
  {
    case 0:  // Sensor getting wet
              //Serial.println("Raining");
      break;
    case 1:    // Sensor getting wet
               //Serial.println("Rain Warning");
      break;
    case 2:    // Sensor dry - To shut this up delete the " Serial.println("Not Raining"); " below.
               //0Serial.println("Not Raining");
      break;
  }
  delay(1); 
}

void lcddisplay()
{
  lcd.print("Hello");
}

void motionsensor()
{
  val = digitalRead(inputPin);  
  if (val == HIGH)
  { 
    if (pirState == LOW)
    {
      
      pirState = HIGH;
    }
  }
  else
  {
    if (pirState == HIGH)
    {
      pirState = LOW;
    }
  }
}

void waitMilliseconds(uint16_t msWait)
{
  uint32_t start = millis();
  while ((millis() - start) < msWait)
  {
    delay(1);
  }
}

void SendMessage1()
{
  Serial.println("AT+CMGF=1");    
  delay(1000);  
  Serial.println("AT+CMGS=\"+918610360497\"\r"); 
  delay(1000);
  Serial.println("DUMPSTER FULL COME AND CLEAN AT SRM");
  delay(100);
  Serial.println((char)26);
  delay(1000);
}

void SendMessage2()
{
   Serial.println("AT+CMGF=1");    
  delay(1000);  
  Serial.println("AT+CMGS=\"+918610360497\"\r"); 
  delay(1000);
  Serial.println("MOTION DETECTED INSIDE GARBAGE AT SRM");
  delay(100);
 
  Serial.println((char)26);
  delay(1000);
  
}
