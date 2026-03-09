#include "config.h"

void setup() {
  Serial.begin(9600);
  setupBuzzer();
  Serial.println("Enter TDS and pH value (Example: 800 7)");
}

void loop() {
  if (Serial.available() > 0) {
    readSimulatedInputs();

    int gsrValue = readGSR();

    displaySensorValues(tdsValue, phValue, gsrValue);

    bool tdsAbnormal = isTdsAbnormal(tdsValue);
    bool phAbnormal  = isPhAbnormal(phValue);
    bool gsrAbnormal = isGsrAbnormal(gsrValue);

    displayStatus(tdsAbnormal, phAbnormal, gsrAbnormal);

    int riskPercent  = calculateRiskPercent(tdsAbnormal, phAbnormal, gsrAbnormal);
    String riskLevel = getRiskLevel(riskPercent);

    displayRisk(riskPercent, riskLevel);
    triggerBuzzer(riskPercent);
  }
}
