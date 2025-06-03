#pragma once

#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"
#include "esphome/components/text_sensor/text_sensor.h"

namespace esphome {
namespace uart_read_line_sensor {

class UartReadLineSensor : public Component, public uart::UARTDevice, public text_sensor::TextSensor {
 public:
  // Default constructor (needed by ESPHome codegen)
  UartReadLineSensor();

  // Optional constructor to manually assign UART parent
  explicit UartReadLineSensor(uart::UARTComponent *parent);

  void setup() override;
  void loop() override;

 protected:
  int readline(int readch, char *buffer, int len);
};

}  // namespace uart_read_line_sensor
}  // namespace esphome
