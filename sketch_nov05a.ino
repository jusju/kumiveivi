
// VALITUS 1:15 VEIVI

// Include the libraries:
// LiquidCrystal_I2C.h: https://github.com/johnrickman/LiquidCrystal_I2C
#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for 

// Wiring: SDA pin is connected to A4 and SCL pin to A5.
// Connect to LCD via I2C, default address 0x27 (A0-A2 not jumpered)
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Change to (0x27,16,2) for 16x2 LCD.
int rotations = 0;

void setup() {
    // Initiate the LCD:
  lcd.init();
  lcd.backlight();
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(11, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  // Print 'Hello World!' on the first line of the LCD:
  lcd.setCursor(0, 0); // Set the cursor on the first column and first row.
  lcd.print(rotations);
  lcd.setCursor(1, 1); //Set the cursor on the third column and the second row (counting starts at 0!).
  lcd.print("VEIVI JUSLIN V2");

  
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(11);
  //print out the value of the pushbutton
  Serial.println(sensorVal);
  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
    rotations = rotations + 15;
  }
  delay(20);
}
