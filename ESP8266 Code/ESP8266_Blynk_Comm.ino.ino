#define BLYNK_TEMPLATE_ID "TMPL67aE43LgZ"
#define BLYNK_TEMPLATE_NAME "Solar Tracker"
#define BLYNK_AUTH_TOKEN "9NB33jz4Fy4Vd2QKYxjUWaoQG3eJ4seB"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "9NB33jz4Fy4Vd2QKYxjUWaoQG3eJ4seB";
char ssid[] = "PU_OTHER STUDENTS";
char pass[] = "PuC123456789#";

#define ARDUINO_RX D7
#define ARDUINO_TX D8

#include <SoftwareSerial.h>
SoftwareSerial ArduinoSerial(ARDUINO_RX, ARDUINO_TX);

void setup() {
  Serial.begin(9600);
  ArduinoSerial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  Blynk.virtualWrite(V0, 0);
  Blynk.virtualWrite(V1, 0);
  Blynk.virtualWrite(V2, 90);
  Blynk.virtualWrite(V3, 0);
}

BLYNK_WRITE(V3) {
  int ledState = param.asInt();
  if (ledState == 1) {
    ArduinoSerial.println("LED_ON");
  } else {
    ArduinoSerial.println("LED_OFF");
  }
}

void loop() {
  Blynk.run();
  if (ArduinoSerial.available()) {
    String data = ArduinoSerial.readStringUntil('\n');
    data.trim();
    int values[4];
    int index = 0;
    int lastPos = 0;
    for (int i = 0; i < data.length(); i++) {
      if (data.charAt(i) == ',') {
        values[index++] = data.substring(lastPos, i).toInt();
        lastPos = i + 1;
      }
    }
    values[index] = data.substring(lastPos).toInt();
    if (index == 3) {
      Blynk.virtualWrite(V0, values[0]);
      Blynk.virtualWrite(V1, values[1]);
      Blynk.virtualWrite(V2, values[2]);
      Blynk.virtualWrite(V3, values[3]);
    }
  }
  delay(100);
}
