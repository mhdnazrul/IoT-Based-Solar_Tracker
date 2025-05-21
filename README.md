## 🌞 IoT-Based Solar Tracker Using ESP8266, Arduino Uno

This project demonstrates a smart solar tracking system that rotates a solar panel or device to follow the direction of maximum sunlight. It uses two **LDRs** to detect light intensity, a **servo motor** to adjust the position, and integrates with **Blynk IoT** using an **ESP8266 NodeMCU** to monitor the system remotely in real-time.

---

## 🔍 Overview

The system performs the following functions:

* **LDR Sensors (x2):** Continuously measure light intensity from two directions.
* **Servo Motor:** Rotates the solar panel toward the LDR receiving more light, ensuring optimal sunlight tracking.
* **ESP8266 NodeMCU:** Handles Wi-Fi communication and updates data to the Blynk cloud.
* **Blynk App Integration:** Displays live readings from the LDRs, current servo position, and provides LED control functionality.

---

## 📲 Blynk Integration

This project uses the Blynk IoT platform for monitoring and controlling the solar tracker remotely.

| Virtual Pin | Function    | Data Type | Description                             |
| ----------- | ----------- | --------- | --------------------------------------- |
| V0          | LDR1 Value  | Integer   | Shows analog value from LDR1 (A0)       |
| V1          | LDR2 Value  | Integer   | Shows analog value from LDR2 (A1)       |
| V2          | Servo Angle | Integer   | Displays current servo position (0–180) |
| V3          | LED Toggle  | Switch    | Remotely turns an LED ON/OFF on Arduino |

---

## 🧰 Hardware Requirements

| Component                 | Quantity |
| ------------------------- | -------- |
| Arduino Uno               | 1        |
| ESP8266 NodeMCU           | 1        |
| LDR (Light Sensor)        | 2        |
| 10kΩ Resistors (for LDRs) | 2        |
| Servo Motor (SG90)        | 1        |
| LED                       | 1        |
| 220Ω Resistor (for LED)   | 1        |
| Jumper Wires              | Several  |
| Breadboard                | 1        |
| Power Supply (5V)         | 1        |

---

## 🖥️ Software Requirements

* **Arduino IDE**
* **ESP8266 Board Package** (via Board Manager)
* **Blynk Library**
* **Servo Library**
* **Blynk Template Configuration**

  * `Template ID`, `Template Name`, `Auth Token`

---

## ⚡ Circuit Diagram

### Arduino Uno:

| Component   | Pin                              |
| ----------- | -------------------------------- |
| LDR1        | A0                               |
| LDR2        | A1                               |
| Servo Motor | Pin 9                            |
| LED         | Pin 7                            |
| Arduino TX  | ESP8266 D7 (via voltage divider) |
| Arduino RX  | ESP8266 D8 (via 1kΩ resistor)    |

### ESP8266 NodeMCU:

| Component | Pin                            |
| --------- | ------------------------------ |
| D7 (RX)   | ← Arduino TX (through divider) |
| D8 (TX)   | → Arduino RX (through 1kΩ)     |

> ⚠️ Make sure to use a voltage divider between Arduino TX (5V) and ESP8266 RX (3.3V).

---

## ⚙️ Functional Description

* **LDR Reading:** Arduino continuously reads values from both LDRs.
* **Servo Control:** If LDR1 > LDR2, servo turns left; if LDR2 > LDR1, servo turns right. The movement is smooth and adaptive based on the light difference.
* **LED Control:** LED on Arduino board can be toggled from Blynk via V3 switch.
* **ESP8266 Communication:** ESP8266 and Arduino communicate via Software Serial. ESP8266 handles Blynk communication and relays LED commands to Arduino. It also receives LDR readings and servo angle from Arduino and sends them to Blynk.

---

## 💬 Communication Protocol

* **From Arduino to ESP8266:**
  A comma-separated string every 500ms in the format:
  `LDR1,LDR2,ServoAngle,LEDStatus`
  Example: `456,387,90,1`

* **From ESP8266 to Arduino:**
  LED control commands as a single character:
  `'1'` to turn ON the LED
  `'0'` to turn OFF the LED

---

## 🔧 Arduino Code Highlights

* Reads analog values from LDRs on A0 and A1.
* Calculates light intensity difference and rotates the servo accordingly (within limits).
* Responds to LED ON/OFF command from ESP8266.
* Sends sensor data to ESP8266 via Serial.

---

## 🔧 ESP8266 Code Highlights

* Connects to Wi-Fi and Blynk using Auth Token.
* Receives LED toggle commands from Blynk and forwards them to Arduino.
* Reads Arduino's serial output, parses values, and updates Blynk:

  * V0 ← LDR1
  * V1 ← LDR2
  * V2 ← Servo Angle
  * V3 ← LED Status

---

## 🧪 Real-Time Monitoring (via Blynk)

| Data        | Widget Type | Pin | Range            |
| ----------- | ----------- | --- | ---------------- |
| LDR1        | Gauge       | V0  | 0–1023           |
| LDR2        | Gauge       | V1  | 0–1023           |
| Servo Angle | Gauge       | V2  | 0–180            |
| LED Control | Button      | V3  | 0 (OFF) / 1 (ON) |

---

## 🚀 How to Run the Project

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/IoT-Solar-Tracker.git
   cd IoT-Solar-Tracker
   ```

2. Open the **Arduino sketch**:

   * `Arduino/Arduino_Solar_Tracker.ino`
   * Upload it to **Arduino Uno**

3. Open the **ESP8266 sketch**:

   * `ESP8266/ESP8266_Blynk_Comm.ino`
   * Replace Wi-Fi credentials and Blynk token
   * Upload it to **NodeMCU**

4. Connect hardware as per schematic

5. Open Blynk mobile app → Create a dashboard → Add virtual widgets (V0–V3)

6. Power both boards and observe the servo rotating based on light intensity

---

## 📂 Folder Structure

```
IoT-Solar-Tracker/
│
├── Arduino/
│   └── Arduino_Solar_Tracker.ino
│
├── ESP8266/
│   └── ESP8266_Blynk_Comm.ino
│
├── schematic/
│   ├── circuit_diagram.png
│   └── pcb_layout.png
│
├── docs/
│   └── user_manual.pdf
│
└── README.md
```

---

## 📝 Future Improvements

* Add auto/manual switch mode in Blynk
* Add temperature sensor for solar panel health
* Integrate real-time clock (RTC) for timed resets
* Add battery voltage monitoring

---

## 👨‍💻 Author

**Nazrul Islam**
Department of Computer Science & Engineering
Premier University, Chattogram
🔗 [LinkedIn]([https://www.linkedin.com](https://www.linkedin.com/in/nazulislam/))
