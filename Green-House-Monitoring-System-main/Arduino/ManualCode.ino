#include <Arduino.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>
#define MOSFET 2
#define DHT_SENSOR 3 
#define REDLED 4
#define FAN 7
#define HEATER 8
#define LIGHT 9
#define MOISTURE A1
#define LDR A6

unsigned long PreviousTime=0;
const unsigned long Interval=1000;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //reference : https://educ8s.tv/arduino-20x4-character-lcd/
dht DHT;  //reference: https://www.brainy-bits.com/post/how-to-use-the-dht11-temperature-and-humidity-sensor-with-an-arduino

/* ----- setup --------- */

void setup() {
  
  Serial.begin(9600);
  lcd.begin(20,4);
  pinMode(REDLED,OUTPUT); 
  pinMode(FAN,OUTPUT);
  pinMode(HEATER,OUTPUT);
  pinMode(LIGHT,OUTPUT);
  pinMode(MOSFET,OUTPUT);
  digitalWrite(MOSFET,LOW); //initially keep PUMP off
  digitalWrite(REDLED, LOW); //initially keep REDLED off
  digitalWrite(HEATER,HIGH); //initially keep HEATER off
  digitalWrite(LIGHT,HIGH);  //initially keep LIGHT off
}

/* ---- loop -------- */
void loop() {
  DHT.read11(DHT_SENSOR);
  lcd.setCursor(1,0);
  lcd.print("EECS MAJOR PROJECT");
  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.setCursor(5,1);
  lcd.print(DHT.temperature);
  lcd.setCursor(7,1);
  lcd.print((char)223);
  lcd.setCursor(8,1); 
  lcd.print("C ");
  lcd.setCursor(11,1); 
  lcd.print("Humid:");
  lcd.setCursor(17,1);
  lcd.print(DHT.humidity);
  lcd.setCursor(19,1);
  lcd.print("%  ");
  lcd.setCursor(0,2);
  lcd.print("Fan:");
  lcd.setCursor(11,2);
  lcd.print("Light:");
  lcd.setCursor(0,3);
  lcd.print("Heater:");
  lcd.setCursor(11,3);
  lcd.print("PUMP:");
  
  unsigned long CurrentTime=millis();
  if(CurrentTime-PreviousTime>=Interval){
       SendMoistureData();         //reference:https://www.programmingelectronics.com/arduino-sketch-with-millis-instead-of-delay/
       PreviousTime=CurrentTime;
       }
  if (!Serial.available()) {
    return;
    }
    const auto receivedData = Serial.read();
    // format the data
    char buf[16];
    sprintf(buf, "%03d  ", receivedData);
    if(receivedData==50){
        digitalWrite(MOSFET,HIGH);
        digitalWrite(REDLED, HIGH);
        lcd.setCursor(16,3);
        lcd.print("ON ");
        }
      else if(receivedData==100){
        digitalWrite(FAN,HIGH);
        digitalWrite(HEATER,HIGH);
        lcd.setCursor(4,2);
        lcd.print("ON ");
        lcd.setCursor(7,3);
        lcd.print("OFF");
        }
      else if(receivedData==150){
        digitalWrite(HEATER,LOW);
        digitalWrite(FAN,LOW);
        lcd.setCursor(4,2);
        lcd.print("OFF");
        lcd.setCursor(7,3);
        lcd.print("ON ");
        } 
      else if(receivedData==200){
        digitalWrite(LIGHT,LOW);
        lcd.setCursor(17,2);
        lcd.print("ON ");
        }  
     else{
       digitalWrite(MOSFET,LOW);
       digitalWrite(REDLED, LOW);
       lcd.setCursor(16,3);
       lcd.print("OFF");
       digitalWrite(HEATER,HIGH);
       digitalWrite(FAN,LOW); 
       lcd.setCursor(4,2);
       lcd.print("OFF");
       lcd.setCursor(7,3);
       lcd.print("OFF");
       digitalWrite(LIGHT,HIGH);
       lcd.setCursor(17,2);
       lcd.print("OFF");
      }
}

void SendMoistureData() {
  const auto value = analogRead(A1);
  const byte data[] = {0, 0, highByte(value), lowByte(value)};
  Serial.write(data, 4); // send 0,0, "high byte", "low byte"
  Serial.println(); // send "newline"
}
