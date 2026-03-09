void displaySensorValues(float tds, float ph, int gsr) {
  Serial.println("---- Input Received ----");

  Serial.print("TDS: ");
  Serial.print(tds);
  Serial.println(" ppm");

  Serial.print("pH: ");
  Serial.println(ph);

  Serial.print("GSR: ");
  Serial.println(gsr);
}

void displayStatus(bool tdsAbnormal, bool phAbnormal, bool gsrAbnormal) {
  Serial.println(tdsAbnormal ? "TDS Status: ABNORMAL" : "TDS Status: NORMAL");
  Serial.println(phAbnormal  ? "pH Status: ABNORMAL"  : "pH Status: NORMAL");
  Serial.println(gsrAbnormal ? "GSR Status: ABNORMAL" : "GSR Status: NORMAL");
}

void displayRisk(int riskPercent, String riskLevel) {
  Serial.print("Cardiac Risk Percentage: ");
  Serial.print(riskPercent);
  Serial.println("%");

  Serial.print("Cardiac Risk Level: ");
  Serial.println(riskLevel);

  Serial.println("------------------------------");
}
