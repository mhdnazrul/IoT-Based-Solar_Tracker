🌞 IoT-Based Solar Tracker using ESP8266 & Arduino
This project is designed to create an IoT-based solar tracking system that automatically aligns a solar panel using two LDRs and a servo motor to maximize sunlight exposure. The system integrates Arduino and ESP8266 (NodeMCU) via serial communication and sends real-time data to the Blynk app for remote monitoring and control.

📌 Features
📡 LDR Sensors: Detect the light intensity from two directions.

🔄 Servo Motor: Adjusts the angle of the solar panel based on the light difference.

💡 LED Control: An LED can be remotely turned on/off from Blynk.

📊 Real-time Monitoring: Live LDR readings, servo angle, and LED status shown on Blynk app.

🔗 Serial Communication: ESP8266 and Arduino communicate over UART.

🛠️ Hardware Components
Component	Quantity
Arduino UNO	1
ESP8266 (e.g., NodeMCU)	1
LDR (Light Sensor)	2
10kΩ Resistor (for LDR voltage divider)	2
Servo Motor (SG90 or similar)	1
LED	1
Breadboard + Jumper Wires	As needed
USB Cable (for Arduino)	1
Resistor (1kΩ) for TX to RX voltage divider	1

🔌 Circuit Diagram
Arduino Connections:
LDR1: One end to 5V, other end to A0 with 10kΩ resistor to GND.

LDR2: One end to 5V, other end to A1 with 10kΩ resistor to GND.

Servo Motor: Signal to pin 9, VCC to 5V, GND to GND.

LED: Anode to pin 7 (with 220Ω resistor), cathode to GND.

Serial (To ESP8266): TX (pin 1) → ESP8266 RX (via 1kΩ resistor), RX (pin 0) ← ESP8266 TX.

ESP8266 Connections:
TX (D7) → Arduino RX

RX (D8) ← Arduino TX (through 1kΩ resistor)

VCC & GND: Connected to 3.3V and GND.

Flash via USB then switch to communication mode.

📱 Blynk Configuration
Use Blynk IoT Platform and configure the following:

⚙️ Datastreams (Virtual Pins)
Virtual Pin	Name	Type	Data Type	Range	Description
V0	LDR1 Value	Input	Integer	0–1023	Displays value of LDR1
V1	LDR2 Value	Input	Integer	0–1023	Displays value of LDR2
V2	Servo Angle	Input	Integer	0–180	Shows current servo angle
V3	LED Control	Switch	Integer	0 or 1	Turns LED ON/OFF

🧠 How It Works
LDRs detect light intensity on two sides of the panel.

Arduino calculates the difference and adjusts the servo to tilt toward stronger light.

The ESP8266 receives sensor and servo data from Arduino via serial and sends it to Blynk Cloud.

Users can monitor LDR values, current servo angle, and control the LED remotely using Blynk.

Blynk switch (V3) sends commands to ESP8266 which then relays the message to Arduino to toggle the LED.

🔄 File Structure
bash
Copy
Edit
IoT-Solar-Tracker/
│
├── arduino/
│   └── solar_tracker_arduino.ino       # Arduino code (LDRs, servo, LED)
│
├── esp8266/
│   └── solar_tracker_esp8266.ino       # ESP8266 code (Blynk + serial)
│
├── circuit/
│   └── solar_tracker_circuit.png       # Optional circuit diagram image
│
└── README.md                           # Project description and setup
🧾 Installation Steps
Install Arduino IDE

Install libraries:

ESP8266 Board (via Board Manager)

Blynk library (BlynkSimpleEsp8266)

Servo library

Upload the Arduino sketch to Arduino Uno.

Upload the ESP8266 sketch to NodeMCU.

Connect ESP8266 TX/RX with Arduino as shown.

Create your project in Blynk, set up widgets as described.

Power up both boards and observe live updates on your Blynk app.

🚀 Future Improvements
Dual-axis tracking using 2 servos.

Integration with solar panel power monitoring.

Display panel using OLED or LCD.

Battery-powered standalone operation.

## 👨‍💻 Author

**Nazrul Islam**
Department of Computer Science & Engineering
Premier University, Chattogram
🔗 [LinkedIn](https://www.linkedin.com/in/nazulislam/)
