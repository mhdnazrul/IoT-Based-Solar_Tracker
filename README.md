# ☀️ IoT Based Solar_Tracker

This project is a **Solar Tracker System** that uses two **LDRs (Light Dependent Resistors)** to detect light intensity and rotate a **servo motor** accordingly to follow the direction of the light (e.g. the sun). The system also includes a **manual control LED**, and real-time feedback is displayed on the **Blynk IoT mobile app** using the **ESP8266 NodeMCU** as the Wi-Fi module.

## 📌 Features

- Dual LDR light tracking using Arduino Uno
- Servo motor positioning based on LDR input
- Remote LED control via Blynk
- Real-time feedback to Blynk app:
  - LDR1 and LDR2 values
  - Current servo angle
  - LED status
- Communication between Arduino Uno and ESP8266 via Serial

---

## 🛠️ Hardware Components

| Component              | Quantity |
|------------------------|----------|
| Arduino Uno            | 1        |
| ESP8266 NodeMCU        | 1        |
| LDR (Light Sensor)     | 2        |
| Servo Motor (SG90)     | 1        |
| LED (any color)        | 1        |
| Resistors (1kΩ, 10kΩ)  | As needed |
| Jumper Wires           | Many     |
| Breadboard             | 1        |
| Power Supply (5V USB)  | 1        |

---

## ⚙️ Circuit Connections

### Arduino Uno
- **LDR1** → A0  
- **LDR2** → A1  
- **Servo Motor** → Pin 9  
- **LED** → Pin 7  
- **TX** → Connect to ESP8266 D7 (through voltage divider)  
- **RX** → Connect to ESP8266 D8  

### ESP8266 NodeMCU
- **D7 (RX)** ← Arduino TX  
- **D8 (TX)** → Arduino RX via 1kΩ resistor  
- **Wi-Fi**: Connects to Blynk server

A voltage divider is used to step down the 5V TX signal from Arduino to safe 3.3V for ESP8266 RX pin.

---

## 📲 Blynk IoT Setup

### 1. Create a new Template
- Template Name: `Solar Tracker`
- Hardware: `ESP8266`
- Connection: `WiFi`
- Copy the `Template ID`, `Template Name`, and `Auth Token`

### 2. Create Datastreams
| Virtual Pin | Name       | Type    | Use                          |
|-------------|------------|---------|------------------------------|
| V0          | LDR1       | Integer | LDR1 value from Arduino      |
| V1          | LDR2       | Integer | LDR2 value from Arduino      |
| V2          | ServoAngle | Integer | Servo motor position (0–180)|
| V3          | LEDControl | Switch  | Turn LED ON/OFF remotely     |

### 3. Add Widgets to Dashboard
- **Gauge** for V0 and V1 (LDRs)
- **Gauge or Slider** for V2 (Servo Angle)
- **Switch** for V3 (LED Control)

---

## 🧠 Code Overview

### Arduino (Uno)
- Reads analog input from LDRs.
- Calculates light difference and adjusts servo angle.
- Responds to LED control commands from ESP8266.
- Sends comma-separated values over Serial:  
  `LDR1,LDR2,Angle,LEDStatus`

### ESP8266 (NodeMCU)
- Connects to Wi-Fi and Blynk.
- Sends LED commands to Arduino based on V3 switch.
- Reads Serial data from Arduino and pushes values to Blynk.

---

## 🧪 How It Works

1. The Arduino constantly monitors light intensity from both LDRs.
2. It rotates the servo left/right to balance light on both sides.
3. The ESP8266 reads data from Arduino and updates Blynk.
4. The user can turn ON/OFF the LED remotely from Blynk.
5. Real-time feedback of LDR readings and servo position is shown in Blynk app.

---

## 🔋 Power Supply

You can power the ESP8266 separately using a USB cable or a 3.3V regulator. Make sure the grounds of Arduino and ESP8266 are connected.

---

## 🔐 Security Tip

Don’t expose your Auth Token or Wi-Fi credentials in a public repository. Use environment variables or a `secrets.h` file (add it to `.gitignore`) for production use.

---

## 📷 Schematic & PCB

See `/schematic/` folder for circuit diagram and sample PCB layout. You may also find PDF documentation in `/docs/`.

---

## 👨‍💻 Author

Nazrul Islam – Computer Science & Engineering, Premier University  
Connect on [LinkedIn](https://www.linkedin.com/in/nazulislam/)

---

## ✅ Future Improvements
- Add automatic/manual toggle mode
- Add feedback acknowledgment from Arduino
- Use OLED display for on-device monitoring
