# FIREWORK DETONATION DEVICE

**WARNING: THIS IS AN EXPERIMENTAL OPEN-SOURCE PROJECT THAT HAS NOT BEEN TESTED BY THE AUTHOR. USE THIS SOFTWARE AT YOUR OWN RISK.**

For both the controller and detonator, any ATMEGA328P Arduino board (such as the Arduino UNO or NANO) may be used.

## CONTROLLER

For the controller, the source code is at `Firework_detonator_controller.ino`.

Make sure the library **LiquidCrystal I2C** by **Frank de Brabander** is installed in the Arduino IDE, for the LCD to work.

### COMPONENTS NEEDED

- Arduino
- HC-12 RF Module
- LCD with I2C board
- Pull-up button
- Active buzzer

### HC-12 CONFIG

First, the HC-12 module needs to be configured so that it can send and receive correctly. Start with the following configuration:

```
AT
AT+B9600
AT+C001
AT+FU3
AT+RX
```

### WIRING THE CONTROLLER

| Point 1 | Point 2 |
|---|---|
| Arduino 5V | I2C LCD VIN |
| Arduino GND | I2C LCD GND |
| Arduino A4 or Arduino SDA | I2C LCD SDA |
| Arduino A5 or Arduino SCL | I2C LCD SCL |
| Arduino D0 | HC-12 TXD |
| Arduino D1 | HC-12 RXD |
| Arduino 5V | HC-12 VIN |
| Arduino GND | HC-12 GND |
| Arduino D12 | Button 1 |
| Arduino GND | Button 2 |
| Arduino D11 | Buzzer +ve |
| Arduino GND | Buzzer -ve |

## DETONATOR

For the detonator, the source code is at `Firework_detonator.ino`.

### COMPONENTS NEEDED

- Arduino
- HC-12 RF Module
- Heating element (such as Nichrome wire)
- Red LED
- Green LED
- Active buzzer
- Relay module
- External DC power (to power the heating element)

### HC-12 CONFIG

First, the HC-12 module needs to be configured with AT commands so that it can send correctly. Connect the `SET` pin of the HC-12 to the `GND` of the Arduino to send the AT commands. Start with the following configuration in the serial monitor with a baud rate of **9600** and **No line ending**.

```
AT
AT+B9600
AT+C001
AT+FU3
AT+RX
```

### WIRING THE DETONATOR

| Point 1 | Point 2 |
|---|---|
| Arduino D0 | HC-12 TX |
| Arduino D1 | HC-12 RX |
| Arduino 5V | HC-12 VIN |
| Arduino GND | HC-12 GND |
| Arduino D12 | Relay IN |
| Arduino GND | Relay GND |
| Arduino 5V | Relay VIN |
| Relay NO | Power +ve |
| Relay COM | Heater 1 |
| Power -ve | Heater 2 |
| Arduino D11 | Red LED +ve |
| Arduino GND | Red LED -ve |
| Arduino D10 | Green LED +ve |
| Arduino GND | Green LED -ve |
| Arduino D9 | Buzzer +ve |
| Arduino GND | Buzzer -ve |

## HOW TO OPERATE

The trigger button on the controller should be pressed and held for 5 seconds. Once it is held for 5 seconds, the security code is transmitted to the detonator. If the security code matches on both devices, the detonator will initiate the detonation secuence and the heating element heats up.

The heating element should be in contact with the firework's wick.

The red LED of the detontor flashes when it is detonating. Otherwise, it is green.

Henceforth, avoid approaching the detonator when it is red with a firework linked to it.

## SETUP POINTS

Make sure the security code is the same on `Firework_detonator_controller.ino` and `Firework_detonator.ino`.

Additionally, Make sure the channels and modes set on both HC-12 modules are on the same.

For example `AT+C001` (for the channel) and `AT+FU3` (for the mode) must me the same on both HC-12 modules, where `C001` is the channel and `FU3` is the mode.

Make sure baud rate is set to **9600** on both modules, using the `AT+B9600` command.

***WARNING: ENSURE THAT THE HEATING ELEMENT IS SITUATED FURTHER AWAY FROM THE OTHER COMPONENTS, TO ENSURE THAT THEY REMAIN SAFE.**

Enjoy detonating your fireworks and stay safe!