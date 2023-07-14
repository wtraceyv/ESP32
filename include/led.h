#include <Arduino.h>

#define LED GPIO_NUM_35

void blink(int millisecondsOn, int millisecondsAfter) {
  digitalWrite(LED, HIGH);
  delay(millisecondsOn);
  digitalWrite(LED, LOW);
  delay(millisecondsAfter);
}