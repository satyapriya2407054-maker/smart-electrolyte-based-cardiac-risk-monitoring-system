#include "config.h"

float tdsValue = 0;
float phValue = 0;

void readSimulatedInputs() {
  tdsValue = Serial.parseFloat();
  phValue = Serial.parseFloat();
}

int readGSR() {
  return analogRead(GsrSensorPin);
}
