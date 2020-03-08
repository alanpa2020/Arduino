#include <Arduino.h>

void setup() {
  for (int i = 24; i <= 33; i++){
    pinMode (i, OUTPUT);
  }
}

void loop() {
  digitalWrite (26, 1);
  delay (100);
  for (int i = 26; i<=33; i++){
    digitalWrite (i, 0);
    digitalWrite (i+1, 1);
    delay (100);
  }
}