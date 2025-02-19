# IOT-Based-Gas-Leakage-Detection

# Gas Leakage Detection & Alert System

## Project Overview

Gas leakage poses a significant risk in homes, industries, and workplaces where combustible gases such as LPG, methane, or propane are used. A gas leak can lead to fire hazards, explosions, or health issues due to toxic inhalation. This project aims to develop an intelligent **Gas Leakage Detection & Alert System** that ensures safety by providing real-time gas monitoring and immediate alerts in case of a leak.

The system integrates an **MQ6 gas sensor**, **Arduino Uno**, **ESP8266 WiFi module**, **buzzer**, and **LEDs** to detect gas leakage and notify users via a mobile app. When the gas concentration crosses a defined threshold, the system triggers the buzzer and LED indicators while simultaneously sending a real-time notification to the user’s smartphone via the **Blynk IoT platform**. This allows quick intervention and mitigates the risk of fire hazards. 

### Key Features:
- **Real-time Gas Monitoring:** Continuously detects gas levels using the MQ6 sensor.
- **Immediate Alert System:** Activates buzzer and LED indicators upon gas detection.
- **Wireless Notifications:** Sends mobile alerts through WiFi using the ESP8266 module.
- **User-friendly & Cost-effective:** Can be deployed in homes, kitchens, factories, and laboratories.
- **Customizable Thresholds:** Users can modify gas sensitivity based on environmental conditions.

## Components Required

| Component                    | Quantity |
|------------------------------|----------|
| Arduino Uno                  | 1        |
| MQ6 Gas Sensor               | 1        |
| ESP8266 WiFi Module (ESP-01) | 1        |
| Buzzer                       | 1        |
| Red LED                      | 1        |
| Green LED                    | 1        |
| Resistors (1KΩ, 330Ω, 10KΩ)  | As needed|
| Jumper Wires                 | As needed|

## Circuit Connections

| Component         | Arduino Pin            |
|-------------------|------------------------|
| MQ6 AO            | A0                     |
| Buzzer +          | D6                     |
| LED (Red) +       | D7                     |
| LED (Green) +     | D8                     |
| ESP8266 TX        | D2                     |
| ESP8266 RX        | D3 (via 10KΩ resistor) |
| ESP8266 VCC/CH_PD | 3.3V                   |
| ESP8266 GND       | GND                    |

## Software Requirements
- **Arduino IDE** (For coding and uploading the sketch)
- **Blynk IoT App** (For notifications on mobile)
- **ESP8266WiFi and Blynk Library** (Install via Arduino Library Manager)

## How It Works
1. The **MQ6 Sensor** detects gas concentration and sends an analog signal to the Arduino.
2. If the **gas level exceeds the threshold**, the Arduino:
   - Activates the **buzzer** and **red LED** as a warning.
   - Turns off the **green LED** to indicate an unsafe environment.
   - Sends a **real-time notification** to the mobile phone via ESP8266.
3. Once the gas level returns to normal, the system resets, turning off the buzzer and switching the green LED back on.

## Setting Up Blynk Notifications
1. **Download the Blynk App** (iOS/Android).
2. **Create a new project** and select ESP8266 as the device.
3. **Add a Notification Widget**.
4. **Copy the Auth Token** (You will use this in the Arduino code).
5. **Connect Arduino to WiFi and Upload Code.**
6. **Receive Alerts on Your Phone** when a gas leak is detected.

## Arduino Code
Upload the provided **Arduino Code** to the **Arduino Uno** using the **Arduino IDE**. Don't forget to update **WiFi credentials** and **Blynk Auth Token** in the code.

## Future Improvements
- **Integration with SMS and Email Alerts** via IFTTT Webhooks.
- **LCD Display** to show real-time gas levels.
- **Cloud Dashboard (Firebase, MQTT, Thingspeak)** for remote monitoring.
- **Battery Backup and Solar Power** for uninterrupted operation.
- **AI-based Predictive Analysis** to detect gas leaks before they become critical.

## Troubleshooting
- **ESP8266 Not Connecting?** Ensure the correct baud rate (9600/115200) and power supply (3.3V).
- **Blynk Not Receiving Alerts?** Check internet connectivity and authentication token.
- **False Alarms?** Adjust the gas detection threshold based on environmental conditions.

## Conclusion
This Arduino-based **Gas Leakage Detection System** is a reliable, real-time monitoring solution for **homes, offices, and industrial settings**. It provides an early warning system, helping prevent hazardous incidents by alerting users to gas leaks promptly. With further improvements, the system can be extended to support AI-based prediction models and cloud monitoring for enhanced safety.

If you have any questions or need modifications, feel free to reach out.

Stay safe and ensure a gas-free environment!

