#include "config.h"

void setupBuzzer() {
  pinMode(buzzerPin, OUTPUT);
  noTone(buzzerPin);
}

void triggerBuzzer(int riskPercent) {
  if (riskPercent >= 40) {
    tone(buzzerPin, 1000);
  } else {
    noTone(buzzerPin);
  }
}
