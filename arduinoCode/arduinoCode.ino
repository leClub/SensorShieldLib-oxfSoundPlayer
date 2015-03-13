#include <sensorShieldLib.h>

SensorShield board;

void setup() {
  board.init();
  board.addSensor("btn1", 10, INPUT_PULLUP);
  board.addSensor("btn2", 11, INPUT_PULLUP);
  board.addSensor("btn3", 12, INPUT_PULLUP);

  board.addSensor("btn4", 8, INPUT_PULLUP);
  board.addSensor("btn5", 7, INPUT_PULLUP);
  board.addSensor("btn6", 9, INPUT_PULLUP);

  board.addSensor("btn7", 3, INPUT_PULLUP);
}

void loop() {
  board.update();
}
