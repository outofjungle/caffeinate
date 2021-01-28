#include <BleMouse.h>

BleMouse bleMouse;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleMouse.begin();
}

void draw_circle(int radius) {
  float theta = TWO_PI;

  while (theta > 0) {
    theta = theta - 0.1;

    int move_x = radius * cos(theta);
    int move_y = radius * sin(theta);

    bleMouse.move(move_x, move_y, 0);
    delay(100);
  }
}

void loop() {
  if (bleMouse.isConnected()) {
    draw_circle(10);
  }
}
