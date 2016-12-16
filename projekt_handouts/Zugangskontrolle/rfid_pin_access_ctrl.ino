/*
 *  
 * Typical pin layout used for RFID reader:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 * 
 * Sven: reads id of RFID card followed by a pin entered via foil keyboard
 *
 */

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
#include <Key.h>
#include <Keypad.h>

//RFID PINS
#define RST_PIN         22          // Configurable, see typical pin layout above
#define SS_PIN          53         // Configurable, see typical pin layout above

//STATUS PINS
#define LED_AVAILABLE   30
#define LED_OCCUPY      31

/* initialize the library with the numbers of the interface pins */
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

/* keypad setup */
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Three columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'D','C','B','A'},
  {'#','9','6','3'},
  {'0','8','5','2'},
  {'*','7','4','1'}
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 34, 36, 38, 40 };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 35, 37, 39, 41 }; 

// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
/* end keypad setup */

/* display messages */
const char* msg =               "Access control  ";
const char* msg_stage1 =        "Show card       ";
const char* msg_stage2 =        "Enter pin, send#";
const char* msg_acc_denied =    "Access denied   ";
const char* msg_acc_granted =   "Access granted  ";
const char* emptyLine =         "                ";
char* pinInput =                "                ";

byte nPinInput = 0;
String serverResponse="   ";
/*
 * stage variable stores mc stage:
 * 0: waiting for rfid card
 * 1: rfid read, waiting for pin
 * 2: pin input (until # to send)
 * 3: waiting for server response
 * 4: unlock door (for 5 seconds or so) --> back to 0
 * 5: access denied message (for 5 seconds or so) --> back to 0
 */
int stage = 0;

/* Init array that will store rfid id */
byte rfid_uid[4];

// Create MFRC522 instance
MFRC522 mfrc522(SS_PIN, RST_PIN);  


void setup() {
  pinMode(LED_AVAILABLE, OUTPUT);
  pinMode(LED_OCCUPY, OUTPUT);
  stage = 0;
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print(msg);
  
	Serial.begin(115200);		// Initialize serial communications with the PC
	while (!Serial);		// Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  lcd.print("Serial set up");
	SPI.begin();			// Init SPI bus
  lcd.setCursor(0, 1);
  lcd.print("SPI set up");
  delay(500);
	mfrc522.PCD_Init();		// Init MFRC522
	//mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
  lcd.setCursor(0, 1);
  lcd.write(emptyLine);
  delay(100);
  lcd.setCursor(0, 1);
  lcd.print(msg_stage1);

  serverResponse.reserve(50);
	//Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
 loop();
} //END SETUP

void loop() {
  digitalWrite(LED_OCCUPY, LOW);
  digitalWrite(LED_AVAILABLE, LOW);
  
  /* waiting for rfid card */
  if (stage==0){
    readRfid();
  } 
  /* handling pin input via keypad */
  else if (stage==1){
    handleKeypad();
  }

  else if (stage == 3){
    while(Serial.available() && nPinInput<50){
      char inKey=(char)Serial.read();
      if (inKey !='\n'){
        serverResponse+=inKey;
        nPinInput++;
      }
      else break;
    }
    if (nPinInput > 2){
      /*lcd.setCursor(0,1);
      serverResponse.toCharArray(pinInput, nPinInput);
      for (byte i=0; i < nPinInput; i++)
          lcd.write(pinInput[i]);
      lcd.write(": ");
      lcd.write(nPinInput);*/
      lcd.setCursor(0,1);
      
      delay(3000);      
      lcd.write(emptyLine);
      lcd.setCursor(0,1);
      if (serverResponse.substring(3).compareTo("OK ")==0){
          lcd.write(msg_acc_granted);  
          digitalWrite(LED_OCCUPY, LOW);
          digitalWrite(LED_AVAILABLE, HIGH);
                    
      }
      else {
        lcd.write(msg_acc_denied);
          digitalWrite(LED_OCCUPY, HIGH);
          digitalWrite(LED_AVAILABLE, LOW);
      }
      stage = 0;
      nPinInput=0;
      delay(3000);
      lcd.setCursor(0, 1);
      lcd.print(msg_stage1);
    }
  }
} // END loop()

void readRfid(){
    // Look for new cards
    if ( ! mfrc522.PICC_IsNewCardPresent()) {
      return;
    }
  
    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial()) {
      return;
    }
    lcd.setCursor(0, 1);
    lcd.write("                ");
    lcd.setCursor(0, 1);
    // Dump debug info about the card; PICC_HaltA() is automatically called
    //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
    // Store NUID into nuidPICC array
    for (int i = 0; i <= mfrc522.uid.size; i++) {
      rfid_uid[i] = mfrc522.uid.uidByte[i];
    }
    printHex(rfid_uid,mfrc522.uid.size);
    delay(0.5);
    lcd.setCursor(0, 1);
    lcd.write("Please enter pin");
    lcd.setCursor(0, 1);
        
    stage = 1;
}

/* handling pin input via keypad */
void handleKeypad(){
      char key = kpd.getKey();
      /* input state, collect and append */
      if(key && nPinInput < 16 && key != '#' && key != 'C')  // Check for a valid key.
      {
        if (nPinInput==0){ //clear display with first input
          lcd.setCursor(0, 1);
          lcd.write(emptyLine);
          lcd.setCursor(0, 1);
          delay(100);
        }
        /* gather input */ 
        pinInput[nPinInput]=key; 
        /* display input, mask previous input */ 
        if (nPinInput>0){
          lcd.setCursor(nPinInput-1,1);
          lcd.write('*');
        }
        lcd.write(key);
        nPinInput++;
      } 
      /* #-button sends both rfid and pin */
      else if (key == '#'){       
        sendRequest();
      } 
      /* C-button allows deletion of last input */
      else if (key=='C' && nPinInput>0){
        nPinInput--;
        lcd.setCursor(nPinInput,1);
        lcd.write(' ');
        nPinInput=0;
        pinInput="               ";
      }
      /* take care of overflows */ 
      if (nPinInput >= 16){
        stage = 0;
        nPinInput=0;
        lcd.setCursor(0, 0);
        lcd.print(msg_stage1);
        delay(100);
        lcd.setCursor(0,1);
        delay(100);
        lcd.print(emptyLine);
        delay(100);
        lcd.setCursor(0, 1);
        lcd.print(msg_stage1);
      }
  
}

/* cleanup serial */
void cleanupSerial(){
   while(Serial.available()){
      Serial.read();
   }
}

/* sends both rfid and pin for authentication */
void sendRequest(){
  cleanupSerial();
  Serial.println("Login request");
  for (byte i=0; i < 4; i++){
    Serial.print(rfid_uid[i],HEX);
    Serial.print(' ');
  }
  Serial.println();
  for ( byte i=0; i < nPinInput;i++)
    Serial.print(pinInput[i]);
  lcd.setCursor(0, 1);delay(100);
  lcd.write("Wait for access");
  nPinInput=0;
  stage=3;
}

bool checkUidAtServer(byte* uid, byte size){
  for (byte i=0; i < size;i++){
    Serial.print(uid[i] < 0x10 ? " 0" : " ");
    Serial.print(uid[i], HEX);
  }
  byte response = NULL;
  for (int i = 0; i < 100 && response==NULL; i++){
    delay(300);
    digitalWrite(LED_OCCUPY, LOW);
    if (Serial.available() == 1){
      response = Serial.read();
      lcd.setCursor(0, 1);
      lcd.write("Server:          ");
      lcd.setCursor(8, 1);
          
      delay(300);
        if (response='1'){
          lcd.write("OK");
          delay(2000);
          return true;
        }
        else{
          lcd.write("NOK");
          delay(2000);        
          return false;
        }    
      }
  
    }
    lcd.setCursor(0, 1);
    lcd.write("No server response");  
    delay(3000);
    digitalWrite(LED_OCCUPY, HIGH);  return false;
}


/**
 * Helper routine to dump a byte array as hex values to Serial. 
 */
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    lcd.print(buffer[i] < 0x10 ? " 0" : " ");
    lcd.print(buffer[i], HEX);
  }
}
