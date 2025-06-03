import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart, text_sensor
from esphome.const import CONF_ID

CODEOWNERS = ["@SirJohnDoe"]
DEPENDENCIES = ["uart"]
AUTO_LOAD = ["text_sensor"]

uart_read_line_sensor_ns = cg.esphome_ns.namespace('uart_read_line_sensor')
UartReadLineSensor = uart_read_line_sensor_ns.class_(
    'UartReadLineSensor',
    cg.Component,
    uart.UARTDevice,
    text_sensor.TextSensor,
)

CONFIG_SCHEMA = text_sensor.text_sensor_schema(UartReadLineSensor).extend(
    uart.UART_DEVICE_SCHEMA
).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    yield uart.register_uart_device(var, config)
    yield text_sensor.register_text_sensor(var, config)
