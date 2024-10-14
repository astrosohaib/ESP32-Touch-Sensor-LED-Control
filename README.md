# ESP32-Touch-Sensor-LED-Control
This project uses an ESP32 microcontroller to control 4 LEDs using 4 touch sensors. When a touch sensor is activated, its corresponding LED lights up.
# ESP32 Touch Sensor LED Control

This project uses an ESP32 microcontroller to control 4 LEDs using 4 touch sensors. When a touch sensor is activated, its corresponding LED lights up.

## Pin Configuration

### Touch Sensors
- Touch Sensor 1: GPIO 32 (T9)
- Touch Sensor 2: GPIO 33 (T8)
- Touch Sensor 3: GPIO 27 (T7)
- Touch Sensor 4: GPIO 14 (T6)

### LEDs
- LED 1: GPIO 16
- LED 2: GPIO 17
- LED 3: GPIO 18
- LED 4: GPIO 19

## Hardware Setup

1. Connect four touch-sensitive surfaces or wires to the touch sensor pins (GPIO 32, 33, 27, and 14).
2. Connect four LEDs to the LED pins (GPIO 16, 17, 18, and 19). Remember to use appropriate resistors for your LEDs.
3. Ensure your ESP32 is properly powered.

## Software Configuration

- The touch threshold is set to 40 by default. You may need to adjust this value based on your specific touch sensors and environmental conditions.
- The serial monitor baud rate is set to 115200.

## Functionality

- When a touch sensor detects a touch (reading falls below the threshold), the corresponding LED turns on.
- When the touch is released, the LED turns off.
- Touch sensor readings are continuously printed to the serial monitor for debugging purposes.


  
