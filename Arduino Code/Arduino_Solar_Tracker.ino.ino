#include <Servo.h>

#define LDR1_PIN A0
#define LDR2_PIN A1
#define SERVO_PIN 9
#define LED_PIN 7

Servo solarServo;
int servoAngle = 90;
int tolerance = 30;
bool ledState = false;
unsigned long lastSendTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  solarServo.attach(SERVO_PIN);
  solarServo.write(servoAngle);
  delay(1000);
}

void loop() {
  int ldr1 = analogRead(LDR1_PIN);
  int ldr2 = analogRead(LDR2_PIN);
  int diff = ldr1 - ldr2;

  if (abs(diff) > tolerance) {
    if (diff > 0) {
      servoAngle = min(servoAngle + 1, 180);
    } else {
      servoAngle = max(servoAngle - 1, 0);
    }
    solarServo.write(servoAngle);
  }

  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd == "LED_ON") {
      digitalWrite(LED_PIN, HIGH);
      ledState = true;
    } else if (cmd == "LED_OFF") {
      digitalWrite(LED_PIN, LOW);
      ledState = false;
    }
  }

  if (millis() - lastSendTime >= 500) {
    String data = String(ldr1) + "," + String(ldr2) + "," + String(servoAngle) + "," + String(ledState);
    Serial.println(data);
    lastSendTime = millis();
  }

  delay(50);
}
