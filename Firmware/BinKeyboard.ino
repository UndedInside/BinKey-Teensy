#include <stdio.h>
#include <Bounce.h>

// BinKey v1.1
// Author: UndedInside
// Date modified 25/12/2022

Bounce keyBack = Bounce(20, 5);    // backspace key
Bounce key0 = Bounce(21, 5);       // 0 key
Bounce key1 = Bounce(22, 5);       // 1 key

int count = 0;         // Counts how many bits have been entered
int byteValue = 0;     // Stores current byte value
int bitValue = 128;    // Stores value of current bit

void setup() {
  // init key pins
  pinMode(20, INPUT_PULLUP);    // backspace key
  pinMode(21, INPUT_PULLUP);    // 0 key
  pinMode(22, INPUT_PULLUP);    // 1 key

  // debug LED
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  
  // Debug LED flashes morse 'OK' when setup is complete
  // O
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(125);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(125);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);

  delay(250);

  // K
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(125);
  digitalWrite(13, HIGH);
  delay(125);
  digitalWrite(13, LOW);
  delay(125);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
}

void loop() {
  // Update keys to detect changes
  key0.update();
  key1.update();
  keyBack.update();

  if (key0.fallingEdge()){
    // 0 key pressed
    count++;
    bitValue = bitValue / 2;
  }
  
  if (key1.fallingEdge()){
    // 1 key pressed
    count++;
    byteValue = byteValue + bitValue;
    bitValue = bitValue / 2;
  }
  if (keyBack.fallingEdge()){
    // Backspace pressed
    count = 0;
    byteValue = 0;
    bitValue = 128;
  }

  if (count == 8){
    // Full byte has been typed
    // Convert decimal byteValue to ASCII and send as keypress
    char toType = byteValue;
    Keyboard.print(toType);
    // Reset values to get new keypress
    count = 0;
    byteValue = 0;
    bitValue = 128;
  }
}
