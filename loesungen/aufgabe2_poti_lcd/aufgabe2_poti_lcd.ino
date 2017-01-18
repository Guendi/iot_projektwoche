
// include the library code:
#include <Wire.h>
#include <FaBoLCD_PCF8574.h>

// initialize the library
FaBoLCD_PCF8574 lcd;

int pinSpannung = A0;

int lastValue = 0;
int currentValue = 0;

char* emptyLine = "                ";

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Spannungsmessung");
  lcd.setCursor(1,0);
  lastValue = analogRead(pinSpannung);
  currentValue = lastValue;
  ausgabe(currentValue);
}

void ausgabe(int value){
  float voltage = value / 1023.0 * 5.0;
  lcd.setCursor(0,1);  
  lcd.print(emptyLine);
  lcd.setCursor(0,1);
  lcd.print(voltage);
  lcd.print(" V"); 
  Serial.print(voltage);
  Serial.println(" V");
}

void loop() {
  // put your main code here, to run repeatedly:
  currentValue = analogRead(pinSpannung);
  if (currentValue != lastValue){
    ausgabe(currentValue);
    lastValue=currentValue;
    
  }
  delay(100);
}
