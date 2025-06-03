#include "uart_read_line_sensor.h"

namespace esphome {
namespace uart_read_line_sensor {

UartReadLineSensor::UartReadLineSensor() : uart::UARTDevice(), text_sensor::TextSensor() {}

UartReadLineSensor::UartReadLineSensor(uart::UARTComponent *parent) : uart::UARTDevice(parent) {}

void UartReadLineSensor::setup() {
  // nothing to do here
}

int UartReadLineSensor::readline(int readch, char *buffer, int len) {
  static int pos = 0;
  int rpos;

  if (readch > 0) {
    switch (readch) {
      case '\n':
        break;
      case '\r':
        rpos = pos;
        pos = 0;
        return rpos;
      default:
        if (pos < len - 1) {
          buffer[pos++] = readch;
          buffer[pos] = 0;
        }
    }
  }
  return -1;
}

void UartReadLineSensor::loop() {
  const int max_line_length = 80;
  static char buffer[max_line_length];
  while (available()) {
    if (readline(read(), buffer, max_line_length) > 0) {
      this->publish_state(buffer);
    }
  }
}

}  // namespace uart_read_line_sensor
}  // namespace esphome
