//Lab 6 Displays
//Author Rino D & Nolan V
//CPE 301

#include <Keypad.h>
#include <SevSeg.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {11,10,9,8};
byte colPins[COLS] = {7,6,5,4};

Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

SevSeg sevseg;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  byte numDigits = 4;

  byte digitPins[] = {30, 31, 32, 33};
  byte segmentPins[] = {29, 22, 23, 25, 26, 28, 27, 24};

  bool resistorsOnSegments = true;
  bool updateWithDelaysIn = true;
  bool disableDecPoint = true;
  bool leadingZeros = false;

  byte hardwareConfig = COMMON_CATHODE;

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelaysIn, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);
}

char displayText[4] = {'0', '0', '0', '0'};

void loop() {

  int numPressed = 0;
  char chooseKey;

//Will continuously attempt to read the numpad until 4 characters have been read and stored in the appropriate character array.
  while(numPressed < 4) {
    chooseKey = myKeypad.getKey();
    if(chooseKey) {
      Serial.println(chooseKey);
      displayText[numPressed] = chooseKey;
      numPressed++;
    }
  }

//Once 4 characters have been read will begin to display the 4 characters for x and amount of time determined by the while loop. 
//The reason delay can't be used in this scenario is that to display content we must use sevseg.refreshDisplay() constatly. 
//Delay ends the program temporily for x amount of time thus not producing an output for the segment display.
//Instead we will count how long the actual program has been running for and determine if x amount of time has passed to end the while loop that currently displays text. 
  if(numPressed = 4) {
    sevseg.setChars(displayText);

    unsigned long startTime = millis();
    unsigned long endTime = startTime;
  
    while ((endTime - startTime) <= 3000) {
      sevseg.refreshDisplay();
      endTime = millis();
    }
  }
}

