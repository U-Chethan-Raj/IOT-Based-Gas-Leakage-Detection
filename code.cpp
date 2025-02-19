#include <ESP8266WiFi.h>  // Include WiFi Library
#include <BlynkSimpleEsp8266.h>  

// WiFi Credentials
char ssid[] = "YourWiFiSSID";      
char pass[] = "YourWiFiPassword";  

// Blynk Authentication Token
char auth[] = "YourBlynkAuthToken";  

// Define Pins
#define MQ6 A0      // Gas sensor analog pin
#define BUZZER 6    // Buzzer pin
#define LED_RED 7   // Red LED (Gas Detected)
#define LED_GREEN 8 // Green LED (Safe)

// Threshold for gas detection (Adjust based on testing)
const int gasThreshold = 400;  

void setup() {
  Serial.begin(9600);        // Start serial communication
  Blynk.begin(auth, ssid, pass);  // Connect to Blynk

  pinMode(MQ6, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  digitalWrite(LED_GREEN, HIGH); // Default state: Safe
}

void loop() {
  int gasLevel = analogRead(MQ6);  // Read gas sensor value
  Serial.print("Gas Level: ");
  Serial.println(gasLevel);

  if (gasLevel > gasThreshold) { // Gas detected
    digitalWrite(LED_RED, HIGH);  // Turn on red LED
    digitalWrite(LED_GREEN, LOW); // Turn off green LED
    digitalWrite(BUZZER, HIGH);   // Activate buzzer

    Blynk.notify("⚠️ Gas Leak Detected! Take Action Immediately!");  
  } 
  else {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(BUZZER, LOW);
  }

  Blynk.run();  // Keep Blynk connection alive
  delay(2000);  // Wait before next reading
}
