/*
  ESP32 BLE Caffeinate Mouse

  Tested on [ESP32 Dev Board](https://www.adafruit.com/product/3269)
  Needs [ESP32 BLE Mouse Library](https://github.com/T-vK/ESP32-BLE-Mouse/tree/0.3.1)

*/

#include <BleMouse.h>

const int SWITCH_PIN = 22;
const int LED_PIN = 23;
const int RADIUS = 10;

BleMouse bleMouse;
float theta;

void setup() {
  pinMode(SWITCH_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  bleMouse.begin();
  theta = TWO_PI;
}

void loop() {
  int x, y;

  if (bleMouse.isConnected()) {
    int switch_state = digitalRead(SWITCH_PIN);

    if (switch_state == HIGH) {
      digitalWrite(LED_PIN, HIGH);

      x = RADIUS * cos(theta);
      y = RADIUS * sin(theta);

      bleMouse.move(x, y, 0);

      theta = theta - 0.1;
      if (theta < 0) {
        theta = TWO_PI;
      }
    } else {
      digitalWrite(LED_PIN, LOW);
    }
  }

  delay(100);
}
