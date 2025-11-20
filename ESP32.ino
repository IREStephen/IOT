#include <Wire.h>
#include <BH1750.h>

// Create BH1750 object
BH1750 lightMeter;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22); // SDA, SCL pins for ESP32

  // Initialize BH1750
  if (!lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println("BH1750 error");
  } else {
    Serial.println("BH1750 initialized");
  }
}

void loop() {
  // Read light level in lux
  float lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");

  delay(1000); // Read every second
}
