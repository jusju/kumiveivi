
// RATIO OF WINDER 1:15

// Include the libraries:
// LiquidCrystal_I2C.h: https://github.com/johnrickman/LiquidCrystal_I2C
#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for 

// Wiring: SDA pin is connected to A4 and SCL pin to A5.
// Connect to LCD via I2C, default address 0x27 (A0-A2 not jumpered)
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Change to (0x27,16,2) for 16x2 LCD.
int rotations = -15;

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 11;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers


void setup() {
  // Initiate the LCD:
  lcd.init();
  lcd.backlight();
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop() {
  // Print 'Hello World!' on the first line of the LCD:
  
  int reading = digitalRead(buttonPin);

  // Serial.println(reading);

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

      //rotations = rotations + 15;
            // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
           Serial.println("TSANKE");   


      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        rotations = rotations + 15;
        Serial.println("WE ARE HAVING A STATE CHANGE!");
        lcd.setCursor(0, 0); // Set the cursor on the first column and first row.
        lcd.print(rotations);
        lcd.setCursor(1, 1); //Set the cursor on the third column and the second row (counting starts at 0!).
        lcd.print("VEIVI JUSLIN V2");

        
        //Serial.println(reading);        
        ledState = !ledState;
      }
    }
  }
  lastButtonState = reading;
  
}
