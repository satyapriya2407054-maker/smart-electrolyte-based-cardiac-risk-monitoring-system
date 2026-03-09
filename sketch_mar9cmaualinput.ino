#define GsrSensorPin A1
#define buzzerPin 8  

// ----------- NORMAL RANGE -----------  
#define TDS_MIN 500  
#define TDS_MAX 1500  

#define PH_MIN 4.5
#define PH_MAX 7.5

#define GSR_MIN 100
#define GSR_MAX 350

float tdsValue = 0;
float phValue = 0;

void setup() {  
  
  Serial.begin(9600);  
  
  pinMode(buzzerPin, OUTPUT);  
  noTone(buzzerPin);  
  
  Serial.println("Enter TDS and pH value (Example: 800 7)");
}

void loop() {  

  if (Serial.available() > 0) {

    // -------- SIMULATED INPUT --------
    tdsValue = Serial.parseFloat();  
    phValue = Serial.parseFloat();  

    Serial.println("---- Input Received ----");

    // -------- GSR REAL SENSOR --------
    int gsrValue = analogRead(GsrSensorPin);

    // -------- DISPLAY VALUES --------
    Serial.print("TDS: ");
    Serial.print(tdsValue);
    Serial.println(" ppm");

    Serial.print("pH: ");
    Serial.println(phValue);

    Serial.print("GSR: ");
    Serial.println(gsrValue);

    // -------- STATUS CHECK --------
    bool tdsAbnormal = (tdsValue < TDS_MIN || tdsValue > TDS_MAX);
    bool phAbnormal = (phValue < PH_MIN || phValue > PH_MAX);
    bool gsrAbnormal = (gsrValue < GSR_MIN || gsrValue > GSR_MAX);

    // -------- STATUS DISPLAY --------
    if (tdsAbnormal)
      Serial.println("TDS Status: ABNORMAL");
    else
      Serial.println("TDS Status: NORMAL");

    if (phAbnormal)
      Serial.println("pH Status: ABNORMAL");
    else
      Serial.println("pH Status: NORMAL");

    if (gsrAbnormal)
      Serial.println("GSR Status: ABNORMAL");
    else
      Serial.println("GSR Status: NORMAL");

    // -------- RISK PERCENTAGE --------
    int riskPercent = 0;

    if (tdsAbnormal) riskPercent += 35;
    if (phAbnormal) riskPercent += 35;
    if (gsrAbnormal) riskPercent += 30;

    // -------- RISK LEVEL --------
    String riskLevel;

    if (riskPercent >= 80)
      riskLevel = "HIGH";
    else if (riskPercent >= 40)
      riskLevel = "MODERATE";
    else
      riskLevel = "LOW";

    Serial.print("Cardiac Risk Percentage: ");
    Serial.print(riskPercent);
    Serial.println("%");

    Serial.print("Cardiac Risk Level: ");
    Serial.println(riskLevel);

    // -------- BUZZER --------
    if (riskPercent >= 40) {
      tone(buzzerPin, 1000);
    } else {
      noTone(buzzerPin);
    }

    Serial.println("------------------------------");
  }

}