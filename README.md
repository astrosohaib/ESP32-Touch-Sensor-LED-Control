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

// Define touch pins and LED pins
#define TOUCH_PIN_1 32  // T9
#define TOUCH_PIN_2 33  // T8
#define TOUCH_PIN_3 27  // T7
#define TOUCH_PIN_4 14  // T6

#define LED_PIN_1 16
#define LED_PIN_2 17
#define LED_PIN_3 18
#define LED_PIN_4 19

// Touch threshold (adjust if necessary)
int touchThreshold = 40;

void setup() {
  Serial.begin(115200);

  // Set LED pins as output
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);

  // Initialize LEDs as OFF
  digitalWrite(LED_PIN_1, LOW);
  digitalWrite(LED_PIN_2, LOW);
  digitalWrite(LED_PIN_3, LOW);
  digitalWrite(LED_PIN_4, LOW);
}

void loop() {
  // Read touch sensor values
  int touchValue1 = touchRead(TOUCH_PIN_1);
  int touchValue2 = touchRead(TOUCH_PIN_2);
  int touchValue3 = touchRead(TOUCH_PIN_3);
  int touchValue4 = touchRead(TOUCH_PIN_4);

  // Debugging: print touch values to serial monitor
  Serial.print("Touch Value 1: "); Serial.println(touchValue1);
  Serial.print("Touch Value 2: "); Serial.println(touchValue2);
  Serial.print("Touch Value 3: "); Serial.println(touchValue3);
  Serial.print("Touch Value 4: "); Serial.println(touchValue4);
  
  // Turn LEDs ON/OFF based on touch threshold
  if (touchValue1 < touchThreshold) {
    digitalWrite(LED_PIN_1, HIGH);
  } else {
    digitalWrite(LED_PIN_1, LOW);
  }

  if (touchValue2 < touchThreshold) {
    digitalWrite(LED_PIN_2, HIGH);
  } else {
    digitalWrite(LED_PIN_2, LOW);
  }

  if (touchValue3 < touchThreshold) {
    digitalWrite(LED_PIN_3, HIGH);
  } else {
    digitalWrite(LED_PIN_3, LOW);
  }

  if (touchValue4 < touchThreshold) {
    digitalWrite(LED_PIN_4, HIGH);
  } else {
    digitalWrite(LED_PIN_4, LOW);
  }

  // Add a short delay for stability
  delay(100);
}
