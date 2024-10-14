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
