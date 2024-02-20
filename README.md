# ESPHome controller for NAD C368/C388

Big thanks for machosallad

Control NAD C368/C388 through RS232 from Home Assistant (HA) using ESPHome and a Wemos D1. The ESPhome configuration exposes the following entities to HA:

- Power
- Sources
- Mute
- Speaker A/B
- Volume increment and decrement
- Set volume level

The entities are queried during startup and will automatically be updated based on the information received from the amplifier.
Volume entities are configured as buttons and volume slider which can be added to Home Assistant universal media player integration.
There is Home Assistant uart write service "nadrs232_write". You can send any command to RS232 over HA service.

![D1|300](https://user-images.githubusercontent.com/16154330/224545597-2250914c-15a7-4edc-a7ab-20a4b03c57b4.jpg)

## Resources

The UART text sensor used for ESPHome is based on the description at [Custom UART Text Sensor](https://esphome.io/cookbook/uart_text_sensor.html).

## Hardware

- MAX3232 RS232 Serial Port to TTL Conversion Module
- Wemos D1
- Null modem cable

### Wiring

| Wemos D1 | MAX3232 |
| -------- | ------- |
| D4       | TX      |
| D3       | RX      |
| GND      | GND     |
| 3.3      | VCC     |

## C368 RS232 command list

Set the baud rate to `115200` to properly send and receive serial data from C356BEE. A reference for these commands can be
found on this [webpage](https://www.yumpu.com/en/document/read/35405103/c356-rs232-command-list-nad-electronics-main-lektropacks).

| Command         | Operators | Possible values                     | Description                                   | Example             |
| --------------- | --------- | ----------------------------------- | ----------------------------------------------| ------------------- |
| `Main.Model`    | ?         | N/A                                 | Query model                                   | `Main.Model?`       |
| `Main.Mute`     | =/+/-/?   | On, Off                             | Set mute                                      | `Main.Mute=On`      |
| `Main.Power`    | =/+/-/?   | On, Off                             | Set power on/off                              | `Main.Power=On`     |
| `Main.Source`   | =/+/-/?   | 1,2,3,4,5,6,7,8                     | Set source                                    | `Main.Source=CD`    |
| `Main.SpeakerA` | =/+/-/?   | On, Off                             | Set speaker A on/off                          | `Main.SpeakerA=On`  |
| `Main.SpeakerB` | =/+/-/?   | On, Off                             | Set speaker B on/off                          | `Main.SpeakerB=Off` |
| `Main.Tape1`    | =/+/-/?   | On, Off                             | Set tape 1 on/off                             | `Main.Tape1=On`     |
| `Main.Volume`   | =/+/-/?   | -70 to 20                           | Increment or decrement volume or set volume   | `Main.Volume+`      |

## 3D printed case

The case and cover can be printed using a filament printer in order to store the electronics neatly.

## Useful insights

Make sure to connect the Rx and Tx pins properly between the nodes that need to communicate. I had a problem with my amplifier and
MAX3232 where I used a straight cable instead of a twisted/null cable, which caused the devices to not communicate with each other.
It took me a long time to realize this mistake.
