#include <BH1750.h>
#include <Wire.h>
#include <Servo.h>

BH1750 lightMeter;
Servo myServo;  // Create a Servo object

void setup() {
  Serial.begin(9600);

  // Initialize the I2C bus
  Wire.begin();
  
  lightMeter.begin();

  // Attach the servo to a pin (e.g., D5 for ESP8266 or pin 9 for Arduino)
  myServo.attach(9);  // Adjust pin as needed
  
  Serial.println(F("BH1750 Test begin"));
}

void loop() {
  float lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");

  // Check if the light level is above 500 lx
  if (lux > 500) {
    Serial.println("Light level above 500 lx. Rotating servo.");
    myServo.write(180);  // Rotate the servo to 180 degrees
  } else {
    myServo.write(0);  // Rotate the servo to 0 degrees (initial position)
  }

  delay(1000);
}