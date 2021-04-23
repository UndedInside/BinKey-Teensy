#include <stdio.h>
void setup() {
  // init key pins
  pinMode(20, INPUT_PULLUP);    // 0 key
  pinMode(21, INPUT_PULLUP);    // 1 key
  pinMode(22, INPUT_PULLUP);    // backspace key

  // debug LED
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  int charInt;
  // loop until full byte
  for (int count = 0; count < 9; count++) {
    // sets value of the first bit to 128
    int bitValue = 128;
    charInt = 0;
    
    // key logic
    if (digitalRead(20) == LOW) {
      // 0 pressed
      // do nothing
    }
      else if (digitalRead(21) == LOW) {
      // 1 pressed
      // add the current value of the bit to the total
      charInt = charInt + bitValue;
    }
      else if (digitalRead(22) == LOW) {
      // backspace pressed
      // reduce count to go back a bit
      count --;
      // increase the value of the current bit
      bitValue = bitValue * 2;
    }
    bitValue = bitValue / 2;
  }
  digitalWrite(13, HIGH);
  // converts int to char and types it
  char toType = charInt;
  Keyboard.print(toType);
  delay(500);
  digitalWrite(13, LOW);
}
