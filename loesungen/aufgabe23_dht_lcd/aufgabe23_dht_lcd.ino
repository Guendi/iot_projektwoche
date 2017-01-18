
// include the library code:
#include <Wire.h>
#include <FaBoLCD_PCF8574.h>

#include <DHT.h>

#define DHTPIN 8     // data pin
#define DHTTYPE DHT22   // DHT22
DHT dht(DHTPIN, DHTTYPE);

// initialize I2C LCD library
FaBoLCD_PCF8574 lcd;

const byte STATE_VOLTAGE = 0;
const byte STATE_TEMPERATURE = 1;
const byte STATE_HUMIDITY = 2;

const char* TXT_VOLTAGE = "Spannung";
const char* TXT_TEMPERATURE = "Temperatur";
const char* TXT_HUMIDITY = "Luftfeuchtigkeit";

int pinSpannung = A0;
int pinButton = 7;

float lastValue = 0;
float currentValue = 0;

char* emptyLine = "                ";

int state = STATE_VOLTAGE;

void setup() {
  Serial.begin(9600);
  pinMode(pinButton,INPUT);
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print(TXT_VOLTAGE);
  lcd.setCursor(1,0);
  lastValue = analogRead(pinSpannung)/1023.0*5.0;
  currentValue = lastValue;
  ausgabe(currentValue);
}

/* print routine */
void ausgabe(float value){
  lcd.setCursor(0,0);
  lcd.print(emptyLine);
  lcd.setCursor(0,1);
  lcd.print(emptyLine);
  lcd.setCursor(0,0);
  switch (state){
    case STATE_VOLTAGE:
        lcd.print(TXT_VOLTAGE);
        lcd.setCursor(0,1);
        lcd.print(value);
        lcd.print(" V"); 
        Serial.print(value);
        Serial.println(" V");    
        break;
    case STATE_TEMPERATURE:
        lcd.print(TXT_TEMPERATURE);
        lcd.setCursor(0,1);  
        lcd.print(value);
        lcd.print(" C"); 
        Serial.print(value);
        Serial.println(" C");    
        break;
     case STATE_HUMIDITY:
        lcd.print(TXT_HUMIDITY);
        lcd.setCursor(0,1);
        lcd.print(value);
        lcd.print(" %"); 
        Serial.print(value);
        Serial.println(" %");    
        break;

     default:
        lcd.print("UNGUELTIG"); 
  }

}

void loop() {
  /* take care of state transitions by pushButton */
  if (digitalRead(pinButton)==HIGH){
    Serial.print("State changed: ");
    state = (state+1)%3;
    Serial.println(state);
    delay(300);
  }
  switch (state){
    case STATE_VOLTAGE:
      currentValue = analogRead(pinSpannung)/1023.0*5.0;
      break;
    case STATE_TEMPERATURE:
      currentValue = dht.readTemperature();
      break;
    case STATE_HUMIDITY:
      currentValue = dht.readHumidity();
      break;      
    
  }
  /* finally, print measures in case they changed */
  if (currentValue != lastValue){
    ausgabe(currentValue);
    lastValue=currentValue; 
  }

  delay(100);
}
