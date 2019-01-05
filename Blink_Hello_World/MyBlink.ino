/*
  My Blink - Hello World

  Last Modified by:
  Anthony Rolfe
  4 January 2019

  This program changes the L LED on your board from the steady on-off to display "Hello World" in
  morse code. The light pulses will follow the guidelines from the International Morse Code as
  found on https://en.wikipedia.org/wiki/Morse_code. This code is based off the example code that
  comes with the boards.

  1. The length of one unit is 150ms.
  2. The length of a dot is one unit.
  3. A dash is three units.
  4. The space between parts of the same letter is one unit. (when the light is off)
  5. The space between letters is three units.
  6. The space between words is seven units.

  My repository for this code is found at https://github.com/H1tman1978/Arduino_fun
*/

// Some constants for configuration. Feel free to adjust as needed.
const int UNIT = 150;
const int END_OF_MESSAGE = 2000;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}


// the dot function displays a dot on the L LED
void dot() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on for a unit
  delay(UNIT);
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off for a unit
  delay(UNIT);
} // End of dot function


// the dash function displays a dash on the L LED
void dash() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on for 3 units
  delay(UNIT * 3);
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off for a unit
  delay(UNIT);
} // End of dash function


// the delay_letter function adds the appropiate delay for after a letter
void delay_letter() {
  delay(UNIT * 2);
}

// the delay_word function adds the appropriate delay for after a word
void delay_word() {
  delay(UNIT * 6);
}


// the end_of_message function adds a delay of 3 seconds for the end of message indication
void end_of_message() {
  delay(END_OF_MESSAGE); //Value is in milliseconds or in this case, a two second pause.
}


// the loop function runs over and over again forever
void loop() {
  //display the "H" - Dot - Dot - Dot - Dot
  for (int i = 0; i < 4; i++) {
    dot();
  } // End of "H" Loop
  delay_letter();

  // display the "E" - Dot
  dot();
  delay_letter();

  // display the "L" Dot - Dash - Dot - Dot
  dot();
  dash();
  dot();
  dot();
  delay_letter();

  // display the "L" Dot - Dash - Dot - Dot
  dot();
  dash();
  dot();
  dot();
  delay_letter();

  // display the "O" Dash - Dash - Dash
  for (int i = 0; i < 3; i++) {
    dash();
  } // End of "O" Loop
  delay_word();

  // display the "W" Dot - Dash - Dash
  dot();
  dash();
  dash();
  delay_letter();

  // display the "O" Dash - Dash - Dash
  for (int i = 0; i < 3; i++) {
    dash();
  } // End of "O" Loop
  delay_letter();

  // display the "R" Dot - Dash - Dot
  dot();
  dash();
  dot();

  // display the "L" Dot - Dash - Dot - Dot
  dot();
  dash();
  dot();
  dot();

  // display the "D" Dash - Dot - Dot
  dash();
  dot();
  dot();

  end_of_message();
}// End Loop Function
