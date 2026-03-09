#include "config.h"

bool isTdsAbnormal(float tds) {
  return (tds < TDS_MIN || tds > TDS_MAX);
}

bool isPhAbnormal(float ph) {
  return (ph < PH_MIN || ph > PH_MAX);
}

bool isGsrAbnormal(int gsr) {
  return (gsr < GSR_MIN || gsr > GSR_MAX);
}

int calculateRiskPercent(bool tdsAbnormal, bool phAbnormal, bool gsrAbnormal) {
  int risk = 0;
  if (tdsAbnormal) risk += 35;
  if (phAbnormal)  risk += 35;
  if (gsrAbnormal) risk += 30;
  return risk;
}

String getRiskLevel(int riskPercent) {
  if (riskPercent >= 80) return "HIGH";
  if (riskPercent >= 40) return "MODERATE";
  return "LOW";
}
